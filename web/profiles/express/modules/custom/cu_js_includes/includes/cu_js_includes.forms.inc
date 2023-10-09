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

/**
 * Form values for mainstay form embed.
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
function cu_js_includes_mainstay_form(&$form, &$form_state, $id = NULL, $data = array()) {
  $form['options']['account_id'] = array(
    '#title' => t('License ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['account_id']) ? $data['account_id'] : '',
    '#required' => TRUE,
    '#size' => 128,
  );
  $form['options']['college_id'] = array(
    '#title' => t('College ID'),
    '#type' => 'textfield',
    '#default_value' => !empty($data['college_id']) ? $data['CuBoulder'] : 'CuBoulder',
    '#required' => TRUE,
    '#size' => 128,
  );
}

/**
 * Form values for servicecloud form embed.
 *
 * The salesforcechat client was renamed to servicecloud. We had to keep the salesforcechat machine name, though.
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
function cu_js_includes_servicecloud_form(&$form, &$form_state, $id = NULL, $data = array()) {

  $form['options']['enable_auto_open'] = array(
    '#title' => t('Enable Auto Open'),
    '#description' => t('Select if you want this chat client to open automatically. Auto open will only work on desktop browsers.'),
    '#type' => 'checkbox',
    '#default_value' => !empty($data['enable_auto_open']) ? $data['enable_auto_open'] : 0
  );
  $form['options']['auto_open_time'] = array(
    '#title' => t('Auto Open Time'),
    '#description' => t("The number of seconds to wait before opening the chat client automatically."),
    '#type' => 'textfield',
    '#attributes' => array('type' => 'number'),
    '#default_value' => !empty($data['auto_open_time']) ? $data['auto_open_time'] : 15,
    '#element_validate' => array('_validate_auto_open_time'),
    '#states' => array(
      'disabled' => array(
        ':input[name="enable_auto_open"]' => array('checked' => FALSE),
      ),
      'enabled' => array(
        ':input[name="enable_auto_open"]' => array('checked', TRUE)
      )
    )
  );
  $form['options']['enable_eye_catcher'] = array(
    '#title' => t('Enable Eye Catcher Image'),
    '#description' => t('Select the checkbox if you want the eye catcher to be displayed.  Eye catcher will only display on desktop browsers.'),
    '#type' => 'checkbox',
    '#default_value' => !empty($data['enable_eye_catcher']) ? $data['enable_eye_catcher'] : 0
  );
}

/**
 * Validates the auto open time can be converted to an number.
 */
function _validate_auto_open_time($element, $form_state) {
  if (!is_numeric($element['#value'])) {
    form_error($element, t('The auto open time should be written as an integer. For example "10".'));
  }
}