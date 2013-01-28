<?php

/**
 * @file
 * This file describes the Content pushing plugin as implemented by Acadre
 */
/**
 * Plugin definition with callbacks
 */
$plugin = array(
  'description' => t('Acadre ESDH Case Pushing backend'),
  'version' => 1,
  'handle_request' => 'acadre_esdh_cp_handle_request',
);

/**
 * This functions handles a request on the webservice API.
 */
function acadre_esdh_cp_handle_request() {
  module_load_include('inc', 'acadre_esdh', 'plugins/cp/ArpService.class');
  if (isset($_GET['wsdl']) || isset($_GET['xsd'])) {
    TraenPublishingDestinationSystemService::getWSDL($_GET['xsd']);
  }
  if (isset($_GET['xsd'])) {
    _acadre_esdh_cp_get_wsdl($_GET['xsd']);
  }
  if (!lock_acquire(__FUNCTION__, 5)) {
    lock_wait(__FUNCTION__);
    return acadre_esdh_cp_handle_request();
  }

  global $HTTP_RAW_POST_DATA;
  $data = $HTTP_RAW_POST_DATA;
  file_unmanaged_save_data($data, 'public://soap/request-' . time(), FILE_EXISTS_REPLACE);

  class TraenPublishingDestinationSystemService {

    public function RecievedEntityLayout($data) {
      error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $data = ' . print_r($data, 1));
    }

    public function RecievedItemPublished($data) {
      error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $data = ' . print_r($data, 1));
    }

    public function RecievedItemUnPublished($data) {
      error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $data = ' . print_r($data, 1));
    }

  }

  global $HTTP_RAW_POST_DATA;
  $data = $HTTP_RAW_POST_DATA;
  file_unmanaged_save_data($data, 'public://soap/request-' . time(), FILE_EXISTS_REPLACE);


  ini_set("soap.wsdl_cache_enabled", "0");
  $server = new SoapServer(NULL, array(
        'uri' => 'http://tempuri.org/',
      ));
  $server->setClass(TraenPublishingDestinationSystemService);
  $server->handle();
}

/**
 * Process case info and generate API arrays.
 *
 * @param array $info
 *   Info block from request.
 */
function _acadre_esdh_cp_process_case($info) {
  $item_id = $info->ItemId;
  $meta = $info->Metadata;
  $node = (object) NULL;
  $node->type = 'arp_case';
  $node->uid = 0;
  $node->status = 1;
  $node->comment = 0;
  $node->promote = 0;
  $node->moderate = 0;
  $node->sticky = 0;
  $node->language = LANGUAGE_NONE;
  $arp_year = $meta->Year % 100;
  node_object_prepare($node);

  $node->title = (string) $meta->Title;
  $node->field_itemid[LANGUAGE_NONE][]['value'] = $item_id;
  $node->body[LANGUAGE_NONE][]['value'] = (string) $meta->CaseContent;
  $node->field_arp_case_type[LANGUAGE_NONE][]['value'] = (string) $meta->CaseType;

  $tid = db_query('SELECT tid FROM  `taxonomy_term_data` WHERE  `name` LIKE  :term', array(
    ':term' => $meta->JournalizingCode[0]->FieldValue . '%',
      ))->fetchField();
  if (is_numeric($tid)) {
    $node->field_termref_kle[LANGUAGE_NONE][]['tid'] = $tid;
  }

  $responsible = $meta->CaseResponsibleUser;
  $node->field_arp_case_handler_ini[LANGUAGE_NONE][]['value'] = $responsible->UserInitials;
  $node->field_arp_casehandler_name[LANGUAGE_NONE][]['value'] = $responsible->UserName;
  $node->field_arp_case_created[LANGUAGE_NONE][]['value'] = strtotime((string) $meta->CreationDate);
  $node->field_arp_case_last_modified[LANGUAGE_NONE][]['value'] = strtotime((string) $meta->CreationDate);
  $node->field_case[LANGUAGE_NONE][]['case_ident'] = $arp_year . '/' . (string) $meta->SequenceNumber;
  $node->field_arp_case_id[LANGUAGE_NONE][]['value'] = $arp_year . '/' . (string) $meta->SequenceNumber;

  node_submit($node);
  node_save($node);
  if (is_numeric($node->nid)) {
    return "Success: Node-id = " . $node->nid;
  }
  else {
    soap_error(3);
  }
}

/**
 * Locates nids with a given ItemId.
 *
 * @param string $item_id
 *   Item ID to locate.
 *
 * @return array
 *   List of nids
 */
function _acadre_esdh_cp_find_item($item_id) {
  $query = new EntityFieldQuery();
  $result = $query
      ->entityCondition('entity_type', 'node')
      ->propertyCondition('type', array('arp_case', 'arp_document'))
      ->propertyCondition('status', 1)
      ->fieldCondition('field_itemid', 'value', $item_id, '=')
      ->execute();
  $nids = array_keys($result['node']);
  return $nids;
}

/**
 * Dumps the wsdl for the serivce.
 */
function _acadre_esdh_cp_get_wsdl($xsd = FALSE) {
  if ($xsd) {
    $xsd = (int) str_replace('xsd', '', $xsd);
    $xsd = $xsd > 0 ? $xsd : '';
    error_log("Var: \$xsd = " . print_r($xsd, 1));
    $filename = 'TraenPublishingDestinationSystemService' . $xsd . '.xsd';
  }
  else {
    $filename = 'TraenPublishingDestinationSystemService.wsdl';
  }
  $filename = drupal_get_path('module', 'acadre_esdh') . '/' . $filename;
  $handle = fopen($filename, 'r');
  $contents = fread($handle, filesize($filename));
  fclose($handle);

  drupal_add_http_header('Connection', 'close', FALSE);
  drupal_add_http_header('Content-Length', drupal_strlen($contents), TRUE);
  drupal_add_http_header('Content-Type', 'text/plain; charset=utf-8', TRUE);
  drupal_add_http_header('Date', date('r'), TRUE);

  $replacements = array(
    '!endpointurl' => 'http' . ($_SERVER['HTTPS'] === 'on' ? 's' : '') . '://' . $_SERVER['SERVER_NAME'] . '/' . request_path(),
  );
  echo format_string($contents, $replacements);
  exit;
}
