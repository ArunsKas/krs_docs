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
    'krs_doc' => array(
      'name' => t('Dokumentas'),
      'base' => 'node_content',
      'description' => t('Dokumentas, pvz., tarybos sprendimas, direktoriaus įsakymas.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
