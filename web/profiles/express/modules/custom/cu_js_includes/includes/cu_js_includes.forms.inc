<?php

/**
 * Form values for admithub chat widget.
 *
 * @param array $form
 *   Form containing default embed template form options.
 * @param array $form_state
 *   State of the default embed template form.
 * @param int|null $id
 *   ID of the current embed being edited if that embed exists.
 * @param array $data
 *   Data of the current embed if it is being edited.
 */
function cu_js_includes_admithub_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['account_id'] = array(
    '#title' => t('License ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['account_id']) ? $data['account_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}

/**
 * Form values for livechat chat widget.
 *
 * @param array $form
 *   Form containing default embed template form options.
 * @param array $form_state
 *   State of the default embed template form.
 * @param int|null $id
 *   ID of the current embed being edited if that embed exists.
 * @param array $data
 *   Data of the current embed if it is being edited.
 */
function cu_js_includes_livechat_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['account_id'] = array(
    '#title' => t('License ID'),
    '#type' => 'textfield',
    // Added $_GET in the case that a user, who has a LiveChat licence number is being linked here from the admin/settings/livechat/configuration page.
    '#default_value' => !empty($data['account_id']) ? $data['account_id'] : $_GET['LiveChatLicence'],
    '#required' => TRUE,
    '#size' => 128,
  );
}

/**
 * Form values for statuspage.io widget.
 *
 * @param array $form
 *   Form containing default embed template form options.
 * @param array $form_state
 *   State of the default embed template form.
 * @param int|null $id
 *   ID of the current embed being edited if that embed exists.
 * @param array $data
 *   Data of the current embed if it is being edited.
 */
function cu_js_includes_statuspage_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['statuspage_url'] = array(
    '#title' => t('StatusPage.io URL'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['statuspage_url']) ? $data['statuspage_url'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}

/**
 * Form values for slate form embed.
 *
 * @param array $form
 *   Form containing default embed template form options.
 * @param array $form_state
 *   State of the default embed template form.
 * @param int|null $id
 *   ID of the current embed being edited if that embed exists.
 * @param array $data
 *   Data of the current embed if it is being edited.
 */
function cu_js_includes_slateform_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['slate_form_id'] = array(
    '#title' => t('Form ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['slate_form_id']) ? $data['slate_form_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );

  $form['options']['slate_domain'] = array(
    '#title' => t('Slate Domain'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['slate_domain']) ? $data['slate_domain'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
}
