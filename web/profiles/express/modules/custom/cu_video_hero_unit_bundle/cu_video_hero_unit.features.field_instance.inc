<?php
/**
 * @file
 * cu_video_hero_unit.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_video_hero_unit_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_headline'.
  $field_instances['bean-video_hero_unit-field_hero_unit_headline'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 0,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_headline',
    'label' => 'Headline',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_image'.
  $field_instances['bean-video_hero_unit-field_hero_unit_image'] = array(
    'bundle' => 'video_hero_unit',
    'deleted' => 0,
    'description' => 'This image should be the same aspect ratio as the video files and will be displayed while the video loads and on smaller screens.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image_url_formatter',
        'settings' => array(
          'image_link' => '',
          'image_style' => 'hero',
          'url_type' => 0,
        ),
        'type' => 'image_url',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_image',
    'label' => 'Background Image',
    'required' => 1,
    'settings' => array(
      'alt_field' => 0,
      'default_image' => 0,
      'file_directory' => '',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '',
      'min_resolution' => '',
      'title_field' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'image',
      'settings' => array(
        'insert' => 0,
        'insert_absolute' => FALSE,
        'insert_class' => '',
        'insert_default' => 'auto',
        'insert_styles' => array(
          'auto' => 'auto',
          'colorbox__backstretch' => 0,
          'colorbox__el_hero' => 0,
          'colorbox__email_ad' => 0,
          'colorbox__email_ad_large' => 0,
          'colorbox__email_feature_thumbnail' => 0,
          'colorbox__email_feature_thumbnail_large' => 0,
          'colorbox__email_large' => 0,
          'colorbox__email_medium' => 0,
          'colorbox__email_teaser_thumbnail' => 0,
          'colorbox__flexslider_full' => 0,
          'colorbox__flexslider_thumbnail' => 0,
          'colorbox__focal_point_preview' => 0,
          'colorbox__hero' => 0,
          'colorbox__large' => 0,
          'colorbox__large_square_thumbnail' => 0,
          'colorbox__large_wide_thumbnail' => 0,
          'colorbox__linkit_thumb' => 0,
          'colorbox__medium' => 0,
          'colorbox__preview' => 0,
          'colorbox__slider' => 0,
          'colorbox__slider-large' => 0,
          'colorbox__small' => 0,
          'colorbox__small_square_thumbnail' => 0,
          'colorbox__small_thumbnail' => 0,
          'colorbox__square' => 0,
          'colorbox__square_thumbnail' => 0,
          'colorbox__thumbnail' => 0,
          'icon_link' => 0,
          'image' => 0,
          'image_backstretch' => 0,
          'image_el_hero' => 0,
          'image_email_ad' => 0,
          'image_email_ad_large' => 0,
          'image_email_feature_thumbnail' => 0,
          'image_email_feature_thumbnail_large' => 0,
          'image_email_large' => 0,
          'image_email_medium' => 0,
          'image_email_teaser_thumbnail' => 0,
          'image_flexslider_full' => 0,
          'image_flexslider_thumbnail' => 0,
          'image_focal_point_preview' => 0,
          'image_hero' => 0,
          'image_large' => 0,
          'image_large_square_thumbnail' => 0,
          'image_large_wide_thumbnail' => 0,
          'image_linkit_thumb' => 0,
          'image_medium' => 0,
          'image_preview' => 0,
          'image_slider' => 0,
          'image_slider-large' => 0,
          'image_small' => 0,
          'image_small_square_thumbnail' => 0,
          'image_small_thumbnail' => 0,
          'image_square' => 0,
          'image_square_thumbnail' => 0,
          'image_thumbnail' => 0,
          'link' => 0,
        ),
        'insert_width' => '',
        'preview_image_style' => 'thumbnail',
        'progress_indicator' => 'throbber',
      ),
      'type' => 'image_image',
      'weight' => 19,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_link'.
  $field_instances['bean-video_hero_unit-field_hero_unit_link'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_link',
    'label' => 'Link',
    'required' => 0,
    'settings' => array(
      'absolute_url' => 1,
      'attributes' => array(
        'class' => '',
        'configurable_class' => 0,
        'configurable_title' => 0,
        'rel' => '',
        'target' => 'default',
        'title' => '',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 1,
        'profile' => 'express_linkit_field_profile',
      ),
      'rel_remove' => 'default',
      'title' => 'optional',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
      'user_register_form' => FALSE,
      'validate_url' => 1,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 6,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_link_color'.
  $field_instances['bean-video_hero_unit-field_hero_unit_link_color'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => array(
      0 => array(
        'value' => 'blue',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_link_color',
    'label' => 'Link Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 22,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_text'.
  $field_instances['bean-video_hero_unit-field_hero_unit_text'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_text',
    'label' => 'Text',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 5,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_text_align'.
  $field_instances['bean-video_hero_unit-field_hero_unit_text_align'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => array(
      0 => array(
        'value' => 'left',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => FALSE,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_text_align',
    'label' => 'Text Align',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 23,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_unit_text_color'.
  $field_instances['bean-video_hero_unit-field_hero_unit_text_color'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => array(
      0 => array(
        'value' => 'white',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_unit_text_color',
    'label' => 'Text Color',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 21,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_video_overlay'.
  $field_instances['bean-video_hero_unit-field_hero_video_overlay'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => 'Add a semi-transparent overlay to the video to make the text easier to read.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_video_overlay',
    'label' => 'Video Background Overlay',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 20,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_hero_video_size'.
  $field_instances['bean-video_hero_unit-field_hero_video_size'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => array(
      0 => array(
        'value' => 'medium',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => FALSE,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_key',
        'weight' => 11,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_hero_video_size',
    'label' => 'Size',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 24,
    ),
  );

  // Exported field_instance: 'bean-video_hero_unit-field_video_hero_url'.
  $field_instances['bean-video_hero_unit-field_video_hero_url'] = array(
    'bundle' => 'video_hero_unit',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'ID of a video hosted on Vimeo.com',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_plain',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_video_hero_url',
    'label' => 'Vimeo.com Video ID',
    'required' => 1,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 0,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'size' => 60,
      ),
      'type' => 'text_textfield',
      'weight' => 18,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Add a semi-transparent overlay to the video to make the text easier to read.');
  t('Background Image');
  t('Headline');
  t('ID of a video hosted on Vimeo.com');
  t('Link');
  t('Link Color');
  t('Size');
  t('Text');
  t('Text Align');
  t('Text Color');
  t('This image should be the same aspect ratio as the video files and will be displayed while the video loads and on smaller screens.');
  t('Video Background Overlay');
  t('Vimeo.com Video ID');

  return $field_instances;
}
