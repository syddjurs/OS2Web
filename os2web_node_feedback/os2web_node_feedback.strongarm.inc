<?php
/**
 * @file
 * os2web_node_feedback.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function os2web_node_feedback_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'feedback_excluded_paths';
  $strongarm->value = 'admin/
admin/reports/feedback
<front>';
  $export['feedback_excluded_paths'] = $strongarm;

  return $export;
}
