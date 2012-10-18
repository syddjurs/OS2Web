<?php
/**
 * @file
 * This file describes the CM plugin as implemented by Acadre
 *
 * @author Jesper Mathiassen <jm@bellcom.dk>
 * @copyright Bellcom Open Source aps.
 */

/**
 * Plugin definition with callbacks
 */
$plugin = array(
  'description' => t('Acadre ESDH CM Backend'),
  'version' => 1,
  'test' => 'acadre_esdh_test',
  'get_document' => 'acadre_esdh_get_document',
  'get_document_file' => 'acadre_esdh_get_document_file',
  'get_case_docs' => 'acadre_esdh_get_case_docs',
  'get_case_data' => 'acadre_esdh_get_case_data',
  'lookup_doc' => 'acadre_esdh_lookup_doc',
  'lookup_case' => 'acadre_esdh_lookup_case',
);

/**
 * Test method to verify plugin operationability.
 *
 * @param any $stuff
 * @return string
 */
function acadre_esdh_test($stuff) {
  return 'Test successful. Recieved: ' . $stuff;
}

/**
 * Return data relating to a given Document
 *
 * @param int or string $doc_id
 * @return array - Document structure
 * @TODO: Rework into generic datatypes for return value
 */
function acadre_esdh_get_document($doc_id) {
  $pws = _acadre_esdh_get_pws_instance();
  $doc_id = trim($doc_id);
  // Translate the SSSSSS/YY serial into database identifier
  if (!is_numeric($doc_id)) {
    $doc_id = acadre_esdh_lookup_doc($doc_id);
  }
  $doc_data = $pws->getDocument($doc_id);
  if ($doc_data === FALSE) {
    return FALSE;
  }
  $doc = array(
    'id' => $doc_id,
    'case_reference' => $doc_data->Record->CaseFileReference,
    'title' => $doc_data->Document->DocumentTitleText,
    'last_update' => $doc_data->Record->RecordLatestUpdateDate,
    'access_code' => $doc_data->Record->AccessCode,
    'publication_indicator' => $doc_data->Record->PublicationIndicator,
    'lock_status' => $pws->getDocLock($doc_id),
  );
  $doc += os2web_esdh_provider_default_document();
  return $doc;
}

/**
 * Return the actual file object for a given document
 *
 * @param int or string $doc_id
 * @return object - Drupal file structure
 */
function acadre_esdh_get_document_file($doc_id) {
  $pws = _acadre_esdh_get_pws_instance();
  $doc_id = trim($doc_id);
  // Translate the SSSSSS/YY serial into database identifier
  if (!is_numeric($doc_id)) {
    $doc_id = acadre_esdh_lookup_doc($doc_id);
  }
  if ($doc_id > 0) {
    $file = $pws->getDocData($doc_id);
    return $file;
  }
  else {
    return (object) NULL;
  }
}

/**
 * Returns a list of documents for a given case
 *
 * @param int or string $case_id
 * @return list of database ids of the documents related to the case.
 */
function acadre_esdh_get_case_docs($case_id) {
  $pws = _acadre_esdh_get_pws_instance();
  $case_id = trim($case_id);
  // Translate the SSSSSS/YY serial into database identifier
  if (!is_numeric($case_id)) {
    $case_id = acadre_esdh_lookup_case($case_id);
  }
  $docs = $pws->getCaseDocs($case_id);
  foreach ($docs as $doc) {
    $docids[] = (int) $doc->Document->DocumentIdentifier;
  }
  return $docids;
}

/**
 * Looks up a case if neccesary and return the metadata related to this case.
 *
 * @param int or string $case_id - either database identifier or year/serial to look up
 * @return array - Case data structure
 */
function acadre_esdh_get_case_data($case_id) {
  $pws = _acadre_esdh_get_pws_instance();
  $case_id = trim($case_id);
  // Translate the SSSSSS/YY serial into database identifier
  if (!is_numeric($case_id)) {
    $case_id = acadre_esdh_lookup_case($case_id);
  }

  $case_data = $pws->fetchCase($case_id);
  if ($case_data === FALSE) {
    return FALSE;
  }
  $case = array(
    'id' => $case_id,
    'access_code' => $case_data->AccessCode,
    'restricted_from_public' => $case_data->RestrictedFromPublicText,
  );
  $case += os2web_esdh_provider_default_case();
  return $case;
}

function acadre_esdh_lookup_doc($search_id) {
  $pws = _acadre_esdh_get_pws_instance();
  return $pws->lookupDoc(trim($search_id));
}

function acadre_esdh_lookup_case($search_id) {
  $pws = _acadre_esdh_get_pws_instance();
  return $pws->lookupCase(trim($search_id));
}

function _acadre_esdh_get_pws_instance() {
  $obj = &drupal_static(__FUNCTION__);
  if (is_object($obj))
    return $obj;
  module_load_include('inc', 'acadre_esdh', 'AcadrePWS.class');
  return $obj = new AcadrePWS();
}
