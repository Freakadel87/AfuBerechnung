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
#include <QFont>

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
    void triggeredComboBox();
};
#endif // AFUBERECHNUNGANZEIGEFREQUENZ_H
