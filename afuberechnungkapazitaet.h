#ifndef AFUBERECHNUNGKAPAZITAET_H
#define AFUBERECHNUNGKAPAZITAET_H

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
#include <QFont>
#include <QMessageBox>
#include <QComboBox>

class AfuBerechnungKapazitaet : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungKapazitaet(QWidget *parent);

    // Variablendeklaration
    float const f_Pi = 3.141592653589793238462643383279;

private:
    // Erstelle Textfelder
    QLabel *LabelEingabeL;
    QLabel *LabelEingabeF;
    QLabel *LabelAusgabeC;
    QLabel *LabelLoesung;

    QComboBox *ComboEinheitL;
    QComboBox *ComboEinheitF;
    QLabel *LabelEinheitC;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditEingabeL;
    QLineEdit *EditEingabeF;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGKAPAZITAET_H
