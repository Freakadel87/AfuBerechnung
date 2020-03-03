#ifndef AFUBERECHNUNG_H
#define AFUBERECHNUNG_H

/// Interne Includes
#include "afuberechnungfrequenz.h"
#include "afuberechnungkapazitaet.h"
#include "afuberechnunginduktivitaet.h"
#include "afuberechnungdrahtlaenge.h"
#include "afuberechnungverlaengerungsspule.h"
#include "afuberechnungluftspule.h"

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
#include <QPushButton>
#include <QGridLayout>

class AfuBerechnung : public QMainWindow
{
    Q_OBJECT

private:
    AfuBerechnungFrequenz *BerechnungFrequenz;
    AfuBerechnungInduktivitaet *BerechnungInduktivitaet;
    AfuBerechnungKapazitaet *BerechnungKapazitaet;
    AfuBerechnungDrahtlaenge *BerechnungDrahtlaenge;
    AfuBerechnungVerlaengerungsSpule *BerechnungVerlaengerungsSpule;
    AfuBerechnungLuftspule *BerechnungLuftspule;

    QMenu *menuDatei;
    QAction *menuDateiNeu;
    QAction *menuDateiOeffnen;
    QAction *menuDateiSpeichern;
    QAction *menuDateiBeenden;

    QMenu *menuBearbeiten;
    QAction *menuBearbeitenFrequenz;
    QAction *menuBearbeitenKapazitaet;
    QAction *menuBearbeitenInduktivitaet;
    QAction *menuBearbeitenDrahtlaenge;
    QAction *menuBearbeitenVerlaengerungsSpule;
    QAction *menuBearbeitenLuftspule;

    QMenu *menuHilfe;
    QAction *menuHilfeInfo;

    QGridLayout *GridLayoutButton;

    QPushButton *ButtonFrequenz;
    QPushButton *ButtonInduktivitaet;
    QPushButton *ButtonKapazitaet;
    QPushButton *ButtonSpule;

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
    void triggeredDrahtlaengeBerechnen();
    void triggeredVerlaengerungBerechnen();
    void triggeredLuftspuleBerechnen();

};

#endif // AFUBERECHNUNG_H
