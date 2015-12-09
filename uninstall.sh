#!/bin/bash

# root check
if [ `whoami` != "root" ];
then
    echo "You have to be root to run this script ....";
    exit -1;
fi;
echo "***********************************************"
echo "*                                             *"
echo "* clean up .....................              *"
echo "*                                             *"
echo "***********************************************"
rm /usr/sbin/kndiswrapper
rm -rf /usr/share/kndiswrapper
