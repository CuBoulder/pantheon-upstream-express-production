<?php

/**
 * @file
 * cu_js_includes.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_js_includes_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-js_include-field_js_include'.
  $field_instances['bean-js_include-field_js_include'] = array(
    'bundle' => 'js_include',
    'default_value' => array(
      0 => array(
        'value' => 'none',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_js_include',
    'label' => 'Include',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 2,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Include');

  return $field_instances;
}
