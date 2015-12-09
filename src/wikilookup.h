#ifndef WIKILOOKUP_H
#define WIKILOOKUP_H

#include <QDialog>
#include <QTextEdit>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QProcess>
#include <QFile>
#include <QTextStream>
#include "ui_wikilookup.h"

namespace Ui {
    class wikiLookup;
}

class wikiLookup : public QDialog
{
    Q_OBJECT

public:
    wikiLookup(QWidget *parent = 0,int mode = 0);
    ~wikiLookup();

private:
    QProcess        * lsusbProcess;
    QString           workingCards;
    QString           cardsFound;
    int               modus;

private:
    Ui::wikiLookup *ui;

private slots:
  void slot_lsusbProcessExited();
  void slot_installButtonClicked();
  void slot_cancelButtonClicked();
  void slot_searchButtonClicked();
};

#endif // WIKILOOKUP_H
