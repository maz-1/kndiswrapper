#include "wifistartup.h"
#include "ui_wifistartup.h"

wifiStartup::wifiStartup(QWidget *parent, QString scriptPath) : QDialog(parent), ui(new Ui::wifiStartup)
{
    script = scriptPath;
    ui->setupUi(this);

    scriptProcess = new QProcess(this);
    connect(scriptProcess,SIGNAL(readyRead()),this,SLOT(slot_scriptProcessCanReadStdout()));
    connect(scriptProcess,SIGNAL(finished(int)),this,SLOT(slot_scriptProcessExited()));
    connect(scriptProcess,SIGNAL(readyReadStandardError()),this,SLOT(slot_scriptProcessReadyReadStdError()));

}

wifiStartup::~wifiStartup()
{
    delete ui;
}

void wifiStartup::slot_startScriptButtonClicked(){
    ui->scriptOutput->setPlainText("");
    ui->doneButton->setEnabled(false);
    ui->exportScriptButton->setEnabled(false);
    ui->scriptOutput->setPlainText(tr("Starting Script: ") + script + "\n\n");
    scriptProcess->start(script);
}

void wifiStartup::slot_scriptProcessCanReadStdout(){
    QString output;
    output = ui->scriptOutput->toPlainText();
    while (scriptProcess->canReadLine()){
        output = output + scriptProcess->readLine() + "\n";
    }

    ui->scriptOutput->setPlainText(output);
    ui->scriptOutput->moveCursor(QTextCursor::End);

}

void wifiStartup::slot_scriptProcessReadyReadStdError(){
    QString output;
    output = ui->scriptOutput->toPlainText();
    output = output + scriptProcess->readAllStandardError() + "\n";

    ui->scriptOutput->setPlainText(output);
    ui->scriptOutput->moveCursor(QTextCursor::End);

}

void wifiStartup::slot_scriptProcessExited(){
    QString output = ui->scriptOutput->toPlainText();
    output = output + tr("\nDONE!");
    ui->scriptOutput->setPlainText(output);
    ui->doneButton->setEnabled(true);
    ui->exportScriptButton->setEnabled(true);
}

void wifiStartup::slot_doneButtonClicked(){
    this->done(0);
}

void wifiStartup::slot_exportScriptButtonClicked(){
int rc;
    QString s = QFileDialog::getExistingDirectory(this,tr("Choose a folder where to save" ),"/home");
    if (s != ""){
        rc = QProcess::execute("cp " + script + " " + s);
        rc == 0?QMessageBox::information(this,tr("Info"),tr("Script ") + script + tr(" saved at ") + s + " !"):QMessageBox::information(this,tr("Info"),("Saving of ") + script + tr(" failed!"));
    }
}
