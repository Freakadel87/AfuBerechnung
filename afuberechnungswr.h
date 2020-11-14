#ifndef AFUBERECHNUNGSWR_H
#define AFUBERECHNUNGSWR_H

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
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QDialog>


class AfuBerechnungSwr : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungSwr(QWidget *parent);

private:
    //Objekterstellung
    QGridLayout *GridLayout;
    QVBoxLayout *MainLayout;

    QPushButton *ButtonAbbrechen;
    QPushButton *ButtonOk;

    QComboBox *ComboBoxBandwahl;
    QLabel *LabelBandwahl;
    QLabel *LabelUeberschrift;
    QLabel *LabelSpalte1;
    QLabel *LabelSpalte2;
    QLabel *LabelZeile1;
    QLabel *LabelZeile2;
    QLabel *LabelZeile3;
    QLabel *LabelZeile4;
    QLabel *LabelZeile5;
    QLabel *LabelZeile6;
    QLabel *LabelZeile7;
    QLabel *LabelZeile8;
    QLabel *LabelZeile9;
    QLabel *LabelZeile10;
    QLabel *LabelZeile11;
    QLabel *LabelZeile12;
    QLabel *LabelZeile13;
    QLabel *LabelZeile14;
    QLabel *LabelZeile15;
    QLabel *LabelZeile16;
    QLabel *LabelZeile17;
    QLabel *LabelZeile18;
    QLabel *LabelZeile19;
    QLabel *LabelZeile20;
    QLineEdit *EditZeile1;
    QLineEdit *EditZeile2;
    QLineEdit *EditZeile3;
    QLineEdit *EditZeile4;
    QLineEdit *EditZeile5;
    QLineEdit *EditZeile6;
    QLineEdit *EditZeile7;
    QLineEdit *EditZeile8;
    QLineEdit *EditZeile9;
    QLineEdit *EditZeile10;
    QLineEdit *EditZeile11;
    QLineEdit *EditZeile12;
    QLineEdit *EditZeile13;
    QLineEdit *EditZeile14;
    QLineEdit *EditZeile15;
    QLineEdit *EditZeile16;
    QLineEdit *EditZeile17;
    QLineEdit *EditZeile18;
    QLineEdit *EditZeile19;
    QLineEdit *EditZeile20;

private slots:
    void triggeredButtonAbbrechenClicked(); //Button ABBRECHEN betaetigt
    void triggeredButtonOkClicked(); //Button OK betaetigt
    void triggeredComboBox();
    void CreatePlotter();
    void LoadConfig(); //Lade zuvor gespeicherte Parameter zurueck
    void SaveConfig(); //Speichere vorgenommene Parameter
};
#endif // AFUBERECHNUNGSWR_H
