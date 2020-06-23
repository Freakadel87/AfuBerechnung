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
#include <QWidget>
#include <QPushButton>
#include <QFontDialog>
#include <QColorDialog>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QSettings>

class AfuBerechnungEinstellungen : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungEinstellungen(QWidget *parent);

private:
    QFontDialog *FontDialog;
    QColorDialog *ColorDialog;

    QVBoxLayout *MainLayout;
    QHBoxLayout *OberesLayout;
    QHBoxLayout *UnteresLayout;
    QPushButton *ButtonSchriftart;
    QPushButton *ButtonSchriftfarbe;
    QPushButton *ButtonAbbrechen;
    QPushButton *ButtonOk;

private slots:
    void triggeredButtonAbbrechenClicked();
    void triggeredButtonOkClicked();
    void triggeredButtonSchriftartClicked();
    void triggeredButtonSchriftfarbeClicked();
    void LoadConfig();
    void SaveConfig();
};
#endif // AFUBERECHNUNGEINSTELLUNGEN_H
