#ifndef KNDISWRAPPER_H
#define KNDISWRAPPER_H
//
#include <QDialog>
#include <QTextEdit>
#include <QMessageBox>
#include <QPushButton>
#include <QFileDialog>
#include <QMenu>
#include "instwizard.h"
#include "wikilookup.h"
#include "wifisetup.h"
#include <QProcess>
#include <QToolTip>
#include <QPixmap>
#include <QLabel>
#include <QTableWidget>
#include <QTimer>
#include <QFont>
#include <QDir>
#include <QAction>
#include <QStandardPaths>
//#include <cstdlib>
//#include <cstring>
#include "ui_kndiswrapper.h"
//print debug infomation
//#include <QDebug>
//check root
#include <unistd.h>
//
class kndiswrapper : public QDialog, public Ui::kndiswrapper{
	Q_OBJECT
public:
	kndiswrapper(QWidget * parent = 0, Qt::WindowFlags f = 0);
	virtual ~kndiswrapper();

private:
	QTextEdit		* comment;
        QLabel			* logoLabel;
        QLabel                  * popupLogo;
        QTableWidget            * hardwareList;
	QProcess		* removeProcess;
	QProcess		* moduleCheck;
	QProcess		* infoProcess;
	QProcess		* getConfProcess;
	QProcess		* restoreProcess;
	QProcess		* findNDISProcess;
	QProcess		* configNetworkProcess;
	QProcess		* moduleLoadedCheckProcess;
	QPushButton		* quitButton;
	QPushButton		* reloadButton;
	QPushButton		* addDriverButton;
	QPushButton		* removeDriverButton;
	QPushButton		* restoreDriverButton;
	QPushButton		* configNetworkButton;
	QMenu	 		* contextMenu;
        int			  quitButtonEndPosition;
        int			  reloadButtonEndPosition;
        int			  removeDriverButtonEndPosition;
        int			  restoreDriverButtonEndPosition;
        int			  configNetworkButtonEndPosition;
	bool			  getConfFlag;
	bool			  invokeSetup;
	bool			  disablerootcheck;
	bool			  disablenetconf;
        bool                      debug;
	QTimer			* moveButtonTimer;
        QTimer                  * popupLogoTimer;
	QString			  ndiswrapperPath;
	QString			  moduleCheckOutput;
	QString			  workingCards;

	int quit;
	int hwList;
	int disabled;
	int addDriver;
	int delDriver;
	int reloadList;
	int restoreDriver;
	int netconf;

	void getConf();
	void initWidget();
	void addNewRow(QString);
	void activateControls(int);
	void resizeEvent(QResizeEvent *);
        QString getSuCmd();

private slots:
	void slot_wikiRequested();
	void slot_infoProcessExited();
	void slot_reloadButtonClicked();
	void slot_removeProcessExited();
	void slot_moduleCheckRequested();
	void slot_getConfProcessExited();
	void slot_restoreProcessExited();
	void slot_infoProcessRequested();
        void slot_popupLogoTimerTimeout();
	void slot_configNetworkRequested();
	void slot_addDriverButtonClicked();
	void slot_buttonMoveTimerTimeout();
        void slot_moduleCheckProcessExited();
	void slot_removeDriverButtonClicked();
	void slot_restoreDriverButtonClicked();
	void slot_configNetworkProcessExited();
	void slot_moduleLoadedCheckProcessExited();
	void slot_moduleCheckProcessReadyReadStdout();
        void slot_hardwareListRightClicked(const QPoint &);
};
#endif
