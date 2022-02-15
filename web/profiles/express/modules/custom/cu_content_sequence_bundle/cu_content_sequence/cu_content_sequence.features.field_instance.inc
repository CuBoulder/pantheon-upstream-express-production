<?php
/**
 * @file
 * cu_content_sequence.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function cu_content_sequence_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'bean-content_sequence-field_cont_seq_content'.
  $field_instances['bean-content_sequence-field_cont_seq_content'] = array(
    'bundle' => 'content_sequence',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'field_collection',
        'settings' => array(
          'view_mode' => 'full',
        ),
        'type' => 'field_collection_fields',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_content',
    'label' => 'Sequence Content',
    'required' => 0,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'field_collection',
      'settings' => array(),
      'type' => 'field_collection_embed',
      'weight' => 6,
    ),
  );

  // Exported field_instance:
  // 'bean-content_sequence-field_cont_seq_description'.
  $field_instances['bean-content_sequence-field_cont_seq_description'] = array(
    'bundle' => 'content_sequence',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_description',
    'label' => 'Description',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'text',
      'settings' => array(
        'rows' => 5,
      ),
      'type' => 'text_textarea',
      'weight' => 10,
    ),
  );

  // Exported field_instance: 'bean-content_sequence-field_cont_seq_display'.
  $field_instances['bean-content_sequence-field_cont_seq_display'] = array(
    'bundle' => 'content_sequence',
    'default_value' => array(
      0 => array(
        'value' => 'advanced',
      ),
    ),
    'default_value_function' => '',
    'default_value_php' => '',
    'deleted' => 0,
    'description' => '"Advanced" timelines sort the content by the Start Date field, not the order it appears when editing.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'list',
        'settings' => array(),
        'type' => 'list_default',
        'weight' => 2,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_display',
    'label' => 'Display',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 4,
    ),
  );

  // Exported field_instance: 'bean-content_sequence-field_cont_seq_photos'.
  $field_instances['bean-content_sequence-field_cont_seq_photos'] = array(
    'bundle' => 'content_sequence',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cont_seq_photos',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'timeline',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '2000x2000',
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
          'colorbox__large_rectangle_thumbnail' => 0,
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
          'image_large_rectangle_thumbnail' => 0,
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
      'weight' => 11,
    ),
  );

  // Exported field_instance: 'bean-content_sequence-field_cont_seq_scale'.
  $field_instances['bean-content_sequence-field_cont_seq_scale'] = array(
    'bundle' => 'content_sequence',
    'default_value' => array(
      0 => array(
        'value' => 2,
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
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_scale',
    'label' => 'Scale',
    'required' => 1,
    'settings' => array(
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(),
      'type' => 'options_select',
      'weight' => 9,
    ),
  );

  // Exported field_instance: 'bean-content_sequence-field_cont_sequence_title'.
  $field_instances['bean-content_sequence-field_cont_sequence_title'] = array(
    'bundle' => 'content_sequence',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'bean',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_sequence_title',
    'label' => 'Title',
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
      'weight' => 3,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_body'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_body'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 4,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_body',
    'label' => 'Body',
    'required' => 0,
    'settings' => array(
      'linkit' => array(
        'button_text' => 'Search',
        'enable' => 0,
        'profile' => '',
      ),
      'text_processing' => 1,
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

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_date'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_date'] = array(
    'bundle' => 'field_cont_seq_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 3,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_date',
    'label' => 'Start Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 1,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_display_date'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_display_date'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 6,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cont_seq_display_date',
    'label' => 'Display Date',
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
      'weight' => 2,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_display_end_date'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_display_end_date'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 7,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_display_end_date',
    'label' => 'Display End Date',
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
      'weight' => 14,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_end_date'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_end_date'] = array(
    'bundle' => 'field_cont_seq_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'date',
        'settings' => array(
          'format_type' => 'long',
          'fromto' => 'both',
          'multiple_from' => '',
          'multiple_number' => '',
          'multiple_to' => '',
          'show_remaining_days' => FALSE,
        ),
        'type' => 'date_default',
        'weight' => 5,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cont_seq_end_date',
    'label' => 'End Date',
    'required' => 0,
    'settings' => array(
      'default_value' => 'now',
      'default_value2' => 'same',
      'default_value_code' => '',
      'default_value_code2' => '',
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'date',
      'settings' => array(
        'increment' => 15,
        'input_format' => 'm/d/Y - H:i:s',
        'input_format_custom' => '',
        'label_position' => 'above',
        'no_fieldset' => 0,
        'text_parts' => array(),
        'year_range' => '-3:+3',
      ),
      'type' => 'date_popup',
      'weight' => 13,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_group'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_group'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'text',
        'settings' => array(),
        'type' => 'text_default',
        'weight' => 8,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_group',
    'label' => 'Group',
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
      'weight' => 16,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_photos'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_photos'] = array(
    'bundle' => 'field_cont_seq_content',
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'image',
        'settings' => array(
          'image_link' => '',
          'image_style' => '',
        ),
        'type' => 'image',
        'weight' => 1,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cont_seq_photos',
    'label' => 'Image',
    'required' => 0,
    'settings' => array(
      'alt_field' => 1,
      'default_image' => 0,
      'file_directory' => 'timeline',
      'file_extensions' => 'png gif jpg jpeg',
      'max_filesize' => '',
      'max_resolution' => '2000x2000',
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
          'colorbox__large_rectangle_thumbnail' => 0,
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
          'image_large_rectangle_thumbnail' => 0,
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
      'weight' => 7,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_title'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_title'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'link',
        'settings' => array(),
        'type' => 'link_default',
        'weight' => 10,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'no_wrapper',
    'field_name' => 'field_cont_seq_title',
    'label' => 'Title',
    'required' => 1,
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
      'title' => 'required',
      'title_label_use_field_label' => 0,
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 'optional',
      'user_register_form' => FALSE,
      'validate_url' => 0,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'link',
      'settings' => array(),
      'type' => 'link_field',
      'weight' => 15,
    ),
  );

  // Exported field_instance:
  // 'field_collection_item-field_cont_seq_content-field_cont_seq_video'.
  $field_instances['field_collection_item-field_cont_seq_content-field_cont_seq_video'] = array(
    'bundle' => 'field_cont_seq_content',
    'default_value' => NULL,
    'deleted' => 0,
    'description' => 'Enter the url of a Vimeo or YouTube video.',
    'display' => array(
      'default' => array(
        'label' => 'hidden',
        'module' => 'video_embed_field',
        'settings' => array(
          'description' => 1,
          'description_position' => 'bottom',
          'video_style' => 'normal',
        ),
        'type' => 'video_embed_field',
        'weight' => 9,
      ),
    ),
    'entity_type' => 'field_collection_item',
    'fences_wrapper' => 'div_div_div',
    'field_name' => 'field_cont_seq_video',
    'label' => 'Video',
    'required' => 0,
    'settings' => array(
      'allowed_providers' => array(
        'vimeo' => 'vimeo',
        'youtube' => 'youtube',
      ),
      'description_field' => 0,
      'description_length' => 128,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 0,
      'module' => 'video_embed_field',
      'settings' => array(),
      'type' => 'video_embed_field_video',
      'weight' => 8,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('"Advanced" timelines sort the content by the Start Date field, not the order it appears when editing.');
  t('Body');
  t('Description');
  t('Display');
  t('Display Date');
  t('Display End Date');
  t('End Date');
  t('Enter the url of a Vimeo or YouTube video.');
  t('Group');
  t('Image');
  t('Scale');
  t('Sequence Content');
  t('Start Date');
  t('Title');
  t('Video');

  return $field_instances;
}
