<?php

define('PWS_CACHE_TIMEOUT', 3600 * 4);

// $Id$
/*
 * 
 * @author Jesper Mathiassen <jm@bellcom.dk>
 * @copyright Bellcom Open Source aps.
 */
module_load_include('inc', 'os2web_pws', 'CaseService.class');

class AcadrePWS extends CaseService {

  private $client;
  private $client6;
  private $client_search;

  private function _get_ws_base_setup() {
    $user = variable_get('os2web_pws_user');
    $password = variable_get('os2web_pws_password');

    $proxy = variable_get('os2web_pws_proxy', FALSE);
    $proxy_host = variable_get('os2web_pws_proxy_host');
    $proxy_port = variable_get('os2web_pws_proxy_port');
    $options['trace'] = FALSE; // For debugging purposes. Remove on prod.
    $options['exceptions'] = TRUE;
    $options['login'] = $user;
    $options['cache_wsdl'] = WSDL_CACHE_BOTH;
    $options['password'] = $password;
    $options['soap_version'] = SOAP_1_1;
    if ($proxy) {
      $options['proxy_host'] = $proxy_host;
      $options['proxy_port'] = $proxy_port;
    }
    return $options;
  }

  private function get_client() {
    //error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
    $this->client = &drupal_static('os2web_acadre_pws_client');
    if (!$this->client) {
      $url = variable_get('os2web_pws_url');
      $url = trim($url);
      if ($url == '') {
        drupal_set_message(t('Error, no endpoint url set for v4soap.'), 'error');
      } else {
        //FIXME: Use a wellformed WSDL for V4 services.
        $options = $this->_get_ws_base_setup();
        $options['location'] = $url;
        $options['uri'] = 'http://www.traen.com/2007/09/06/';
        try {
          $this->client = new SoapClient(NULL, $options);
        } catch (Exception $e) {
          drupal_set_message('Error connecting to PWSv4 endpoint', 'error');
          return false;
        }
      }
    }
    return isset($this->client);
  }

  private function get_client6() {
    //error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
    $this->client6 = &drupal_static('os2web_acadre_pws_client6');
    if (!$this->client6) {
      $url = variable_get('os2web_pws_url_v6');
      $url = trim($url);
      if ($url == '') {
        drupal_set_message(t('Error, no endpoint url set for v6.'), 'error');
      } else {
        $options = $this->_get_ws_base_setup();
        try {
          $this->client6 = new SoapClient($url . '?WSDL', $options);
        } catch (Exception $sf) {
          drupal_set_message('Error connecting to PWSv6 endpoint', 'error');
        }
      }
    }
    return isset($this->client6);
  }

  private function get_client_search() {
    //error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
    $this->client_search = &drupal_static('os2web_acadre_pws_client_search');
    if (!$this->client_search) {
      $url = variable_get('os2web_pws_url_search');
      $url = trim($url);
      if ($url == '') {
        drupal_set_message(t('Error, no endpoint url set for document search searvice.'), 'error');
      } else {
        $options = $this->_get_ws_base_setup();
        try {
          $this->client_search = new SoapClient($url . '?WSDL', $options);
          return TRUE;
        } catch (SoapFault $sf) {
          drupal_set_message('Error connecting to PWS document search service endpoint', 'error');
          return false;
        }
      }
    }
    return isset($this->client_search);
  }

  /**
   * Initial service setup.
   */
  function __construct() {
    // Using a static allows singleton use of the connector class 
  }

  /**
   * Looks up a journaling entry and returns the id of a case.
   * FIXME: Make this a true call to webservice.
   *
   * @param string $query A case journaling number, ie. 11/14293
   */
  public function lookupCase($query) {
    $cid = __FUNCTION__ . $query;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client_search()) {
      $query = str_replace('-', '/', $query);
      $query = explode('/', $query);
      if (is_numeric($query[0]) && is_numeric($query[1])) {
        try {
          $result = (int) $this->client_search->getCaseSystemIdByYearAndSerial(array('year' => $query[0], 'serial' => $query[1]))->GetCaseSystemIdByYearAndSerialResult;
          cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
        } catch (SoapFault $sf) {
          $trace = $this->client_search->__getLastRequest();
          error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $trace = ' . print_r($trace, 1));
          $result = $sf;
        }
      }
    }
    return $result;
  }

  /**
   * Looks up a journaling entry and returns the id of a document.
   *
   * @param string $query A case journaling number, ie. 14293/11
   */
  public function lookupDoc($query) {
    $cid = __FUNCTION__ . $query;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client_search()) {
      $query = str_replace('-', '/', $query);
      $query = explode('/', $query);
      if (is_numeric($query[0]) && is_numeric($query[1])) {
        try {
          $result = (int) $this->client_search->getDocumentSystemIdByYearAndSerial(array('year' => $query[1], 'serial' => $query[0]))->GetDocumentSystemIdByYearAndSerialResult;
          $result = $result != -1 ? $result : false;
          cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
        } catch (SoapFault $sf) {
          $result = $sf;
        }
      }
    }
    return $result;
  }

  /**
   * Get metadata for a case by id.
   *
   * @param type $id
   * @return mixed array with info on success, false otherwise
   */
  public function fetchCase($id) {
    $cid = __FUNCTION__ . $id;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client6()) {
      try {
        $result = $this->client6->getCase($id);
        cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
      } catch (SoapFault $exc) {
        //TODO: Handle exception better...
        error_log("Var: \$exc = " . print_r($exc, 1));
        return false;
      }
    }
    return $result;
  }

  public function getCaseDocs($id) {
    $result = &drupal_static(__FUNCTION__ . $id, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get(__FUNCTION__ . $id, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } else {
      if ($this->get_client()) {
        $request = '<?xml version="1.0" encoding="utf-8"?>
          <soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
          <soap:Body>
          <CaseFileIdentifier xmlns="http://www.traen.com/2007/09/06/schema">!CaseID</CaseFileIdentifier>
          </soap:Body>
          </soap:Envelope> ';
        $request = format_string($request, array('!CaseID' => $id));
        try {
          $result = $this->client->__doRequest($request, $this->client->location, $this->client->uri . 'GetAllDocuments', SOAP_1_1);
          cache_set(__FUNCTION__ . $id, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
        } catch (SoapFault $sf) {
          error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $sf = ' . print_r($sf, 1));
          return false;
        }
      }
    }
    if (is_string($result)) {
      $result = simplexml_load_string($result)->xpath('//soap:Body[1]/*/*');
    } else {
      return false;
    }
    return $result;
  }

  public function getDocLock($id) {
    $cid = __FUNCTION__ . $id;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client()) {
      $request = '<?xml version="1.0" encoding="utf-8"?>
<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
  <soap:Body>
    <GetLockStatusDocumentId xmlns="http://www.traen.com/2007/09/06/schema">[DocID]</GetLockStatusDocumentId>
  </soap:Body>
</soap:Envelope>';
      try {
        $result = $this->client->__doRequest(t($request, array('[DocID]' => $id)), $this->client->location, $this->client->uri . 'GetLockStatus', SOAP_1_1);
        $result = simplexml_load_string($result);
        if (is_object($result)) {
          if ('' !== (string) array_pop($result->xpath('//soap:Fault/faultcode'))) { // This will indicate fault
            $result = false;
          } else {
            $result = $result->xpath('//soap:Body');
            $result = ('TRUE' === (string) $result[0]->DocumentLockStatus) ? TRUE : false;
            //        $result = (string)array_pop($result->xpath('//soap:Fault/faultcode')); // This will indicate fault
          }
        }
      } catch (SoapFault $sf) {

      }
      cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
    }
    return $result;
  }

  public function getDocInfo($id) {
    $cid = __FUNCTION__ . $id;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client_search()) {
      try {
        $result = $this->client_search->getDocumentById(array('id' => $id));
        $result = $result->GetDocumentByIdResult;
        cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
      } catch (SoapFault $sf) {
        $result = FALSE;
      }
    }
    return $result;
  }

  public function getDocument($id) {
    $cid = __FUNCTION__ . $id;
    $result = &drupal_static($cid, FALSE);
    if ($result != FALSE) {
      return $result;
    }
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client6()) {
      try {
        $result = $this->client6->getMainDocument($id);
        cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
      } catch (SoapFault $sf) {
        $result = FALSE;
      }
    }
    return $result;
  }

  public function getDocRef($id) {
    $doc = $this->getDocument($id);
    if (isset($doc->DocumentVersion->DocumentFileReference) && isset($doc->DocumentVersion->VersionNumber)) {
      return array(
          'ref' => $doc->DocumentVersion->DocumentFileReference,
          'ver' => $doc->DocumentVersion->VersionNumber,
      );
    } else {
      return false;
    }
  }

  public function getDocFileName($ref, $ver = FALSE) {
    $result = false;
    if (!is_numeric($ver)) {
      $info = $this->getDocRef($ref);
      $ref = $info['ref'];
      $ver = $info['ver'];
    }
    $cid = __FUNCTION__ . $ref . $ver;
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client()) {
      $request = '<?xml version="1.0" encoding="utf-8"?>
<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
  <soap:Body>
    <FileVersionReference1 xmlns="http://www.traen.com/2007/09/06/schema">
      <FileReference>@FileRef</FileReference>
      <Version>@Version</Version>
    </FileVersionReference1>
  </soap:Body>
</soap:Envelope>';
      try {
        $result = $this->client->__doRequest(t($request, array('@FileRef' => $ref, '@Version' => $ver)), $this->client->location, $this->client->uri . 'GetFileName', SOAP_1_1);
        $result = (string) array_shift(simplexml_load_string($result)->xpath('//soap:Body'))->FileName1;
        // Use md5sum to avoid long  and guessable filenames
        $info = pathinfo($result);
        $result = md5('adlibsalt' . $info['basename']) . '.' . $info['extension'];
        cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
      } catch (SoapFault $sf) {
        error_log("Var: \$sf = " . print_r($sf, 1));
      }
    }
    return $result;
  }

  public function getDocData($id, $ver = FALSE) {
    $dest = DEFAULT_DOC_CACHE_PATH;
    $result = false;
    if (!is_numeric($ver)) {
      $info = $this->getDocRef($id);
      $ref = $info['ref'];
      $ver = $info['ver'];
    }
    drupal_load('module', 'os2web_adlib_api');

    // Cache files unless there is a newer version available
    $fid = os2web_adlib_api_get_fid($ref);
    if ($fid > 0 && ($result = file_load($fid)) && is_file(drupal_realpath($result->uri))) {
      error_log(basename(__FILE__) . ':' . __LINE__ . " jm@bellcom.dk: File cached.");
      $ctime = filectime(drupal_realpath($result->uri));
      $info = $this->getDocInfo($id);
      if (is_object($info)) {
        $updated = strtotime($info->ChangedDateTime);
        if ($updated < $ctime) {
          $result = file_create_url($result->uri);
          return $result;
        }
      }
    }

    // Clean up failed files
    if (is_object($result) && !is_file(drupal_realpath($result->uri))) {
      error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' Failed file ' . $result->filename);
      file_delete($result, TRUE);
    }

    error_log(basename(__FILE__) . ':' . __LINE__ . " jm@bellcom.dk: Fetching file from WS. Ref: $ref");
    if ($this->get_client()) {
      $request = '<?xml version="1.0" encoding="utf-8"?>
<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
  <soap:Body>
    <FileVersionReference xmlns="http://www.traen.com/2007/09/06/schema">
      <FileReference>@FileRef</FileReference>
      <Version>@Version</Version>
    </FileVersionReference>
  </soap:Body>
</soap:Envelope>';
      try {
        $result = $this->client->__doRequest(t($request, array('@FileRef' => $ref, '@Version' => $ver)), $this->client->location, $this->client->uri . 'GetPhysicalDocument', SOAP_1_1);
//        $result = simplexml_load_string($result)->xpath('/soap:Envelope/soap:Body/*');
        $result = (string) array_shift(simplexml_load_string($result)->xpath('//soap:Body'))->XMLBinary;
        if (file_prepare_directory($dest, FILE_CREATE_DIRECTORY | FILE_MODIFY_PERMISSIONS)) {
          $filename = (string) $ref . '-' . (string) $ver . '-' . $this->getDocFileName($ref, $ver);
          error_log(basename(__FILE__) . ':' . __LINE__ . ' Var: $name = ' . print_r($filename, 1));
          $result = file_save_data(base64_decode($result), $dest . $filename, FILE_EXISTS_REPLACE);
          if (FALSE != $result) {
            drupal_load('module', 'os2web_adlib_api');
            os2web_adlib_api_convert_to_pdf($result->fid, $ref);
            $result = file_create_url($result->uri);
          } else {
            drupal_set_message('There was an error saving the file', 'error');
          }
        } else {
          drupal_set_message('There was an error creating the file', 'error');
        }
//        $result = $result[0];
      } catch (SoapFault $sf) {
        watchdog('acadre_pws', 'Error during SOAP call in ' . __FUNCTION__, NULL, WATCHDOG_WARNING);
      }
    }
    return $result;
  }

  public function getDocDataRaw($ref, $ver = FALSE) {
    $result = false;
    if (!is_numeric($ver)) {
      $info = $this->getDocRef($ref);
      $ref = $info['ref'];
      $ver = $info['ver'];
    }
    $cid = __FUNCTION__ . $ref . $ver;
    if (($cache = cache_get($cid, 'cache_os2web_pws')) && !empty($cache->data)) {
      $result = $cache->data;
    } elseif ($this->get_client()) {
      $request = '<?xml version="1.0" encoding="utf-8"?>
<soap:Envelope xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:xsd="http://www.w3.org/2001/XMLSchema" xmlns:soap="http://schemas.xmlsoap.org/soap/envelope/">
  <soap:Body>
    <FileVersionReference xmlns="http://www.traen.com/2007/09/06/schema">
      <FileReference>@FileRef</FileReference>
      <Version>@Version</Version>
    </FileVersionReference>
  </soap:Body>
</soap:Envelope>';
      try {
        $result = $this->client->__doRequest(t($request, array('@FileRef' => $ref, '@Version' => $ver)), $this->client->location, $this->client->uri . 'GetPhysicalDocument', SOAP_1_1);
        $result = (string) array_shift(simplexml_load_string($result)->xpath('//soap:Body'))->XMLBinary;
        cache_set($cid, $result, 'cache_os2web_pws', time() + PWS_CACHE_TIMEOUT);
      } catch (SoapFault $sf) {
        return false;
      }
    }
    return $result;
  }

}
