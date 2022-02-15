<?php

/**
 * @file
 * Form functions for cu_js_includes module.
 */

// Include confirm form file.
module_load_include('inc', 'cu_js_includes', 'pages/cu_js_includes.confirm_form');

/**
 * Form for adding embeds.
 *
 * @param array $form
 *   Empty form passed in to be built upon.
 * @param array $form_state
 *   State of form which might be in confirmation step.
 * @param int|null $cu_js_includes_id
 *   ID of embed if being edited or deleted.
 *
 * @return array
 *   Fully built form ready to send to user.
 */
function cu_js_includes_form($form, &$form_state, $cu_js_includes_id = NULL) {

  // If set to delete embeds, then return that form.
  if (isset($form_state['storage']['confirm'])) {
    return cu_js_includes_confirm($form, $form_state);
  }

  // Initialize default form variables.
  $form = array();
  $label = $path = '';
  $data = array();
  $cu_js_includes = NULL;
  $id = NULL;
  $size = variable_get('cu_js_includes_form_field_size', 128);

  // Load embed if it exists.
  if ($cu_js_includes_id != NULL && $cu_js_includes = entity_load_single('cu_js_includes', $cu_js_includes_id)) {
    // Grab existing values to place in form.
    $label = $cu_js_includes->name;
    $type = $cu_js_includes->type;
    $data = unserialize($cu_js_includes->data);
    $id = $cu_js_includes_id;

    // Store embed in form for form submission processing.
    $form_state['cu_js_includes'] = $cu_js_includes;

    // @todo Deal with embed templates entity not loading?
  }
  else {
    // Get type.
    $path_parts = explode('/', current_path());
    $type = array_pop($path_parts);

    // Get type definition.
    $type_definition = cu_js_includes_get_include_type($type);
  }

  $form['include'] = array(
    '#type' => 'fieldset',
    '#title' => t('Include'),
    '#weight' => -10,
  );

  $form['include']['label'] = array(
    '#title' => t('Label'),
    '#description' => t('Administrative label used in overview screen.'),
    '#type' => 'textfield',
    '#default_value' => $label,
    '#required' => TRUE,
    '#size' => $size,
  );

  // Add options for save and cancel.
  $form['actions'] = array(
    '#type' => 'actions',
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Save'),
    ),
  );
  // Add delete button only if editing an embed.
  if (isset($cu_js_includes) && user_access('delete js includes')) {
    $form['actions']['delete'] = array(
      '#type' => 'submit',
      '#submit' => array('cu_js_includes_form_submit'),
      '#value' => t('Delete'),
    );
  }
  $form['actions']['cancel'] = array(
    '#type' => 'submit',
    '#value' => t('Cancel'),
    '#submit' => array('js_include_code_form_cancel'),
    '#limit_validation_errors' => array(),
  );

  // to the user.
  $form['options'] = array(
    '#type' => 'fieldset',
    '#title' => t('Options'),

  );
  // Get the specific parts of the embed form.
  if (!isset($form['confirm'])) {
    call_user_func_array(cu_js_includes_get_form_callback($type), array(
      &$form,
      &$form_state,
      $id,
      $data
    ));
  }

  return $form;
}

/**
 * Submit function for adding or editing an embed.
 *
 * @param array $form
 *   Fully built form shown to user.
 * @param array $form_state
 *   Ste of form with user-entered values.
 *
 * @return mixed
 *   Ends up redirecting user so nothing is really returned.
 */
function cu_js_includes_form_submit(&$form, &$form_state) {

  // If the user has chosen the delete operation, then try to delete embed.
  // Otherwise, go about trying to save embed information.
  if ($form_state['input']['op'] == 'Delete') {
    // If the user hasn't confirmed, they want to delete items, send them to confirm form.
    if (!isset($form_state['storage']['confirm'])) {
      // @todo Don't have recursive $form_state. Probably only store part of the array I need.
      $form_state['storage']['form_state'] = $form_state;
      $form_state['storage']['form'] = $form;
      // This will cause the form to be rebuilt returning to the confirm part of the form.
      $form_state['storage']['confirm'] = TRUE;
      $form_state['rebuild'] = TRUE;
      return $form_state;
    }
    else {
      // Finally delete embed and redirect to the embed codes overview form.
      entity_delete('cu_js_includes', $form_state['cu_js_includes']->id);
      $form_state['redirect'] = 'admin/content/js-includes';
    }
  }
  else {

    // Take type form URL or embed entity.
    if (isset($form_state['cu_js_includes'])) {
      $type = $form_state['cu_js_includes']->type;
      $renderer = $form_state['cu_js_includes']->renderer;
    }
    else {
      $path_parts = explode('/', current_path());
      $type = array_pop($path_parts);
      $renderer = cu_js_includes_get_renderer($type);
    }

    // Build data array for serialization by grabbing form values for embed type.
    $data = array();
    $options = array();

    foreach ($form['options'] as $key => $value) {
      if (strpos($key, '#') === FALSE) {
        $options[] = $key;
      }
    }

    // @todo Deal with possibility of form elements with same keys. Input values are overwritten if they have the same keys.
    foreach ($form_state['values'] as $key => $value) {
      if (in_array($key, $options)) {
        $data[$key] = $value;
      }
    }

    // Need user for embed overview page.
    global $user;

    // If editing an embed, add data to existing embed object.
    // Otherwise, make a new embed entity.
    if (isset($form_state['cu_js_includes']->id)) {
      $cu_js_includes = $form_state['cu_js_includes'];
      $cu_js_includes->name = $form_state['values']['label'];
      $cu_js_includes->uid = $user->uid  ?: 0;
      $cu_js_includes->created = $cu_js_includes->created;
      $cu_js_includes->changed = REQUEST_TIME;
      $cu_js_includes->type = $type;
      $cu_js_includes->renderer = $renderer;
      $cu_js_includes->data = serialize($data);
    }
    else {
      $values = array(
        'name' => $form_state['values']['label'],
        'uid' => $user->uid  ?: 0,
        'created' => REQUEST_TIME,
        'changed' => REQUEST_TIME,
        'type' => $type,
        'renderer' => $renderer,
        'data' => serialize($data),
      );
      $cu_js_includes = entity_create('cu_js_includes', $values);
    }

    // @todo make sure that the type + name is unique and send form error if not. Probably best to do in validation function.
    $success = $cu_js_includes->save();

    // Redirect to overview page if successful.
    // Otherwise, show error to user.
    if ($success) {
      $form_state['redirect'] = 'admin/content/js-includes';
    }
    else {
      drupal_set_message('Include code could not be saved. Please try again.', 'error');
    }
  }
}
