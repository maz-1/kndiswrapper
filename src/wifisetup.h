#ifndef WIFISETUP_H
#define WIFISETUP_H

#include <QInputDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFileDialog>
#include <QProcess>
#include <QDialog>
#include <QTimer>
#include <QDir>
#include <QStandardPaths>
#include "wifistartup.h"

namespace Ui {
    class wifiSetup;
}

class wifiSetup : public QDialog
{
    Q_OBJECT

public:
    explicit wifiSetup(QWidget *parent = 0, QString iface = "");
    ~wifiSetup();

private:
    Ui::wifiSetup *ui;
    QString interface;
    QString basePath;
    QString wpa_supplicantPath;
    QString iwlistPath;
    QString iwconfigPath;
    QString dhclientPath;
    QString findResult;
    QString hostname;
    QString filePath;
    bool    validFlag;
    bool    changeFlag;
    QProcess      * scanProcess;
    QProcess      * find_wpa_supplicantProcess;
    QProcess      * find_iwlistProcess;
    QProcess      * find_iwconfigProcess;
    QProcess      * find_dhclientProcess;
    QProcess      * get_hostname;
    QProcess      * getSignalLevelProcess;
    QTimer        * getLevelTimer;
    void enableControls(bool);
    void loadConfig();
    bool checkValidHex(QString);
    bool checkIP(QString);
    bool checkNetMask();

private slots:
    void slot_find_wpa_supplicantProcessExited();
    void slot_keyTextChanged(QString);
    void slot_getSignalLevelProcessExited();
    void slot_find_iwconfigProcessExited();
    void slot_find_dhclientProcessExited();
    void slot_cryptComboBoxActivated(int);
    void slot_modeComboBoxActivated(int);
    void slot_find_iwlistProcessExited();
    void slot_getHostnameProcessExited();
    void slot_dhcpConfigButtonClicked();
    void slot_ipConfigButtonClicked();
    void slot_configGroupClicked(int);
    void slot_postConfButtonClicked();
    void slot_getLevelTimerTimeout();
    void slot_preConfButtonClicked();
    void slot_submitButtonClicked();
    void slot_radioButtonChanged();
    void slot_closeButtonClicked();
    void slot_scanButtonClicked();
    void slot_scanProcessExited();
    void slot_editButtonClicked();
    void slot_saveButtonClicked();
    void slot_delButtonClicked();
    void loadStage2(int);
};

#endif // WIFISETUP_H
