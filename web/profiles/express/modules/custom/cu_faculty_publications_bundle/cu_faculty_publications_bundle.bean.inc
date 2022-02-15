<?php

/**
 * @file
 * cu_faculty_publications_bundle.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function cu_faculty_publications_bundle_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'faculty_publications';
  $bean_type->label = 'Faculty Publications';
  $bean_type->options = '';
  $bean_type->description = 'Display a list of publications from experts.colorado.edu.';
  $export['faculty_publications'] = $bean_type;

  return $export;
}
