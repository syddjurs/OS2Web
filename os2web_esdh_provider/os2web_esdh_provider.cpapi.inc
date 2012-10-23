<?php
/**
 * @file
 * This file implements the Content pushing inteface
 *
 * @author Jesper Mathiassen <jm@bellcom.dk>
 * @copyright Bellcom Open Source aps.
 */

function _os2web_esdh_provider_handler() {
  if (!os2web_esdh_provider_has_api('cp')) {
    drupal_access_denied();
  }
  return os2web_esdh_provider_invoke('cp', 'handle_request');
}
