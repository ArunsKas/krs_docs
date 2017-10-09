<?php
/**
 * @file
 * krs_docs_importer.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function krs_docs_importer_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_t2';
  $feeds_importer->config = array(
    'name' => 'import_docs',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 0,
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'expire' => '-1',
        'author' => '1',
        'authorize' => 1,
        'mappings' => array(
          0 => array(
            'source' => 'docno',
            'target' => 'field_doc_no',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'docdate',
            'target' => 'field_doc_date:start',
            'timezone' => 'Europe/Vilnius',
            'language' => 'und',
          ),
          2 => array(
            'source' => 'doctitle',
            'target' => 'field_doc_heading',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'docno',
            'target' => 'title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'doclink',
            'target' => 'field_doc_file:uri',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Blank source 1',
            'target' => 'guid',
            'unique' => 1,
            'language' => 'und',
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'krs_doc',
        'language' => 'und',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_t2'] = $feeds_importer;

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'import_t2_attach';
  $feeds_importer->config = array(
    'name' => 'import_docs_attach',
    'description' => '',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'delete_uploaded_file' => 0,
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'encoding' => 'UTF-8',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsFieldCollectionProcessor',
      'config' => array(
        'field_name' => 'field_attachs',
        'host_entity_type' => 'node',
        'guid_field_name' => '',
        'is_field' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'attach1',
            'target' => 'field_attach_title',
            'unique' => FALSE,
            'language' => 'und',
          ),
          1 => array(
            'source' => 'link1',
            'target' => 'field_attach_file:uri',
            'file_exists' => '5',
            'language' => 'und',
          ),
          2 => array(
            'source' => 'docno',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          3 => array(
            'source' => 'docdate',
            'target' => 'Temporary target 1',
            'unique' => FALSE,
            'language' => 'und',
          ),
          4 => array(
            'source' => 'Blank source 1',
            'target' => 'host_entity_guid',
            'unique' => FALSE,
            'language' => 'und',
          ),
          5 => array(
            'source' => 'Blank source 2',
            'target' => 'guid',
            'unique' => 1,
          ),
        ),
        'insert_new' => '1',
        'update_existing' => '1',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'field_attachs',
        'language' => 'und',
        'host_entity_importer_id' => '',
        'host_entity_importer_nid' => NULL,
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['import_t2_attach'] = $feeds_importer;

  return $export;
}
