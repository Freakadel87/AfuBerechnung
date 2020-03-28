#include "afuberechnungwattdbm.h"

AfuBerechnungWattDbm::AfuBerechnungWattDbm(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    Layout = new QVBoxLayout(this);
    LabelEingabe = new QLabel("Tabelle Umrechnung Watt --> dBm:");
    LabelEingabe->setFont(QFont("Arial", 11, QFont::Normal));

    EditText = new QTextEdit;
    EditText->setFont(QFont("Arial", 11, QFont::Normal));
    EditText->clear();
    EditText->setReadOnly(true);
    EditText->setText("  0 dBm = 0,001 W\n"
                      "  3 dBm = 0,002 W\n"
                      "  7 dBm = 0,005 W\n"
                      "10 dBm = 0,01 W\n"
                      "13 dBm = 0,02 W\n"
                      "17 dBm = 0,05 W\n"
                      "20 dBm = 0,1 W\n"
                      "23 dBm = 0,2 W\n"
                      "27 dBm = 0,5 W\n"
                      "30 dBm = 1 W\n"
                      "33 dBm = 2 W\n"
                      "37 dBm = 5 W\n"
                      "40 dBm = 10 W\n"
                      "43 dBm = 20 W\n"
                      "47 dBm = 50 W\n"
                      "50 dBm = 100 W\n"
                      "53 dBm = 200 W\n"
                      "57 dBm = 500 W\n"
                      "60 dBm = 1.000 W\n");

    ButtonSchliessen = new QPushButton("Schließen");
    ButtonSchliessen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSchliessen->setFont(QFont("Arial", 11, QFont::Normal));

    Layout->addWidget(LabelEingabe);
    Layout->addWidget(EditText);
    Layout->addWidget(ButtonSchliessen);

    // Erstelle Verbindung fuer Button
    QObject::connect(ButtonSchliessen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchliessenClicked()));
}

void AfuBerechnungWattDbm::triggeredButtonSchliessenClicked()
{
    close();
}
