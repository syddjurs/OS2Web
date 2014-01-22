<?php
/**
 * @file
 * os2web_indholdstyper.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function os2web_indholdstyper_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_additional_info'
  $field_bases['field_additional_info'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_additional_info',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_attached_node'
  $field_bases['field_attached_node'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_attached_node',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'borger_dk_permalink' => 0,
        'contentpage' => 'contentpage',
        'esdh_dokument' => 0,
        'esdh_sag' => 0,
        'files' => 0,
        'galleri' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 'iframe_selvbetjeningsl_sning_mm',
        'institution' => 0,
        'knactivity' => 0,
        'kontaktblok' => 0,
        'local_plan' => 0,
        'media' => 0,
        'news' => 0,
        'ofir_job' => 0,
        'panel' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'rotating_image' => 0,
        'selvbetjeningslinks' => 0,
        'spotbox' => 0,
        'tema' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_billede'
  $field_bases['field_billede'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_billede',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_case'
  $field_bases['field_case'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_case',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'os2web_case_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'case_ident',
  );

  // Exported field_base: 'field_doc'
  $field_bases['field_doc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_doc',
    'foreign keys' => array(),
    'indexes' => array(
      'doc_ident' => array(
        0 => 'doc_ident',
      ),
    ),
    'locked' => 0,
    'module' => 'os2web_doc_field',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'doc_ident',
  );

  // Exported field_base: 'field_foto'
  $field_bases['field_foto'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_foto',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_gruppe_id'
  $field_bases['field_gruppe_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_gruppe_id',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_iframe_url'
  $field_bases['field_iframe_url'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_iframe_url',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_indholdsside_spotboxe'
  $field_bases['field_indholdsside_spotboxe'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_indholdsside_spotboxe',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'baggrund' => 0,
        'borger_dk_permalink' => 0,
        'bullet_point' => 0,
        'bullet_point_attachment' => 0,
        'contentpage' => 0,
        'esdh_dokument' => 0,
        'esdh_sag' => 0,
        'files' => 0,
        'galleri' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 0,
        'knactivity' => 0,
        'kontaktblok' => 0,
        'local_plan' => 0,
        'media' => 0,
        'meeting' => 0,
        'news' => 0,
        'ofir_job' => 0,
        'os2web_meeting_search_status' => 0,
        'panel' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'rotating_image' => 0,
        'sektionsside' => 0,
        'selvbetjeningslinks' => 0,
        'speaker_paper' => 0,
        'spotbox' => 'spotbox',
        'tema' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_inherit_right_column'
  $field_bases['field_inherit_right_column'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_inherit_right_column',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => 0,
        1 => 1,
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  // Exported field_base: 'field_kilde'
  $field_bases['field_kilde'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_kilde',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_mediafile'
  $field_bases['field_mediafile'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_mediafile',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'file',
    'settings' => array(
      'display_default' => 0,
      'display_field' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'file',
  );

  // Exported field_base: 'field_node_reference_kontaktblok'
  $field_bases['field_node_reference_kontaktblok'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_node_reference_kontaktblok',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'baggrund' => 0,
        'borger_dk_permalink' => 0,
        'bullet_point' => 0,
        'bullet_point_attachment' => 0,
        'contentpage' => 0,
        'esdh_dokument' => 0,
        'esdh_sag' => 0,
        'files' => 0,
        'galleri' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 0,
        'knactivity' => 0,
        'kontaktblok' => 'kontaktblok',
        'local_plan' => 0,
        'media' => 0,
        'meeting' => 0,
        'news' => 0,
        'ofir_job' => 0,
        'os2web_meeting_search_status' => 0,
        'panel' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'rotating_image' => 0,
        'sektionsside' => 0,
        'selvbetjeningslinks' => 0,
        'speaker_paper' => 0,
        'spotbox' => 0,
        'tema' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_noderef_selvbtjn'
  $field_bases['field_noderef_selvbtjn'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_noderef_selvbtjn',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'baggrund' => 0,
        'borger_dk_permalink' => 0,
        'bullet_point' => 0,
        'bullet_point_attachment' => 0,
        'contentpage' => 0,
        'esdh_dokument' => 0,
        'esdh_sag' => 0,
        'files' => 0,
        'galleri' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 0,
        'knactivity' => 0,
        'kontaktblok' => 0,
        'local_plan' => 0,
        'media' => 0,
        'meeting' => 0,
        'news' => 0,
        'ofir_job' => 0,
        'os2web_meeting_search_status' => 0,
        'panel' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'rotating_image' => 0,
        'sektionsside' => 0,
        'selvbetjeningslinks' => 'selvbetjeningslinks',
        'speaker_paper' => 0,
        'spotbox' => 0,
        'tema' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_parent_node'
  $field_bases['field_parent_node'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_parent_node',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'borger_dk_permalink' => 0,
        'contentpage' => 'contentpage',
        'esdh_dokument' => 0,
        'esdh_sag' => 0,
        'files' => 0,
        'galleri' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 0,
        'knactivity' => 0,
        'local_plan' => 0,
        'media' => 0,
        'news' => 0,
        'ofir_job' => 0,
        'panel' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'rotating_image' => 0,
        'spotbox' => 0,
        'tema' => 0,
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_related'
  $field_bases['field_related'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_related',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'activity' => 'activity',
        'borger_dk_permalink' => 0,
        'contentpage' => 'contentpage',
        'files' => 'files',
        'forum' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 'institution',
        'local_plan' => 'local_plan',
        'media' => 'media',
        'news' => 'news',
        'person' => 'person',
        'politician' => 'politician',
        'referat' => 'referat',
        'right_column' => 0,
        'tema' => 'tema',
        'webform' => 'webform',
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_related_tema'
  $field_bases['field_related_tema'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_related_tema',
    'foreign keys' => array(
      'nid' => array(
        'columns' => array(
          'nid' => 'nid',
        ),
        'table' => 'node',
      ),
    ),
    'indexes' => array(
      'nid' => array(
        0 => 'nid',
      ),
    ),
    'locked' => 0,
    'module' => 'node_reference',
    'settings' => array(
      'referenceable_types' => array(
        'activity' => 0,
        'borger_dk_permalink' => 0,
        'contentpage' => 0,
        'files' => 0,
        'forum' => 0,
        'iframe_selvbetjeningsl_sning_mm' => 0,
        'institution' => 0,
        'local_plan' => 0,
        'media' => 0,
        'news' => 0,
        'person' => 0,
        'politician' => 0,
        'referat' => 0,
        'right_column' => 0,
        'tema' => 'tema',
        'webform' => 0,
      ),
      'view' => array(
        'args' => array(),
        'display_name' => '',
        'view_name' => '',
      ),
    ),
    'translatable' => 0,
    'type' => 'node_reference',
  );

  // Exported field_base: 'field_resume_long'
  $field_bases['field_resume_long'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_resume_long',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'text_with_summary',
  );

  // Exported field_base: 'field_rotate_image'
  $field_bases['field_rotate_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rotate_image',
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'uri_scheme' => 'public',
    ),
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_rotate_publish'
  $field_bases['field_rotate_publish'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rotate_publish',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'date',
    'settings' => array(
      'cache_count' => 4,
      'cache_enabled' => 0,
      'granularity' => array(
        'day' => 'day',
        'hour' => 0,
        'minute' => 0,
        'month' => 'month',
        'second' => 0,
        'year' => 'year',
      ),
      'timezone_db' => '',
      'todate' => 'required',
      'tz_handling' => 'none',
    ),
    'translatable' => 0,
    'type' => 'datestamp',
  );

  // Exported field_base: 'field_rotating_link'
  $field_bases['field_rotating_link'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_rotating_link',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'link',
    'settings' => array(
      'attributes' => array(
        'class' => '',
        'rel' => '',
        'target' => 'default',
      ),
      'display' => array(
        'url_cutoff' => 80,
      ),
      'enable_tokens' => 1,
      'title' => 'optional',
      'title_maxlength' => 128,
      'title_value' => '',
      'url' => 0,
    ),
    'translatable' => 0,
    'type' => 'link_field',
  );

  // Exported field_base: 'field_selvbetjening_direkte'
  $field_bases['field_selvbetjening_direkte'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_selvbetjening_direkte',
    'foreign keys' => array(
      'format' => array(
        'columns' => array(
          'format' => 'format',
        ),
        'table' => 'filter_format',
      ),
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'max_length' => 254,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_selvbetjeningslink_type'
  $field_bases['field_selvbetjeningslink_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_selvbetjeningslink_type',
    'foreign keys' => array(),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'handling' => 'Hvis du skal',
        'emne' => 'Emne',
        'liste' => 'Liste',
        'megamenu' => 'Megamenu',
      ),
      'allowed_values_function' => '',
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_source_id'
  $field_bases['field_source_id'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_source_id',
    'foreign keys' => array(),
    'indexes' => array(),
    'locked' => 0,
    'module' => 'number',
    'settings' => array(),
    'translatable' => 0,
    'type' => 'number_integer',
  );

  return $field_bases;
}
