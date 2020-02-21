#ifndef AFUBERECHNUNG_H
#define AFUBERECHNUNG_H

/// Interne Includes
#include "afuberechnungfrequenz.h"

/// Qt-includes
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QIcon>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>

class QAction;
class QLabel;

class AfuBerechnung : public QMainWindow
{
    Q_OBJECT

private:
    QMenu *menuDatei;
    QAction *menuDateiNeu;
    QAction *menuDateiOeffnen;
    QAction *menuDateiSpeichern;
    QAction *menuDateiBeenden;

    QMenu *menuBearbeiten;
    QAction *menuBearbeitenFrequenz;
    QAction *menuBearbeitenKapazitaet;
    QAction *menuBearbeitenInduktivitaet;

    QMenu *menuHilfe;
    QAction *menuHilfeInfo;

    QLineEdit *LineEdit_f;
    QLineEdit *LineEdit_c;
    QLineEdit *LineEdit_l;
    QLabel *Label_f_Loesung;


public:
    AfuBerechnung(QWidget *parent = 0);
    ~AfuBerechnung();

    bool b_FChoice = false;
    bool b_CChoice = false;
    bool b_LChoice = false;

    double const d_Pi = 3.141592653589793238462643383279;
    double d_Frequenz {1.0};
    double d_Kapazitaet {1.0};
    double d_Induktivitaet {1.0};
    double d_CEingabe {0.0};
    double d_FEingabe {0.0};
    double d_LEingabe {0.0};

    void Programm();

protected:
    //void closeEvent(QCloseEvent *event);

private slots:
    void triggeredNeu();
    void triggeredOeffnen();
    void triggeredSpeichern();
    void triggeredBeenden();
    void triggeredInfo();
    void triggeredFrequenzBerechnen();
    void triggeredKapazitaetBerechnen();
    void triggeredInduktivitaetBerechnen();
};

#endif // AFUBERECHNUNG_H
