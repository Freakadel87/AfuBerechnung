#ifndef AFUBERECHNUNG_H
#define AFUBERECHNUNG_H

/// Interne Includes
#include "afuberechnungfrequenz.h"
#include "afuberechnungkapazitaet.h"

/// Qt-includes
#include <QMainWindow>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QIcon>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QFileDialog>
#include <QDialog>
#include <QWidget>

class AfuBerechnung : public QMainWindow
{
    Q_OBJECT

private:
    AfuBerechnungFrequenz *BerechnungFrequenz;
    //AfuBerechnungInduktivitaet *BerechnungInduktivitaet;
    AfuBerechnungKapazitaet *BerechnungKapazitaet;

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

public:
    AfuBerechnung(QWidget *parent = 0);
    ~AfuBerechnung();

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
