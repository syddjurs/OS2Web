<?php

/**
 * @file
 *   The Class which implements the ARP service.
 *
 * @author Jesper Mathiassen <jm@bellcom.dk>
 * @copyright Bellcom Open Source aps.
 */

/**
 * Class that holds the service.
 */
class TraenPublishingDestinationSystemService {

  /**
   * Dumps the wsdl for the serivce.
   */
  public static function getWSDL($xsd = FALSE) {
    if ($xsd) {
      $xsd = str_replace('0', '', str_replace('xsd', '', $xsd));
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService' . check_plain($xsd) . '.xsd';
    }
    else {
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService.wsdl';
    }
    $filename = drupal_get_path('module', 'acadre_esdh') . '/' . $filename;
    $handle = fopen($filename, 'r');
    $contents = fread($handle, filesize($filename));
    fclose($handle);

    drupal_add_http_header('Connection', 'close', FALSE);
    drupal_add_http_header('Content-Length', drupal_strlen($contents), TRUE);
    drupal_add_http_header('Content-Type', 'text/plain; charset=utf-8', TRUE);
    drupal_add_http_header('Date', date('r'), TRUE);

    echo format_string($contents, array(
      '!endpointurl' => 'http' . ((isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on') ? 's' : '') . '://' . $_SERVER['SERVER_NAME'] . '/' . request_path(),
    ));
    exit;
  }

  //*********** PUBLIC API ***************//

  public function RecievedEntityLayout($data) {
    error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $data = ' . print_r($data, 1));
  }

  public function RecievedItemUnPublished($data) {
    error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $data = ' . print_r($data, 1));
  }

  public function RecievedItemPublished($data) {
    switch (strtolower($data->Name)) {
      case 'sag':
        $type = 'case';
        break;
      case 'dokument':
        $type = 'document';
        break;
      default:
        $type = 'unknown';
    }
    if (function_exists('os2web_cs_service_create_' . $type)) {
      foreach ($data->Fields->Field as $field) {
        if (trim($field->Value) && trim($field->Name)) {
          $publication['fields'][$field->Name] = $field->Value;
        }
      }
      foreach ($data->TriggerRules as $rule) {
        if (trim($rule->ID) && trim($rule->Name)) {
          $publication['rules'][$rule->ID] = $rule->Name;
        }
      }
      $publication['type'] = $type;
      $publication['status'] = $data->Status;
      return (bool) os2web_cs_service_create_case($publication);
    }
    else {
      return FALSE;
    }
  }

  public function __call($name, $arguments) {
    watchdog('acadre_esdh', 'Unsupported request recieved: %req', array('%req' => $name), WATCHDOG_NOTICE);
    error_log(basename(__FILE__) . ':' . __LINE__ . " Unsupported request recieved: $name");
  }

}
