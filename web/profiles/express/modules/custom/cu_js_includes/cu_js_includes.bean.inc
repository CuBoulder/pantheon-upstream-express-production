<?php

/**
 * @file
 * cu_js_includes.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function cu_js_includes_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'js_include';
  $bean_type->label = 'JS Include';
  $bean_type->options = '';
  $bean_type->description = 'Block for placing javascript includes in webpage regions';
  $export['js_include'] = $bean_type;

  return $export;
}
