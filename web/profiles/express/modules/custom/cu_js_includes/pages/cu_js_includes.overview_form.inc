<?php

/**
 * @file
 * Form functions for cu_js_includes module.
 */

// Include confirm form file.
module_load_include('inc', 'cu_js_includes', 'pages/cu_js_includes.confirm_form');

/**
 * A listing of embed codes.
 *
 * @param array $form
 *   Empty form to be built.
 * @param array $form_state
 *   Form state that might have embed info for confirmation steps.
 *
 * @return array
 *   The fully built form shown to users.
 */
function cu_js_includes_overview_form($form, &$form_state) {

  // If set to delete embeds, then return confirmation form.
  if (isset($form_state['storage']['confirm'])) {
    // Hacky way to get action link to not display...I hate myself.
    drupal_add_css('ul.action-links {display: none;}', array('type' => 'inline'));
    return cu_js_includes_confirm($form, $form_state);
  }

  // Initialize form array.
  $form = array();

  // Set title since it doesn't stick.
  drupal_set_title('Includes');

  // Add table for listing embed codes.
  // Table alias is "tp".
  $headers = array(
    'name' => array('data' => t('Name'), 'field' => 'tp.name'),
    'type' => array('data' => t('Type'), 'field' => 'tp.type'),
    'author' => array('data' => t('Author'), 'field' => 'tp.uid'),
    'created' => array('data' => t('Created'), 'field' => 'tp.created'),
    'updated' => array('data' => t('Updated'), 'field' => 'tp.changed', 'sort' => 'desc'),
    'edit' => array('data' => t('Edit')),
  );

  // If search has been performed, then return embeds from the search.
  if (isset($form_state['storage']['search_includes'])) {
    $embed_ids = array_map(function ($value) {
      return $value->id;
    }, $form_state['storage']['search_includes']);

    $cu_js_includes = cu_js_includes_get_includes(array('id' => $embed_ids), $headers);
  }
  else {
    // Get existing embed codes with no conditions and a sortable header.
    $cu_js_includes = cu_js_includes_get_includes(array(), $headers);
  }

  // Build table only if embed codes exist.
  if (!empty($cu_js_includes)) {
    // Place embed codes in $form_state for submission processing.
    $form_state['cu_js_includes'] = $cu_js_includes;
    $form_state['table_headers'] = $headers;

    // Add search form.
    $form = cu_js_includes_search_form($form, $form_state);

    // Add table of embeds.
    $form = cu_js_includes_includes_table($form, $form_state);
  }
  else {
    drupal_set_message(t('No includes exist. You can create one by clicking the action link below.'), 'warning');
  }
  return $form;
}

/**
 * Callback to generate search part of embed overview page.
 *
 * @param array $form
 *   Form that contains defaults for embed overview page.
 * @param array $form_state
 *   Form state that might have previous search terms.
 *
 * @return array
 *   Fully built search form for overview page.
 */
function cu_js_includes_search_form($form, $form_state) {
  // Add search fieldset.
  $form['search'] = array(
    '#type' => 'fieldset',
    '#title' => 'Search',
  );

  // Search by embed name.
  $form['search']['name'] = array(
    '#title' => t('Include Name'),
    '#description' => t('Search for include by name.'),
    '#type' => 'textfield',
    '#default_value' => isset($form_state['storage']['search_name']) ? $form_state['storage']['search_name'] : '',
  );

  // Search by type.
  $types_options = array_flip(array_keys(cu_js_includes_get_include_types()));
  // Make values human readable.
  array_walk($types_options, function (&$value, $key) {
    $value = ucwords(str_replace('_', ' ', $key));
  });
  // Add "any" key.
  $types_options = array('any' => '-Any-') + $types_options;

  $form['search']['type'] = array(
    '#title' => t('Include Type'),
    '#description' => t('Search for includes by type.'),
    '#type' => 'select',
    '#options' => $types_options,
    '#default_value' => isset($form_state['storage']['search_type']) ? $form_state['storage']['search_type'] : '',
  );

  $form['search']['search'] = array(
    '#type' => 'submit',
    '#value' => t('Search'),
    '#submit' => array('cu_js_includes_overview_form_submit'),
  );
  $form['search']['reset'] = array(
    '#type' => 'submit',
    '#value' => t('Reset'),
    '#submit' => array('cu_js_includes_form_overview_reset'),
  );

  // Remove operations that user doesn't have permissions to perform.
  $operations = array();
  // Add delete operation if user has permission.
  if (user_access('delete js includes')) {
    $operations = $operations + array('delete' => 'Delete Include Codes');
  }

  // Only add operations fieldset if user has access to perform an operation.
  if (!empty($operations)) {
    // Add container for operations functionality.
    $form['operations'] = array(
      '#type' => 'fieldset',
      '#title' => 'Operations',
    );

    $form['operations']['select'] = array(
      '#type' => 'select',
      '#options' => $operations,
      '#default_value' => current($operations),
    );

    // Add submit button for operations.
    $form['operations']['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Submit'),
    );
  }

  return $form;
}

function cu_js_includes_form_overview_reset($form, &$form_state) {
  $form_state['rebuild'] = FALSE;
}

/**
 * Callback to generate table of embeds.
 *
 * @param array $form
 *   Form that contains defaults for embed overview page.
 * @param array $form_state
 *   Form state that will contain any embeds if they exist.
 *
 * @return array
 *   Fully built table of embeds for overview page.
 */
function cu_js_includes_includes_table($form, $form_state) {

  $rows = array();
  foreach ($form_state['cu_js_includes'] as $result) {
    $edit_link = l(t('Edit'), 'admin/content/js-includes/' . $result->type . '/' . $result->id . '/edit');
    $path_link = $result->path === 'N/A' ? 'N/A' : l(drupal_get_path_alias($result->path), $result->path);
    $author = user_load($result->uid);
    $author_link = isset($author->name) ? "<a title=\"{$author->name}\" href=\"/users/{$author->name}\">{$author->name}</a>" : "N/A";

    $rows[] = array(
      'id' => $result->id,
      'name' => $result->name,
      'type' => $result->type,
      'author' => $author_link,
      'renderer' => $result->renderer,
      'created' => format_date($result->created, 'short'),
      'updated' => format_date($result->changed, 'short'),
      'edit' => $edit_link,
    );
  }

  $form['table'] = array(
    '#type' => 'tableselect',
    '#header' => $form_state['table_headers'],
    '#options' => $rows,
    '#suffix' => empty($rows) ? 'No includes codes have been created.' : '',
    '#weight' => 10,
  );

  $form['pager'] = array(
    '#theme' => 'pager',
    '#weight' => 11,
  );

  return $form;
}

/**
 * Form submission for Embed Code overview form.
 *
 * @param array $form
 *   Form passed into submit function.
 * @param array $form_state
 *   State of form passed in with search and bulk operations.
 *
 * @return mixed
 *   Returns form state for confirmation, returned search results, or NULL for errors.
 */
function cu_js_includes_overview_form_submit(&$form, &$form_state) {
  // Declare default variables. Probably a better way to do this.
  $name = !empty($form_state['values']['name']) ? $form_state['values']['name'] : NULL;
  $type = !empty($form_state['values']['type']) ? $form_state['values']['type'] : NULL;

  // If input for search, then pass to search function.
  if ($form_state['values']['op'] === 'Search') {

    $options = array(
      'name' => $name,
      'type' => $type,
    );

    // Betting on !empty() working for NULL values in array.
    if (!empty($options)) {
      return cu_js_includes_form_search($form_state, $options);
    }
    else {
      drupal_set_message('No search terms entered.', 'error');
      return '';
    }
  }

  // Make sure to make the user confirm they want to proceed with bulk operation.
  if (!isset($form_state['storage']['confirm'])) {
    // @todo Don't put in whole form_state array since it adds recursively.
    $form_state['storage']['form_state'] = $form_state;
    $form_state['storage']['form'] = $form;
    // This will cause the form to be rebuilt returning to the confirm part of the form.
    $form_state['storage']['confirm'] = TRUE;
    $form_state['rebuild'] = TRUE;
    return $form_state;
  }

  // If no embed temlates are present, no need to try and perform any operation.
  if (!isset($form_state['cu_js_includes'])) {
    drupal_set_message('No include templates selected to perform operation on.', 'error');
    return NULL;
  }

  // Perform bulk operation on entities stored in $form_state from confirmation function.
  $operation = $form_state['values']['op'];

  // Check for delete operation first.
  // Didn't want to put this in hook_cu_js_includes_status() since it isn't a status.
  // @todo Refactor this if another operation doesn't fit into the add/edit screen.
  if (lcfirst($operation) == 'delete') {
    // Check for permission.
    if (!user_access('delete js includes')) {
      drupal_set_message('You do not have sufficient permissions to delete these includes.', 'error');
      return NULL;
    }

    foreach ($form_state['cu_js_includes'] as $include) {
      entity_delete('cu_js_includes', $include->id);
    }
    return NULL;
  }

  // Otherwise, set an error message.
  drupal_set_message('Error performing bulk operation. ' . $operation . ' operation not found.', 'error');
  watchdog('cu_js_includes', 'Error performing bulk operation. @op operation not found.', array('@op' => $operation));
  return NULL;
}

/**
 * Callback for searching for embeds from overview page.
 *
 * @param array $form_state
 *   Form state to store search results in.
 * @param array $options
 *   Options containing search terms.
 *
 * @return array
 *   The form state whether any results were found.
 */
function cu_js_includes_form_search(&$form_state, $options = array()) {

  // Setup initial query.
  $query = db_select('cu_js_includes', 'tp')
    ->fields('tp');

  // Need to combine name and path search into one.
  if ($options['name'] != NULL) {
    $or = db_or();
    $or->condition('tp.name', '%' . db_like($options['name']) . '%', 'LIKE');
  }

  // Add search by type.
  if ($options['type'] != NULL && $options['type'] != 'any') {
    $query->condition('tp.type', $options['type'], '=');
  }

  // Only add conditions if the $or object is set.
  if (isset($or)) {
    $query->condition($or);
  }
  $results = $query->execute()->fetchAllAssoc('id');

  // Load embeds to send back to form.
  if (!empty($results)) {
    $cu_js_includes = entity_load('cu_js_includes', array_keys($results));
    $form_state['storage']['search_includes'] = $cu_js_includes;
  }
  else {
    // Set message if there are no results.
    drupal_set_message(t('No results matched your search. All includes are shown.'), 'error');
  }

  $form_state['storage']['search_name'] = $options['name'];
  $form_state['storage']['search_type'] = $options['type'];
  $form_state['rebuild'] = TRUE;
  return $form_state;
}
