<?php
/**
 * @file
 * cu_content_sequence.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_content_sequence_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_advanced|bean|content_sequence|form';
  $field_group->group_name = 'group_advanced';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'content_sequence';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Advanced Settings',
    'weight' => '5',
    'children' => array(
      0 => 'field_cont_seq_description',
      1 => 'field_cont_seq_scale',
      2 => 'field_cont_seq_photos',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Advanced Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-advanced field-group-fieldset',
        'description' => 'These fields only apply to advanced timelines.',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_advanced|bean|content_sequence|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cont_seq_body|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_cont_seq_body';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_content';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '11',
    'children' => array(
      0 => 'field_cont_seq_photos',
      1 => 'field_cont_seq_body',
      2 => 'field_cont_seq_video',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cont-seq-body field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cont_seq_body|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cont_seq_content|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_cont_seq_content';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timeline Content',
    'weight' => '0',
    'children' => array(
      0 => 'group_cont_seq_title',
      1 => 'group_cont_seq_date',
      2 => 'group_cont_seq_body',
      3 => 'group_cont_seq_image',
      4 => 'group_group',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-cont-seq-content field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_cont_seq_content|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cont_seq_date|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_cont_seq_date';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_content';
  $field_group->data = array(
    'label' => 'Date',
    'weight' => '12',
    'children' => array(
      0 => 'group_start_date',
      1 => 'group_end_date',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cont-seq-date field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cont_seq_date|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cont_seq_image|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_cont_seq_image';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_content';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '13',
    'children' => array(),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cont-seq-image field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cont_seq_image|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_cont_seq_title|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_cont_seq_title';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_content';
  $field_group->data = array(
    'label' => 'Title',
    'weight' => '10',
    'children' => array(
      0 => 'field_cont_seq_title',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-cont-seq-title field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_cont_seq_title|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_end_date|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_end_date';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_date';
  $field_group->data = array(
    'label' => 'End Date',
    'weight' => '11',
    'children' => array(
      0 => 'field_cont_seq_end_date',
      1 => 'field_cont_seq_display_end_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'End Date',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-end-date field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_end_date|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_group|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_group';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_content';
  $field_group->data = array(
    'label' => 'Group',
    'weight' => '14',
    'children' => array(
      0 => 'field_cont_seq_group',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-group field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_group|field_collection_item|field_cont_seq_content|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_start_date|field_collection_item|field_cont_seq_content|form';
  $field_group->group_name = 'group_start_date';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_cont_seq_content';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_cont_seq_date';
  $field_group->data = array(
    'label' => 'Start Date',
    'weight' => '10',
    'children' => array(
      0 => 'field_cont_seq_date',
      1 => 'field_cont_seq_display_date',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-start-date field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_start_date|field_collection_item|field_cont_seq_content|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Advanced Settings');
  t('Content');
  t('Date');
  t('End Date');
  t('Group');
  t('Image');
  t('Start Date');
  t('Timeline Content');
  t('Title');

  return $field_groups;
}
