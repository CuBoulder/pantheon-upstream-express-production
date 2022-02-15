<?php
/**
 * @file
 * express_responsive_visibility_bundle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function express_responsive_visibility_bundle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_responsive_vis_settings|bean|responsive_visibility|form';
  $field_group->group_name = 'group_responsive_vis_settings';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'responsive_visibility';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Visibility Settings',
    'weight' => '3',
    'children' => array(
      0 => 'field_responsive_vis_mobile',
      1 => 'field_responsive_vis_tablet',
      2 => 'field_responsive_vis_desktop',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-responsive-vis-settings field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_responsive_vis_settings|bean|responsive_visibility|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Visibility Settings');

  return $field_groups;
}
