<?php
/**
 * @file
 * cu_video_hero_unit.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cu_video_hero_unit_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_hero_video_overlay'.
  $field_bases['field_hero_video_overlay'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hero_video_overlay',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 'Hide',
        1 => 'Show',
      ),
      'allowed_values_function' => '',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_hero_video_size'.
  $field_bases['field_hero_video_size'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_hero_video_size',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'small' => 'Small',
        'medium' => 'Medium',
        'large' => 'Large',
      ),
      'allowed_values_function' => 'cu_video_hero_unit_size_options',
      'allowed_values_php' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_video_hero_url'.
  $field_bases['field_video_hero_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_video_hero_url',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  return $field_bases;
}
