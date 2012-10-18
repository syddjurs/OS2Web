<?php

// $Id$
/*
 * 
 * @author Jesper Mathiassen <jm@bellcom.dk>
 * @copyright Bellcom Open Source aps.
 */

function _os2web_esdh_provider_handler() {
  if (!os2web_esdh_provider_has_api('cp')) {
    error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
    drupal_access_denied();
  }
  error_log('MARK - ' . basename(__FILE__) . ':' . __LINE__ . ' in ' . __FUNCTION__ . '()');
  return os2web_esdh_provider_invoke('cp','handle_request');
}
