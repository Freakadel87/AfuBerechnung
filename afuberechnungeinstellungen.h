#ifndef AFUBERECHNUNGEINSTELLUNGEN_H
#define AFUBERECHNUNGEINSTELLUNGEN_H

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

class AfuBerechnungEinstellungen : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungEinstellungen(QWidget *parent);

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
#endif // AFUBERECHNUNGEINSTELLUNGEN_H
