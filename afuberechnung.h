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
#include "afuberechnungswr.h"
#include "afuberechnungamateurfunkbaender.h"
#include "afuberechnungwattdbm.h"
#include "afuberechnungwiderstand.h"
#include "afuberechnungeinstellungen.h"
#include "afuberechnungsprache.h"
#include "afuberechnungfilter.h"
#include "afuberechnungentfernung.h"

/// Qt-includes
#include <QApplication>
#include <QCheckBox>
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
#include <QPixmap>
#include <windows.h>
#include <QSettings>
#include <QDateTime>

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
    AfuBerechnungFilter *WidgetFilter;
    AfuBerechnungWattDbm *UmrechnungWattDbm;
    AfuBerechnungResoTrans *BerechnungResoTrans;
    AfuBerechnungWiderstand *Widerstand;
    AfuBerechnungEinstellungen *WidgetEinstellungen;
    AfuBerechnungSprache *WidgetSprache;
    AfuBerechnungEntfernung *WidgetEntfernung;
    AfuBerechnungSwr *WidgetSwr;

    QWidget *myWidget = new QWidget();

    QLabel *LabelStartbild;
    QLabel *LabelTime;

    QMenu *menuProgramm;
    QAction *menuDateiBeenden;

    QMenu *menuBearbeiten;
    QAction *menuBearbeitenUndo;
    QAction *menuBearbeitenRedo;
    QAction *menuBearbeitenCut;
    QAction *menuBearbeitenCopy;
    QAction *menuBearbeitenPaste;

    QMenu *menuBerechnen;
    QAction *menuBerechnenFrequenz;
    QAction *menuBerechnenKapazitaet;
    QAction *menuBerechnenInduktivitaet;
    QAction *menuBerechnenDrahtlaenge;
    QAction *menuBerechnenVerlaengerungsSpule;
    QAction *menuBerechnenLuftspule;
    QAction *menuBerechnenTrap;
    QAction *menuBerechnenResoTrans;
    QAction *menuBerechnenSwr;
    QAction *menuBerechnenWiderstand;
    QAction *menuBerechnenEntfernung;

    QMenu *menuOptionen;
    QAction *menuEinstellungen;
    QAction *menuSprache;

    QMenu *menuHilfe;
    QAction *menuHilfeInfo;
    QAction *menuHilfeFilter;
    QAction *menuHilfeFrequenzen;
    QAction *menuHilfeAmateurfunk;
    QAction *menuHilfeWattDbm;

    QGridLayout *GridLayoutButton;

    QLabel *LabelButton1;
    QLabel *LabelButton2;
    QPushButton *ButtonFrequenz;
    QPushButton *ButtonInduktivitaet;
    QPushButton *ButtonKapazitaet;
    QPushButton *ButtonSpule;
    QPushButton *ButtonLuftspule;
    QPushButton *ButtonTrap;
    QPushButton *ButtonBeenden;
    QPushButton *ButtonDrahtlaenge;
    QPushButton *ButtonResoTrans;
    QPushButton *ButtonWiderstand;

    QCheckBox *CheckBoxFenster;

public:
    AfuBerechnung(QWidget *parent = 0);
    ~AfuBerechnung();

protected:
    //void closeEvent(QCloseEvent *event);

private slots:
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
    void triggeredSwrBerechnen();
    void triggeredEntfernungBerechnen();
    void triggeredFilter();
    void triggeredWattDbm();
    void triggeredWiderstand();
    void triggeredRedo();
    void triggeredUndo();
    void triggeredCut();
    void triggeredCopy();
    void triggeredPaste();
    void triggeredEinstellungen();
    void triggeredSprache();
    void triggeredCheckBoxChecked();
    void LoadConfig();
    void SaveConfig();
};

#endif // AFUBERECHNUNG_H
