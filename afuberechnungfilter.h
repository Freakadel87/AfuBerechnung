#ifndef AFUBERECHNUNGFILTER_H
#define AFUBERECHNUNGFILTER_H

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

class AfuBerechnungFilter : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungFilter(QWidget *parent);

private:
    // Erstelle Textfelder
    QVBoxLayout *Layout;
    QLabel *LabelUeberschrift;
    QLabel *Label1;
    QLabel *Label2;
    QLabel *Label3;
    QLabel *Label4;

    // Erstelle Buttons
    QPushButton *ButtonSchliessen;

private slots:
    void triggeredButtonSchliessenClicked();
};
#endif // AFUBERECHNUNGFILTER_H
