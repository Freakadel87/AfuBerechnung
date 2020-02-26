#ifndef AFUBERECHNUNGVERLAENGERUNGSSPULE_H
#define AFUBERECHNUNGVERLAENGERUNGSSPULE_H

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
#include <QDoubleValidator>
#include <QColor>

class AfuBerechnungVerlaengerungsSpule : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungVerlaengerungsSpule(QWidget *parent);

    // Variablendeklaration
    double const d_Pi = 3.141592653589793238462643383279;
    double d_HoeheDipol;
    double d_DickeDraht;
    double d_LaengeSeite;
    double d_PosSpule;
    double d_Frequenz;
    double d_PufferSpule;
    double d_PufferFrequenz;

private:
    // Erstelle Textfelder
    QLabel *LabelHoeheDipol;
    QLabel *LabelDickeDraht;
    QLabel *LabelLaengeSeite;
    QLabel *LabelPosSpule;
    QLabel *LabelFrequenz;
    QLabel *LabelLoesungSpule;
    QLabel *ErgebnisSpule;

    QLabel *LabelEinheitHoeheDipol;
    QLabel *LabelEinheitDickeDraht;
    QLabel *LabelEinheitLaengeSeite;
    QLabel *LabelEinheitPosSpule;
    QLabel *LabelEinheitFrequenz;
    QLabel *LabelEinheitSpule;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditHoeheDipol;
    QLineEdit *EditDickeDraht;
    QLineEdit *EditLaengeSeite;
    QLineEdit *EditPosSpule;
    QLineEdit *EditFrequenz;

    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGVERLAENGERUNGSSPULE_H
