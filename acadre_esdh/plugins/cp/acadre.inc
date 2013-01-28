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
  if (!lock_acquire(__FUNCTION__, 5)) {
    lock_wait(__FUNCTION__);
    return acadre_esdh_cp_handle_request();
  }

  global $HTTP_RAW_POST_DATA;
  $data = $HTTP_RAW_POST_DATA;
  file_unmanaged_save_data($data, 'public://soap/request-' . time(), FILE_EXISTS_REPLACE);

  global $HTTP_RAW_POST_DATA;
  $data = $HTTP_RAW_POST_DATA;
  file_unmanaged_save_data($data,'public://soap/request-'.time(),FILE_EXISTS_REPLACE);


  ini_set("soap.wsdl_cache_enabled", "0");
  $server = new SoapServer(NULL, array(
        'uri' => 'http://tempuri.org/',
      ));
  $server->setClass(TraenPublishingDestinationSystemService);
  $server->handle();
}
