#ifndef AFUBERECHNUNGTRAPANTENNE_H
#define AFUBERECHNUNGTRAPANTENNE_H

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

class AfuBerechnungTrapantenne : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungTrapantenne(QWidget *parent);

    // Variablendeklaration
    // Berechnung Laenge Resonanzfrequenz Ist
    float const f_Licht = 299.792;
    float f_Puffer {0.0};
    float f_PufferFreqIst {0.0};
    float f_PufferWelle {0.0};
    float f_PufferRound {0.0};
    float f_PufferRound1 {0.0};

    // Berechnung VF Ist
    float f_PufferVFIst {0.0};
    float f_PufferLaengeIst {0.0};
    float f_PufferLaengeResoIst {0.0};

private:
    QLabel *LabelResoFreq;
    QLabel *EinheitResoFreq;
    QLabel *LabelLaengeIst;
    QLabel *EinheitLaengeIst;
    QLabel *LabelFreqSoll;
    QLabel *EinheitFreqSoll;
    QLabel *LabelWelle;
    QLabel *LabelDraht;
    QLabel *LabelLaengeResoIst;
    QLabel *EinheitLaengeResoIst;
    QLabel *LabelLaengeSoll;
    QLabel *EinheitLaengeSoll;
    QLabel *LabelDrahtIst;
    QLabel *LabelDiff;
    QLabel *LabelDiffErgebnis;
    QLabel *EinheitDiff;

    QLineEdit *EditResoFreq;
    QLineEdit *EditLaengeIst;
    QLineEdit *EditFreqSoll;
    QLineEdit *EditWelle;
    QComboBox *ComboWelle;
    QLineEdit *EditLaengeResoIst;
    QLineEdit *EditLaengeSoll;
    QLineEdit *EditDraht;
    QLabel *LabelDrahtIstErgebnis;



    // Erstelle Buttons
    QPushButton *ButtonBeenden;
    QPushButton *ButtonBerechnen;
    QPushButton *ButtonLeeren;

private slots:
    void triggeredButtonBeendenClicked();
    void triggeredButtonBerechnenClicked();
    void triggeredButtonLeerenClicked();
};
#endif // AFUBERECHNUNGTRAPANTENNE_H
