#include <QApplication>
#include <QTranslator>
#include <QProcess>
#include <QFile>
#include "kndiswrapper.h"
#include "setupdialog.h"
//
int main(int argc, char ** argv)
{
QString rc;
QString tf=(QString)getenv("HOME") + "/.kndiswrapper/setup.txt";

    if (argc > 1) rc=(QString)argv[1];

    QApplication app( argc, argv );

    if ((!QFile::exists(tf)) || (rc == "--setup")){
        setupDialog * setup = new setupDialog(0);
        setup->setModal(true);
        setup->exec();
        rc=setup->getResult();
        if (rc != "") {
            QFile * setupFile = new QFile(tf);
            setupFile->open(QIODevice::ReadWrite);
            QTextStream stream(setupFile);
            rc.replace("/usr/share/kndiswrapper/","");
            stream << rc << "\n";
            setupFile->close();
            exit(0);
        }
    } else {
            rc="";
            QFile f(tf);
            if (f.open(QIODevice::ReadOnly)){
              QTextStream stream(&f);
              rc=stream.readLine();
              f.close();
            }
    }

    QTranslator translator( 0 );
    translator.load( rc, "/usr/share/kndiswrapper" );
    app.installTranslator( &translator );



    kndiswrapper win;
    win.show();
    app.connect( &app, SIGNAL( lastWindowClosed() ), &app, SLOT( quit() ) );
    return app.exec();
}
