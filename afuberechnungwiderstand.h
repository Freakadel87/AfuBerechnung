#ifndef AFUBERECHNUNGWIDERSTAND_H
#define AFUBERECHNUNGWIDERSTAND_H

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
#include <QComboBox>
#include <QPalette>
#include <QColor>

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

    QComboBox *ComboFirstRing;
    QComboBox *ComboSecondRing;
    QComboBox *ComboThirdRing;
    QComboBox *ComboMultiplier;
    QComboBox *ComboTolerance;
    QComboBox *ComboTemperatur;
    QLineEdit *EditWiderstandswert;
    QLabel *LabelWiderstandswert;

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
