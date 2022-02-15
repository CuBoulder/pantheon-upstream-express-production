<?php
/**
 * @file
 * cu_servicenow_feature.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_servicenow_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'node-webform-field_cu_servicenow'.
  $field_instances['node-webform-field_cu_servicenow'] = array(
    'bundle' => 'webform',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
      'teaser' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'node',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cu_servicenow',
    'label' => 'cu_servicenow',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 0,
      ),
      'type' => 'options_onoff',
      'weight' => 5,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('cu_servicenow');

  return $field_instances;
}
