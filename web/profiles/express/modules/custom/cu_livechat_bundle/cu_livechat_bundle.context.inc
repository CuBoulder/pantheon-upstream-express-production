<?php

/**
 * Implements hook_context_default_contexts().
 */
function cu_livechat_bundle_context_default_contexts() {
  $export = array();
  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'livechat';
  $context->description = 'Decide which pages LiveChat should appear on.';
  $context->tag = 'LiveChat';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '*' => '*',
        '~admin' => '~admin',
        '~admin/*' => '~admin/*',
        '~/user' => '~/user',
        '~/user/*' => '~/user/*',
        '~node/*/edit' => '~node/*/edit',
        '~block/*/edit' => '~block/*/edit',
        '~taxonomy/term/*/edit' => '~taxonomy/term/*/edit',
        '~node/*/delete' => '~node/*/delete',
        '~block/*/delete' => '~block/*/delete',
        '~taxonomy/term/*/delete' => '~taxonomy/term/*/delete',
        '~node/*/webform*' => '~node/*/webform*',
        '~node/*/webform-results' => '~node/*/webform-results',
        '~media/browser' => '~media/browser',
        '~node/*/blocks' => '~node/*/blocks',
      ),
    ),
  );
  $context->reactions = array(
    'livechat' => array(
      'livechat' => 1,
    ),
  );
  $context->condition_mode = 0;
// Translatables
// Included for use with string extractors like potx.
  t('Decide which pages LiveChat should appear on');
  $export['livechat'] = $context;
  return $export;
}
