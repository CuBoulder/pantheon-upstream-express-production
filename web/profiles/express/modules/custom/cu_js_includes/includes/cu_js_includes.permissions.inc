<?php

/**
 * Define site permissions in code.
 *
 * Create a secure_permissions_data module directory and place this function
 * in secure_permissions_data.module.
 *
 * @param string $role
 *   The role for which the permissions are being requested.
 *
 * @return array
 *   An array defining all the permissions for the site.
 */
function cu_js_includes_secure_permissions($role) {
  $permissions = array(
    'anonymous user' => array(
      'view js includes',
      'view admithub js includes',
      'view livechat js includes',
      'view statuspage js includes',
      'view slateform js includes',
      'view any js_include bean',
    ),
    'authenticated user' => array(
      'view js includes',
      'view admithub js includes',
      'view livechat js includes',
      'view statuspage js includes',
      'view slateform js includes',
      'view any js_include bean',
    ),
    'developer' => array(
      'administer js includes',
      'administer js includes settings',
      'view js includes',
      'edit js includes',
      'delete js includes',
      'create any js_include bean',
      'delete any js_include bean',
      'edit any js_include bean',
      'view any js_include bean',
    ),
    'administrator' => array(
      'administer js includes',
      'view js includes',
      'edit js includes',
      'delete js includes',
      'create any js_include bean',
      'delete any js_include bean',
      'edit any js_include bean',
      'view any js_include bean',
    ),
    'site_owner' => array(
      'administer js includes',
      'view js includes',
      'edit js includes',
      'delete js includes',
      'create any js_include bean',
      'delete any js_include bean',
      'edit any js_include bean',
      'view any js_include bean',
    ),
    'site_editor' => array(
      'administer js includes',
      'view js includes',
      'edit js includes',
      'delete js includes',
      'create any js_include bean',
      'delete any js_include bean',
      'edit any js_include bean',
      'view any js_include bean',
    ),
  );

  if (isset($permissions[$role])) {
    return $permissions[$role];
  }
}
