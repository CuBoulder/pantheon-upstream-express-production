<?php

/**
 * @file
 * cu_faculty_publications_bundle.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function cu_faculty_publications_bundle_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fp_filters|bean|faculty_publications|form';
  $field_group->group_name = 'group_fp_filters';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fp_group';
  $field_group->data = array(
    'label' => 'Filters',
    'weight' => '3',
    'children' => array(
      0 => 'field_faculty_pub_department',
      1 => 'field_faculty_publication_date',
      2 => 'field_faculty_publication_email',
      3 => 'group_fp_website_people',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fp-filters field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_fp_filters|bean|faculty_publications|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fp_group|bean|faculty_publications|form';
  $field_group->group_name = 'group_fp_group';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faculty Publications',
    'weight' => '2',
    'children' => array(
      0 => 'group_fp_filters',
      1 => 'group_fp_results',
    ),
    'format_type' => 'htabs',
    'format_settings' => array(
      'formatter' => '',
      'instance_settings' => array(
        'classes' => 'group-fp-group field-group-htabs',
        'id' => '',
      ),
    ),
  );
  $field_groups['group_fp_group|bean|faculty_publications|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fp_results|bean|faculty_publications|form';
  $field_group->group_name = 'group_fp_results';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fp_group';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '4',
    'children' => array(
      0 => 'field_faculty_pub_results',
      1 => 'field_faculty_publications_sort',
    ),
    'format_type' => 'htab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-fp-results field-group-htab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_fp_results|bean|faculty_publications|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_fp_website_people|bean|faculty_publications|form';
  $field_group->group_name = 'group_fp_website_people';
  $field_group->entity_type = 'bean';
  $field_group->bundle = 'faculty_publications';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_fp_filters';
  $field_group->data = array(
    'label' => 'Website People',
    'weight' => '9',
    'children' => array(
      0 => 'field_faculty_publication_name',
      1 => 'field_people_list_person_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Website People',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-fp-website-people field-group-fieldset',
        'description' => 'Use these fields to pull faculty publication data for people in your Web Express site.',
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_fp_website_people|bean|faculty_publications|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Faculty Publications');
  t('Filters');
  t('Results');
  t('Website People');

  return $field_groups;
}
