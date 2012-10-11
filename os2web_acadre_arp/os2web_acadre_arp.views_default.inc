<?php
/**
 * @file
 * os2web_acadre_arp.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function os2web_acadre_arp_views_default_views() {
  $export = array();

  $view = new view;
  $view->name = 'arp_case_view';
  $view->description = 'Displays a single case ';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Arp Case view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Overskrift';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Indhold: KL Emneord */
  $handler->display->display_options['fields']['field_termref_kle']['id'] = 'field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['table'] = 'field_data_field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['field'] = 'field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_termref_kle']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['field_api_classes'] = 0;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  /* Felt: Indhold: Sagstype */
  $handler->display->display_options['fields']['field_arp_case_type']['id'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['table'] = 'field_data_field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['field'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['field_api_classes'] = 0;
  /* Felt: Indhold: Sag */
  $handler->display->display_options['fields']['field_case']['id'] = 'field_case';
  $handler->display->display_options['fields']['field_case']['table'] = 'field_data_field_case';
  $handler->display->display_options['fields']['field_case']['field'] = 'field_case';
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Kontekstuelt filter: Indhold: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['default_argument_skip_url'] = 0;
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = 1;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'arp_case' => 'arp_case',
  );
  $handler->display->display_options['arguments']['nid']['validate_options']['access'] = '1';
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Overskrift';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Indhold: KL Emneord */
  $handler->display->display_options['fields']['field_termref_kle']['id'] = 'field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['table'] = 'field_data_field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['field'] = 'field_termref_kle';
  $handler->display->display_options['fields']['field_termref_kle']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['group_rows'] = 1;
  $handler->display->display_options['fields']['field_termref_kle']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_termref_kle']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_termref_kle']['field_api_classes'] = 0;
  /* Felt: Indhold: Oprettelsesdato */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'd-m-Y';
  /* Felt: Indhold: Sagstype */
  $handler->display->display_options['fields']['field_arp_case_type']['id'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['table'] = 'field_data_field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['field'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'arp-case/%';

  /* Display: Parties */
  $handler = $view->new_display('attachment', 'Parties', 'attachment_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Parti */
  $handler->display->display_options['fields']['field_arp_party']['id'] = 'field_arp_party';
  $handler->display->display_options['fields']['field_arp_party']['table'] = 'field_data_field_arp_party';
  $handler->display->display_options['fields']['field_arp_party']['field'] = 'field_arp_party';
  $handler->display->display_options['fields']['field_arp_party']['label'] = 'Parter';
  $handler->display->display_options['fields']['field_arp_party']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_party']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_arp_party']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_arp_party']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );
  /* Filterkriterie: Indhold: Parti (field_arp_party) */
  $handler->display->display_options['filters']['field_arp_party_value']['id'] = 'field_arp_party_value';
  $handler->display->display_options['filters']['field_arp_party_value']['table'] = 'field_data_field_arp_party';
  $handler->display->display_options['filters']['field_arp_party_value']['field'] = 'field_arp_party_value';
  $handler->display->display_options['filters']['field_arp_party_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['field_arp_party_value']['value'] = '1';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Description */
  $handler = $view->new_display('attachment', 'Description', 'attachment_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Indhold */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'Beskrivelse';
  $handler->display->display_options['fields']['body']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['body']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['body']['alter']['external'] = 0;
  $handler->display->display_options['fields']['body']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['body']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['body']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['body']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['body']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['body']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['body']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['body']['alter']['html'] = 0;
  $handler->display->display_options['fields']['body']['element_label_colon'] = 0;
  $handler->display->display_options['fields']['body']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['body']['hide_empty'] = 0;
  $handler->display->display_options['fields']['body']['empty_zero'] = 0;
  $handler->display->display_options['fields']['body']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['body']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );
  /* Filterkriterie: Indhold: Indhold (body) */
  $handler->display->display_options['filters']['body_value']['id'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['table'] = 'field_data_body';
  $handler->display->display_options['filters']['body_value']['field'] = 'body_value';
  $handler->display->display_options['filters']['body_value']['operator'] = 'longerthan';
  $handler->display->display_options['filters']['body_value']['value'] = '1';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Memos */
  $handler = $view->new_display('attachment', 'Memos', 'attachment_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Memos */
  $handler->display->display_options['fields']['field_additional_docs']['id'] = 'field_additional_docs';
  $handler->display->display_options['fields']['field_additional_docs']['table'] = 'field_data_field_additional_docs';
  $handler->display->display_options['fields']['field_additional_docs']['field'] = 'field_additional_docs';
  $handler->display->display_options['fields']['field_additional_docs']['label'] = 'Notater';
  $handler->display->display_options['fields']['field_additional_docs']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_additional_docs']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_additional_docs']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_additional_docs']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_additional_docs']['group_rows'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_additional_docs']['delta_reversed'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['delta_first_last'] = 0;
  $handler->display->display_options['fields']['field_additional_docs']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );
  /* Filterkriterie: Indhold: Memos (field_additional_docs:display) */
  $handler->display->display_options['filters']['field_additional_docs_display']['id'] = 'field_additional_docs_display';
  $handler->display->display_options['filters']['field_additional_docs_display']['table'] = 'field_data_field_additional_docs';
  $handler->display->display_options['filters']['field_additional_docs_display']['field'] = 'field_additional_docs_display';
  $handler->display->display_options['filters']['field_additional_docs_display']['operator'] = 'not empty';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Documents */
  $handler = $view->new_display('attachment', 'Documents', 'attachment_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Forbindelse: Indhold: Documents (field_documents) */
  $handler->display->display_options['relationships']['field_documents_nid']['id'] = 'field_documents_nid';
  $handler->display->display_options['relationships']['field_documents_nid']['table'] = 'field_data_field_documents';
  $handler->display->display_options['relationships']['field_documents_nid']['field'] = 'field_documents_nid';
  $handler->display->display_options['relationships']['field_documents_nid']['required'] = 0;
  $handler->display->display_options['relationships']['field_documents_nid']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Main document */
  $handler->display->display_options['fields']['field_main_document']['id'] = 'field_main_document';
  $handler->display->display_options['fields']['field_main_document']['table'] = 'field_data_field_main_document';
  $handler->display->display_options['fields']['field_main_document']['field'] = 'field_main_document';
  $handler->display->display_options['fields']['field_main_document']['relationship'] = 'field_documents_nid';
  $handler->display->display_options['fields']['field_main_document']['label'] = 'Dokumenter';
  $handler->display->display_options['fields']['field_main_document']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_main_document']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_main_document']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_main_document']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_main_document']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_main_document']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_main_document']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_main_document']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_main_document']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_main_document']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_main_document']['field_api_classes'] = 0;
  /* Felt: Indhold: Sag */
  $handler->display->display_options['fields']['field_case']['id'] = 'field_case';
  $handler->display->display_options['fields']['field_case']['table'] = 'field_data_field_case';
  $handler->display->display_options['fields']['field_case']['field'] = 'field_case';
  $handler->display->display_options['fields']['field_case']['label'] = '';
  $handler->display->display_options['fields']['field_case']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_case']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_case']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_case']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_case']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_case']['empty'] = 'Der er ingen dokumenter til denne sag';
  $handler->display->display_options['fields']['field_case']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_case']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_case']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_case']['field_api_classes'] = 0;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';
  $translatables['arp_case_view'] = array(
    t('Master'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Overskrift'),
    t('KL Emneord'),
    t('Oprettelsesdato'),
    t('Sagstype'),
    t('Sag'),
    t('Alle'),
    t('Page'),
    t('Parties'),
    t('Parter'),
    t('Description'),
    t('Beskrivelse'),
    t('Memos'),
    t('Notater'),
    t('Documents'),
    t('field_documents'),
    t('Dokumenter'),
    t('Der er ingen dokumenter til denne sag'),
  );
  $export['arp_case_view'] = $view;

  $view = new view;
  $view->name = 'arp_cases';
  $view->description = 'Displays a list of Cases published from ARP';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'ARP Cases';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Sager med åben indsigt';
  $handler->display->display_options['use_more_text'] = 'mere';
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Gendan';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sortér efter';
  $handler->display->display_options['exposed_form']['options']['sort_asc_label'] = 'Stigende';
  $handler->display->display_options['exposed_form']['options']['sort_desc_label'] = 'Faldende';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Antal elementer';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options_all_label'] = '- Alle -';
  $handler->display->display_options['pager']['options']['expose']['offset_label'] = 'Forskydning';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Indhold: Sagstype */
  $handler->display->display_options['fields']['field_arp_case_type']['id'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['table'] = 'field_data_field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['field'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['field_api_classes'] = 0;
  /* Felt: Indhold: Oprettelses dato */
  $handler->display->display_options['fields']['field_arp_case_created']['id'] = 'field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['table'] = 'field_data_field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['field'] = 'field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['label'] = 'Oprettet d.';
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_arp_case_created']['field_api_classes'] = 0;
  /* Felt: Indhold: Sag */
  $handler->display->display_options['fields']['field_case']['id'] = 'field_case';
  $handler->display->display_options['fields']['field_case']['table'] = 'field_data_field_case';
  $handler->display->display_options['fields']['field_case']['field'] = 'field_case';
  $handler->display->display_options['fields']['field_case']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_case']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_case']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_case']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_case']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_case']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_case']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_case']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_case']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_case']['field_api_classes'] = 0;
  /* Sorteringskriterie: Indhold: Oprettelsesdato */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filterkriterie: Indhold: Udgivet */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filterkriterie: Indhold: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'arp_case' => 'arp_case',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Felt: Indhold: Titel */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['title']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['title']['alter']['external'] = 0;
  $handler->display->display_options['fields']['title']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['title']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = 0;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = 0;
  $handler->display->display_options['fields']['title']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['title']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['title']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['title']['alter']['html'] = 0;
  $handler->display->display_options['fields']['title']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['title']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['title']['hide_empty'] = 0;
  $handler->display->display_options['fields']['title']['empty_zero'] = 0;
  $handler->display->display_options['fields']['title']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['title']['link_to_node'] = 1;
  /* Felt: Indhold: Sagstype */
  $handler->display->display_options['fields']['field_arp_case_type']['id'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['table'] = 'field_data_field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['field'] = 'field_arp_case_type';
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_type']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_type']['field_api_classes'] = 0;
  /* Felt: Indhold: Oprettelses dato */
  $handler->display->display_options['fields']['field_arp_case_created']['id'] = 'field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['table'] = 'field_data_field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['field'] = 'field_arp_case_created';
  $handler->display->display_options['fields']['field_arp_case_created']['label'] = 'Oprettet d.';
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['alter_text'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['make_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['absolute'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['external'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['replace_spaces'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['trim_whitespace'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['nl2br'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['word_boundary'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['ellipsis'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['more_link'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['strip_tags'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['trim'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['alter']['html'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['element_label_colon'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['element_default_classes'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['hide_empty'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['empty_zero'] = 0;
  $handler->display->display_options['fields']['field_arp_case_created']['hide_alter_empty'] = 1;
  $handler->display->display_options['fields']['field_arp_case_created']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  $handler->display->display_options['fields']['field_arp_case_created']['field_api_classes'] = 0;
  $handler->display->display_options['path'] = 'aaben-indsigt';
  $translatables['arp_cases'] = array(
    t('Master'),
    t('Sager med åben indsigt'),
    t('mere'),
    t('Udfør'),
    t('Gendan'),
    t('Sortér efter'),
    t('Stigende'),
    t('Faldende'),
    t('Antal elementer'),
    t('- Alle -'),
    t('Forskydning'),
    t('Titel'),
    t('Sagstype'),
    t('Oprettet d.'),
    t('Sag'),
    t('Page'),
  );
  $export['arp_cases'] = $view;

  return $export;
}
