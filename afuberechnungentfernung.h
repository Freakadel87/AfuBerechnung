#ifndef AFUBERECHNUNGENTFERNUNG_H
#define AFUBERECHNUNGENTFERNUNG_H
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
#include <QFont>
#include <QMessageBox>

class AfuBerechnungEntfernung : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungEntfernung(QWidget *parent);

private:
    // Erstelle Textfelder
    QLabel *LabelLat1;
    QLabel *LabelLat2;
    QLabel *LabelLon1;
    QLabel *LabelLon2;
    QLabel *LabelErdradius;

    QLabel *LabelErgebnis;
    QLabel *LabelEntfernung;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditEingabeLat1;
    QLineEdit *EditEingabeLat2;
    QLineEdit *EditEingabeLon1;
    QLineEdit *EditEingabeLon2;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGENTFERNUNG_H
