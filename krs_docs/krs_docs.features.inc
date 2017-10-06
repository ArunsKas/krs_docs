<?php
/**
 * @file
 * krs_docs.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function krs_docs_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function krs_docs_node_info() {
  $items = array(
    'ta' => array(
      'name' => t('TA'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
