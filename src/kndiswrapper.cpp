#include "kndiswrapper.h"
#include <QDebug>
#include <unistd.h>
//
QString kndiswrapper::getSuCmd()
{
    QStringList SuCandidates;
    QString SuCmd("sudo"); 
    SuCandidates << "kdesu" << "gksu" << "kdesudo" << "gksudo";
    for (int i=0;i<SuCandidates.count();++i) {
       QString rval;
       rval = QStandardPaths::findExecutable(SuCandidates[i]);
       if (QFileInfo(rval).isExecutable()) {
             SuCmd = SuCandidates[i];
             break;
       }
    }
    return SuCmd;
}

kndiswrapper::kndiswrapper( QWidget * parent, Qt::WindowFlags f) : QDialog(parent, f)
{
	//setupUi(this);

QString homePath=getenv("HOME");
QDir tempDir(homePath);

QString commentText = tr("KNDISWrapper will help you to setup your wireless network with ndiswrapper.\n\nThe Install Driver Button \
is used to install a new driver for a wireless dvice supported by ndiswrapper. To do so, you have to \
identify the appropriate '.inf' file. Sometimes you find this file on the driver-CD delivered together \
with the hardware. In some cases this file is stored in a '.cab' file. This is a Windows archive file \
and can be extracted with 'cabextract'. If the driver is delivered only in a '.exe' setup-file you can '\
only install the driver under Windows and look for the driver in the Windows Directory.\n\n\
The Remove Driver Button is used to remove a Windows driver that doesn't work or isn't used any longer.\n\
A copy of the driver is made so it can be restored if needed.\n\n\
With the Reload List Button the driver list is loaded again. Changes (e.g. hardware installed) are not detected \
automaticly.\n\nWith the Restore Driver Button you can re-install a driver, previously removed through the Remove Button\n\n\
Config Network invokes the network configuration dialog. Here you can setup the interface associated to the driver \
you have selected in the list.\n\n\
With the Quit Button you exit this application.");

	disabled=0;
	addDriver=1;
	delDriver=2;
	reloadList=4;
	restoreDriver=8;
	quit=16;
	hwList=32;
	netconf=64;

        disablerootcheck=false;
	disablenetconf=false;
	invokeSetup=false;
        debug=false;
	if (QCoreApplication::arguments().count() > 1){
		for (int i=0; i < QCoreApplication::arguments().count();i++){
			if ((QString)QCoreApplication::arguments()[i] == "--disablerootcheck") disablerootcheck=true;
			if ((QString)QCoreApplication::arguments()[i] == "--setup") invokeSetup=true;
			if ((QString)QCoreApplication::arguments()[i] == "--disablenetconf") disablenetconf=true;
                        if ((QString)QCoreApplication::arguments()[i] == "--debug") debug=true;
		}
	}

        if (getuid() != 0){
            if (!disablerootcheck){
                QString SuCmd = getSuCmd();
                if (SuCmd != QString()) {
                    QProcess process;
                    process.startDetached(SuCmd+QString(" ")+QCoreApplication::applicationFilePath());
                    //process.waitForFinished(-1);
                } else {
                    QMessageBox::information(this,"DEBUG","You have to be root to run this programm.\nTry --disablerootcheck for testing.");
                }
                exit(0);
            }
        }

	comment = new QTextEdit(this);
	comment->setText(commentText);
	comment->setFont(QFont("Helvetic",10,QFont::Normal,true));
	comment->setReadOnly(true);

	contextMenu = new QMenu(this);
        contextMenu->addAction(QPixmap(":/icons/icons/adddriver.xpm"),tr("Add Driver"),this,SLOT(slot_addDriverButtonClicked()));
        contextMenu->addAction(QPixmap(":/icons/icons/deldriver.xpm"),tr("Remove Driver"),this,SLOT(slot_removeDriverButtonClicked()));
        contextMenu->addSeparator();
        contextMenu->addAction(QPixmap(":/icons/icons/reload.xpm"),tr("Reload List"),this,SLOT(slot_reloadButtonClicked()));
        contextMenu->addSeparator();
        contextMenu->addAction(QPixmap(":icons/icons/kndiswrapper.xpm"),tr("Module Check"),this,SLOT(slot_moduleCheckRequested()));
        contextMenu->addAction(QPixmap(":/icons/icons/info.xpm"),tr("Info dmesg"),this,SLOT(slot_infoProcessRequested()));
        contextMenu->addAction(QPixmap(":/icons/icons/wiki.xpm"),tr("Offline Wiki"),this,SLOT(slot_wikiRequested()));

	if (!disablenetconf){
		contextMenu->addSeparator();
                contextMenu->addAction(QPixmap(":/icons/icons/confignetwork.xpm"),tr("Config Network"),this,SLOT(slot_configNetworkRequested()));
	}

	hardwareList = new QTableWidget(0,1,this);
	hardwareList->setToolTip(tr("Right-Click for more options"));
        hardwareList->setContextMenuPolicy(Qt::CustomContextMenu);
        hardwareList->setIconSize(QSize(48,48));
        QStringList horizontalHeaderLabel;
        horizontalHeaderLabel << "Device";
        hardwareList->setHorizontalHeaderLabels(horizontalHeaderLabel);
        hardwareList->setEditTriggers(QAbstractItemView::NoEditTriggers);

        logoLabel = new QLabel("kndiswrapper",this);
        logoLabel->setPixmap(QPixmap(":/icons/icons/kndiswrapper_logo.xpm"));

	addDriverButton = new QPushButton(QPixmap(":/icons/icons/adddriver.xpm"),tr("Install Driver"),this);
	addDriverButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	addDriverButton->setToolTip(tr("Install a new driver. Therefor locate the appropriate .inf file."));

	removeDriverButton = new QPushButton(QPixmap(":/icons/icons/deldriver.xpm"),tr("Remove Driver"),this);
	removeDriverButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	removeDriverButton->setToolTip(tr("Removes the selected driver in the list."));

	reloadButton = new QPushButton(QPixmap(":/icons/icons/reload.xpm"),tr("Reload List"),this);
	reloadButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	reloadButton->setToolTip(tr("Reload the content of the list"));

	restoreDriverButton = new QPushButton(QPixmap(":/icons/icons/restore.xpm"),tr("Restore Driver"),this);
	restoreDriverButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	restoreDriverButton->setToolTip(tr("Restores a removed driver."));

	if (!disablenetconf){
		configNetworkButton = new QPushButton(QPixmap(":/icons/icons/confignetwork.xpm"),tr("Config Network"),this);
		configNetworkButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
		configNetworkButton->setToolTip(tr("Start's the network configuration dialog"));
	}

	quitButton = new QPushButton(QPixmap(":/icons/icons/stop.xpm"),tr("Quit"),this);
	quitButton->setFont(QFont("Helvetic",10,QFont::Normal,false));
	quitButton->setToolTip(tr("Quit the application"));

	getConfProcess = new QProcess(this);
	restoreProcess = new QProcess(this);
	removeProcess = new QProcess(this);
	findNDISProcess = new QProcess(this);
	moduleCheck = new QProcess(this);
	moduleLoadedCheckProcess = new QProcess(this);
	infoProcess = new QProcess(this);
	configNetworkProcess = new QProcess(this);

	connect(getConfProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_getConfProcessExited()));
	connect(quitButton,SIGNAL(clicked()),qApp,SLOT(quit()));
	connect(removeDriverButton,SIGNAL(clicked()),this,SLOT(slot_removeDriverButtonClicked()));
	connect(reloadButton,SIGNAL(clicked()),this,SLOT(slot_reloadButtonClicked()));
	connect(restoreDriverButton,SIGNAL(clicked()),this,SLOT(slot_restoreDriverButtonClicked()));
	connect(restoreProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_restoreProcessExited()));
	connect(addDriverButton,SIGNAL(clicked()),this,SLOT(slot_addDriverButtonClicked()));
	connect(removeProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_removeProcessExited()));
	connect(findNDISProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_findNDISProcessExited()));
	connect(moduleCheck,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_moduleCheckProcessExited()));
        connect(hardwareList,SIGNAL(customContextMenuRequested(QPoint)),this,SLOT(slot_hardwareListRightClicked(const QPoint &)));
	connect(moduleLoadedCheckProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_moduleLoadedCheckProcessExited()));
	connect(infoProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_infoProcessExited()));
	connect(configNetworkProcess,SIGNAL(finished(int,QProcess::ExitStatus)),this,SLOT(slot_configNetworkProcessExited()));
	if (!disablenetconf) connect(configNetworkButton,SIGNAL(clicked()),this,SLOT(slot_configNetworkRequested()));

	activateControls(addDriver|delDriver|reloadList|restoreDriver|quit|hwList|netconf);
	moveButtonTimer = new QTimer(this);
	connect(moveButtonTimer,SIGNAL(timeout()),this,SLOT(slot_buttonMoveTimerTimeout()));

	getConfFlag=true;  // has to be false in the beginning ....
        this->setFixedSize(700,340);

        popupLogo = new QLabel("KNDISWrapper 0.4.0\n\nSend bug reports to Joerg Zopes\n<joerg.zopes@linux-specialist.com>",this);
        popupLogo->hide();
        popupLogo->setFont(QFont("Helvetic",14,QFont::Bold,true));
        popupLogo->setAutoFillBackground(true);
        popupLogo->setPalette(QColor("#4a801f"));
        popupLogo->setAlignment(Qt::AlignCenter);
        popupLogoTimer = new QTimer(this);
        popupLogoTimer->setSingleShot(true);
        popupLogoTimer->setInterval(4000);
        connect(popupLogoTimer,SIGNAL(timeout()),this,SLOT(slot_popupLogoTimerTimeout()));

	initWidget();
}

kndiswrapper::~kndiswrapper()
{
}


void kndiswrapper::initWidget(){
    QString SuCmd = getSuCmd();
    if (invokeSetup){
      QProcess launcher;
      launcher.start(SuCmd + QString(" kndiswrapper --setup"));
      exit(0);
    }

    if (!disablerootcheck){
      if ((QString)getenv("HOME") != "/root"){
        QString launcher;
        launcher = SuCmd + " \"kndiswrapper ";
        if (QCoreApplication::arguments().count() > 1){
          for (int i=1; i < QCoreApplication::arguments().count();i++){
            launcher += (QString)QCoreApplication::arguments()[i] + " ";
          }
        }
        launcher += "\" &";
        QProcess restart;
        restart.start(launcher);
        exit(0);
      }
    }

    findNDISProcess->start("whereis ndiswrapper");
}


void kndiswrapper::resizeEvent(QResizeEvent * e){
    Q_UNUSED(e);

    comment->setGeometry(2,2,244,this->height()-4);
    logoLabel->setGeometry(255,5,this->width()-210,40);
    hardwareList->setGeometry(255,50,this->width()-425,this->height()-55);
    hardwareList->setColumnWidth(0,hardwareList->width()-4);
    hardwareList->setShowGrid(false);
    addDriverButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    removeDriverButtonEndPosition=addDriverButton->y()+addDriverButton->height()+5;
    reloadButtonEndPosition = removeDriverButtonEndPosition + addDriverButton->height()+5;
    restoreDriverButtonEndPosition = reloadButtonEndPosition + addDriverButton->height()+5;
    configNetworkButtonEndPosition = restoreDriverButtonEndPosition + addDriverButton->height()+5;
    quitButtonEndPosition = configNetworkButtonEndPosition + addDriverButton->height()+25;
    removeDriverButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    reloadButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    restoreDriverButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    quitButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    if (!disablenetconf) configNetworkButton->setGeometry(hardwareList->x()+hardwareList->width()+5,hardwareList->y(),this->width()-hardwareList->width()-265,40);
    popupLogo->setGeometry((this->width()-400) / 2, (this->height()-150) / 2,400,150);
}

void kndiswrapper::getConf(){
    activateControls(disabled);
    while (hardwareList->rowCount() > 0) hardwareList->removeRow(0);
    getConfProcess->start(ndiswrapperPath + " -l");
}

void kndiswrapper::addNewRow(QString listEntry){
    hardwareList->insertRow(hardwareList->rowCount());
    hardwareList->setItem(hardwareList->rowCount()-1,0,new QTableWidgetItem(listEntry));
    if (listEntry.indexOf("invalid") > 0){
        hardwareList->item(hardwareList->rowCount()-1,0)->setIcon(QPixmap(":/icons/icons/kndiswrapper_nok.xpm"));
    } else {
        if (listEntry.indexOf("Device present : Yes") > 0){
            hardwareList->item(hardwareList->rowCount()-1,0)->setIcon(QPixmap(":/icons/icons/kndiswrapper_ok.xpm"));
        } else {
            hardwareList->item(hardwareList->rowCount()-1,0)->setIcon(QPixmap(":/icons/icons/kndiswrapper.xpm"));
        }
    }
    hardwareList->item(hardwareList->rowCount()-1,0)->text() = listEntry;
    hardwareList->setRowHeight(hardwareList->rowCount()-1,50);
}

void kndiswrapper::slot_getConfProcessExited(){
QString rc;
QString nextLine;
int count = 0;
int start,end;
QString processOutput = getConfProcess->readAllStandardOutput();
QStringListIterator it(processOutput.split("\n"));
	
    while (it.hasNext()){
        nextLine = it.next();
        count++;
        switch (count){
        case 1 :  if (nextLine.indexOf("invalid") > 0){
                    addNewRow(nextLine);
                    count=0;
                    rc="";
                  } else {
                    rc = nextLine.left(nextLine.indexOf(":")-1);
                    nextLine="\n     Device present : No";
                  }
                    break;
        case 2 :  if (nextLine.indexOf("present") > 0){
                  // Abfragen von alternate Driver
                    if (nextLine.indexOf("(alternate") > 0){
                        start=nextLine.indexOf("(alternate");
                        end=nextLine.indexOf(")",start);
                        end=end-start+1;
                        rc = rc + " : " + nextLine.mid(start,end);
                    }
                  // ----------------------------------------------------
                    rc = rc + "\n     Device present : Yes";
                    addNewRow(rc);
                    count = 0;
                    rc = "";
                  } else {
                    addNewRow(rc + (QString)"\n     Device present : No");
                    if (nextLine.indexOf("invalid") > 0){
                        addNewRow(nextLine);
                        count=0;
                        rc="";
                    } else {
                        rc = nextLine.left(nextLine.indexOf(":")-1);
                        nextLine="\n     Device present : No";
                        count=1;
                  }
            }
            break;
        }
    }
    if (rc.length() != 0) addNewRow(rc + nextLine);
    hardwareList->rowCount() > 0?activateControls(addDriver|delDriver|reloadList|restoreDriver|quit|hwList|netconf):activateControls(addDriver|reloadList|restoreDriver|quit|hwList|netconf);
    getConfFlag=true;
}

void kndiswrapper::slot_removeDriverButtonClicked(){
    int rc;
    QString homePath=getenv("HOME");
    int currentRow = hardwareList->currentRow();
    if (currentRow != -1){
        QString driver = hardwareList->item(hardwareList->currentRow(),0)->text();
        driver = driver.left(driver.indexOf("\n"));
        if (driver.indexOf(":") > 0) driver = driver.left(driver.indexOf(":")-1);
        rc = QMessageBox::question(this,tr("Remove Driver"),tr("Are you sure you want to remove the driver : ") + driver + "?",QMessageBox::Yes,QMessageBox::No);
        if (rc == QMessageBox::Yes){
            activateControls(disabled);
//       Versuche eine Sicherungskopie des Treibers zu erstellen
            QProcess::execute("cp -r /etc/ndiswrapper/" + driver + " " + homePath + "/.kndiswrapper/backup");
            removeProcess->start(ndiswrapperPath + " -r " + driver);
        }
    }
}

void kndiswrapper::slot_reloadButtonClicked(){
    getConf();
}

void kndiswrapper::slot_restoreProcessExited(){
QString rc = "";

    rc = rc + restoreProcess->readAllStandardOutput() + "\n";
    rc = rc + restoreProcess->readAllStandardError() + "\n";

    if (rc.indexOf("nstalling") > 0){
        QMessageBox::information(this,tr("Install Driver"),tr("The driver has been succesfully installed"));
    } else {
        if (rc.indexOf("lready installed") > 0){
            QMessageBox::warning(this,tr("Warning"),tr("The driver is already installed"));
        } else {
            if (rc.indexOf("ouldn't create") > 0){
                QMessageBox::critical(this,tr("Error"),tr("Unable to install the driver!\n\n") + rc);
            } else {
                QMessageBox::information(this,"DEBUG",tr("Unkown outcome!\n") + rc);
            }
        }
    }
    if (QProcess::execute(ndiswrapperPath + " -ma") != 0) QMessageBox::information(this,"DEBUG",tr("Writeing of configuration failed!"));
    if (QProcess::execute("modprobe -r ndiswrapper") != 0) QMessageBox::information(this,"DEBUG",tr("Removing of ndiswrapper module failed!"));
    if (QProcess::execute("modprobe ndiswrapper") != 0) QMessageBox::information(this,"DEBUG",tr("Loading of ndiswrapper module failed!"));
    getConf();
    activateControls(addDriver|delDriver|reloadList|restoreDriver|quit|hwList|netconf);
}

void kndiswrapper::slot_restoreDriverButtonClicked(){
    QString homePath=(QString)getenv("HOME") + "/.kndiswrapper/backup";
    QString rc;

    rc = QFileDialog::getOpenFileName(this,tr("Restore Drivers"),homePath,tr("INF-Files (*.inf)"));
    if (rc != ""){
        restoreProcess->start(ndiswrapperPath + " -i " + rc);
    }
}

void kndiswrapper::slot_addDriverButtonClicked(){
QString homePath=(QString)getenv("HOME");
QString rc;
QString driver;
int rc2;
int rc3;
instWizard * wizard;

    rc2 = QMessageBox::question(this,"Hardware Info",tr("Do you want to use the installation wizard or do you want to select the appropirate *.inf file by yourself"),"Start Wizard","Manual Inst.","Abort Inst.");
    switch(rc2){
    case 0 : wizard = new instWizard(this,&driver);
             rc3 = wizard->exec();
             delete wizard;
             if (rc3 == QDialog::Accepted) {
               activateControls(disabled);
               QString command = ndiswrapperPath + " -i " + driver;
               restoreProcess->start(command);
             }
                break;
    case 1 : rc = QFileDialog::getOpenFileName(this,tr("New Driver"),homePath,tr("INF-Files (*.inf)"));
             if (rc != ""){
               activateControls(disabled);
               restoreProcess->start(ndiswrapperPath + " -i " + rc);
             }
                break;
    }
}

void kndiswrapper::slot_removeProcessExited(){
    QString rc = "";

    rc = rc + removeProcess->readAllStandardOutput() + "\n";
    rc = rc + removeProcess->readAllStandardError() + "\n";

    if (rc == "\n\n"){
        QMessageBox::information(this,tr("Removing Driver"),tr("The driver has been succesfully removed"));
    } else {
        QMessageBox::warning(this,tr("Warning"),tr("Unable to remove the driver!\n") + rc);
    }
    getConf();
    activateControls(addDriver|delDriver|reloadList|restoreDriver|quit|hwList|netconf);
}

void kndiswrapper::slot_findNDISProcessExited(){
    QString line;
    int start,end;

    line = findNDISProcess->readAllStandardOutput();

    if (line != "ndiswrapper:"){
        start=line.indexOf("/");
        end=line.indexOf(" ",start);
        end = end - start;
        line=line.mid(start,end);
        ndiswrapperPath = line;
        if (ndiswrapperPath == "") {
            QMessageBox::information(this,tr("Fatal Error"),tr("ndiswrapper not found.\nPlease install ndiswrapper before you proceed.\nProgram aborting!"));
            exit(1);
        }
        moduleLoadedCheckProcess->start("lsmod");
    } else {
        QMessageBox::information(this,tr("Fatal Error"),tr("ndiswrapper not found.\nPlease install ndiswrapper before you proceed.\nProgram aborting!"));
        exit(1);
    }

    getConf();
    moveButtonTimer->setSingleShot(true);
    moveButtonTimer->start(8);
    popupLogo->show();
    popupLogoTimer->start();
}

void kndiswrapper::slot_hardwareListRightClicked(const QPoint & pos){

    contextMenu->popup(hardwareList->mapToGlobal(pos));
}

void kndiswrapper::slot_moduleCheckRequested(){
    QString module;

    moduleCheckOutput = "";
    module = hardwareList->item(hardwareList->currentRow(),hardwareList->currentColumn())->text();
    if (module.indexOf("(alternate driver") > 0){
        moduleCheck->start("lsmod");
    } else {
        module=module.left(module.indexOf('\n'));
        if (module.indexOf(":") > 0) module = module.left(module.indexOf(':')-1);
        QMessageBox::information(this,tr("Attention"),tr("There is no alternativ driver for ") + module);
    }
}

void kndiswrapper::slot_moduleCheckProcessReadyReadStdout(){
    moduleCheckOutput = moduleCheckOutput + moduleCheck->readAllStandardOutput();
}

void kndiswrapper::slot_moduleCheckProcessExited(){
    int start,end;
    QString module;
    QString message = tr("A alternativ driver is loaded by the kernel. This may\nprevent ndiswrapper from working properly. ");
    message = message + tr("We have\nto remove the loaded kernel module and blacklist the\nkernel module so it");
    message = message + tr(" will not be loaded by the kernel again.\n\nShall I try to fix the problem for you?");

    module = hardwareList->item(hardwareList->currentRow(),hardwareList->currentColumn())->text();
    module=module.left(module.indexOf('\n'));
    start=module.indexOf("(alternate driver: ");
    start=start+19;
    end=module.indexOf(")");
    end=end-start;
    module=module.mid(start,end);

    moduleCheckOutput = moduleCheckOutput + moduleCheck->readAllStandardOutput();
    if (moduleCheckOutput.indexOf(module) >= 0){
        message = message + tr("\nHints:\n- I will do a : rmmod ") + module + tr("\n- enter the name of the module into /etc/modprobe.d/blacklist\n- and into /etc/modprobe.conf\n\n");
        int rc=QMessageBox::question(this,"Warning",message,QMessageBox::Yes,QMessageBox::No);
        if (rc == QMessageBox::Yes){
            activateControls(disabled);
            QProcess::execute("rmmod " + module);
            QString command="cp /etc/modprobe.d/blacklist.conf /etc/modprobe.d/blacklist.save"; // erstellen einer Sicherungskopie
            QProcess::execute(command);
            command = "cp /etc/modprobe.conf /etc/modprobe.conf.save"; // erstellen einer Sicherungskopie
            QProcess::execute(command);
// Feststellen, ob ein entsprechender Eintrag bereits in der Datei "blacklist" existiert ---> wenn nein, dann erstellen.
            command = "if [ -z \"`fgrep \"blacklist " + module + "\" /etc/modprobe.d/blacklist.conf`\" ]; then echo \"blacklist " + module + "\" >> /etc/modprobe.d/blacklist.conf; fi";
            QProcess::execute(command);
// Feststellen, ob ein entsprechender Eintrag bereits in der Datei modprobe.conf existiert ---> wenn nein, dann erstellen.
            command = "if [ -z \"`fgrep \"alias " + module + " off\" /etc/modprobe.conf`\" ]; then echo \"alias " + module + " off\" >> /etc/modprobe.conf; fi";
            QProcess::execute(command);
            activateControls(addDriver|delDriver|reloadList|restoreDriver|quit|hwList|netconf);
        }
    } else {
        QMessageBox::information(this,tr("Attention"),tr("No conflicting kernel modules are loaded!\n>>>>> erverything is fine <<<<<"));
    }
}

void kndiswrapper::activateControls(int state){
    (state & addDriver) == addDriver?addDriverButton->setEnabled(true):addDriverButton->setEnabled(false);
    (state & delDriver) == delDriver?removeDriverButton->setEnabled(true):removeDriverButton->setEnabled(false);
    (state & reloadList) == reloadList?reloadButton->setEnabled(true):reloadButton->setEnabled(false);
    (state & restoreDriver) == restoreDriver?restoreDriverButton->setEnabled(true):restoreDriverButton->setEnabled(false);
    (state & quit) == quit?quitButton->setEnabled(true):quitButton->setEnabled(false);
    (state & hwList) == hwList?hardwareList->setEnabled(true):hardwareList->setEnabled(false);
    if (!disablenetconf) (state & netconf) == netconf?configNetworkButton->setEnabled(true):configNetworkButton->setEnabled(false);
}

void kndiswrapper::slot_moduleLoadedCheckProcessExited(){
    QString line;
    int rc;

    line = moduleLoadedCheckProcess->readAllStandardOutput();

    if (line.indexOf("ndiswrapper") == -1){
        rc=QMessageBox::question(this,tr("WARNING"),tr("The ndiswrapper module is not loaded.\nndiswrapper will not be able to identify any hardware.\nShall I load the kernel module for you?"),QMessageBox::Yes,QMessageBox::No);
        if (rc == QMessageBox::Yes) {
            rc = system("modprobe ndiswrapper");
            if (rc != 0) QMessageBox::warning(this,tr("Warning"),tr("Loading of the kernel module (ndiswrapper) failed!"));
        }
    }
}

void kndiswrapper::slot_infoProcessRequested(){
    infoProcess->start("dmesg");
}

void kndiswrapper::slot_infoProcessExited(){
    QString line="";
    QString driverInfo;
    QString module;
    int start,end;
    QString tempString;
    QString nicName;

    module = hardwareList->currentItem()->text();
    module=module.left(module.indexOf('\n'));
    start=0;
    end=module.indexOf(" ");
    end=end-start;
    module=module.mid(start,end);
    while (infoProcess->canReadLine()){
        line = line + infoProcess->readLine()+"\n";
    }

    tempString="ndiswrapper: driver " + module;
    start = line.lastIndexOf(tempString);
    if (start != -1){
        end = line.indexOf('\n',start);
        end = end - start;
        driverInfo = line.mid(start,end);
        line=line.mid(start+end+1);
    } else {
        line = "";
    }
    tempString=": " + module;
    start = line.indexOf(tempString);
    start = line.lastIndexOf("\n",start);
    if (start == -1) start = 0;
    end = line.indexOf("\n",start);
    end = end - start;
    nicName = line.mid(start,line.indexOf(":",start)-start);
    if (nicName.indexOf("\n") != -1) nicName.replace(QChar('\n'),"");
    if (nicName == "") nicName = "Not configured!";
    driverInfo = "-------------------------------------------------------------\ndmesg-Info for " + module + " (" + nicName + ")\n-------------------------------------------------------------\n\n" + driverInfo + "\n" + line.mid(start,end);
    line = line.mid(start+end+1);

    start = line.indexOf(nicName+":");
    end = line.indexOf("\n",start);
    end=end-start;
    driverInfo = driverInfo + "\n" + line.mid(start,end);
    line = line.mid(start+end+1);

    tempString = "ndiswrapper: device " + nicName + " removed";
    if (line.indexOf(tempString) != -1) driverInfo = driverInfo + "\n" + tempString;

    QMessageBox::information(this,tr("dmesg-Info"),driverInfo);
}

void kndiswrapper::slot_configNetworkRequested(){
    configNetworkProcess->start("dmesg");
}

void kndiswrapper::slot_configNetworkProcessExited(){
    QString line="";
    QString module;
    int start,end;
    QString tempString;
    QString nicName;
    bool noInterface=true;

    if (hardwareList->currentRow() != -1){
        module = hardwareList->item(hardwareList->currentRow(),hardwareList->currentColumn())->text();
        module=module.left(module.indexOf('\n'));
        start=0;
        end=module.indexOf(" ");
        end=end-start;
        module=module.mid(start,end);
        line = line + configNetworkProcess->readAllStandardOutput()+"\n";

        tempString="ndiswrapper: driver " + module;
        start = line.lastIndexOf(tempString);
        end = line.indexOf('\n',start);
        end = end - start;
        line=line.mid(start+end+1);

        tempString=": " + module;
        start = line.indexOf(tempString);
        start = line.lastIndexOf("\n",start);
        if (start == -1) start = 0;
        end = line.indexOf("\n",start);
        end = end - start;
        nicName = line.mid(start,line.indexOf(":",start)-start);
        if (nicName.indexOf('\n') != -1) nicName.replace(QChar('\n'),"");

        line = line.mid(start+end+1);
        start = line.indexOf(nicName+":");
        end = line.indexOf("\n",start);
        end=end-start;

        line = line.mid(start+end+1);
        tempString = "ndiswrapper: device " + nicName + " removed";
        if (line.indexOf(tempString) == -1) noInterface = false;
        if ((nicName != "") && (noInterface == false)){
            wifiSetup * dialog = new wifiSetup(this,nicName);
            dialog->show();
        } else {
            QMessageBox::warning(this,tr("Warning"),tr("Can't start the network configuration! No interface found!"));
            if (debug){
                wifiSetup * dialog = new wifiSetup(this,"wlan0");
                dialog->show();
            }
        }
    }
}

void kndiswrapper::slot_buttonMoveTimerTimeout(){
int y;
int x;

    if (getConfFlag){
      x = removeDriverButton->x();

      y = removeDriverButton->y();
      if (removeDriverButtonEndPosition > y){
        y++;
        removeDriverButton->move(x,y);
      }

      y = reloadButton->y();
      if (reloadButtonEndPosition > y){
        y+=2;
        reloadButton->move(x,y);
      }

      y = restoreDriverButton->y();
      if (restoreDriverButtonEndPosition > y){
        y+=3;
        restoreDriverButton->move(x,y);
      }

      if (!disablenetconf){
        y = configNetworkButton->y();
        if (configNetworkButtonEndPosition > y){
          y+=4;
          configNetworkButton->move(x,y);
        }
      }

      y = quitButton->y();
      if (quitButtonEndPosition > y) {
        y+=5;
        quitButton->move(x,y);
        moveButtonTimer->setSingleShot(true);
        moveButtonTimer->start(6);
      }
  } else {
  	moveButtonTimer->setSingleShot(true);
        moveButtonTimer->start(6);
  }
}

void kndiswrapper::slot_wikiRequested(){
wikiLookup * hardwareInfo;

    hardwareInfo = new wikiLookup(this,1);
    hardwareInfo->exec();
}

void kndiswrapper::slot_popupLogoTimerTimeout(){
    popupLogo->hide();
}

//
