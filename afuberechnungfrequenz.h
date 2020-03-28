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
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QFont>
#include <QMessageBox>

class AfuBerechnungFrequenz : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungFrequenz(QWidget *parent);

    // Variablendeklaration
    float const d_Pi = 3.141592653589793238462643383279;
    float d_PufferC;
    float d_PufferL;
    float d_PufferF;
    float d_PufferFF;

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
