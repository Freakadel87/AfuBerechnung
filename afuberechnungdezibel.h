#ifndef AFUBERECHNUNGDEZIBEL_H
#define AFUBERECHNUNGDEZIBEL_H

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

extern bool G_bDezibelLeistung;
extern bool G_bDezibelSpannung;

class AfuBerechnungDezibel : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungDezibel(QWidget *parent);

private:
    // Erstelle Textfelder
    QLabel *LabelEingangsLeistungP1;
    QLabel *LabelAusgangsLeistungP2;
    QLabel *LabelEingangsSpannungU1;
    QLabel *LabelAusgangsSpannungU2;
    QLabel *LabelAusgabeText;
    QLabel *LabelAusgabeDezibel;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditEingabeEingangsLeistungP1;
    QLineEdit *EditEingabeAusgangsLeistungP2;
    QLineEdit *EditEingabeEingangsSpannungU1;
    QLineEdit *EditEingabeAusgangsSpannungU2;
    QLineEdit *EditErgebnis;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGDEZIBEL_H
