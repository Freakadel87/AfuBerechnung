#ifndef AFUBERECHNUNGRESOTRANS_H
#define AFUBERECHNUNGRESOTRANS_H

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

class AfuBerechnungResoTrans : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungResoTrans(QWidget *parent);

    // Variablendeklaration
    float const f_Pi = 3.141592653589793238462643383279f;
    float f_PufferC {0.0};
    float f_PufferL {0.0};
    float f_PufferF {0.0};
    float f_PufferR1 {0.0};
    float f_PufferR2 {0.0};
    float f_PufferQ {0.0};
    float f_PufferQQ {0.0};
    float f_PufferZAusgang {0.0};
    float f_PufferZEingang {0.0};
    float f_PufferFrequenz {0.0};

private:
    QVBoxLayout *LayoutVBox;

    // Erstelle Textfelder
    QLabel *LabelZEingang;
    QLabel *LabelZAusgang;
    QLabel *LabelFrequenz;
    QLabel *LabelC;
    QLabel *LabelL;
    QLabel *LabelQ;

    // Erstelle Ein- und Ausgabefelder
    QLineEdit *EditZEingang;
    QLineEdit *EditZAusgang;
    QLineEdit *EditFrequenz;
    QLabel *LabelAusgabeQ;
    QLabel *LabelAusgabeC;
    QLabel *LabelAusgabeL;

    // Erstelle Text fuer Einheiten
    QLabel *LabelEinheitZEingang;
    QLabel *LabelEinheitZAusgang;
    QLabel *LabelEinheitFrequenz;
    QLabel *LabelEinheitC;
    QLabel *LabelEinheitL;

    QLabel *LabelTextInfo;

     // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGRESOTRANS_H
