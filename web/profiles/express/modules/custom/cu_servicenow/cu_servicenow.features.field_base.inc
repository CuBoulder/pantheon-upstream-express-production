<?php
/**
 * @file
 * cu_servicenow_feature.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cu_servicenow_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_cu_servicenow'.
  $field_bases['field_cu_servicenow'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_cu_servicenow',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Disable ServiceNow integration',
        1 => 'Enable ServiceNow integration',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
