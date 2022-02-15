<?php

/**
 * @file
 * cu_faculty_publications_bundle.drush.inc
 */

/**
 * Implements hook_drush_cache_clear().
 */
function cu_faculty_publications_bundle_drush_cache_clear(&$types) {
  $types['cu_faculty_publications_bundle'] = '_cu_faculty_publications_bundle_cache_clear';
}

/**
 * Utility function that clears all the entries in our cache bin.
 */
function _cu_faculty_publications_bundle_cache_clear() {
  cache_clear_all('*', 'cache_cu_faculty_publications_bundle', TRUE);
}
