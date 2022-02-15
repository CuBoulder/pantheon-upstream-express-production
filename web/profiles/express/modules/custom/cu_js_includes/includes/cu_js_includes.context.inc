<?php
/**
 * @file
 * Context plugin file to provide changing the active theme as a context
 * reaction.
 */

/**
 * Expose themes as context reactions.
 */
class context_reaction_js_include extends context_reaction {

  /**
   * Grab the available themes and provide them as a reaction for context.
   *
   * @param $context
   *   The context as passed from context module.
   *
   * @return array
   *   The FAPI array as read by context module.
   */
  function options_form($context) {

    $settings = $this->fetch_from_context($context);
    // Enabled Include Types
    $enabled_includes = variable_get('cu_js_includes_enabled', array());
    // Types of filters that use this context reaction.
    $types = array(
      'admithub',
      'livechat',
    );
    // Types of filters that use this reaction that are also enabled.
    $filter = array_intersect($enabled_includes, $types);
    // Get includes that use this context that are also enabled.
    if (!empty($filter)) {
      $includes = cu_js_includes_get_includes_by_type($filter);
    }
    $options = array();
    foreach ($includes as $key => $include) {
      $options[$key] = $include->name;
    }
    $form = array(
      '#tree' => TRUE,
      '#title' => t('Include JS'),
      'js_include' => array(
        '#title' => t('Include Javascript'),
        '#description' => t('Choose one of the available javascript Includes.'),
        '#type' => 'select',
        '#default_value' => isset($settings['js_include']) ? $settings['js_include'] : '',
        '#options' => $options,
      ),
    );
    return $form;
  }

  /**
   * Return the active theme based on the context
   *
   * @return string | null
   *   String of the theme name, or NULL if not to be altered.
   */
  function execute() {
    $js_include = NULL;
    foreach ($this->get_contexts() as $context) {
      if (isset($context->reactions['js_include'])) {
        $js_include = $context->reactions['js_include'];
      }
    }
    return $js_include;
  }

}
