#include "afuberechnungfrequenz.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungFrequenz::AfuBerechnungFrequenz(QWidget *parent) : QWidget(parent)

{
    QWidget *frequenzWidget = new QWidget();
    frequenzWidget->setGeometry(200, 100, 450, 150);

    // Erstelle Menue --> Berechnung --> ...
 //   menuBerechnung = menuBar()->addMenu(tr("Berechnung"));
    menuBerechnungBeenden = menuBerechnung->addAction("Beenden", this, SLOT(triggeredBeenden()));
    menuBerechnungBeenden->setIcon(QIcon::fromTheme("application-exit"));

    // erstelle Menue --> Hilfe --> ...
//    menuHilfe = menuBar()->addMenu(tr("Hilfe"));

}

void AfuBerechnungFrequenz::triggeredBeenden()
{
    close();
}
