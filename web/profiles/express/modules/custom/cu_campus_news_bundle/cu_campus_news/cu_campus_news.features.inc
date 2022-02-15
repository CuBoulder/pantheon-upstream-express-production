<?php
/**
 * @file
 * cu_campus_news.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cu_campus_news_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
}
