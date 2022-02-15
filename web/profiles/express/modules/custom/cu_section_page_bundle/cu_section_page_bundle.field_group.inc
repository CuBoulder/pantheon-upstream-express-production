<?php

/**
 * @file
 * cu_section_page_bundle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_section_page_bundle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_page_navigation|node|section_page|form';
  $field_group->group_name = 'group_section_page_navigation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'section_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Settings',
    'weight' => '4',
    'children' => array(
      0 => 'field_section_page_navigation',
      1 => 'field_section_page_size',
      2 => 'field_section_page_hide_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-section-page-navigation field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_section_page_navigation|node|section_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Settings');

  return $field_groups;
}
