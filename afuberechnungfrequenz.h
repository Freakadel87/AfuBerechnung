#ifndef AFUBERECHNUNGFREQUENZ_H
#define AFUBERECHNUNGFREQUENZ_H

// Interne Includes
//#include "afuberechnung.h"

// Systeminterne Includes
#include <math.h>
#include <sstream>
#include <iomanip>

// Qt Includes
#include <QWidget>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QIcon>

class AfuBerechnungFrequenz : public QWidget
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungFrequenz(QWidget *parent);
// Variablendeklaration
double const d_Pi = 3.141592653589793238462643383279;

private:
QMenu *menuBerechnung;
QAction *menuBerechnungBeenden;

QMenu *menuHilfe;

private slots:
void triggeredBeenden();


};
#endif // AFUBERECHNUNGFREQUENZ_H
