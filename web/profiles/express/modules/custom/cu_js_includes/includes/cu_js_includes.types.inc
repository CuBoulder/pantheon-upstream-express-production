<?php

/**
 * @file
 * Implemtations of all cu_js_include types.
 */

/**
 * Implements hook_embed_templates_types().
 *
 *   List of custom embed types.
 */
function cu_js_includes_get_include_types() {
  // Create a few initial embed types.
  $custom_types = array();
  $module_path = drupal_get_path('module', 'cu_js_includes');

  $custom_types['admithub'] = array(
    'label' => 'AdmitHub',
    'form_callback' => 'cu_js_includes_admithub_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/admithub',
  );

  $custom_types['mainstay'] = array(
    'label' => 'Mainstay Chatbot',
    'form_callback' => 'cu_js_includes_mainstay_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/mainstay',
  );

  $custom_types['livechat'] = array(
    'label' => 'LiveChat',
    'form_callback' => 'cu_js_includes_livechat_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/livechat',
  );

  $custom_types['statuspage'] = array(
    'label' => 'StatusPage',
    'form_callback' => 'cu_js_includes_statuspage_form',
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/statuspage',
  );

  $custom_types['slateform'] = array(
    'label' => 'Slate Form',
    'form_callback' => 'cu_js_includes_slateform_form',
    'renderer' => 'block',
    'path' => $module_path,
    'template' => 'templates/slateform',
  );

  // salesforcechat has been renamed service cloud chat client.
  // However we need to keep the machine name as salesforcechat
  // so that previously created includes of that type will continue to work.
  // We have only changed the name in the UI visible to a user and a couple
  // of function names to help make of what code is being included.
  $custom_types['salesforcechat'] = array(
    'label' => 'Service Cloud Chat Client',
    'form_callback' => 'cu_js_includes_servicecloud_form',
    'renderer' => 'page_top_bottom',
    'path' => $module_path,
    'template' => 'templates/servicecloud',
  );

  return $custom_types;
}

/**
 * Implements hook_node_list_groups().
 *
 * Adds grouping/labels for includes since they use the node list function.
 */
function cu_js_includes_express_node_list_groups($bundles) {
  $bundles['includes']['title'] = 'Include Types';
  $bundles['includes']['types'][] = 'Add AdmitHub Include';
  $bundles['includes']['types'][] = 'Add Mainstay Chatbot Include';
  $bundles['includes']['types'][] = 'Add LiveChat Include';
  $bundles['includes']['types'][] = 'Add Slate Form Include';
  $bundles['includes']['types'][] = 'Add StatusPage Include';
  $bundles['includes']['types'][] = 'Add Service Cloud Chat Client Include';
  // $bundles['includes']['types'][] = 'Add Salesforce Chatbot Include';
  return $bundles;
}
