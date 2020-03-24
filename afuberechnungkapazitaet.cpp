#include "afuberechnungkapazitaet.h"


// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungKapazitaet::AfuBerechnungKapazitaet(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeL = new QLabel("Eingabe Induktivität:");
    LabelEingabeF = new QLabel("Eingabe Frequenz:");
    LabelAusgabeC = new QLabel("Ergebnis Kapazität:");
    LabelLoesung = new QLabel();
    LabelLoesung->setStyleSheet("QLabel {background-color : lightgray; color : black;}");

    LabelEinheitC = new QLabel("pF");
    LabelEinheitF = new QLabel("MHz");
    LabelEinheitL = new QLabel("µH");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeL->setInputMask("00000.00");
    EditEingabeL->setCursorPosition(0);
    EditEingabeF = new QLineEdit;
    EditEingabeF->setInputMask("00000.00");
    EditEingabeF->setCursorPosition(0);

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelEingabeF, 0, 0);
    GridLayout->addWidget(EditEingabeF, 0, 2);
    GridLayout->addWidget(LabelEinheitF, 0, 3);
    GridLayout->addWidget(LabelEingabeL, 1, 0);
    GridLayout->addWidget(EditEingabeL, 1, 2);
    GridLayout->addWidget(LabelEinheitL, 1, 3);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(LabelAusgabeC, 5, 0);
    GridLayout->addWidget(LabelLoesung, 5, 2);
    GridLayout->addWidget(LabelEinheitC, 5, 3);
    GridLayout->addWidget(ButtonBerechnen, 6, 0);
    GridLayout->addWidget(ButtonLeeren, 6, 1);
    GridLayout->addWidget(ButtonBeenden, 6, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungKapazitaet::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungKapazitaet::triggeredButtonBerechnenClicked()
{
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeF->text().toFloat();
    f_PufferL = EditEingabeL->text().toFloat();

    f_PufferC = 1 / ((2 * f_Pi * f_PufferF) * (2 * f_Pi * f_PufferF) * f_PufferL) / 0.001;
   // f_PufferCC = (int)(f_PufferC*100+0.5)/100.0;
    f_PufferCC = f_PufferC * 1000;

    LabelLoesung->setNum(f_PufferCC);
    LabelLoesung->setFont(QFont("Arial", 10, QFont::Thin));
}

void AfuBerechnungKapazitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeF->clear();
    EditEingabeL->clear();
}
