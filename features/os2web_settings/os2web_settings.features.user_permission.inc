<?php
/**
 * @file
 * os2web_settings.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function os2web_settings_user_default_permissions() {
  $permissions = array();

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
      2 => 'Kommunikation',
      3 => 'Webmaster',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer media.
  $permissions['administer media'] = array(
    'name' => 'administer media',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: edit media.
  $permissions['edit media'] = array(
    'name' => 'edit media',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
      2 => 'Webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: import media.
  $permissions['import media'] = array(
    'name' => 'import media',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
      2 => 'Kommunikation',
      3 => 'Webmaster',
    ),
    'module' => 'media',
  );

  // Exported permission: view media.
  $permissions['view media'] = array(
    'name' => 'view media',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Editor',
      2 => 'Webmaster',
    ),
    'module' => 'media',
  );

  return $permissions;
}
