<?php

/**
* Implements hook_drush_cache_clear().
*/
function cu_campus_news_drush_cache_clear(&$types) {
  $types['cu_campus_news'] = '_cu_campus_news_cache_clear';
}

/**
* Utility function that clears all the entries in our cache bin.
*/
function _cu_campus_news_cache_clear() {
  cache_clear_all('*', 'cu_campus_news', true);
}
