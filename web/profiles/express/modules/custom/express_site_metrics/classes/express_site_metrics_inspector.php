<?php

/**
 * @file
 * Class for inspecting Express site metrics.
 */

/**
 * Class for gathering site metrics.
 */
class SiteMetricsInspector {

  /**
   * Build the class.
   */
  public function __construct() {
    // Not much to build here.
  }

  /**
   * Calls all implemented hook_express_site_metrics() functions.
   *
   * @param string $drupalModuleInvokeAll
   *   This is module_invoke_all passed in as a string.
   * @param string $hookNameForInvokeAll
   *   The hook name for module_invoke_all() to call.
   *
   * @return array
   *   Associative array of site metrics data.
   */
  private static function gatherData($drupalModuleInvokeAll, $hookNameForInvokeAll) {
    $dataAfterModuleInvokeAll = $drupalModuleInvokeAll($hookNameForInvokeAll);
    $metricsData = array_merge($dataAfterModuleInvokeAll);
    return $metricsData;
  }

  /**
   * Encodes output from gatherData() as JSON.
   *
   * @param string $drupalModuleInvokeAll
   *   This is module_invoke_all passed in as a string. Called in gatherData().
   * @param string $hookNameForInvokeAll
   *   The hook name for module_invoke_all() to call. Called in gatherData().
   * @param bool $pretty
   *   If true pretty prints JSON output. Defaults to FALSE.
   *
   * @return string
   *   Metrics data encoded as JSON.
   */
  public static function makeReport($drupalModuleInvokeAll, $hookNameForInvokeAll, $pretty = FALSE) {
    $metrics = self::gatherData($drupalModuleInvokeAll, $hookNameForInvokeAll);
    return $pretty ? json_encode(['metrics' => $metrics], JSON_PRETTY_PRINT) : json_encode(['metrics' => $metrics]);
  }

}
