<?php
/**
 * @file
 * cu_video_hero_unit.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_video_hero_unit_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_background_video|bean|hero_unit|form';
  $field_group->group_name = 'group_background_video';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'hero_unit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_hero_unit_design';
  $field_group->data = array(
    'label' => 'Background Video',
    'weight' => '45',
    'children' => array(
      0 => 'field_hero_video_mp4',
      1 => 'field_hero_video_overlay',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Background Video',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-background-video field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_background_video|bean|hero_unit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content|bean|video_hero_unit|form';
  $field_group->group_name = 'group_content';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'video_hero_unit';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '2',
    'children' => array(
      0 => 'group_text',
      1 => 'group_video_design',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-content field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_content|bean|video_hero_unit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_text|bean|video_hero_unit|form';
  $field_group->group_name = 'group_text';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'video_hero_unit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Text',
    'weight' => '3',
    'children' => array(
      0 => 'field_hero_unit_headline',
      1 => 'field_hero_unit_link',
      2 => 'field_hero_unit_text',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-text field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_text|bean|video_hero_unit|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_video_design|bean|video_hero_unit|form';
  $field_group->group_name = 'group_video_design';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'video_hero_unit';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_content';
  $field_group->data = array(
    'label' => 'Video/Design',
    'weight' => '7',
    'children' => array(
      0 => 'field_hero_unit_image',
      1 => 'field_hero_unit_link_color',
      2 => 'field_hero_unit_text_align',
      3 => 'field_hero_unit_text_color',
      4 => 'field_hero_video_overlay',
      5 => 'field_video_hero_url',
      6 => 'field_hero_video_size',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-video-design field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_video_design|bean|video_hero_unit|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Background Video');
  t('Content');
  t('Text');
  t('Video/Design');

  return $field_groups;
}
