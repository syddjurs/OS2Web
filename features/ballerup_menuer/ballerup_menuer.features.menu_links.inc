<?php
/**
 * @file
 * ballerup_menuer.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function ballerup_menuer_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:http://su.dk/Sider/default.aspx
  $menu_links['main-menu:http://su.dk/Sider/default.aspx'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://su.dk/Sider/default.aspx',
    'router_path' => '',
    'link_title' => 'Min SU',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '8',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:http://tastselv.skat.dk/
  $menu_links['main-menu:http://tastselv.skat.dk/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://tastselv.skat.dk/',
    'router_path' => '',
    'link_title' => 'TastSelv Skat',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '7',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:http://www.borger.dk
  $menu_links['main-menu:http://www.borger.dk'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.borger.dk',
    'router_path' => '',
    'link_title' => 'Borger.dk',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '3',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:http://www.survey-xact.dk/LinkCollector?key=S1WES4U1151K
  $menu_links['main-menu:http://www.survey-xact.dk/LinkCollector?key=S1WES4U1151K'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'http://www.survey-xact.dk/LinkCollector?key=S1WES4U1151K',
    'router_path' => '',
    'link_title' => 'Hvad synes du?',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '9',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:https://minside.borger.dk/
  $menu_links['main-menu:https://minside.borger.dk/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://minside.borger.dk/',
    'router_path' => '',
    'link_title' => 'Min side',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '4',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:https://minside.borger.dk/post
  $menu_links['main-menu:https://minside.borger.dk/post'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://minside.borger.dk/post',
    'router_path' => '',
    'link_title' => 'Digital post',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '5',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:https://www.nemid.nu/
  $menu_links['main-menu:https://www.nemid.nu/'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'https://www.nemid.nu/',
    'router_path' => '',
    'link_title' => 'Bestil NemID',
    'options' => array(
      'attributes' => array(
        'target' => '_blank',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '6',
    'parent_path' => 'taxonomy/term/223',
  );
  // Exported menu link: main-menu:taxonomy/term/195
  $menu_links['main-menu:taxonomy/term/195'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/195',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'English',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/208
  $menu_links['main-menu:taxonomy/term/208'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/208',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Politik og planer',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '1',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/223
  $menu_links['main-menu:taxonomy/term/223'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/223',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Selvbetjening',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '2',
    'parent_path' => 'taxonomy/term/50',
  );
  // Exported menu link: main-menu:taxonomy/term/228
  $menu_links['main-menu:taxonomy/term/228'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/228',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Forside',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:taxonomy/term/50
  $menu_links['main-menu:taxonomy/term/50'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/50',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Borger',
    'options' => array(
      'attributes' => array(
        'rel' => 'nofollow',
        'class' => array(
          0 => 'l1',
          1 => 'borger',
          2 => 'green',
        ),
      ),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '1',
  );
  // Exported menu link: main-menu:taxonomy/term/52
  $menu_links['main-menu:taxonomy/term/52'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/52',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Om kommunen',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
    'parent_path' => 'taxonomy/term/208',
  );
  // Exported menu link: main-menu:taxonomy/term/56
  $menu_links['main-menu:taxonomy/term/56'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/56',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'Borgerservice',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '1',
    'parent_path' => 'taxonomy/term/50',
  );
  // Exported menu link: main-menu:taxonomy/term/60
  $menu_links['main-menu:taxonomy/term/60'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'taxonomy/term/60',
    'router_path' => 'taxonomy/term/%',
    'link_title' => 'By, Bolig & Trafik',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '3',
    'parent_path' => 'taxonomy/term/50',
  );
  // Exported menu link: menu-header:<front>
  $menu_links['menu-header:<front>'] = array(
    'menu_name' => 'menu-header',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'A - a',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '1',
    'has_children' => '1',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-header:http://gis.ballerup.dk/webgis/
  $menu_links['menu-header:http://gis.ballerup.dk/webgis/'] = array(
    'menu_name' => 'menu-header',
    'link_path' => 'http://gis.ballerup.dk/webgis/',
    'router_path' => '',
    'link_title' => 'Balkort',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
    'parent_path' => '<front>',
  );
  // Exported menu link: menu-header:nyheder
  $menu_links['menu-header:nyheder'] = array(
    'menu_name' => 'menu-header',
    'link_path' => 'nyheder',
    'router_path' => 'nyheder',
    'link_title' => 'Nyheder',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-header:taxonomy/term/198
  $menu_links['menu-header:taxonomy/term/198'] = array(
    'menu_name' => 'menu-header',
    'link_path' => 'taxonomy/term/198',
    'router_path' => 'taxonomy/term/%',
    'link_title' => ' Job hos os',
    'options' => array(
      'attributes' => array(),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t(' Job hos os');
  t('A - a');
  t('Balkort');
  t('Bestil NemID');
  t('Borger');
  t('Borger.dk');
  t('Borgerservice');
  t('By, Bolig & Trafik');
  t('Digital post');
  t('English');
  t('Forside');
  t('Hvad synes du?');
  t('Min SU');
  t('Min side');
  t('Nyheder');
  t('Om kommunen');
  t('Politik og planer');
  t('Selvbetjening');
  t('TastSelv Skat');


  return $menu_links;
}
