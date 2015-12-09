#include "wikilookup.h"
#include "ui_wikilookup.h"

wikiLookup::wikiLookup(QWidget *parent,int mode) : QDialog(parent), ui(new Ui::wikiLookup)
{
    ui->setupUi(this);
// mode = 0 --> Installationsroutine
// mode = 1 --> Wiki Modus.
modus = mode;
QString path="/usr/share/kndiswrapper/cards_known_to_work.txt";
QFile file(path);
  this->setMinimumSize(700,300);
  if (file.open(QIODevice::ReadOnly)){
    QTextStream stream (&file);
    while (!stream.atEnd()){
      workingCards = workingCards + stream.readLine() + "\n";
    }
    file.close();
  }
  this->setWindowTitle("Offline Wiki");

  if (mode == 0) ui->cancelButton->setText(tr("cancel installation")); else ui->cancelButton->setText(tr("close window"));
  if (mode == 0) ui->installButton->setVisible(true); else ui->installButton->setVisible(false);

  lsusbProcess = new QProcess(this);
  connect(lsusbProcess,SIGNAL(finished(int)),this,SLOT(slot_lsusbProcessExited()));
  lsusbProcess->start("lsusb");
}


wikiLookup::~wikiLookup()
{
}

void wikiLookup::slot_lsusbProcessExited(){
QString line;
int start,stop,temp;
cardsFound="";

  while (lsusbProcess->canReadLine()){
    line=lsusbProcess->readLine();
    start = line.indexOf(":");
    if (start > 0){
      start = line.indexOf(":",start+1);
      start-=4;
      stop=9;
      line = line.mid(start,stop);
      start = 0;
      while (workingCards.indexOf(line,start,Qt::CaseInsensitive) != -1) {
        start = workingCards.indexOf(line,start,Qt::CaseInsensitive);
        start = workingCards.lastIndexOf("\n\n",start);
        if (start == -1) start=1;
        stop = workingCards.indexOf("\n\n",start + 2);
        temp = stop;
        stop = stop-start;
        cardsFound = cardsFound + workingCards.mid(start+2,stop-2) + "\n------------------------------------------------------------------\n";
        start = temp;
      }
    }
  }
  if (cardsFound == "")
    cardsFound = tr("Sorry. No information for your hardware found in the ndiswrapper wiki!");
  else
    cardsFound = "Information obtained from the ndiswrapper wiki page.\n\n------------------------------------------------------------------\n" + cardsFound + tr("\nTo continue the installation you must find the appropriate .inf-File. Maybe the information above from the ndiswrapper wiki gives you some help. The driver may be packed in an archiv file (*.cab, *.zip or even *.exe). Search for this files and try cabextrac for *.cab, unzip for *.zip and unshield for .exe files.\nGood luck.");

  ui->outputWindow->setPlainText(cardsFound);
  ui->searchButton->setFocus();
}

void wikiLookup::slot_installButtonClicked(){
  this->done(0);
}

void wikiLookup::slot_cancelButtonClicked(){
  this->done(-1);
}

void wikiLookup::slot_searchButtonClicked(){
QString line = ui->searchEdit->text();
int start,stop,temp;
cardsFound="";

  if (line == "") line = " ";
  start = 0;
  while (workingCards.indexOf(line,start,Qt::CaseInsensitive) != -1) {
      start = workingCards.indexOf(line,start,Qt::CaseInsensitive);
      start = workingCards.lastIndexOf("\n\n",start);
      if (start == -1) start=1;
      stop = workingCards.indexOf("\n\n",start + 2);
      temp = stop;
      stop = stop-start;
      cardsFound = cardsFound + workingCards.mid(start+2,stop-2) + "\n------------------------------------------------------------------\n";
      start = temp;
  }
  if (cardsFound == "")
    cardsFound = tr("Sorry. No information found for the keyword you enterd!");
  else
    cardsFound = cardsFound + tr("\nTo continue the installation you must find the appropriate .inf-File. Maybe the information above from the ndiswrapper wiki gives you some help. The driver may be packed in an archiv file (*.cab, *.zip or even *.exe). Search for this files and try cabextrac for *.cab, unzip for *.zip and unshield for .exe files.\nGood luck.");

  ui->outputWindow->setPlainText(cardsFound);
  ui->searchButton->setFocus();
}
