#include "instwizard.h"
#include "ui_instwizard.h"

instWizard::instWizard(QWidget *parent, QString * driver) : QDialog(parent), ui(new Ui::instWizard)
{
QDir tempDir;
QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");
    ui->setupUi(this);
    QString delPath = configPath + (QString)"/temp";
    this->setWindowTitle(tr("KNDISWrapper Installation Wizard"));
    tempDir.rmdir(delPath);
    driverRC = driver;

    lsusbProcess = new QProcess(this);
    connect(lsusbProcess,SIGNAL(finished(int)),this,SLOT(slot_lsusbProcessExited()));

    ui->fileSelectButton->setToolTip(tr("Click to select a folder from where the search should start ..."));

    ui->wikiLookupButton->setToolTip(tr("Click to open the offline ndiswrapper wiki"));

    ui->startInstButton->setToolTip(tr("Start the installation of the selected windows driver."));

    ui->cancelInstButton->setToolTip(tr("Cancel the installation."));

    searchProcess = new QProcess(this);
    connect(searchProcess,SIGNAL(finished(int)),this,SLOT(slot_searchProcessExited()));

    searchProcess2 = new QProcess(this);
    connect(searchProcess2,SIGNAL(finished(int)),this,SLOT(slot_searchProcess2Exited()));

    QStringList horizontalHeaderLabel;
    horizontalHeaderLabel << tr("No.") << tr("Path");
    ui->resultTable->setHorizontalHeaderLabels(horizontalHeaderLabel);
    ui->resultTable->setSelectionBehavior(QAbstractItemView::SelectRows);

    lsusbProcess->start("lsusb");

}

instWizard::~instWizard()
{
    delete ui;
}

void instWizard::slot_lsusbProcessExited(){
QString line;
QString entry;
QStringList lst;
int pos;

  while (lsusbProcess->canReadLine()){
    line = lsusbProcess->readLine();
    pos = line.indexOf("ID ");
    entry = line.mid(pos+3);
    if (entry.indexOf("0000:0000")) lst << entry.trimmed();
  }
  ui->deviceComboBox->addItems(lst);
}

void instWizard::slot_fileSelectButtonClicked(){
    QString path = QFileDialog::getExistingDirectory(this,tr("Select the directory to start the search from ..."),"/home");

  ui->searchPath->setText(path);
}

void instWizard::slot_wikiLookupButtonClicked(){
wikiLookup * wiki = new wikiLookup(this,1);
  wiki->exec();
}

void instWizard::slot_startSearchButtonClicked(){
  ui->startSearchButton->setEnabled(false);
  ui->startInstButton->setEnabled(false);
  ui->cancelInstButton->setEnabled(false);
  while (ui->resultTable->rowCount() > 0) ui->resultTable->removeRow(0);
  QString command = "find " + ui->searchPath->text() + " -iname *.inf -print";
  searchProcess->start(command);
}

void instWizard::slot_searchProcessExited(){
QString line;
QString line2;
QString searchTerm="VID_" + ui->deviceComboBox->currentText().left(4) + "&PID_" + ui->deviceComboBox->currentText().mid(5,4);
QFile file;
bool found=false;

int count=1;

while (searchProcess->canReadLine()){
    found = false;
    line = searchProcess->readLine().trimmed();
    file.setFileName(line);
    if (file.open(QIODevice::ReadOnly|QIODevice::Text)){
      QTextStream stream(&file);
      while ((found == false) && (!stream.atEnd())){
        line2 = stream.readLine();
        if (line2.indexOf(searchTerm,0,Qt::CaseInsensitive) != -1){
          found = true;
        }
      }
    }
    file.close();
    if (found){
      ui->resultTable->insertRow(ui->resultTable->rowCount());
      // changed //
      ui->resultTable->setItem(ui->resultTable->rowCount()-1,0,new QTableWidgetItem(QString::number(count++)));
      ui->resultTable->setItem(ui->resultTable->rowCount()-1,1,new QTableWidgetItem(line));
    }
  }
  ui->possibleHitsLabel->setText(tr("Possible Hits : ") + QString::number(ui->resultTable->rowCount()));
  ui->startSearchButton->setEnabled(true);
  ui->cancelInstButton->setEnabled(true);
  ui->startInstButton->setEnabled(true);
}

void instWizard::slot_resultTableClicked(){
  ui->driverEdit->setText(ui->resultTable->item(ui->resultTable->currentRow(),1)->text());
}

void instWizard::slot_cancelInstButtonClicked(){
  this->done(QDialog::Rejected);
}

void instWizard::slot_startInstButtonClicked(){
bool ok=false;
QString serviceBinary;
QString line;
QString temp = ui->driverEdit->text();
int pos=temp.lastIndexOf("/");
QString path = temp.left(pos+1);
QString infFile = temp.mid(pos+1);

  if (ui->driverEdit->text() == ""){
    QMessageBox::information(this,tr("WARNING"),tr("You must select a driver from the list first!"));
  } else {
    QFile file(ui->driverEdit->text());
    if (file.open(QIODevice::ReadOnly)){
      QTextStream stream(&file);
      while (!stream.atEnd()){
        line = stream.readLine();
        if (line.indexOf("servicebinary",0,Qt::CaseInsensitive) != -1){
          pos = line.lastIndexOf("\\");
          serviceBinary=line.mid(pos+1);
          ok = QFile::exists(path+serviceBinary);
          if (!ok) {
            serviceBinary=line.mid(pos+1).toLower();
            ok = QFile::exists(path+serviceBinary);
          }
        }
      }
    }
    if (ok){
      *driverRC = ui->driverEdit->text();
      this->done(QDialog::Accepted);
    } else {
        QMessageBox::critical(this,tr("ERROR"),tr("The file \"") + serviceBinary + tr("\" is required and was not found in \"") + path + tr("\".\nI will try to find the file in the given searchpath (1 level up)."));
        tryAgain(path,infFile,serviceBinary);
    }
  }
}

void instWizard::tryAgain(QString infPath, QString infFile, QString serviceBinary){
QString temp = ui->searchPath->text();
QString path = temp;
QDir    tempDir;
QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");

  infFileGlobal = infFile;
  tempDir.mkdir((QString)"mkdir " + configPath + "/temp");
  QProcess::execute("cp " + infPath + "/" + infFile + " " + configPath + "/temp");
  ui->startSearchButton->setEnabled(false);

  if (temp.lastIndexOf("/") != -1) path = temp.left(temp.lastIndexOf("/"));

  QString command = "find " + path + " -iname " + serviceBinary + " -print";
  searchProcess2->start(command);
}

void instWizard::slot_searchProcess2Exited(){
QString line;
bool found = false;
QString configPath = QStandardPaths::standardLocations(QStandardPaths::ConfigLocation)[0] + QString("/kndiswrapper");

  while ((searchProcess2->canReadLine()) && (found == false)){
    line = searchProcess2->readLine();
    found = true;
    QString command = "cp " + line + " " + configPath + "/temp";
    QProcess::execute(command);
  }
  if (found){
    QMessageBox::information(this,tr("Attention"),tr("Found a matching file. Try to continue the installtion"));
    *driverRC = configPath + (QString)"/temp/" + infFileGlobal;
    this->done(QDialog::Accepted);
  } else {
    QMessageBox::information(this,tr("Attention"),tr("No matching file was found. Installation aborted!"));
    this->done(QDialog::Rejected);
  }
}
