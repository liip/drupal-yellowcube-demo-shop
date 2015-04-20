<?php
/**
 * @file
 * yellowcube_demo_config.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function yellowcube_demo_config_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|yellowcube_demo_product|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'yellowcube_demo_product';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|yellowcube_demo_product|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|yellowcube_demo_product|full';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'yellowcube_demo_product';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'comments' => array(
      'weight' => '9',
      'label' => 'hidden',
      'format' => 'default',
    ),
  );
  $export['node|yellowcube_demo_product|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|yellowcube_demo_product|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'yellowcube_demo_product';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '1',
        'wrapper' => 'h2',
        'class' => '',
      ),
    ),
  );
  $export['node|yellowcube_demo_product|teaser'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function yellowcube_demo_config_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|yellowcube_demo_product|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'yellowcube_demo_product';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'left' => array(
        0 => 'field_image',
      ),
      'right' => array(
        1 => 'title',
        2 => 'product:commerce_price',
        3 => 'field_product',
      ),
      'bottom' => array(
        4 => 'product:yellowcube_demo_description',
        5 => 'product:field_weight',
        6 => 'product:field_dimensions',
        7 => 'product:commerce_stock',
        8 => 'product:yellowcube_demo_ean',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'field_image' => 'left',
      'title' => 'right',
      'product:commerce_price' => 'right',
      'field_product' => 'right',
      'product:yellowcube_demo_description' => 'bottom',
      'product:field_weight' => 'bottom',
      'product:field_dimensions' => 'bottom',
      'product:commerce_stock' => 'bottom',
      'product:yellowcube_demo_ean' => 'bottom',
      'comments' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'class="detail-view"',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|yellowcube_demo_product|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|yellowcube_demo_product|full';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'yellowcube_demo_product';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'bootstrap_6_6_stacked';
  $ds_layout->settings = array(
    'regions' => array(
      'right' => array(
        0 => 'title',
        2 => 'product:commerce_price',
        3 => 'field_product',
      ),
      'left' => array(
        1 => 'field_image',
      ),
      'bottom' => array(
        4 => 'product:yellowcube_demo_description',
        5 => 'product:field_weight',
        6 => 'product:field_dimensions',
        7 => 'product:commerce_stock',
        8 => 'product:yellowcube_demo_ean',
        9 => 'comments',
      ),
    ),
    'fields' => array(
      'title' => 'right',
      'field_image' => 'left',
      'product:commerce_price' => 'right',
      'field_product' => 'right',
      'product:yellowcube_demo_description' => 'bottom',
      'product:field_weight' => 'bottom',
      'product:field_dimensions' => 'bottom',
      'product:commerce_stock' => 'bottom',
      'product:yellowcube_demo_ean' => 'bottom',
      'comments' => 'bottom',
    ),
    'classes' => array(),
    'wrappers' => array(
      'top' => 'div',
      'left' => 'div',
      'right' => 'div',
      'bottom' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => 'class="detail-view"',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|yellowcube_demo_product|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|yellowcube_demo_product|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'yellowcube_demo_product';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'bootstrap_12';
  $ds_layout->settings = array(
    'regions' => array(
      'central' => array(
        0 => 'field_image',
        1 => 'title',
        2 => 'product:commerce_price',
        3 => 'product:commerce_stock',
      ),
    ),
    'fields' => array(
      'field_image' => 'central',
      'title' => 'central',
      'product:commerce_price' => 'central',
      'product:commerce_stock' => 'central',
    ),
    'classes' => array(),
    'wrappers' => array(
      'central' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['node|yellowcube_demo_product|teaser'] = $ds_layout;

  return $export;
}
