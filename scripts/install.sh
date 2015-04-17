#!/bin/bash

cd ${0%/*} # move into the current directory
git clone https://github.com/swisspost-yellowcube/drupal-yellowcube.git ../profiles/yellowcube_demo/modules/yellowcube
cd ../profiles/yellowcube_demo/modules/yellowcube
git checkout 7.x-1.x
composer install
