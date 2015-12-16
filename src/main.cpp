#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QProcess>
#include <QFile>
#include <QDir>
#include "kndiswrapper.h"
//
#include <QDebug>
//

int main(int argc, char ** argv)
{
QString rc;

    if (argc > 1) rc=(QString)argv[1];

    QApplication app( argc, argv );
    
    QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
        if (QFile::exists(configPath) == false){
            QDir().mkdir(configPath);
        }

        if (QFile::exists(configPath + "/netconf") == false){
            QDir().mkdir(configPath + "/netconf");
        }

        if (QFile::exists(configPath + "/backup") == false){
            QDir().mkdir(configPath + "/backup");
        }
    qDebug() << configPath;
    QTranslator translator( 0 );
    translator.load(QLocale(), QLatin1String("kndiswrapper"), QLatin1String("_"), QLatin1String("/usr/share/kndiswrapper"));
    app.installTranslator( &translator );



    kndiswrapper win;
    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
