<?php

/**
 * @file
 * cu_js_includes.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cu_js_includes_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_js_include'.
  $field_bases['field_js_include'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_js_include',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => 'cu_js_includes_block_options',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  return $field_bases;
}
