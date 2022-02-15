<?php
/**
 * @file
 * cu_class_notes.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function cu_class_notes_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_class_note_class_year'
  $field_bases['field_class_note_class_year'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_class_note_class_year',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(),
      'allowed_values_function' => '_cu_class_notes_class_years',
      'allowed_values_php' => '',
    ),
    'translatable' => 0,
    'type' => 'list_integer',
  );

  return $field_bases;
}
