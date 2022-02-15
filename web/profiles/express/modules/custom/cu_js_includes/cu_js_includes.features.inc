<?php

/**
 * @file
 * cu_js_includes.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function cu_js_includes_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "bean_admin_ui" && $api == "bean") {
    return array("version" => "5");
  }
  if ($module == 'context' && $api == 'plugins') {
    return array('version' => 3);
  }
}
