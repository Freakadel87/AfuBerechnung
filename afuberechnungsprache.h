#ifndef AFUBERECHNUNGSPRACHE_H
#define AFUBERECHNUNGSPRACHE_H

// Interne Includes

// Systeminterne Includes
#include <math.h>

// Qt Includes
#include <QMainWindow>
#include <QApplication>
#include <QFontDialog>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSettings>
#include <QRadioButton>
#include <QMessageBox>
#include <QFont>
#include <QIcon>
#include <QSize>

class AfuBerechnungSprache : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungSprache(QWidget *parent);

private:
    //Objekterstellung
    QVBoxLayout *MainLayout;
    QGridLayout *GridSprache;
    QVBoxLayout *LayoutSpracheLinks;
    QVBoxLayout *LayoutSpracheRechts;
    QHBoxLayout *LayoutButton;
    QPushButton *ButtonAbbrechen;
    QPushButton *ButtonOk;
    QRadioButton *RadioButtonDeu;
    QRadioButton *RadioButtonEng;
    QRadioButton *RadioButtonFra;
    QRadioButton *RadioButtonRus;
    QRadioButton *RadioButtonIta;
    QRadioButton *RadioButtonSpa;
    QRadioButton *RadioButtonPor;
    QRadioButton *RadioButtonPol;

private slots:
    void triggeredButtonAbbrechenClicked(); //Button ABBRECHEN betaetigt
    void triggeredButtonOkClicked(); //Button OK betaetigt
    void triggeredRadioButtonDeuClicked(); //Sprache DEUTSCH
    void triggeredRadioButtonEngClicked(); //Sprache ENGLISCH
    void triggeredRadioButtonFraClicked(); //Sprache FRANZOESISCH
    void triggeredRadioButtonRusClicked(); //Sprache RUSSISCH
    void triggeredRadioButtonItaClicked(); //Sprache ITALIENISCH
    void triggeredRadioButtonSpaClicked(); //Sprache SPANISCH
    void triggeredRadioButtonPorClicked(); //Sprache PORTUGISISCH
    void triggeredRadioButtonPolClicked(); //Sprache POLNISCH
    void LoadConfig(); //Lade zuvor gespeicherte Parameter zurueck
    void SaveConfig(); //Speichere vorgenommene Parameter
};
#endif // AFUBERECHNUNGSPRACHE_H
