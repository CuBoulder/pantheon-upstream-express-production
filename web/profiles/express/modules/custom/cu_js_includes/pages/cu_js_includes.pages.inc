<?php

/**
 * @file
 * Page callbacks for adding, editing, deleting, and revisions management for content.
 */

/**
 * Provides a listing of all embed types you can add.
 *
 * @return string
 *   Markup for list of embed types.
 */
function cu_js_includes_add_page() {
  $item = menu_get_item();
  $content = system_admin_menu_block($item);
  $output = theme('node_add_list', array('content' => $content));

  // Need to check and see if output is empty so we can change the help message sent to the user.
  if (is_string($output) && strpos($output, 'You have not created any content types yet') != FALSE) {
    $output = '<p>' . t('No JavaScript includes have been created.') . '</p>';
  }

  return $output;
}

/**
 * Configuration form for enabling/disabling includes by type.
 */
function cu_js_includes_settings_form($form, &$form_state) {
  $form = array();
  // Get all embed types.
  $include_types = cu_js_includes_get_include_types();

  $options = array();
  foreach ($include_types as $key => $value) {
    $options[$key] = $value['label'];
  }
  $form['cu_js_includes_enabled'] = array(
    '#title' => 'Enable JS Include Types',
    '#type' => 'checkboxes',
    '#options' => $options,
    '#default_value' => variable_get('cu_js_includes_enabled', array()),
  );
  $form['#submit'][] = 'cu_js_includes_settings_form_submit';
  $form['save'] = array(
    '#type' => 'submit',
    '#value' => 'Save Configuration',
  );
  return $form;
}

/**
 * Submit function for enable/disable form.
 * Sets variable of types, rebuilds menu because of add/edit paths.
 */
function cu_js_includes_settings_form_submit($form, &$form_state) {
  variable_set('cu_js_includes_enabled', $form_state['values']['cu_js_includes_enabled']);
  menu_rebuild();
  drupal_set_message('Javascript Include settings have been saved.', 'status');
}
