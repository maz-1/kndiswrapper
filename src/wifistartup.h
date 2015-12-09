#ifndef WIFISTARTUP_H
#define WIFISTARTUP_H

#include <QDialog>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>

namespace Ui {
    class wifiStartup;
}

class wifiStartup : public QDialog
{
    Q_OBJECT

public:
    explicit wifiStartup(QWidget *parent = 0, QString scriptPath = "");
    ~wifiStartup();

private:
    Ui::wifiStartup *ui;
    QString          script;
    QProcess        *scriptProcess;

private slots:
    void slot_scriptProcessCanReadStdout();
    void slot_scriptProcessReadyReadStdError();
    void slot_exportScriptButtonClicked();
    void slot_startScriptButtonClicked();
    void slot_scriptProcessExited();
    void slot_doneButtonClicked();
};

#endif // WIFISTARTUP_H
