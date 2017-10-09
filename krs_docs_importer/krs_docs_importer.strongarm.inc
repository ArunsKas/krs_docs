<?php
/**
 * @file
 * krs_docs_importer.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function krs_docs_importer_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_feeds_importer';
  $strongarm->value = array(
    'import_t2' => FALSE,
    'import_t2_attach' => FALSE,
    'node' => FALSE,
    'test_csv' => FALSE,
    'test_url' => FALSE,
    'user' => FALSE,
  );
  $export['default_feeds_importer'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_feeds_tamper';
  $strongarm->value = array(
    'test_url-item-rewrite' => FALSE,
    'test_url-title-default_value' => TRUE,
    'test_url-item-debug' => TRUE,
    'test_url-blank_source_1-debug' => TRUE,
    'test_url-blank_source_1-copy' => FALSE,
    'test_csv-title-truncate_text' => FALSE,
    'test_csv-fileextra-implode' => FALSE,
    'test_csv-title-truncate_text1' => FALSE,
    'test_csv-title-strip_tags' => FALSE,
    'test_csv-title-copy' => FALSE,
    'test_csv-blank_source_1-copy' => FALSE,
    'test_csv-blank_source_1-truncate_text' => FALSE,
    'test_csv-blank_source_2-copy' => FALSE,
    'import_t2-blank_source_1-rewrite' => FALSE,
    'import_t2_attach-blank_source_1-rewrite' => FALSE,
    'import_t2_attach-guid-rewrite' => FALSE,
    'import_t2_attach-attach1-explode' => FALSE,
    'import_t2_attach-link1-explode' => FALSE,
    'import_t2-doclink-debug' => FALSE,
    'import_t2_attach-link1-debug' => FALSE,
    'import_t2_attach-blank_source_2-copy' => FALSE,
    'import_t2_attach-blank_source_2-hash' => FALSE,
    'import_t2_attach-blank_source_2-rewrite' => FALSE,
  );
  $export['default_feeds_tamper'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'http_request_timeout';
  $strongarm->value = 1000;
  $export['http_request_timeout'] = $strongarm;

  return $export;
}
