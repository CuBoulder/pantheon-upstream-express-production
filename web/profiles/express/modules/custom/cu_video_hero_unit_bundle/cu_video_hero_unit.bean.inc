<?php
/**
 * @file
 * cu_video_hero_unit.bean.inc
 */

/**
 * Implements hook_bean_admin_ui_types().
 */
function cu_video_hero_unit_bean_admin_ui_types() {
  $export = array();

  $bean_type = new stdClass();
  $bean_type->disabled = FALSE; /* Edit this to true to make a default bean_type disabled initially */
  $bean_type->api_version = 5;
  $bean_type->name = 'video_hero_unit';
  $bean_type->label = 'Video Hero Unit';
  $bean_type->options = '';
  $bean_type->description = 'A hero unit with a video background.';
  $export['video_hero_unit'] = $bean_type;

  return $export;
}
