#!/bin/bash
basedir=$(cd `dirname $0`;pwd)
cd "$basedir"
# root check
#if [ `whoami` != "root" ];
#then
#    echo "You have to be root to run this script ....";
#    exit -1;
#fi;
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
mkdir -p "$basedir/build"
cd "$basedir/build"
qmake-qt5 ..
make
echo "***********************************************"
echo "*                                             *"
echo "* Translations .................              *"
echo "*                                             *"
echo "***********************************************"

#lrelease ../kndiswrapper.pro
cp -r "$basedir/translations" "$basedir/build"
lrelease-qt5 "$basedir/build/translations"/*.ts
echo "***********************************************"
echo "*                                             *"
echo "* installing ...................              *"
echo "*                                             *"
echo "***********************************************"

mkdir -p ${1}/usr/share/{kndiswrapper,applications,pixmaps}
mkdir -p ${1}/usr/bin

echo "cp icons/kndiswrapper.xpm ${1}/usr/share/kndiswrapper"
cp "$basedir/icons/kndiswrapper.xpm" ${1}/usr/share/kndiswrapper/kndiswrapper.xpm
echo "cp icons/kndiswrapper.xpm ${1}/usr/share/pixmaps"
cp "$basedir/icons/kndiswrapper.xpm" ${1}/usr/share/pixmaps/kndiswrapper.xpm
echo "cp kndiswrapper ${1}/usr/bin" && cp kndiswrapper ${1}/usr/bin
#chown root:root ${1}/usr/bin/kndiswrapper
chmod 755 ${1}/usr/bin/kndiswrapper
echo "cp translations/build/*.qm ${1}/usr/share/kndiswrapper"
cp "$basedir/translations/"*.qm ${1}/usr/share/kndiswrapper
echo "cp translations/cards_known_to_work.txt ${1}/usr/share/kndiswrapper"
cp "$basedir/translations/cards_known_to_work.txt" ${1}/usr/share/kndiswrapper
cat > ${1}/usr/share/applications/kndiswrapper.desktop <<EOF
[Desktop Entry]
Encoding=UTF-8
Name=kndiswrapper
Name[de]=kndiswrapper
GenericName=kndiswrapper
GenericName[de]=kndiswrapper
Comment=A GUI for ndiswrapper
Comment[de]=Eine GUI fuer ndiswrapper.
Exec=/usr/bin/kndiswrapper
Icon=kndiswrapper
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
