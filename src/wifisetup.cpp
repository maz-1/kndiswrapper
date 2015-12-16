#include "wifisetup.h"
#include "ui_wifisetup.h"

wifiSetup::wifiSetup(QWidget *parent, QString iface) : QDialog(parent), ui(new Ui::wifiSetup)
{
    interface = iface;
    changeFlag = false;
    ui->setupUi(this);
    ui->commentEdit->setToolTip(tr("Read this for further information about how to setup your wireless lan"));
    ui->confLabel->setToolTip(tr("If multiple configurations are found, you can select the active configuration"));
    ui->confComboBox->setToolTip(tr("If multiple configurations are found, you can select the active configuration"));
    ui->delButton->setToolTip(tr("Removes the actual configuration file"));
    ui->keyLengthLabel->setToolTip(tr("Shows the number of character and whether the key is valid (green) or not (red)"));
    ui->keyEdit->setToolTip(tr("Enter the hex-key or passphrase"));
    ui->essidComboBox->setToolTip(tr("Select a network or enter the ESSID manually"));
    ui->cryptComboBox->setToolTip(tr("Select which encryption mode you want to use"));
    ui->scanButton->setToolTip(tr("Scan for available networks"));
    ui->editButton->setToolTip(tr("Enter the name of your network (ESSID) manually"));
    ui->ipAddrEdit->setToolTip(tr("Enter the static IP-Addr of the interface (192.168.2.1)"));
    ui->netMaskEdit->setToolTip(tr("Enter the desired Netmask (255.255.255.0)"));
    ui->defaultRouteEdit->setToolTip(tr("(Optional) The IP Address of the Gateway (e.g. DSL Route to the internet)\nIf you have a working default Gateway you can ommit this field"));
    ui->DNSEdit->setToolTip(tr("Optional a DNS Entry for the /etc/resolv.conf file.\nIf you have a working DNS entry you can ommit this field."));
    ui->secondaryDNSEdit->setToolTip(tr("Optional a DNS Entry for the /etc/resolv.conf file.\nIf you have a working DNS entry you can ommit this field."));
    ui->preConfScriptEdit->setToolTip(tr("A script, that should be startet before the network configuration is done."));
    ui->postConfScriptEdit->setToolTip(tr("A script, that should be startet after the network configurationis done."));
    ui->preConfButton->setToolTip(tr("Select a script to run"));
    ui->postConfButton->setToolTip(tr("Select a script to run"));
    ui->saveButton->setToolTip(tr("Save the actual configuration"));
    ui->closeButton->setToolTip(tr("close this dialog window without doing anything"));
    ui->submitButton->setToolTip(tr("Try to activate the new network configuration"));
    ui->disableInterfaces->setToolTip(tr("Shut down all remaining interfaces."));
    ui->deviceLabel->setText("Device : " + interface);
    findResult = tr("Required Programms:\n\n");

    if (interface.indexOf('\n') != -1) interface.replace(QChar('\n'),"");
    
    QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
    basePath = configPath + "/netconf/" + interface;
    QDir tempDir(basePath);

    this->setWindowTitle("Wifi-Setup");

    if (tempDir.exists(basePath) == false) tempDir.mkdir(basePath);

    getLevelTimer = new QTimer(this);
    getLevelTimer->setSingleShot(true);
    getSignalLevelProcess = new QProcess(this);
    scanProcess = new QProcess(this);
    find_wpa_supplicantProcess = new QProcess(this);
    find_iwlistProcess = new QProcess(this);
    find_iwconfigProcess = new QProcess(this);
    find_dhclientProcess = new QProcess(this);
    get_hostname = new QProcess(this);

    connect(getLevelTimer,SIGNAL(timeout()),this,SLOT(slot_getLevelTimerTimeout()));
    connect(getSignalLevelProcess,SIGNAL(finished(int)),this,SLOT(slot_getSignalLevelProcessExited()));
    connect(scanProcess,SIGNAL(finished(int)),this,SLOT(slot_scanProcessExited()));
    connect(find_wpa_supplicantProcess,SIGNAL(finished(int)),this,SLOT(slot_find_wpa_supplicantProcessExited()));
    connect(find_iwlistProcess,SIGNAL(finished(int)),this,SLOT(slot_find_iwlistProcessExited()));
    connect(find_iwconfigProcess,SIGNAL(finished(int)),this,SLOT(slot_find_iwconfigProcessExited()));
    connect(find_dhclientProcess,SIGNAL(finished(int)),this,SLOT(slot_find_dhclientProcessExited()));
    connect(get_hostname,SIGNAL(finished(int)),this,SLOT(slot_getHostnameProcessExited()));

    emit slot_cryptComboBoxActivated(0);
    getLevelTimer->setSingleShot(true);
    getLevelTimer->start(1000);

    find_wpa_supplicantProcess->start("whereis wpa_supplicant");
}

wifiSetup::~wifiSetup()
{
    delete ui;
}

void wifiSetup::slot_scanButtonClicked(){
    enableControls(false);
    QString command = "/usr/sbin/iwlist " + interface + " scanning";
    scanProcess->start(command);
    changeFlag=true;
}

void wifiSetup::slot_scanProcessExited(){
    QString buffer="";
    int start,end;
    int hiddenCount=0;
    QString entry;

    while (scanProcess->canReadLine()) buffer = buffer + scanProcess->readLine() + "\n";
    if (buffer.indexOf("No scan results") != -1){
        if (QMessageBox::information(this,tr("Question"),tr("No network essid found. Do you want to enter a network essid manually"),QMessageBox::Yes,QMessageBox::No) == QMessageBox::Yes){
            ui->essidComboBox->clear();
            buffer="";
            buffer = QInputDialog::getText(this,tr("ESSID"),tr("Enter the ESSID of your network:"),QLineEdit::Normal,buffer,0);
            if (buffer != ""){
                ui->essidComboBox->addItem(buffer);
                ui->essidComboBox->setCurrentIndex(0);
            }
            if ((ui->essidComboBox->currentText() == "") && (ui->cryptComboBox->currentIndex() == 3)){
              ui->submitButton->setEnabled(false);
            } else {
              ui->submitButton->setEnabled(true);
            }
        }
    } else {
        ui->essidComboBox->clear();
        while (buffer.indexOf("ESSID:") >= 0){
            start = buffer.indexOf("ESSID:");
            start = start + 6;
            end = buffer.indexOf("\n",start);
            end = end-start;
            entry=buffer.mid(start+1,end-2);
            buffer=buffer.mid(start+end+7);
            if (entry != ""){
                ui->essidComboBox->addItem(entry);
            } else {
                hiddenCount++;
            }
        }
        if ((ui->essidComboBox->count() == 0) && (ui->cryptComboBox->currentIndex() == 3)){
          ui->submitButton->setEnabled(false);
        } else {
          ui->submitButton->setEnabled(true);
        }
        if (hiddenCount > 0) QMessageBox::information(this,tr("Info"),tr("There was at least one hidden cell found!"));
        ui->essidComboBox->setCurrentIndex(0);
    }
    enableControls(true);
    changeFlag=true;
}

void wifiSetup::enableControls(bool mode){
    ui->scanButton->setEnabled(mode);
    ui->modeComboBox->setEnabled(mode);
    ui->essidComboBox->setEnabled(mode);
    ui->cryptComboBox->setEnabled(mode);
    ui->editButton->setEnabled(mode);
}

void wifiSetup::slot_editButtonClicked(){
    QString buffer;
    ui->essidComboBox->clear();
    buffer = QInputDialog::getText(this,tr("ESSID"),tr("Enter the ESSID of your network:"),QLineEdit::Normal,buffer,0);
    if (buffer != ""){
        ui->essidComboBox->addItem(buffer);
        ui->essidComboBox->setCurrentIndex(0);
    }
    if ((ui->essidComboBox->currentText() == "") && (ui->cryptComboBox->currentIndex() == 3)){
      ui->submitButton->setEnabled(false);
    } else {
      ui->submitButton->setEnabled(true);
    }
    changeFlag=true;
}

void wifiSetup::slot_modeComboBoxActivated(int index){
    if (index == 1){ // is Ad-hoc
        if (ui->cryptComboBox->currentIndex() == 3) { // WPA-PSK
            ui->cryptComboBox->setCurrentIndex(0);
            ui->hexButton->setEnabled(true);
            ui->asciiButton->setEnabled(true);
            ui->passphraseButton->setEnabled(false);
            if (ui->passphraseButton->isChecked() == true) ui->hexButton->setChecked(true);
        }
        if (ui->modeComboBox->currentIndex() == 1) ui->cryptComboBox->removeItem(3);
    } else {
      if (ui->cryptComboBox->count() < 4) ui->cryptComboBox->addItem("WPA-PSK (WPA-Home)");
    }
    changeFlag=true;
    slot_keyTextChanged(ui->keyEdit->text());
}

void wifiSetup::slot_cryptComboBoxActivated(int index){

    if (index == 3) { // is WPA-PSK
        if (ui->modeComboBox->currentIndex() == 1){ // Ad-hoc
            ui->modeComboBox->setCurrentIndex(0);
            ui->hexButton->setEnabled(true);
            ui->asciiButton->setEnabled(false);
            ui->passphraseButton->setEnabled(true);
            ui->keyEdit->setEnabled(true);
            if (ui->asciiButton->isChecked() == true) ui->hexButton->setChecked(true);
        } else {
            ui->hexButton->setEnabled(true);
            ui->asciiButton->setEnabled(false);
            ui->passphraseButton->setEnabled(true);
            ui->keyEdit->setEnabled(true);
            if (ui->asciiButton->isChecked() == true) ui->hexButton->setChecked(true);
        }
    } else {
        if (index == 0){
          ui->hexButton->setEnabled(false);
          ui->asciiButton->setEnabled(false);
          ui->passphraseButton->setEnabled(false);
          ui->keyEdit->setEnabled(false);
        } else {
          ui->hexButton->setEnabled(true);
          ui->asciiButton->setEnabled(true);
          ui->passphraseButton->setEnabled(false);
          ui->keyEdit->setEnabled(true);
          if (ui->passphraseButton->isChecked() == true) ui->hexButton->setChecked(true);
        }
    }
    if ((ui->essidComboBox->currentText().length() == 0) && (ui->cryptComboBox->currentIndex() == 3)){
      ui->submitButton->setEnabled(false);
    } else {
      ui->submitButton->setEnabled(true);
    }
    slot_keyTextChanged(ui->keyEdit->text());
    changeFlag=true;
}

void wifiSetup::slot_keyTextChanged(QString text){
    int len=text.length();
    bool valid=false;

// ASCII Key (nur WEP)
    if (ui->asciiButton->isChecked() == true){
        if ((len == 5) || (len == 13)){
            valid=true;
        } else {
            valid=false;
        }
    } else {

    // HEX Key (WEP oder WPA)
        if (ui->hexButton->isChecked() == true){
            if (ui->cryptComboBox->currentIndex() == 3){
      // WPA
                len == 64?valid=true:valid=false;
            } else {
      // WEP
                ((len == 10) || (len == 26))?valid=true:valid=false;
            }
            if (valid) valid=checkValidHex(ui->keyEdit->text());
        } else {

      // Passphrase
            if (ui->passphraseButton->isEnabled() == true){
                ((len >= 8) && (len <= 63))?valid=true:valid=false;
            }
        }
    }

    if (ui->cryptComboBox->currentIndex() == 0) valid = true;

    valid==true?ui->keyLengthLabel->setPalette(QColor(Qt::green)):ui->keyLengthLabel->setPalette(QColor(Qt::red));
    valid==true?ui->submitButton->setEnabled(true):ui->submitButton->setEnabled(false);
    ui->keyLengthLabel->setText(QString::number(text.length()));
    validFlag = valid;
    changeFlag=true;
}


void wifiSetup::slot_ipConfigButtonClicked(){
    emit slot_configGroupClicked(0);
}

void wifiSetup::slot_dhcpConfigButtonClicked(){
    emit slot_configGroupClicked(1);
}

void wifiSetup::slot_configGroupClicked(int index){
    bool mode;

    index == 0?mode=true:mode=false;
    ui->ipAddrEdit->setEnabled(mode);
    ui->netMaskEdit->setEnabled(mode);
    ui->defaultRouteEdit->setEnabled(mode);
    ui->DNSEdit->setEnabled(mode);
    ui->secondaryDNSEdit->setEnabled(mode);
    changeFlag=true;
}

void wifiSetup::slot_closeButtonClicked(){
    if (changeFlag){
        int rc = QMessageBox::question(this,tr("Config changed"),tr("The configuration changed. Do you want to save the changes?"),QMessageBox::Yes,QMessageBox::No);
        if (rc == QMessageBox::Yes){
            slot_saveButtonClicked();
        }
    }

    this->reject();
}

void wifiSetup::loadConfig(){
QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
QDir tempDir(configPath + "/netconf/" + interface);
     QStringList namedFilters;
     namedFilters << "*.conf";
     tempDir.setNameFilters(namedFilters);
QStringList fileList = tempDir.entryList();
QString entry;

    for ( QStringList::Iterator it = fileList.begin(); it != fileList.end(); ++it ) {
        entry = *it;
        entry = entry.mid(0,entry.indexOf(".conf"));
        ui->confComboBox->addItem(entry);
    }
    if (ui->confComboBox->count() == 0) ui->confComboBox->addItem("wlan0");
    ui->confComboBox->setCurrentIndex(0);
    loadStage2(ui->confComboBox->currentIndex());
    changeFlag=false;
}

void wifiSetup::loadStage2(int entry){
QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
QString oldPath=configPath + "/netconf/" + ui->confComboBox->currentText() + ".conf";
int count=0;
QString line;
    entry = entry; // just to keep the compiler happy .... entry is not used.

    filePath=configPath + "/netconf/" + interface + "/" + ui->confComboBox->currentText() + ".conf";

    if (QFile::exists(oldPath)) QProcess::execute("mv " + oldPath + " " + filePath);
    QFile loadFile(filePath);
    if (loadFile.open(QIODevice::ReadOnly)){
        QTextStream stream(&loadFile);
        do {
            line = stream.readLine();
            switch (count){
                case 0  : line == "Managed"?ui->modeComboBox->setCurrentIndex(0):ui->modeComboBox->setCurrentIndex(1);
                            break;
                case 1  : ui->essidComboBox->clear();
                          ui->essidComboBox->addItem(line);
                          ui->essidComboBox->setCurrentIndex(0);
                            break;
                case 2  : if (line == "Off") {
                            ui->cryptComboBox->setCurrentIndex(0);
                            ui->hexButton->setEnabled(false);
                            ui->asciiButton->setEnabled(false);
                            ui->passphraseButton->setEnabled(false);
                            ui->keyEdit->setEnabled(false);
                          }
                          if (line == "WEP-Open") ui->cryptComboBox->setCurrentIndex(1);
                          if (line == "WEP-Shared Key") ui->cryptComboBox->setCurrentIndex(2);
                          if (line == "WPA-PSK (WPA-Home)") {
                            ui->cryptComboBox->setCurrentIndex(3);
                            ui->hexButton->setEnabled(true);
                            ui->asciiButton->setEnabled(false);
                            ui->passphraseButton->setEnabled(true);
                          } else {
                            ui->passphraseButton->setEnabled(false);
                          }
                            break;
                case 3  : if (line == "hex") ui->hexButton->setChecked(true);
                          if (line == "ascii") ui->asciiButton->setChecked(true);
                          if (line == "passphrase") ui->passphraseButton->setChecked(true);
                            break;
                case 4  : ui->keyEdit->setText(line);
                            break;
                case 5  : if (line == "dhcp") {
                            ui->dhcpConfig->setChecked(true);
                            ui->ipAddrEdit->setEnabled(false);
                            ui->netMaskEdit->setEnabled(false);
                            ui->defaultRouteEdit->setEnabled(false);
                            ui->DNSEdit->setEnabled(false);
                            ui->secondaryDNSEdit->setEnabled(false);
                          } else {
                            ui->ipConfig->setChecked(true);
                            ui->ipAddrEdit->setEnabled(true);
                            ui->netMaskEdit->setEnabled(true);
                            ui->defaultRouteEdit->setEnabled(true);
                            ui->DNSEdit->setEnabled(true);
                            ui->secondaryDNSEdit->setEnabled(true);
                          }
                            break;
                case 6  : ui->ipAddrEdit->setText(line);
                            break;
                case 7  : ui->netMaskEdit->setText(line);
                            break;
                case 8  : ui->defaultRouteEdit->setText(line);
                            break;
                case 9  : ui->DNSEdit->setText(line);
                            break;
                case 10  : ui->preConfScriptEdit->setText(line);
                            break;
                case 11  : ui->postConfScriptEdit->setText(line);
                            break;
                case 12  : ui->secondaryDNSEdit->setText(line);
                            break;
                case 13  : ui->nicknameEdit->setText(line);
                            break;
                case 14  : ui->channelComboBox->setCurrentIndex(ui->channelComboBox->findText(line));
                            break;
                case 15  : ui->bitRateComboBox->setCurrentIndex(ui->bitRateComboBox->findText(line));
                            break;
                case 16  : line=="true"?ui->disableInterfaces->setChecked(true):ui->disableInterfaces->setChecked(false);
                            break;
            }
            count++;
        } while (!line.isNull());
        loadFile.close();
        if ((ui->essidComboBox->currentText() == "") && (ui->cryptComboBox->currentIndex() == 3)){
          ui->submitButton->setEnabled(false);
        } else {
          ui->submitButton->setEnabled(true);
        }
    }
    changeFlag=false;
}

void wifiSetup::slot_saveButtonClicked(){
QString buffer = ui->confComboBox->currentText();

    buffer = QInputDialog::getText(this,tr("Save as"),tr("Save configuration as (press Enter to save it with its actual name):"),QLineEdit::Normal,buffer,0);
    if (buffer != ""){
      bool exist=false;
      for (int i=0;i<ui->confComboBox->count();i++){
        if (buffer == ui->confComboBox->itemText(i)) exist=true;
      }
      if (exist == false) {
        ui->confComboBox->addItem(buffer);
        ui->confComboBox->setCurrentIndex(ui->confComboBox->count()-1);
      }
      QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
      filePath = configPath + "/netconf/" + interface + "/" + buffer + ".conf";
      QFile saveFile(filePath);
      if (saveFile.open(QIODevice::WriteOnly)){
        QTextStream stream(&saveFile);
        stream << ui->modeComboBox->currentText() << "\n";
        stream << ui->essidComboBox->currentText() << "\n";
        stream << ui->cryptComboBox->currentText() << "\n";
        if (ui->hexButton->isChecked()) stream << "hex" << "\n";
        if (ui->asciiButton->isChecked()) stream << "ascii" << "\n";
        if (ui->passphraseButton->isChecked()) stream << "passphrase" << "\n";
        stream << ui->keyEdit->text() << "\n";
        if (ui->ipConfig->isChecked()) stream << "static" << "\n";
        if (ui->dhcpConfig->isChecked()) stream << "dhcp" << "\n";
        stream << ui->ipAddrEdit->text() << "\n";
        stream << ui->netMaskEdit->text() << "\n";
        stream << ui->defaultRouteEdit->text() << "\n";
        stream << ui->DNSEdit->text() << "\n";
        stream << ui->preConfScriptEdit->text() << "\n";
        stream << ui->postConfScriptEdit->text() << "\n";
        stream << ui->secondaryDNSEdit->text() << "\n";
        stream << ui->nicknameEdit->text() << "\n";
        stream << ui->channelComboBox->currentText() << "\n";
        stream << ui->bitRateComboBox->currentText() << "\n";
        ui->disableInterfaces->isChecked()==true?stream << "true\n":stream << "false\n";
        saveFile.close();
        QMessageBox::information(this,tr("Info"),tr("Configuration for ") + ui->confComboBox->currentText() + tr(" saved!"));
    } else {
        QMessageBox::information(this,tr("WARNING"),tr("Couldn't save the configuration. Unknown Error!"));
    }
  }
    changeFlag=false;
}

void wifiSetup::slot_find_wpa_supplicantProcessExited(){
    QString line;
    int start,end;

    while (find_wpa_supplicantProcess->canReadLine()){
        line = line + find_wpa_supplicantProcess->readLine();
    }

    if (line != "wpa_supplicant:"){
        start=line.indexOf("/");
        end=line.indexOf(" ",start);
        end = end - start;
        line=line.mid(start,end);
        wpa_supplicantPath = line;
        if (wpa_supplicantPath == "") {
            findResult = findResult + tr("wpa_supplicant not found. No WPA encryption available\n");
            ui->cryptComboBox->removeItem(3);
        } else {
            findResult = findResult + tr("wpa_supplicant found : ") + line + "\n";
        }
    } else {
        findResult = findResult + tr("wpa_supplicant not found. No WPA encryption available\n");
        ui->cryptComboBox->removeItem(3);
    }

    find_iwlistProcess->start("whereis iwlist");
}

void wifiSetup::slot_find_iwlistProcessExited(){
    QString line;
    int start,end;

    while (find_iwlistProcess->canReadLine()){
        line = line + find_iwlistProcess->readLine();
    }

    if (line != "iwlist:"){
        start=line.indexOf("/");
        end=line.indexOf(" ",start);
        end = end - start;
        line=line.mid(start,end);
        iwlistPath = line;
        if (iwlistPath == "") {
            findResult = findResult + ("iwlist not found. No network scanning possible.\n");
            ui->scanButton->setEnabled(false);
        } else {
            findResult = findResult + tr("iwlist found : ") + line + "\n";
        }
    } else {
        findResult = findResult + ("iwlist not found. No network scanning possible.\n");
        ui->scanButton->setEnabled(false);
    }

    find_iwconfigProcess->start("whereis iwconfig");
}

void wifiSetup::slot_find_iwconfigProcessExited(){
    QString line;
    int start,end;

    while (find_iwconfigProcess->canReadLine()){
        line = line + find_iwconfigProcess->readLine();
    }

    if (line != "iwconfig:"){
        start=line.indexOf("/");
        end=line.indexOf(" ",start);
        end = end - start;
        line=line.mid(start,end);
        iwconfigPath = line;
        if (iwconfigPath == "") {
            findResult = findResult + tr("iwconfig not found. No configuration of wlan possible.\n");
            ui->submitButton->setEnabled(false);
        } else {
            findResult = findResult + tr("iwconfig found : ") + line + "\n";
        }
    } else {
        findResult = findResult + tr("iwconfig not found. No configuration of wlan possible.\n");
        ui->submitButton->setEnabled(false);
    }

    get_hostname->start("hostname");
}

void wifiSetup::slot_getHostnameProcessExited(){

    while (get_hostname->canReadLine()){
        hostname = get_hostname->readLine();
    }

    find_dhclientProcess->start("whereis dhcpcd");
}

void wifiSetup::slot_find_dhclientProcessExited(){
    QString line;
    int start,end;

    while (find_dhclientProcess->canReadLine()){
        line = line + find_dhclientProcess->readLine();
    }

    if (line != "dhclient:"){
        start=line.indexOf("/");
        end=line.indexOf(" ",start);
        end = end - start;
        line=line.mid(start,end);
        dhclientPath = line;
        if (dhclientPath == "") {
            findResult = findResult + tr("dhcpcd not found. No dhcp configuration possible. Static IP only\n");
            ui->dhcpConfig->setEnabled(false);
        } else {
            findResult = findResult + tr("dhcpcd found : ") + line + "\n";
        }
    } else {
        ui->dhcpConfig->setEnabled(false);
        findResult = findResult + tr("dhcpcd not found. No dhcp configuration possible. Static IP only\n");
    }
    if (findResult.indexOf(tr("not found")) != -1)  QMessageBox::information(this,tr("Warning"),findResult);

    loadConfig();
}

bool wifiSetup::checkValidHex(QString value){
unsigned int pos=0;
bool valid=true;
QString checkString="01234567890abcdefABCDEF";

    while (pos < (unsigned int)value.length()){
        if (checkString.indexOf(value.mid(pos,1)) == -1) valid=false;
        pos++;
    }
    return valid;
}

bool wifiSetup::checkIP(QString ipAddress){
bool flag=false;
int ip1=256;
int ip2=256;
int ip3=256;
int ip4=256;
QString part;

    part = ipAddress.mid(0,ipAddress.indexOf("."));
    ip1 = part.toInt();
    ipAddress=ipAddress.mid(ipAddress.indexOf(".")+1);

    part = ipAddress.mid(0,ipAddress.indexOf("."));
    ip2 = part.toInt();
    ipAddress=ipAddress.mid(ipAddress.indexOf(".")+1);

    part = ipAddress.mid(0,ipAddress.indexOf("."));
    ip3 = part.toInt();
    ipAddress=ipAddress.mid(ipAddress.indexOf(".")+1);

    part = ipAddress.mid(0,ipAddress.indexOf("."));
    ip4 = part.toInt();
    ipAddress=ipAddress.mid(ipAddress.indexOf(".")+1);

    if (
        ((ip1 >=1) && (ip1 <=254)) &&
        ((ip2 >=0) && (ip2 <=255)) &&
        ((ip3 >=0) && (ip3 <=255)) &&
        ((ip4 >=1) && (ip4 <=254))
       ) flag = true;

  return flag;
}


bool wifiSetup::checkNetMask(){
bool flag=false;
int oct1=256;
int oct2=256;
int oct3=256;
int oct4=256;
QString netMask = ui->netMaskEdit->text();
QString part;

    part = netMask.mid(0,netMask.indexOf("."));
    oct1 = part.toInt();
    netMask=netMask.mid(netMask.indexOf(".")+1);

    part = netMask.mid(0,netMask.indexOf("."));
    oct2 = part.toInt();
    netMask=netMask.mid(netMask.indexOf(".")+1);

    part = netMask.mid(0,netMask.indexOf("."));
    oct3 = part.toInt();
    netMask=netMask.mid(netMask.indexOf(".")+1);

    part = netMask.mid(0,netMask.indexOf("."));
    oct4 = part.toInt();
    netMask=netMask.mid(netMask.indexOf(".")+1);

    if (
        ((oct1 >=128) && (oct1 <=255)) &&
        ((oct2 >=0) && (oct2 <=255)) &&
        ((oct3 >=0) && (oct3 <=255)) &&
        ((oct4 >=0) && (oct4 <=255))
       ) flag = true;

  return flag;
}

void wifiSetup::slot_submitButtonClicked(){
bool valid = true;
QString essidString = ui->essidComboBox->currentText();
    if (essidString == "") essidString="any";
    QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
    QString home = configPath + "/netconf";

    if (validFlag){
        QString scriptPath=home + "/ipup-" + interface + ".sh";
        QFile file(scriptPath);
        if (file.open(QIODevice::WriteOnly)){
            QTextStream stream(&file);
            stream << "#/bin/bash\n# Startup-Script for Interface " << interface << "\n\n";
            if (ui->preConfScriptEdit->text() != "") stream << ui->preConfScriptEdit->text() << "\n";
            stream << "echo \"- Shutting down interface " << interface << " ....\"\n";
            stream << "ifconfig " << interface << " down\n\n";
            if (ui->disableInterfaces->isChecked() == true){
              stream << "echo \"- Shutting down all unused interfaces ...\"\n";
              stream << "for device in `ls /proc/sys/net/ipv4/conf`; do if [ $device != \"all\" ] && [ $device != \"default\" ] && [ $device != \"lo\" ]; then ifconfig $device down; fi ; done\n";
            }
            if (ui->modeComboBox->currentIndex() == 0){
            // managed
                if (ui->cryptComboBox->currentIndex() != 3){
                // WEP
                    stream << "if [ -d \"/var/run/wpa_supplicant\" ]; then\n  echo \"- Stopping pre-existing wpa_supplicant\"\n  killproc wpa_supplicant\n  sleep 2\n  if [ -d /var/run/wpa_supplicant ];\n  then\n    echo \"- removing staled pid-file and folder ....\"\n    rm -rf /var/run/wpa_supplicant\n    sleep 1\n  fi\nfi\n";
                    stream << "echo \"- Setting up " << interface << " via iwconfig ....\"\n";
                    stream << "sleep 1\n";
                    stream << "iwconfig " << interface << " essid \"" << essidString << "\" mode " << ui->modeComboBox->currentText();
                    switch (ui->cryptComboBox->currentIndex()){
                    case 0  : stream << " key off ";
                                break;
                    case 1  : stream << " key open ";
                                break;
                    case 2  : stream << " key restricted ";
                                break;
                    }
                    if (ui->cryptComboBox->currentIndex() != 0) ui->asciiButton->isChecked() == true?stream << "s:" + ui->keyEdit->text():stream << ui->keyEdit->text();
                    stream << " commit\n\n";
                    if (ui->channelComboBox->currentText() != "auto"){
                      stream << "echo \"- Setting channel to " << ui->channelComboBox->currentText() << "\"\n";
                      stream << "iwconfig " << interface << " channel " << ui->channelComboBox->currentText() << "\n";
                    }
                    if (ui->nicknameEdit->text() != "") {
                      stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "\"\n";
                      stream << "iwconfig " << interface << " nickname " << ui->nicknameEdit->text() << "\n";
                    }
                    if (ui->bitRateComboBox->currentText() == "auto"){
                      stream << "echo \"- Setting BitRate to " << ui->bitRateComboBox->currentText() << "\"\n";
                      stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "\n";
                    } else {
                      stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "M\"\n";
                      stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "M\n";
                    }
                } else {
                // WPA-PSK
                    stream << "echo \"- Creating conf-file for wpa_supplicant ....\"\n# .... just for info. The Conf-File was already created by the gui\n";
                    stream << "sleep 1\n\n";
                    QString wpaConfFilename=configPath + "/wpa_supplicant-" + interface + ".conf";
                    QFile wpaConfFile(wpaConfFilename);
                    if (wpaConfFile.open(QIODevice::WriteOnly)){
                        QTextStream wpaStream(&wpaConfFile);
                        wpaStream << "ctrl_interface=/var/run/wpa_supplicant\nnetwork={\n  scan_ssid=1\n  ssid=\"" << essidString << "\"\n";
                        wpaStream << "  key_mgmt=WPA-PSK\n";
                        if (ui->hexButton->isChecked()){
                            wpaStream << "  psk=" << ui->keyEdit->text() << "\n}\n";
                        } else {
                            wpaStream << "  psk=\"" << ui->keyEdit->text() << "\"\n}\n";
                        }
                        wpaConfFile.close();
                    }
                    stream << "if [ -d \"/var/run/wpa_supplicant\" ]; then\n  echo \"- Stopping pre-existing wpa_supplicant\"\n  killproc wpa_supplicant\n  sleep 2\n  if [ -d /var/run/wpa_supplicant ];\n  then\n    echo \"- removing staled pid-file and folder ....\"\n    rm -rf /var/run/wpa_supplicant\n    sleep 1\n  fi\nfi\n";
                    stream << "echo \"- Starting up wpa_supplicant ....\"\n";
                    stream << "sleep 1\n";
                    stream << "wpa_supplicant -i" << interface << " -c" << wpaConfFilename << " -Dndiswrapper -P /var/run/wpa_supplicant/kndis-" << interface << ".pid -B\n\n";
                    if (ui->channelComboBox->currentText() != "auto"){
                      stream << "echo \"- Setting channel to " << ui->channelComboBox->currentText() << "\"\n";
                      stream << "iwconfig " << interface << " channel " << ui->channelComboBox->currentText() << "\n";
                    }
                    if (ui->nicknameEdit->text() != "") {
                      stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "\"\n";
                      stream << "iwconfig " << interface << " nickname " << ui->nicknameEdit->text() << "\n";
                    }
                    if (ui->bitRateComboBox->currentText() == "auto"){
                      stream << "echo \"- Setting BitRate to " << ui->bitRateComboBox->currentText() << "\"\n";
                      stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "\n";
                    } else {
                      stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "M\"\n";
                      stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "M\n";
                    }
                }
            } else {
            // ad-hoc
                stream << "echo \"- Setting up " << interface << " via iwconfig ....\"\n";
                stream << "sleep 1\n";
                if (ui->channelComboBox->currentText() != "auto"){
                  stream << "echo \"- Setting channel to " << ui->channelComboBox->currentText() << "\"\n";
                  stream << "iwconfig " << interface << " channel " << ui->channelComboBox->currentText() << "\n";
                }
                if (ui->nicknameEdit->text() != "") {
                  stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "\"\n";
                  stream << "iwconfig " << interface << " nickname " << ui->nicknameEdit->text() << "\n";
                }
                if (ui->bitRateComboBox->currentText() == "auto"){
                  stream << "echo \"- Setting BitRate to " << ui->bitRateComboBox->currentText() << "\"\n";
                  stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "\n";
                } else {
                  stream << "echo \"- Setting Nickname to " << ui->nicknameEdit->text() << "M\"\n";
                  stream << "iwconfig " << interface << " rate " << ui->bitRateComboBox->currentText() << "M\n";
                }
                stream << "iwconfig " << interface << " essid \"" << essidString << "\" mode " << ui->modeComboBox->currentText();
                switch (ui->cryptComboBox->currentIndex()){
                case 0  : stream << " key off ";
                            break;
                case 1  : stream << " key open ";
                            break;
                case 2  : stream << " key restricted ";
                            break;
                }
                if (ui->cryptComboBox->currentIndex() != 0) ui->asciiButton->isChecked() == true?stream << "s:" + ui->keyEdit->text():stream << ui->keyEdit->text();
                stream << " commit\n\n";
            }
            // IP-Config oder dhcp
            if (ui->dhcpConfig->isChecked()){
                stream << "echo \"- terminating existing dhcpcd .... if exist\"\n";
                stream << "killproc dhcpcd\n";
                stream << "rm /var/run/dhcpcd-" << interface << ".*\n";
                stream << "sleep 1\n\n";
                stream << "echo \"- Setting up interface " << interface << " via dhcpcd .... timeout 30 sec.\"\n";
                stream << "sleep 1\n";
                stream << "ip link set " << interface << " up\n";
                stream << "sleep 1\n";
                stream << "dhcpcd -R -N -t 999999 -h " << hostname << " " << interface << " &\n";
                stream << "for ((i=0;i<30;i++)); do\n  x=\".\"\n  if [ -e /var/run/dhcpcd-" << interface << ".pid ]; then continue\n  else\n    sleep 1\n  fi\ndone\n";
                stream << "if [ ! -e /var/run/dhcpcd-" << interface << ".pid ]; then\n  echo \"- no IP address yet ..... backgrounding.\"\nelse\necho \"- interface set via dhcp\"\nfi\n\n";
            } else {
                if (checkIP(ui->ipAddrEdit->text()) == false){
                  valid=false;
                  QMessageBox::information(this,"ERROR","The IP-Address you entered is not valid!");
                }
                if ((valid) && (checkNetMask() == false)){
                  valid=false;
                  QMessageBox::information(this,"ERROR","The NetMask you entered is not valid!");
                }
                if (ui->defaultRouteEdit->text().length() > 0){
                  if ((valid) && (checkIP(ui->defaultRouteEdit->text()) == false)){
                    valid=false;
                    QMessageBox::information(this,"ERROR","The default Route-Address you entered is not valid!");
                  }
                }

                if (ui->DNSEdit->text().length() > 0){
                  if ((valid) && (checkIP(ui->DNSEdit->text()) == false)){
                    valid=false;
                    QMessageBox::information(this,"ERROR","The DNS-Address you entered is not valid!");
                  }
                }
                stream << "echo \"- Setting up interface " << interface << " via ifconfig ....\"\n";
                stream << "sleep 1\n";
                stream << "ifconfig " << interface << " " << ui->ipAddrEdit->text() << " netmask " << ui->netMaskEdit->text() << " up\n\n";
                if (ui->defaultRouteEdit->text() != "") {
                    stream << "echo \"- Adding default gateway " << ui->defaultRouteEdit->text() << "\"\n";
                    stream << "route add default gw " << ui->defaultRouteEdit->text() << "\n\n";
                }
                if (ui->DNSEdit->text() != ""){
                    if (ui->disableInterfaces->isChecked() == false){
                      stream << "rc=`cat /etc/resolv.conf | grep \"nameserver " << ui->DNSEdit->text() << "\"`\n";
                      stream << "if [ -z \"$rc\" ];\nthen\n  echo \"nameserver " << ui->DNSEdit->text() << "\" >> /etc/resolv.conf\nfi\n";
                      if (ui->secondaryDNSEdit->text() != ""){
                        stream << "rc=`cat /etc/resolv.conf | grep \"nameserver " << ui->secondaryDNSEdit->text() << "\"`\n";
                        stream << "if [ -z \"$rc\" ];\nthen\n  echo \"nameserver " << ui->secondaryDNSEdit->text() << "\" >> /etc/resolv.conf\nfi\n";
                      }
                    } else {
                      stream << "echo \"nameserver " << ui->DNSEdit->text() << "\" > /etc/resolv.conf\n";
                      if (ui->secondaryDNSEdit->text() != ""){
                        stream << "echo \"nameserver " << ui->secondaryDNSEdit->text() << "\" >> /etc/resolv.conf\nfi\n";
                      }
                    }
                }
            }

            if (ui->postConfScriptEdit->text() != "") stream << ui->postConfScriptEdit->text() << "\n";

            file.close();
            QProcess::execute("chmod 777 " + scriptPath);
            if (valid){
              wifiStartup * startup = new wifiStartup(this,scriptPath);
              startup->show();
            }
        }
    } else {
        QMessageBox::information(this,tr("WARNING"),tr("invalid Key. Can not create config file"));
    }
}

void wifiSetup::slot_delButtonClicked(){
  if (ui->confComboBox->currentText() != ""){
    int rc = QMessageBox::question(this,tr("WARNING"),tr("Do you realy want to remove the config-file for ") + ui->confComboBox->currentText(),QMessageBox::Yes,QMessageBox::No);
    if (rc == QMessageBox::Yes){
      QFile tempFile(filePath);
      tempFile.remove();
      ui->confComboBox->clear();
      loadConfig();
    }
  }
  changeFlag=false;
}

void wifiSetup::slot_preConfButtonClicked(){
QString Buffer = QFileDialog::getOpenFileName(this,tr("Select the pre config script."),"/","all(*)");
  ui->preConfScriptEdit->setText(Buffer);
  changeFlag=true;
}

void wifiSetup::slot_postConfButtonClicked(){
QString Buffer = QFileDialog::getOpenFileName(this,tr("Select the post config script."),"/","all(*)");
  ui->postConfScriptEdit->setText(Buffer);
  changeFlag=true;
}

void wifiSetup::slot_getLevelTimerTimeout(){
  getSignalLevelProcess->start(iwconfigPath + " " + interface);
}

void wifiSetup::slot_getSignalLevelProcessExited(){
QString output;
QString helperString;
int start,end;
int signal,noise;

  while (getSignalLevelProcess->canReadLine()){
    output = output + getSignalLevelProcess->readLine() + "\n";
  }
  start = output.indexOf("Link");
  start = output.indexOf(":",start) + 1;
  end = output.indexOf("/100",start) - start;
  helperString = output.mid(start,end);
  ui->signalLevel->setValue(output.mid(start,end).toInt());

  if (ui->signalLevel->value() > 0){
    start = output.indexOf("Bit Rate=") + 9;
    end = output.indexOf("Mb/s",start)-start;
    helperString = output.mid(start,end);
    ui->bitRateValueLabel->setText("Bit Rate : " + output.mid(start,end) + " Mb/s");
  } else {
    ui->bitRateValueLabel->setText("Bit Rate : n/a");
  }
  start = output.indexOf("Signal level:") + 13;
  end = output.indexOf("dBm",start) - start;
  signal = output.mid(start,end).toInt();

  start = output.indexOf("Noise level:") + 12;
  end = output.indexOf("dBm",start) - start;
  noise = output.mid(start,end).toInt();

  signal = signal - noise;

  if (signal < 15) {
    ui->signalQualityLabel->setPalette(Qt::red);
    ui->signalQualityLabel->setText(tr("Signal Qual. : bad"));
  }
  if ((signal >= 15) && (signal < 20)) {
    ui->signalQualityLabel->setPalette(QColor("#ff945f"));
    ui->signalQualityLabel->setText(tr("Signal Qual. : medium"));
  }
  if ((signal >= 20) && (signal < 25)) {
    ui->signalQualityLabel->setPalette(Qt::yellow);
    ui->signalQualityLabel->setText(tr("Signal Qual. : good"));
  }
  if (signal >= 25) {
    ui->signalQualityLabel->setPalette(Qt::green);
    ui->signalQualityLabel->setText(tr("Signal Qual. : excellent"));
  }

  getLevelTimer->start(2000);
}

void wifiSetup::slot_radioButtonChanged(){
    changeFlag=true;
    emit slot_keyTextChanged(ui->keyEdit->text());
}
