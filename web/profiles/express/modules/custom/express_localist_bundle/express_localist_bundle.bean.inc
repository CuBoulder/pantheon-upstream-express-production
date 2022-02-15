<?php
/**
 * @file
 * express_localist_bundle.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function express_localist_bundle_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'localist_events';
  $bean_type->label = 'Localist Events';
  $bean_type->options = '';
  $bean_type->description = 'Display a feed of events from the campus Localist calendar.';
  $export['localist_events'] = $bean_type;

  return $export;
}
