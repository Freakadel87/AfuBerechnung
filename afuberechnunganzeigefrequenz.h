#ifndef AFUBERECHNUNGANZEIGEFREQUENZ_H
#define AFUBERECHNUNGANZEIGEFREQUENZ_H

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
#include <QTextEdit>

class AfuBerechnungAnzeigeFrequenz : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungAnzeigeFrequenz(QWidget *parent);

private:
    // Erstelle Textfelder
    QHBoxLayout *Layout;
    QLabel *LabelEingabe;
    QComboBox *ComboBetriebsart;
    QTextEdit *EditText;
    QVBoxLayout *LayoutVertical;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;

private slots:
    void triggeredButtonBeendenClicked();
};
#endif // AFUBERECHNUNGANZEIGEFREQUENZ_H
