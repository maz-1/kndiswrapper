#include "setupdialog.h"
#include "ui_setupdialog.h"

setupDialog::setupDialog(QWidget *parent) : QDialog(parent), ui(new Ui::setupDialog)
{
QStringList filters;
            filters << "*.qm";

QDir tempDir("/usr/share/kndiswrapper");
     tempDir.setNameFilters(filters);
QStringList fileList = tempDir.entryList();
QString homePath = (QString)getenv("HOME");

    ui->setupUi(this);
    if (QFile::exists(homePath + "/.kndiswrapper") == false){
            tempDir.mkdir(homePath + "/.kndiswrapper");
    }

    if (QFile::exists(homePath + "/.kndiswrapper/netconf") == false){
            tempDir.mkdir(homePath + "/.kndiswrapper/netconf");
    }

    if (QFile::exists(homePath + "/.kndiswrapper/backup") == false){
            tempDir.mkdir(homePath + "/.kndiswrapper/backup");
    }
    ui->languageSelectComboBox->addItems(fileList);
}

setupDialog::~setupDialog()
{
    delete ui;
}


QString setupDialog::getResult(){
    return result;
}

void setupDialog::slot_doneButtonClicked(){
    result = ui->languageSelectComboBox->currentText();
    this->accept();
}
