<?php
/**
 * @file
 *  Contains base migration classes used by other Commerce Kickstart modules.
 */

/**
 * Migrate product variations from Artikelstamm.csv file.
 */
class YellowCubeDemoProducts extends Migration {

  /**
   * {@inheritDoc}
   */
  public function __construct() {
    parent::__construct();
    $this->description = t('Import demo products from CSV file.');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'sku' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationEntityAPI::getKeySchema('commerce_product', 'yellowcube_demo_product')
    );

    // Create a MigrateSource object.
    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'yellowcube_demo_content') . '/import/Artikelstamm.csv', self::csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationEntityAPI('commerce_product', 'yellowcube_demo_product');

    $this->addFieldMapping('status')->defaultValue(1);

    $this->addFieldMapping('commerce_stock')->defaultValue(0);

    $this->addFieldMapping('title', 'title_de')
      ->callbacks(array($this, 'prependValue'));;

    $this->addFieldMapping('sku', 'sku');

    $this->addFieldMapping('commerce_price', 'price');

    $this->addFieldMapping('yellowcube_demo_ean', 'ean');
    $this->addFieldMapping('yellowcube_demo_description', 'description_de');

    $this->addFieldMapping('field_weight', 'gross_weight');
    $this->addFieldMapping('field_weight:unit')->defaultValue('kg');
    $this->addFieldMapping('field_dimensions:length', 'length');
    $this->addFieldMapping('field_dimensions:width', 'width');
    $this->addFieldMapping('field_dimensions:height', 'height');
    $this->addFieldMapping('field_dimensions:unit')->defaultValue('m');



    //$this->addFieldMapping('');

    $this->addFieldMapping('language', 'language');
    $this->addFieldMapping('uid', 'uid');
  }

  /**
   * {@inheritDoc}
   */
  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

  /**
   * Return the CSV columns array used for reading the Stammdata.csv file.
   *
   * @return array
   */
  public static function csvcolumns() {
    $columns = array();

    // ArticleNo,EAN,ArticleDescription-de,ArticleDescription-fr,ArticleDescription-it,ArticleDescription-en,NetWeight-KGM,BatchMngtReq,SerialNoFlag,MinRemLife,PeriodExpDateType,AlternateUnitISO,AltNumeratorUOM,AltDenominatorUOM,GrossWeight-KGM,Length-MTR,Width-MTR,Height-MTR,Volume-MTQ,titleDE,titleFR,titleIT,titleEN,LOT1,LOT2
    $columns[0] = array('sku', 'ArticleNo');
    $columns[1] = array('ean', 'EAN');
    $columns[2] = array('description_de', 'ArticleDescription-de');
    $columns[3] = array('description_fr', 'ArticleDescription-fr');
    $columns[4] = array('description_it', 'ArticleDescription-it');
    $columns[5] = array('description_en', 'ArticleDescription-en');
    $columns[6] = array('net_weight', 'NetWeight-KGM');
    $columns[7] = array('batch_required_amount', 'BatchMngtReq');
    $columns[8] = array('serial_number_flag', 'SerialNoFlag');
    $columns[9] = array('min_rem_lift', 'MinRemLife');
    $columns[10] = array('period_exp_date_Type', 'PeriodExpDateType');
    $columns[11] = array('alternate_unit', 'AlternateUnitISO');
    $columns[12] = array('alternate_numerator', 'AltNumeratorUOM');
    $columns[13] = array('alternate_denominator', 'AltDenominatorUOM');
    $columns[14] = array('gross_weight', 'GrossWeight-KGM');
    $columns[15] = array('length', 'Length-MTR');
    $columns[16] = array('width', 'Width-MTR');
    $columns[17] = array('height', 'Height-MTR');
    $columns[18] = array('volume', 'Volume-MTQ');
    $columns[19] = array('title_de', 'titleDE');
    $columns[20] = array('title_fr', 'titleFR');
    $columns[21] = array('title_it', 'titleIT');
    $columns[22] = array('title_en', 'titleEN');
    $columns[23] = array('lot_1', 'LOT1');
    $columns[24] = array('lot_2', 'LOT2');

    return $columns;
  }

  /**
   * {@inheritDoc}
   */
  function prepareRow($row) {
    // There is no price in the demo data, so we make something up.
    $row->price = $row->net_weight * M_PI * 2 * 100;

    $row->language = LANGUAGE_NONE;
    $row->uid = 1;
  }


  public function prependValue($value) {
    $value = 'Drupal: ' .$value;
    return $value;
  }

}

/**
 * Import product displays for the variations imported above.
 */
class YellowCubeDemoProductNodes extends Migration {

  /**
   * {@inheritDoc}
   */
  public function __construct(array $arguments) {
    $this->arguments = $arguments;
    parent::__construct();
    $this->description = t('Import product nodes.');
    $this->dependencies = array('YellowCubeDemoProducts');

    // Create a map object for tracking the relationships between source rows
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'product_id' => array(
          'type' => 'varchar',
          'length' => 255,
          'not null' => TRUE,
        ),
      ),
      MigrateDestinationNode::getKeySchema()
    );

    $this->source = new MigrateSourceCSV(drupal_get_path('module', 'yellowcube_demo_content') . '/import/product-displays.csv', self::csvcolumns(), array('header_rows' => 1));

    $this->destination = new MigrateDestinationNode('yellowcube_demo_product');

    //Force update
    $this->highwaterField = array();

    // Created by admin.
    $this->addFieldMapping('uid')->defaultValue(1);

    // Promote to the front page.
    $this->addFieldMapping('promote')->defaultValue(1);

    $this->addFieldMapping('status')->defaultValue(1);

    // Disable comments.
    $this->addFieldMapping('comment')->defaultValue(0);

    // Map the values from the row.
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_product', 'skus');
  }

  /**
   * {@inheritDoc}
   */
  public function prepareRow($row) {
    $products = array();
    foreach(explode(',', $row->sku) as $sku) {
      $product = commerce_product_load_by_sku($sku);
      $products[] = $product->product_id;
    }
    $row->skus = $products;
  }

  /**
   * Return the CSV columns array used for reading the product-displays.csv file.
   *
   * @return array
   */
  public static function csvcolumns() {
    $columns = array();

    // ID,Title,SKUs
    $columns[0] = array('product_id', 'ID');
    $columns[1] = array('title', 'Title');
    $columns[2] = array('sku', 'SKUs');

    return $columns;
  }

  /**
   * {@inheritDoc}
   */
  public function processImport(array $options = array()) {
    parent::processImport($options);
    // Do not force menu rebuilding. Otherwise pathauto will try to rebuild
    // in each node_insert invocation.
    variable_set('menu_rebuild_needed', FALSE);
  }

}
