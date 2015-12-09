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
make clean 2>/dev/null
make distclean 2>/dev/null
echo "***********************************************"
echo "*                                             *"
echo "* compiling ....................              *"
echo "*                                             *"
echo "***********************************************"
qmake
make
echo "***********************************************"
echo "*                                             *"
echo "* Translations .................              *"
echo "*                                             *"
echo "***********************************************"
lrelease kndiswrapper.pro
echo "***********************************************"
echo "*                                             *"
echo "* installing ...................              *"
echo "*                                             *"
echo "***********************************************"
if [ ! -e /usr/share/kndiswrapper ];
then
    mkdir -p /usr/share/kndiswrapper
fi

echo "cp icons/kndiswrapper.xpm /usr/share/kndiswrapper" && cp icons/kndiswrapper.xpm /usr/share/kndiswrapper/kndiswrapper.xpm
echo "cp kndiswrapper /usr/sbin" && cp kndiswrapper /usr/sbin
chown root:root /usr/sbin/kndiswrapper
chmod 755 /usr/sbin/kndiswrapper
echo "cp translations/*.qm /usr/share/kndiswrapper" && cp translations/*.qm /usr/share/kndiswrapper
echo "cp translations/cards_known_to_work.txt /usr/share/kndiswrapper" && cp translations/cards_known_to_work.txt /usr/share/kndiswrapper
cat > /usr/share/applications/kndiswrapper.desktop <<EOF
[Desktop Entry]
Encoding=UTF-8
Name=kndiswrapper
Name[de]=kndiswrapper
GenericName=kndiswrapper
GenericName[de]=kndiswrapper
Comment=A GUI for ndiswrapper
Comment[de]=Eine GUI fuer ndiswrapper.
Exec=/usr/bin/kndiswrapper
Icon=/usr/share/kndiswrapper/kndiswrapper.png
Terminal=false
Type=Application
StartupNotify=true
Categories=Network;
EOF
echo "********************************************************************************************"
echo "*                                                                                          *"
echo "* Done!                                                                                    *"
echo "*                                                                                          *"
echo "* If no error messages occurred you can start the program with \"sudo kndiswrapper\"         *"
echo "*                                                                                          *"
echo "* Suggestions and bug-reports can be send to joerg.zopes@linux-specialist.com              *"
echo "*                                                                                          *"
echo "********************************************************************************************"
