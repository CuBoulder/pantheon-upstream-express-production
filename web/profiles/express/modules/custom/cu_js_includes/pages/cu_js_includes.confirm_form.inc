<?php

/**
 * @file
 * Form functions for cu_js_includes module.
 */

/**
 * Callback for canceling addition of embeds.
 *
 * @param array $form
 *   Empty form.
 * @param array $form_state
 *   Used to redirect user if they cancel confirmation.
 */
function js_include_code_form_cancel($form, &$form_state) {
  $form_state['redirect'] = 'admin/content/js-includes';
}

/**
 * Form callback for confirming operations performed on embed entities.
 *
 * @param array $form
 *   Embed form prior to confirmation step.
 * @param array $form_state
 *   Form state to check for embeds being deleted or updated.
 *
 * @return array|mixed|null
 *   The confirm form with names of embeds being operated on.
 */
function cu_js_includes_confirm(&$form, &$form_state) {
  // Initialize default variables.
  $path = 'admin/content/js-includes';
  $form = array();

  // The operation key differs depending on whether coming from edit or overview form.
  $op = isset($form_state['input']['select']) ? $form_state['input']['select'] : $form_state['input']['op'];

  // Make sure there are embed codes to operation on.
  if (isset($form_state['cu_js_includes'])) {
    // If only one embed code...
    if (isset($form_state['cu_js_includes']->name)) {
      $include_names = array($form_state['cu_js_includes']->name);
    }
    else {
      // For multiple pixels, we need to match array key positions with embed IDs.
      $table_options = $form_state['storage']['form']['table']['#options'];
      $selected_options = $form_state['storage']['form_state']['input']['table'];

      // Loop through selected rows and add pixel name.
      $include_names = array();
      foreach ($selected_options as $key => $option) {
        if ($option != NULL) {
          $include_names[] = $table_options[$key]['name'];
        }
        else {
          // Replace embeds in form_state array with selected embed codes.
          unset($form_state['cu_js_includes'][$table_options[$key]['id']]);
        }
      }
    }

    // Build confirm form that is sent back to user.
    $list = theme_item_list(array(
      'items' => $include_names,
      'title' => NULL,
      'type' => 'ul',
      'attributes' => array(),
    ));

    

    // Check for deletion operation.
    if (lcfirst($op) == 'delete') {
      $operation_label = 'Delete';
    }

    return confirm_form(
      $form,
      t('Do you really want to !op the following includes?', array('!op' => $operation_label)),
      $path,
      $list,
      $operation_label,
      'Cancel'
    );
  }

  // Account for the case where somehow no embed entities made it to the confirm function.
  return drupal_set_message(t('No includes selected for operations. Please take appropriate action from the !link.', array('!link' => l(t('Includes overview page'), $path))), 'error');
}
