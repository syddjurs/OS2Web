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
  public static function getWSDL($wsdl = FALSE) {
    if ($wsdl) {
      $wsdl = str_replace('wsdl', '', $wsdl);
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService' . check_plain($wsdl + 1) . '.wsdl';
    }
    else {
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService.wsdl';
    }
    self::echoFile($filename);
  }

  /**
   * Dumps an xsd for the serivce.
   */
  public static function getXSD($xsd = FALSE) {
    if ($xsd) {
      $xsd = str_replace('xsd', '', $xsd);
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService' . check_plain($xsd + 1) . '.xsd';
    }
    else {
      $filename = 'plugins/cp/TraenPublishingDestinationSystemService.xsd';
    }
    self::echoFile($filename);
  }

  private static function echoFile($filename) {
    $filename = drupal_get_path('module', 'acadre_esdh') . '/' . $filename;
    if (!file_exists($filename)) {
      drupal_not_found();
    }
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
<<<<<<< HEAD
    $function = 'os2web_cs_service_create_' . $type;
    if (function_exists($function)) {
=======
    if (function_exists('os2web_cs_service_create_' . $type)) {
>>>>>>> Handling of case publications
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
<<<<<<< HEAD
      return (bool) call_user_func($function, $publication);
=======
      return (bool) os2web_cs_service_create_case($publication);
>>>>>>> Handling of case publications
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
