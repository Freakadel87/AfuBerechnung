#ifndef AFUBERECHNUNGWIDERSTAND_H
#define AFUBERECHNUNGWIDERSTAND_H

// Interne Includes
#include "stdlib.h"

// Systeminterne Includes
#include <math.h>
#include <string>
#include <iostream>

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
#include <QComboBox>
#include <QPalette>
#include <QColor>
#include <QMessageBox>

class AfuBerechnungWiderstand : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungWiderstand(QWidget *parent);

private:
    QLabel *LabelSchritt_1;
    QComboBox *ComboBox_1;
    QLabel *LabelSchritt_2;
    QHBoxLayout *HLayoutCombo;
    QVBoxLayout *VLayoutButton;

    QComboBox *ComboFirstRing;
    QComboBox *ComboSecondRing;
    QComboBox *ComboThirdRing;
    QComboBox *ComboMultiplier;
    QComboBox *ComboTolerance;
    QComboBox *ComboTemperatur;
    QLabel *LabelWiderstandswertOhm;
    QLabel *LabelWiderstandswertKiloOhm;
    QLabel *LabelWiderstandswertMegaOhm;
    QLabel *LabelErgebnisOhm;
    QLabel *LabelErgebnisKiloOhm;
    QLabel *LabelErgebnisMegaOhm;

    QLabel *LabelMaxTolWert;
    QLabel *LabelErgebnisMaxTol;
    QLabel *LabelMinTolWert;
    QLabel *LabelErgebnisMinTol;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGWIDERSTAND_H
