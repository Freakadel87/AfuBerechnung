#include "afuberechnungkapazitaet.h"

// Destruktor
//AfuBerechnungKapazitaet::~AfuBerechnungKapazitaet()
//{

//}

AfuBerechnungKapazitaet::AfuBerechnungKapazitaet(QWidget *parent) : QWidget(parent)
{
    // Erstelle Menue --> Berechnung --> ...
//    menuDatei = new QMenuBar(this);

//    //menuDatei = menuBar()->addMenu("Datei");
//    actionDateiBerechnen = menuDatei->addAction("Berechnen", this, SLOT(triggeredButtonBerechnenClicked()));
//    actionDateiLeeren = menuDatei->addAction("Felder leeren", this, SLOT(triggeredButtonLeerenClicked()));
//    menuDatei->addSeparator();
//    actionDateiBeenden = menuDatei->addAction("Beenden", this, SLOT(triggeredActionBeenden()));
//    actionDateiBeenden->setIcon(QIcon::fromTheme("application-exit"));

    QGridLayout *GridLayout = new QGridLayout;
    GridLayout->addWidget(LabelEingabeF, 0, 0);
    GridLayout->addWidget(LabelEingabeL, 1, 0);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(ButtonBeenden, 5, 0);
    GridLayout->addWidget(ButtonBerechnen, 5, 1);
    GridLayout->addWidget(ButtonLeeren, 5, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
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

void AfuBerechnungKapazitaet::triggeredActionBeenden()
{
    close();
}
