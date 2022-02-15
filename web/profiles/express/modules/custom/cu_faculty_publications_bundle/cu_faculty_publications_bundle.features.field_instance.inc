<?php

/**
 * @file
 * cu_faculty_publications_bundle.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_faculty_publications_bundle_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_pub_department'.
  $field_instances['bean-faculty_publications-field_faculty_pub_department'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Type a University of Colorado Boulder department ID or name.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_faculty_pub_department',
    'label' => 'Department',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_pub_results'.
  $field_instances['bean-faculty_publications-field_faculty_pub_results'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => array(
      0 => array(
        'value' => 25,
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
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_faculty_pub_results',
    'label' => 'Number of Results',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 5,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_publication_date'.
  $field_instances['bean-faculty_publications-field_faculty_publication_date'] = array(
    'bundle' => 'faculty_publications',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_faculty_publication_date',
    'label' => 'Publication Date',
    'required' => 0,
    'settings' => array(
      'default_value' => '',
      'default_value2' => '',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 1,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_text',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_publication_email'.
  $field_instances['bean-faculty_publications-field_faculty_publication_email'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_faculty_publication_email',
    'label' => 'Faculty Email Address',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'email',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'email_textfield',
      'weight' => 8,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_publication_name'.
  $field_instances['bean-faculty_publications-field_faculty_publication_name'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => NULL,
    'default_value_function' => '',
    'default_value_php' => FALSE,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_faculty_publication_name',
    'label' => 'Faculty Name',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 10,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_faculty_publications_sort'.
  $field_instances['bean-faculty_publications-field_faculty_publications_sort'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => array(
      0 => array(
        'value' => 'date-desc',
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
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_faculty_publications_sort',
    'label' => 'Sort',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'bean-faculty_publications-field_people_list_person_type'.
  $field_instances['bean-faculty_publications-field_people_list_person_type'] = array(
    'bundle' => 'faculty_publications',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_people_list_person_type',
    'label' => 'Job Type',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 11,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Department');
  t('Faculty Email Address');
  t('Faculty Name');
  t('Job Type');
  t('Number of Results');
  t('Publication Date');
  t('Sort');
  t('Type a University of Colorado Boulder department ID or name.');

  return $field_instances;
}
