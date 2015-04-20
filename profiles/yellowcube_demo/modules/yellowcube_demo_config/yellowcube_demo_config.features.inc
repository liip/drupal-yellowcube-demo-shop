<?php
/**
 * @file
 * yellowcube_demo_config.features.inc
 */

/**
 * Implements hook_commerce_product_default_types().
 */
function yellowcube_demo_config_commerce_product_default_types() {
  $items = array(
    'yellowcube_demo_product' => array(
      'type' => 'yellowcube_demo_product',
      'name' => 'YellowCube Demo Product',
      'description' => '',
      'help' => '',
      'revision' => 1,
    ),
  );
  return $items;
}

/**
 * Implements hook_ctools_plugin_api().
 */
function yellowcube_demo_config_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function yellowcube_demo_config_node_info() {
  $items = array(
    'yellowcube_demo_product' => array(
      'name' => t('YellowCube Demo Product'),
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
