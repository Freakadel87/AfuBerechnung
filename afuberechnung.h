#ifndef AFUBERECHNUNG_H
#define AFUBERECHNUNG_H

/// Interne Includes
#include "afuberechnungfrequenz.h"
#include "afuberechnungkapazitaet.h"
#include "afuberechnunginduktivitaet.h"
#include "afuberechnungdrahtlaenge.h"
#include "afuberechnungverlaengerungsspule.h"
#include "afuberechnungluftspule.h"
#include "afuberechnungtrapantenne.h"
#include "afuberechnunganzeigefrequenz.h"
#include "afuberechnungresotrans.h"
#include "afuberechnungamateurfunkbaender.h"
#include "afuberechnungwattdbm.h"

/// Qt-includes
#include <QApplication>
#include <QFont>
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
#include <QTextEdit>

class AfuBerechnung : public QMainWindow
{
    Q_OBJECT

private:
    AfuBerechnungFrequenz *BerechnungFrequenz;
    AfuBerechnungInduktivitaet *BerechnungInduktivitaet;
    AfuBerechnungKapazitaet *BerechnungKapazitaet;
    AfuBerechnungDrahtlaenge *BerechnungDrahtlaenge;
    AfuBerechnungVerlaengerungsSpule *BerechnungVerlaengerungsSpule;
   /// AfuBerechnungLuftspule *BerechnungLuftspule;
    AfuBerechnungTrapantenne *BerechnungTrap;
    AfuBerechnungAnzeigeFrequenz *AnzeigeFrequenz;
    AfuBerechnungAmateurfunkBaender *AmateurfunkBaender;
    AfuBerechnungWattDbm *UmrechnungWattDbm;
    AfuBerechnungResoTrans *BerechnungResoTrans;

    QWidget *myWidget = new QWidget();

    QMenu *menuDatei;
    QAction *menuDateiNeu;
    QAction *menuDateiOeffnen;
    QAction *menuDateiSpeichern;
    QAction *menuDateiBeenden;

    QMenu *menuBerechnen;
    QAction *menuBerechnenFrequenz;
    QAction *menuBerechnenKapazitaet;
    QAction *menuBerechnenInduktivitaet;
    QAction *menuBerechnenDrahtlaenge;
    QAction *menuBerechnenVerlaengerungsSpule;
    QAction *menuBerechnenLuftspule;
    QAction *menuBerechnenTrap;
    QAction *menuBerechnenResoTrans;

    QMenu *menuHilfe;
    QAction *menuHilfeInfo;
    QAction *menuHilfeFrequenzen;
    QAction *menuHilfeAmateurfunk;
    QAction *menuHilfeWattDbm;

    QGridLayout *GridLayoutButton;

    QLabel *LabelButton1;
    QPushButton *ButtonFrequenz;
    QPushButton *ButtonInduktivitaet;
    QPushButton *ButtonKapazitaet;
    QPushButton *ButtonSpule;
    QPushButton *ButtonLuftspule;
    QPushButton *ButtonTrap;
    QPushButton *ButtonBeenden;
    QPushButton *ButtonDrahtlaenge;
    QPushButton *ButtonResoTrans;

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
    void triggeredAnzeigeFrequenz();
    void triggeredAmateurfunkBaender();
    void triggeredFrequenzBerechnen();
    void triggeredKapazitaetBerechnen();
    void triggeredInduktivitaetBerechnen();
    void triggeredDrahtlaengeBerechnen();
    void triggeredVerlaengerungBerechnen();
    void triggeredLuftspuleBerechnen();
    void triggeredTrapBerechnen();
    void triggeredResoTransBerechnen();
    void triggeredWattDbm();
};

#endif // AFUBERECHNUNG_H
