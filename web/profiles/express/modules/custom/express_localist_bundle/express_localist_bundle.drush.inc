<?php

/**
* Implements hook_drush_cache_clear().
*/
function express_localist_bundle_drush_cache_clear(&$types) {
  $types['express_localist_bundle'] = '_express_localist_bundle_cache_clear';
}

/**
* Utility function that clears all the entries in our cache bin.
*/
function _express_localist_bundle_cache_clear() {
  cache_clear_all('*', 'express_localist_bundle', true);
}
