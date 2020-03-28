#ifndef AFUBERECHNUNGAMATEURFUNKBAENDER_H
#define AFUBERECHNUNGAMATEURFUNKBAENDER_H

// Interne Includes

// Systeminterne Includes

// Qt Includes
#include <QMainWindow>
#include <QApplication>
#include <QDesktopWidget>
#include <QFontDialog>
#include <QGridLayout>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QTextEdit>
#include <QFont>

class AfuBerechnungAmateurfunkBaender : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungAmateurfunkBaender(QWidget *parent);

private:
    // Erstelle Textfelder
    QVBoxLayout *Layout;
    QLabel *LabelEingabe;
    QTextEdit *EditText;

    // Erstelle Buttons
    QPushButton *ButtonSchliessen;

private slots:
    void triggeredButtonSchliessenClicked();
};
#endif // AFUBERECHNUNGAMATEURFUNKBAENDER_H
