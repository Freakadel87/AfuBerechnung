#include "afuberechnungamateurfunkbaender.h"

AfuBerechnungAmateurfunkBaender::AfuBerechnungAmateurfunkBaender(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    Layout = new QVBoxLayout(this);
    LabelEingabe = new QLabel(tr("Amateurfunkfrequenzen:"));
    LabelEingabe->setFont(QFont("Arial", 11, QFont::Normal));

    EditText = new QTextEdit;
    EditText->setFont(QFont("Arial", 11, QFont::Normal));
    EditText->clear();
    EditText->setReadOnly(true);
    EditText->setText("2.200m = 0,137 - 0,1378 MHz\n"
                      "630m = 0,472 - 0,479 MHz\n"
                      "160m = 1,80 - 2,00 MHz\n"
                      "80m = 3,50 - 3,80 MHz\n"
                      "60m = 5,3515 - 5,3665 MHz\n"
                      "40m = 7,00 - 7,20 MHz\n"
                      "30m = 10,10 - 10,15 MHz\n"
                      "20m = 14,00 14,35 MHz\n"
                      "17m = 18,069 - 18,168 MHz\n"
                      "15m = 21,00 - 21,45 MHz\n"
                      "12m = 24,89 - 24,99 MHz\n"
                      "10m = 28,00 - 29,70 MHz\n"
                      "6m = 50,00 - 52,00 MHz\n"
                      "4m = 70,00 - 70,50 MHz\n"
                      "2m = 144,00 - 146,00 MHz\n"
                      "70cm = 430,00 - 440,00 MHz\n"
                      "23cm = 1,24 - 1,30 GHz\n"
                      "13cm = 2,32 - 2,45 GHz\n"
                      "9cm = 3,40 - 3475 GHz\n"
                      "6cm = 5,56 - 5,85 GHz\n"
                      "3cm = 10,00 - 10,50 GHz\n"
                      "1,2cm = 24,00 - 24,25 GHz\n"
                      "6mm = 47,00 - 47,20 GHz\n"
                      "4mm = 75,50 - 81,50 GHz\n"
                      "2,5mm = 122,25 - 123,00 GHz\n"
                      "2mm = 134,00 - 141,00 GHz\n"
                      "1,2mm = 241,00 - 250,00 GHz");

    ButtonSchliessen = new QPushButton(tr("Schließen"));
    ButtonSchliessen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSchliessen->setFont(QFont("Arial", 11, QFont::Normal));

    Layout->addWidget(LabelEingabe);
    Layout->addWidget(EditText);
    Layout->addWidget(ButtonSchliessen);

    // Erstelle Verbindung fuer Button
    QObject::connect(ButtonSchliessen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchliessenClicked()));
}

void AfuBerechnungAmateurfunkBaender::triggeredButtonSchliessenClicked()
{
    close();
}
