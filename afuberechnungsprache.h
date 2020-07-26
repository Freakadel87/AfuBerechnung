#ifndef AFUBERECHNUNGSPRACHE_H
#define AFUBERECHNUNGSPRACHE_H

// Interne Includes

// Systeminterne Includes
#include <math.h>

// Qt Includes
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QFontDialog>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSettings>
#include <QRadioButton>

class AfuBerechnungSprache : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungSprache(QWidget *parent);

private:
    QVBoxLayout *MainLayout;
    QVBoxLayout *LayoutSprache;
    QHBoxLayout *LayoutButton;
    QPushButton *ButtonAbbrechen;
    QPushButton *ButtonOk;
    QRadioButton *RadioButtonDeu;
    QRadioButton *RadioButtonEng;
    QRadioButton *RadioButtonFra;
    QRadioButton *RadioButtonRus;
    QRadioButton *RadioButtonIta;

private slots:
    void triggeredButtonAbbrechenClicked();
    void triggeredButtonOkClicked();
    void LoadConfig();
    void SaveConfig();
};
#endif // AFUBERECHNUNGSPRACHE_H
