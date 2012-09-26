<?php
/**
 * @file
 * os2web_menuer_og_blokke.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function os2web_menuer_og_blokke_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-indholdsmenu
  $menus['menu-indholdsmenu'] = array(
    'menu_name' => 'menu-indholdsmenu',
    'title' => 'Indholdsmenu',
    'description' => '',
  );
  // Exported menu: menu-overordnet-sitemenu
  $menus['menu-overordnet-sitemenu'] = array(
    'menu_name' => 'menu-overordnet-sitemenu',
    'title' => 'Overordnet sitemenu',
    'description' => '',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Indholdsmenu');
  t('Overordnet sitemenu');


  return $menus;
}
