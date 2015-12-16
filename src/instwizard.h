#ifndef INSTWIZARD_H
#define INSTWIZARD_H

#include <QDialog>
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>
#include <QStandardPaths>
#include "wikilookup.h"

namespace Ui {
    class instWizard;
}

class instWizard : public QDialog
{
    Q_OBJECT

public:
    explicit instWizard(QWidget *parent = 0,QString * driver = 0);
    ~instWizard();
    QString            infFileGlobal;
    void tryAgain(QString, QString,QString);

private:
    Ui::instWizard *ui;
    QString        *driverRC;
    QProcess       *lsusbProcess;
    QProcess       *searchProcess;
    QProcess       *searchProcess2;
private slots:
    void slot_lsusbProcessExited();
    void slot_fileSelectButtonClicked();
    void slot_wikiLookupButtonClicked();
    void slot_startSearchButtonClicked();
    void slot_searchProcessExited();
    void slot_searchProcess2Exited();
    void slot_resultTableClicked();
    void slot_cancelInstButtonClicked();
    void slot_startInstButtonClicked();
};

#endif // INSTWIZARD_H
