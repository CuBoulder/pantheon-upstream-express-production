<?php
/**
 * @file
 * express_localist_bundle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function express_localist_bundle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_category|bean|localist_events|form';
  $field_group->group_name = 'group_localist_category';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Category',
    'weight' => '9',
    'children' => array(
      0 => 'field_localist_category',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Category',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-category field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_category|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_config|bean|localist_events|form';
  $field_group->group_name = 'group_localist_config';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Configuration',
    'weight' => '2',
    'children' => array(
      0 => 'group_localist_display',
      1 => 'group_localist_filters',
      2 => 'group_localist_options',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-localist-config field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_localist_config|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_display|bean|localist_events|form';
  $field_group->group_name = 'group_localist_display';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_config';
  $field_group->data = array(
    'label' => 'Display',
    'weight' => '9',
    'children' => array(
      0 => 'field_localist_widget_type',
      1 => 'field_localist_style',
      2 => 'field_localist_hide_descriptions',
      3 => 'field_localist_truncate_desc',
      4 => 'field_localist_render_html',
      5 => 'field_localist_hide_images',
      6 => 'field_localist_hide_times',
      7 => 'field_localist_new_window',
      8 => 'field_localist_minical_layout',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Display',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_localist_display|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_excluded|bean|localist_events|form';
  $field_group->group_name = 'group_localist_excluded';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Excluded Content',
    'weight' => '50',
    'children' => array(
      0 => 'field_localist_hide_past_events',
      1 => 'field_localist_filters_excluded',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Excluded Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-excluded field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_excluded|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_filter_options|bean|localist_events|form';
  $field_group->group_name = 'group_localist_filter_options';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Filtering Options',
    'weight' => '0',
    'children' => array(
      0 => 'field_localist_show_featured',
      1 => 'field_localist_show_sponsored',
      2 => 'field_localist_content_match',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-localist-filter-options field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_localist_filter_options|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_filters|bean|localist_events|form';
  $field_group->group_name = 'group_localist_filters';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_config';
  $field_group->data = array(
    'label' => 'Filters',
    'weight' => '8',
    'children' => array(
      0 => 'field_localist_filters',
      1 => 'group_localist_excluded',
      2 => 'group_localist_places',
      3 => 'group_localist_tags',
      4 => 'group_localist_filter_options',
      5 => 'group_localist_group',
      6 => 'group_localist_department',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'label' => 'Filters',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Return events with any of these filter values.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_localist_filters|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_group_exclude|bean|localist_events|form';
  $field_group->group_name = 'group_localist_group_exclude';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_excluded';
  $field_group->data = array(
    'label' => 'Exclude by Group',
    'weight' => '59',
    'children' => array(
      0 => 'field_localist_groups_excluded',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Exclude by Group',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-group-exclude field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_group_exclude|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_group|bean|localist_events|form';
  $field_group->group_name = 'group_localist_group';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Filter by Group',
    'weight' => '43',
    'children' => array(
      0 => 'field_localist_groups',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Filter by Group',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-group field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_group|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_options|bean|localist_events|form';
  $field_group->group_name = 'group_localist_options';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_config';
  $field_group->data = array(
    'label' => 'Options',
    'weight' => '7',
    'children' => array(
      0 => 'field_localist_results',
      1 => 'field_localist_days_ahead',
      2 => 'field_localist_start_date',
      3 => 'field_localist_skip_recurring',
      4 => 'field_localist_all_instances',
      5 => 'field_localist_link',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-localist-options field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_localist_options|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_places|bean|localist_events|form';
  $field_group->group_name = 'group_localist_places';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Filter by Place',
    'weight' => '47',
    'children' => array(
      0 => 'field_localist_places',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Filter by Place',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-places field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_places|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_tags|bean|localist_events|form';
  $field_group->group_name = 'group_localist_tags';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Filter by Keywords and Tags',
    'weight' => '48',
    'children' => array(
      0 => 'field_localist_tags',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Filter by Keywords and Tags',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-tags field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_tags|bean|localist_events|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_localist_type|bean|localist_events|form';
  $field_group->group_name = 'group_localist_type';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'localist_events';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_localist_filters';
  $field_group->data = array(
    'label' => 'Type',
    'weight' => '13',
    'children' => array(
      0 => 'field_localist_event_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Type',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-localist-type field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_localist_type|bean|localist_events|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Category');
  t('Configuration');
  t('Display');
  t('Exclude by Group');
  t('Excluded Content');
  t('Filter by Group');
  t('Filter by Keywords and Tags');
  t('Filter by Place');
  t('Filtering Options');
  t('Filters');
  t('Options');
  t('Type');

  return $field_groups;
}
