<?php

/**
 * @file
 * cu_section_page_bundle.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cu_section_page_bundle_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function cu_section_page_bundle_node_info() {
  $items = array(
    'section_page' => array(
      'name' => t('Section Page'),
      'base' => 'node_content',
      'description' => t('A page built with Block Sections that can include in-page navigation for each section.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
