#include "afuberechnungfrequenz.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungFrequenz::AfuBerechnungFrequenz(QWidget *parent) : QWidget(parent)
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
    GridLayout->addWidget(LabelEingabeC, 0, 0);
    GridLayout->addWidget(LabelEingabeL, 1, 0);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(ButtonBeenden, 5, 0);
    GridLayout->addWidget(ButtonBerechnen, 5, 1);
    GridLayout->addWidget(ButtonLeeren, 5, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungFrequenz::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungFrequenz::triggeredButtonBerechnenClicked()
{
    d_PufferC = 0.0000001 * EditEingabeC->text().toDouble();
    d_PufferL = 0.0000000000001 * EditEingabeL->text().toDouble();

    // Thomsonsche Schwingungsformel
    d_PufferF = 1 / (2 * d_Pi * sqrt(d_PufferL * d_PufferC));
    LabelLoesung->setNum(d_PufferF);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungFrequenz::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeL->clear();
}

void AfuBerechnungFrequenz::triggeredActionBeenden()
{
    close();
}
