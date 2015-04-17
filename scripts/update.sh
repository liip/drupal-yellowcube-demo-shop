#!/bin/bash
cd ${0%/*} # move into the current directory
cd ..

drush -y updatedb
drush pm-enable yellowcube yellowcube_demo yellowcube_demo_content admin_menu_toolbar -y
drush pm-disable toolbar -y
drush vset theme_default yellowcube

drush mi YellowCubeDemoProducts
drush mi YellowCubeDemoProductNodes
