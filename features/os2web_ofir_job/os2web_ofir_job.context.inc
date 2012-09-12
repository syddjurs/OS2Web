<?php
/**
 * @file
 * os2web_ofir_job.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function os2web_ofir_job_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'jobliste';
  $context->description = 'Indholdslister udenfor menu';
  $context->tag = '';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'news' => 'news',
      ),
      'options' => array(
        'node_form' => '1',
      ),
    ),
    'path' => array(
      'values' => array(
        '*job-opslag/*' => '*job-opslag/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu_block-14' => array(
          'module' => 'menu_block',
          'delta' => 14,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu_block-5' => array(
          'module' => 'menu_block',
          'delta' => 5,
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'block-6' => array(
          'module' => 'block',
          'delta' => 6,
          'region' => 'sidebar_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Indholdslister udenfor menu');
  $export['jobliste'] = $context;

  return $export;
}
