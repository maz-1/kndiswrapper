#ifndef SETUPDIALOG_H
#define SETUPDIALOG_H

#include <QDialog>
#include <QDir>

namespace Ui {
    class setupDialog;
}

class setupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit setupDialog(QWidget *parent = 0);
    ~setupDialog();
    QString getResult();

private:
    Ui::setupDialog *ui;
    QString result;

private slots:
    void slot_doneButtonClicked();

};

#endif // SETUPDIALOG_H
