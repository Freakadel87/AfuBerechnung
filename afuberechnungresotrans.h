#ifndef AFUBERECHNUNGRESOTRANS_H
#define AFUBERECHNUNGRESOTRANS_H

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

class AfuBerechnungResoTrans : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungResoTrans(QWidget *parent);

    // Variablendeklaration
    float const d_Pi = 3.141592653589793238462643383279;
    float d_PufferC;
    float d_PufferL;
    float d_PufferF;
    float d_PufferFF;

private:
    // Erstelle Textfelder
    QLabel *LabelEingabeZEingang;
    QLabel *LabelEingabeZAusgang;
    QLabel *LabelEingabeFrequenz;
    QLabel *LabelAusgabeC;
    QLabel *LabelAusgabeL;
    QLabel *LabelLoesung;
    QLabel *LabelErgebnis;

    QLabel *LabelEinheitZEingang;
    QLabel *LabelEinheitZAusgang;
    QLabel *LabelEinheitFrequenz;
    QLabel *LabelEinheitC;
    QLabel *LabelEinheitL;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditEingabeZEingang;
    QLineEdit *EditEingabeZAusgang;
    QLineEdit *EditEingabeFrequenz;
    QLineEdit *EditAnzeigeC;
    QLineEdit *EditAnzeigeL;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGRESOTRANS_H
