#ifndef AFUBERECHNUNGDRAHTLAENGE_H
#define AFUBERECHNUNGDRAHTLAENGE_H

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

class AfuBerechnungDrahtlaenge : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungDrahtlaenge(QWidget *parent);

    // Variablendeklaration
    float const f_Licht = 299.792; // Lichtgeschwindigkeit auf der Erde 299,792 km/s
    float const f_FaktorVer = 0.955; // Verkuerzungsfaktor
    float f_PufferLamda;
    float f_PufferF;
    float f_Ergebnis;
    float f_ErgebnisOVF;

private:
    // Erstelle Textfelder
    QLabel *LabelLicht;
    QLabel *LabelFrequenz;
    QLabel *LabelErgebnisLaenge;
    QLabel *LabelErgebnisLaengeOVF;
    QLabel *LabelLambda;
    QLabel *LabelFaktorVer;

    QLabel *LabelEinheitLicht;
    QLabel *LabelEinheitFrequenz;
    QLabel *LabelEinheitLaenge;
    QLabel *LabelEinheitLaengeOVF;

    QLabel *LabelInfo;

    // Erstelle Ein- und Ausgabefelder
    QLabel *LabelLichtWert;
    QLabel *LabelFaktorVerWert;
    QLabel *LabelErgebnis;
    QLabel *LabelErgebnisOVF;
    QLineEdit *EditEingabeFrequenz;
    QLineEdit *EditEingabeLambda;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGDRAHTLAENGE_H
