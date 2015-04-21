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
 * Implements hook_image_default_styles().
 */
function yellowcube_demo_config_image_default_styles() {
  $styles = array();

  // Exported image style: detail_landscape.
  $styles['detail_landscape'] = array(
    'label' => 'Detail Landscape',
    'effects' => array(
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => '',
          'height' => 450,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      4 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 450,
          'height' => 450,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: detail_portrait.
  $styles['detail_portrait'] = array(
    'label' => 'Detail Portrait',
    'effects' => array(
      1 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 450,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
      2 => array(
        'name' => 'image_crop',
        'data' => array(
          'width' => 450,
          'height' => 450,
          'anchor' => 'center-center',
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: product_detail.
  $styles['product_detail'] = array(
    'label' => 'Product detail',
    'effects' => array(
      5 => array(
        'name' => 'canvasactions_aspect',
        'data' => array(
          'portrait' => 'detail_portrait',
          'landscape' => 'detail_landscape',
          'ratio_adjustment' => 1,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
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
