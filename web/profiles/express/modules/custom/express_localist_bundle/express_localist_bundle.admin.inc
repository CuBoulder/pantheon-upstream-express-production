<?php

function express_localist_bundle_config_form($form, &$form_state) {
  $form['express_localist_url'] = array(
    '#type' => 'textfield',
    '#title' => 'Localist URL',
    '#description' => 'URL of your Localist Installation.',
    '#default_value' => variable_get('express_localist_url', NULL),
  );

  $options = express_localist_bundle_get_filters();
  $form['express_localist_filters'] = array(
    '#type' => 'checkboxes',
    '#title' => 'Available Filters',
    '#description' => 'Choose which Localist filters are available.',
    '#default_value' => variable_get('express_localist_filters', array()),
    '#options' => $options,
  );
  // Let system_settings_form_submit run first to variable_set vars.
  $form = system_settings_form($form);
  return $form;
}

function express_localist_bundle_get_filters() {
  $options = array();

  $end_point = variable_get('express_localist_url', NULL);
  if (!$end_point) {
    return array();
  }
  else {
    $end_point .= '/api/2/events/filters';
  }

  $response = drupal_http_request($end_point);
  if ($response->code == '200') {
    $options = array();
    $categories = array();
    $filters = drupal_json_decode($response->data, true);

    foreach ($filters as $key => $filter) {
      $options[$key] = ucfirst(substr(str_replace('_', ' ', $key), 6));
    }
  }

  return $options;
}
