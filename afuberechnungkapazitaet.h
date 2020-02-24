#ifndef AFUBERECHNUNGKAPAZITAET_H
#define AFUBERECHNUNGKAPAZITAET_H
// Interne Includes

// Systeminterne Includes
#include <math.h>

// Qt Includes
#include <QAction>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QMenuBar>
#include <QMenu>
#include <QIcon>

class AfuBerechnungKapazitaet : public QWidget//(parent) QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungKapazitaet(QWidget *parent);

// Variablendeklaration
double const d_Pi = 3.141592653589793238462643383279;
double d_PufferC;
double d_PufferL;
double d_PufferF;

private:
// Erstelle Menue --> Berechnung --> ...
QMenuBar *menuDatei;
QAction *actionDateiBerechnen;
QAction *actionDateiBeenden;
QAction *actionDateiLeeren;

// Erstelle Menue --> Hilfe --> ...
QMenu *menuHilfe;
QAction *actionHilfeInfo;

// Erstelle Textfelder
QLabel *LabelEingabeL = new QLabel("Eingabe Induktivität");
QLabel *LabelAusgabeC = new QLabel("Ergebnis Kapazität");
QLabel *LabelEingabeF = new QLabel("Eingabe Frequenz");
QLabel *LabelLoesung = new QLabel();

// Erstelle Ein- und Ausgabefelder
QLineEdit *EditEingabeL = new QLineEdit;
QLineEdit *EditEingabeF = new QLineEdit;

// Erstelle Buttons
QPushButton *ButtonBeenden = new QPushButton("Beenden");
QPushButton *ButtonBerechnen = new QPushButton("Berechnen");
QPushButton *ButtonLeeren = new QPushButton("Leeren");

private slots:
void triggeredButtonBeendenClicked();
void triggeredButtonBerechnenClicked();
void triggeredButtonLeerenClicked();

void triggeredActionBeenden();

};
#endif // AFUBERECHNUNGKAPAZITAET_H
