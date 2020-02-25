#include "afuberechnunginduktivitaet.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungInduktivitaet::AfuBerechnungInduktivitaet(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeF = new QLabel("Eingabe Frequenz:");
    LabelEingabeC = new QLabel("Eingabe Kapazität:");
    LabelAusgabeL = new QLabel("Ergebnis Induktivität:");
    LabelLoesung = new QLabel();

    LabelEinheitC = new QLabel("F");
    LabelEinheitF = new QLabel("MHz");
    LabelEinheitL = new QLabel("H");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeF = new QLineEdit;
    EditEingabeC = new QLineEdit;

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelEingabeC, 0, 0);
    GridLayout->addWidget(EditEingabeC, 0, 2);
    GridLayout->addWidget(LabelEinheitC, 0, 3);
    GridLayout->addWidget(LabelEingabeF, 1, 0);
    GridLayout->addWidget(EditEingabeF, 1, 2);
    GridLayout->addWidget(LabelEinheitF, 1, 3);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(LabelAusgabeL, 5, 0);
    GridLayout->addWidget(LabelLoesung, 5, 2);
    GridLayout->addWidget(LabelEinheitL, 5, 3);
    GridLayout->addWidget(ButtonBerechnen, 6, 0);
    GridLayout->addWidget(ButtonLeeren, 6, 1);
    GridLayout->addWidget(ButtonBeenden, 6, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungInduktivitaet::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungInduktivitaet::triggeredButtonBerechnenClicked()
{
    d_PufferF = 0.0000001 * EditEingabeF->text().toDouble();
    d_PufferC = 0.0000000000001 * EditEingabeC->text().toDouble();

    // Thomsonsche Schwingungsformel
    d_PufferL = 1 / ((2 * d_Pi * d_PufferF) * (2 * d_Pi * d_PufferF) * d_PufferC);
    LabelLoesung->setNum(d_PufferL);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungInduktivitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeF->clear();
}
