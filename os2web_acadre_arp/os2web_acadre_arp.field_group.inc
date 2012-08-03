<?php
/**
 * @file
 * os2web_acadre_arp.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function os2web_acadre_arp_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_arp_files|node|arp_case|default';
  $field_group->group_name = 'group_arp_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'arp_case';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Filer',
    'weight' => '2',
    'children' => array(
      0 => 'field_additional_docs',
      1 => 'field_documents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_arp_files|node|arp_case|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_arp_files|node|arp_case|form';
  $field_group->group_name = 'group_arp_files';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'arp_case';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Filer',
    'weight' => '1',
    'children' => array(
      0 => 'field_additional_docs',
      1 => 'field_documents',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_arp_files|node|arp_case|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_arp_meta|node|arp_case|default';
  $field_group->group_name = 'group_arp_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'arp_case';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_termref_kle',
      1 => 'field_arp_case_type',
      2 => 'body',
      3 => 'field_arp_case_created',
      4 => 'field_arp_case_last_modified',
      5 => 'field_arp_case_id',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
      ),
    ),
  );
  $export['group_arp_meta|node|arp_case|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_arp_meta|node|arp_case|form';
  $field_group->group_name = 'group_arp_meta';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'arp_case';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Meta',
    'weight' => '0',
    'children' => array(
      0 => 'field_termref_kle',
      1 => 'field_arp_case_type',
      2 => 'body',
      3 => 'field_arp_case_created',
      4 => 'field_arp_case_last_modified',
      5 => 'field_arp_case_id',
      6 => 'title',
      7 => 'field_arp_party',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_arp_meta|node|arp_case|form'] = $field_group;

  return $export;
}
