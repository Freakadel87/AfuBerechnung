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

    LabelEinheitC = new QLabel("F");
    LabelEinheitF = new QLabel("MHz");
    LabelEinheitL = new QLabel("H");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeF = new QLineEdit;

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
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
    d_PufferF = 0.0000001 * EditEingabeF->text().toDouble();
    d_PufferL = 0.0000000000001 * EditEingabeL->text().toDouble();

    // Thomsonsche Schwingungsformel
    d_PufferC = 1 / ((2 * d_Pi * d_PufferF) * (2 * d_Pi * d_PufferF) * d_PufferL);
    LabelLoesung->setNum(d_PufferC);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungKapazitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeF->clear();
    EditEingabeL->clear();
}
