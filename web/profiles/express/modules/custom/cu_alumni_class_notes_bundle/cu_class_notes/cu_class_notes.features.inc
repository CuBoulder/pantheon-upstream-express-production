<?php
/**
 * @file
 * cu_class_notes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cu_class_notes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cu_class_notes_node_info() {
  $items = array(
    'class_note' => array(
      'name' => t('Class Note'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
