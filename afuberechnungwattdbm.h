#ifndef AFUBERECHNUNGWATTDBM_H
#define AFUBERECHNUNGWATTDBM_H

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

class AfuBerechnungWattDbm : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungWattDbm(QWidget *parent);

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
#endif // AFUBERECHNUNGWATTDBM_H
