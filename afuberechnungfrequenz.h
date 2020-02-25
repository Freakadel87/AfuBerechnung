#ifndef AFUBERECHNUNGFREQUENZ_H
#define AFUBERECHNUNGFREQUENZ_H

// Interne Includes

// Systeminterne Includes
#include <math.h>

// Qt Includes
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QFontDialog>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

class AfuBerechnungFrequenz : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungFrequenz(QWidget *parent);

    // Variablendeklaration
    double const d_Pi = 3.141592653589793238462643383279;
    double d_PufferC;
    double d_PufferL;
    double d_PufferF;

private:
    // Erstelle Textfelder
    QLabel *LabelEingabeL;
    QLabel *LabelEingabeC;
    QLabel *LabelAusgabeF;
    QLabel *LabelLoesung;

    QLabel *LabelEinheitL;
    QLabel *LabelEinheitC;
    QLabel *LabelEinheitF;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditEingabeL;
    QLineEdit *EditEingabeC;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGFREQUENZ_H
