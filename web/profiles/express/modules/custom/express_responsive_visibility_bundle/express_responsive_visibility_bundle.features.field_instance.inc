<?php
/**
 * @file
 * express_responsive_visibility_bundle.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function express_responsive_visibility_bundle_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance:
  // 'bean-responsive_visibility-field_responsive_vis_block'.
  $field_instances['bean-responsive_visibility-field_responsive_vis_block'] = array(
    'bundle' => 'responsive_visibility',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'entityreference',
        'settings' => array(
          'links' => TRUE,
          'use_content_language' => TRUE,
          'view_mode' => 'default',
        ),
        'type' => 'entityreference_entity_view',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_responsive_vis_block',
    'label' => 'Block',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'entityreference',
      'settings' => array(
        'match_operator' => 'CONTAINS',
        'path' => '',
        'size' => 60,
      ),
      'type' => 'entityreference_autocomplete',
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'bean-responsive_visibility-field_responsive_vis_desktop'.
  $field_instances['bean-responsive_visibility-field_responsive_vis_desktop'] = array(
    'bundle' => 'responsive_visibility',
    'default_value' => array(
      0 => array(
        'value' => 'visible',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => FALSE,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_responsive_vis_desktop',
    'label' => 'Desktop Visibility',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 9,
    ),
  );

  // Exported field_instance:
  // 'bean-responsive_visibility-field_responsive_vis_mobile'.
  $field_instances['bean-responsive_visibility-field_responsive_vis_mobile'] = array(
    'bundle' => 'responsive_visibility',
    'default_value' => array(
      0 => array(
        'value' => 'visible',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => FALSE,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_responsive_vis_mobile',
    'label' => 'Mobile Visibility',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'bean-responsive_visibility-field_responsive_vis_tablet'.
  $field_instances['bean-responsive_visibility-field_responsive_vis_tablet'] = array(
    'bundle' => 'responsive_visibility',
    'default_value' => array(
      0 => array(
        'value' => 'visible',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_responsive_vis_tablet',
    'label' => 'Tablet Visibility',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_buttons',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Block');
  t('Desktop Visibility');
  t('Mobile Visibility');
  t('Tablet Visibility');

  return $field_instances;
}
