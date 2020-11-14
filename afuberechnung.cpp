#include "afuberechnung.h"

//Variablendeklaration
QSettings SettingsAfuFenster;
bool bMerkerFenster {false};
int G_iMODE {0}; // Globale Variable fuer setzen von Widgets

AfuBerechnung::~AfuBerechnung()
{

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AfuBerechnung myWidget;
    myWidget.setWindowTitle("Berechnungen für Antennenbau");
    myWidget.setGeometry(800, 400, 600, 500); // x-Koordinate, y-Koordinate, Fensterhoehe und Fensterbreite
    myWidget.show();
    return a.exec();
}

AfuBerechnung::AfuBerechnung(QWidget *parent)
    : QMainWindow(parent)
{
    ///TODO: Timer wird nicht aktualisiert. Der Code muss wahrscheinlich in das MAIN Programm

    //Auslesen und darstellen des Zeitstempels
    QDateTime qDateTime = QDateTime::currentDateTime(); //Timer auslesen
    QString sTime = qDateTime.toString(Qt::SystemLocaleLongDate); //Timerwert als String wandeln
    LabelTime = new QLabel(this);
    LabelTime->setText(sTime); //Text von Label setzen
    LabelTime->setGeometry(350,400,300,50);
    LabelTime->setFont(QFont("Arial", 10, QFont::Normal));

    // Erstelle Menue --> Datei --> ...
    menuProgramm = menuBar()->addMenu(tr("Programm"));
    menuProgramm->setFont(QFont("Arial", 10, QFont::Normal));
    menuDateiBeenden = menuProgramm->addAction(tr("Beenden"), this, SLOT(triggeredBeenden()));
    menuDateiBeenden->setIcon(QIcon::fromTheme("application-exit"));

    // Erstelle Menue --> Bearbeiten --> ...
    menuBearbeiten = menuBar()->addMenu(tr("Bearbeiten"));
    menuBearbeiten->setFont(QFont("Arial", 10, QFont::Normal));
    menuBearbeitenRedo = menuBearbeiten->addAction(tr("Wiederherstellen"), this, SLOT(triggeredRedo()));
    menuBearbeitenRedo->setIcon(QIcon::fromTheme("document-redo"));
    menuBearbeitenUndo = menuBearbeiten->addAction(tr("Rückgängig"), this, SLOT(triggeredUndo()));
    menuBearbeitenUndo->setIcon(QIcon::fromTheme("document-undo"));
    menuBearbeiten->addSeparator();
    menuBearbeitenCut = menuBearbeiten->addAction(tr("Ausschneiden"), this, SLOT(triggeredCut()));
    // menuBearbeitenCut->setIcon(QIcon::fromTheme("C:/Users/Büro/Desktop/edit-cut.svg"));
    menuBearbeiten->addSeparator();
    menuBearbeitenCopy = menuBearbeiten->addAction(tr("Kopieren"), this, SLOT(triggeredCopy()));
    menuBearbeitenCopy->setIcon(QIcon::fromTheme("copy.png"));
    menuBearbeitenPaste = menuBearbeiten->addAction(tr("Einfügen"), this, SLOT(triggeredPaste()));
    menuBearbeitenPaste->setIcon(QIcon::fromTheme("document-paste"));

    // Erstelle Menue --> Berechnen --> ...
    menuBerechnen = menuBar()->addMenu(tr("Berechnen"));
    menuBerechnen->setFont(QFont("Arial", 10, QFont::Normal));
    menuBerechnenFrequenz = menuBerechnen->addAction(tr("Frequenz berechnen..."), this, SLOT(triggeredFrequenzBerechnen()));
    menuBerechnenKapazitaet = menuBerechnen->addAction(tr("Kapazität berechnen..."), this, SLOT(triggeredKapazitaetBerechnen()));
    menuBerechnenInduktivitaet = menuBerechnen->addAction(tr("Induktivität berechnen..."), this, SLOT(triggeredInduktivitaetBerechnen()));
    menuBerechnen->addSeparator();
    menuBerechnenDrahtlaenge = menuBerechnen->addAction(tr("Drahtlänge berechnen..."), this, SLOT(triggeredDrahtlaengeBerechnen()));
    menuBerechnenVerlaengerungsSpule = menuBerechnen->addAction(tr("Verlängerungsspule berechnen..."), this, SLOT(triggeredVerlaengerungBerechnen()));
    menuBerechnenLuftspule = menuBerechnen->addAction(tr("Luftspule berechnen..."), this, SLOT(triggeredLuftspuleBerechnen()));
    menuBerechnenTrap = menuBerechnen->addAction(tr("Trapantenne berechnen..."), this, SLOT(triggeredTrapBerechnen()));
    menuBerechnenResoTrans = menuBerechnen->addAction(tr("Resonanztransformator berechnen..."), this, SLOT(triggeredResoTransBerechnen()));
    menuBerechnen->addSeparator();
    menuBerechnenDezibelLeistung = menuBerechnen->addAction(tr("Dezibelberechnung Leistung..."), this, SLOT(triggeredDezibelBerechnenLeistung()));
    menuBerechnenDezibelSpannung = menuBerechnen->addAction(tr("Dezibelberechnung Spannung..."), this, SLOT(triggeredDezibelBerechnenSpannung()));
    menuBerechnen->addSeparator();
    menuBerechnenSwr = menuBerechnen->addAction(tr("SWR-Tabelle..."), this, SLOT(triggeredSwrBerechnen()));
    menuBerechnen->addSeparator();
    menuBerechnenWiderstand = menuBerechnen->addAction(tr("Widerstand bestimmen..."), this, SLOT(triggeredWiderstand()));
    menuBerechnen->addSeparator();
    menuBerechnenEntfernung = menuBerechnen->addAction(tr("Entfernung auf der Kugeloberfläche berechnen..."), this, SLOT(triggeredEntfernungBerechnen()));

    // Erstelle Menue --> Optionen --> ...
    menuOptionen = menuBar()->addMenu(tr("Optionen"));
    menuOptionen->setFont(QFont("Arial", 10, QFont::Normal));
    menuEinstellungen = menuOptionen->addAction(tr("Einstellungen..."), this, SLOT(triggeredEinstellungen()));
    menuSprache = menuOptionen->addAction(tr("Sprachumschaltung"), this, SLOT(triggeredSprache()));

    // Erstelle Menue --> Hilfe --> ...
    menuHilfe = menuBar()->addMenu(tr("Hilfe/Info"));
    menuHilfe->setFont(QFont("Arial", 10, QFont::Normal));
    menuHilfeInfo = menuHilfe->addAction(tr("Informationen"), this, SLOT(triggeredInfo()));
    menuHilfe->addSeparator();
    menuHilfeFilter = menuHilfe->addAction(tr("Infos-Filter..."), this, SLOT(triggeredFilter()));
    menuHilfeWattDbm = menuHilfe->addAction(tr("Umrechnung Watt >>> dBm..."), this, SLOT(triggeredWattDbm()));
    menuHilfe->addSeparator();
    menuHilfeFrequenzen = menuHilfe->addAction(tr("Frequenzen..."), this, SLOT(triggeredAnzeigeFrequenz()));
    menuHilfeAmateurfunk = menuHilfe->addAction(tr("Amateurfunk-Bänder..."), this, SLOT(triggeredAmateurfunkBaender()));

    //Erstellung der Buttons im Hauptfenster
    LabelButton1 = new QLabel(tr("Thomsonscher Schwingungskreis:"), this);
    LabelButton1->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    LabelButton1->setFont(QFont("Arial", 10, QFont::Bold));
    LabelButton1->setGeometry(25,35,450,25); //x, y, Laenge, Breite
    ButtonFrequenz = new QPushButton(tr("Frequenz \n berechnen"), this);
    ButtonFrequenz->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonFrequenz->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonFrequenz->setGeometry(25,75,85,85);
    ButtonInduktivitaet = new QPushButton(tr("Induktivität \n berechnen"), this);
    ButtonInduktivitaet->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonInduktivitaet->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonInduktivitaet->setGeometry(125,75,85,85);
    ButtonKapazitaet = new QPushButton(tr("Kapazität \n berechnen"), this);
    ButtonKapazitaet->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonKapazitaet->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonKapazitaet->setGeometry(225,75,85,85);
    LabelButton2 = new QLabel(tr("Sonstige Berechnungen:"), this);
    LabelButton2->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    LabelButton2->setFont(QFont("Arial", 10, QFont::Bold));
    LabelButton2->setGeometry(25,165,450,25); //x, y, Laenge, Breite
    ButtonSpule = new QPushButton(tr("Verlängerungsspule \n berechnen"), this);
    ButtonSpule->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSpule->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonSpule->setGeometry(25,195,85,85);
    ButtonLuftspule = new QPushButton(tr("Luftspule \n berechnen"), this);
    ButtonLuftspule->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLuftspule->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonLuftspule->setGeometry(125,195,85,85);
    ButtonTrap = new QPushButton(tr("Traps \n berechnen"), this);
    ButtonTrap->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonTrap->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonTrap->setGeometry(225,195,85,85);
    ButtonDrahtlaenge = new QPushButton(tr("Drahtlänge \n berechnen"), this);
    ButtonDrahtlaenge->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonDrahtlaenge->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonDrahtlaenge->setGeometry(325,195,85,85);
    ButtonBeenden = new QPushButton(tr("Beenden"), this);
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonBeenden->setGeometry(25,405,85,42);
    ButtonResoTrans = new QPushButton(tr("Resonanz- \n transform. \n berechnen"), this);
    ButtonResoTrans->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonResoTrans->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonResoTrans->setGeometry(25,305,85,85);
    ButtonWiderstand = new QPushButton(tr("Widerstand\n bestimmen"), this);
    ButtonWiderstand->setStyleSheet("QPushButton {image: url(H:/Github/Bilder/Widerstand.jpg);}");
    ButtonWiderstand->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonWiderstand->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonWiderstand->setGeometry(125,305,85,85);
    CheckBoxFenster = new QCheckBox(tr("Fenster im Vordergrund"), this);
    CheckBoxFenster->setFont(QFont("Arial", 10, QFont::Normal));
    CheckBoxFenster->setGeometry(25,430,200,85);

//    QIcon iconBildWiderstand;
//    iconBildWiderstand.addFile("H:/Github/Bilder/Widerstand.jpg");
//    ButtonWiderstand->setIcon(iconBildWiderstand);

    // Bild auf der Startseite einfuegen
    QPixmap Startbild("C:/Users/Büro/Pictures/Amateurfunk_Wellenlaenge.JPG");

/// TODO: Bei Projektweitergabe (Release) kann der C:/ -Pfad nicht bestehen bleiben?
    LabelStartbild = new QLabel(this);
    LabelStartbild->setPixmap(Startbild);
    LabelStartbild->setGeometry(325,250,250,250);

    LoadConfig(); //Lade gespeicherte Parameter

    // Verbindung der Buttons
    QObject::connect(ButtonFrequenz, SIGNAL(clicked(bool)), this, SLOT(triggeredFrequenzBerechnen()));
    QObject::connect(ButtonInduktivitaet, SIGNAL(clicked(bool)), this, SLOT(triggeredInduktivitaetBerechnen()));
    QObject::connect(ButtonKapazitaet, SIGNAL(clicked(bool)), this, SLOT(triggeredKapazitaetBerechnen()));
    QObject::connect(ButtonSpule, SIGNAL(clicked(bool)), this, SLOT(triggeredVerlaengerungBerechnen()));
    QObject::connect(ButtonLuftspule, SIGNAL(clicked(bool)), this, SLOT(triggeredLuftspuleBerechnen()));
    QObject::connect(ButtonTrap, SIGNAL(clicked(bool)), this, SLOT(triggeredTrapBerechnen()));
    QObject::connect(ButtonDrahtlaenge, SIGNAL(clicked(bool)), this, SLOT(triggeredDrahtlaengeBerechnen()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredBeenden()));
    QObject::connect(ButtonResoTrans, SIGNAL(clicked(bool)), this, SLOT(triggeredResoTransBerechnen()));
    QObject::connect(ButtonWiderstand, SIGNAL(clicked(bool)), this, SLOT(triggeredWiderstand()));
    QObject::connect(CheckBoxFenster, SIGNAL(clicked(bool)), this, SLOT(triggeredCheckBoxChecked()));
}

void AfuBerechnung::triggeredBeenden()
{
    // Abfrage ob das Programm tatsaechlich beendet werden soll
    int ret {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle(tr("AfuBerechnung beenden?"));
    msgBox.setText(tr("Wollen Sie das Programm wirklich beenden?\n"
                      "Alle bisher eingegebenen Daten gehen dadurch verloren."));
    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Ja"));
    msgBox.setButtonText(QMessageBox::No, tr("Nein"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setEscapeButton(QMessageBox::No);
    ret = msgBox.exec();

    if (ret == QMessageBox::Yes) //Programm wird beendet
    {
        close();
        myWidget->deleteLater(); //Zerstoere alle Fenster nach Beendigung des Programms
    }
    else if (ret == QMessageBox::No)
    {
        return;
    }
}

void AfuBerechnung::triggeredFrequenzBerechnen()
{
    BerechnungFrequenz = new AfuBerechnungFrequenz(this);
    BerechnungFrequenz->setWindowTitle(tr("Berechnung der Frequenz"));
    BerechnungFrequenz->show();
}

void AfuBerechnung::triggeredKapazitaetBerechnen()
{
    BerechnungKapazitaet = new AfuBerechnungKapazitaet(this);
    BerechnungKapazitaet->setWindowTitle(tr("Berechnung der Kapazität"));
    BerechnungKapazitaet->show();
}

void AfuBerechnung::triggeredInduktivitaetBerechnen()
{
    BerechnungInduktivitaet = new AfuBerechnungInduktivitaet(this);
    BerechnungInduktivitaet->setWindowTitle(tr("Berechnung der Induktivität"));
    BerechnungInduktivitaet->show();
}

void AfuBerechnung::triggeredVerlaengerungBerechnen()
{
    BerechnungVerlaengerungsSpule = new AfuBerechnungVerlaengerungsSpule(this);
    BerechnungVerlaengerungsSpule->setWindowTitle(tr("Berechnung der Spulenverlängerung"));
    BerechnungVerlaengerungsSpule->show();
}

void AfuBerechnung::triggeredDrahtlaengeBerechnen()
{
    BerechnungDrahtlaenge = new AfuBerechnungDrahtlaenge(this);
    BerechnungDrahtlaenge->setWindowTitle(tr("Berechnung der Drahtlänge"));
    BerechnungDrahtlaenge->show();
}

void AfuBerechnung::triggeredLuftspuleBerechnen()
{
    /// TODO: Fehlfunktion
    //    BerechnungLuftspule = new AfuBerechnungLuftspule(this);
    //    BerechnungLuftspule->setWindowTitle("Berechnung der Luftspule");
    //    BerechnungLuftspule->show();
}

void AfuBerechnung::triggeredTrapBerechnen()
{
    BerechnungTrap = new AfuBerechnungTrapantenne(this);
    BerechnungTrap->setWindowTitle(tr("Trapantenne berechnen"));
    BerechnungTrap->show();
}

void AfuBerechnung::triggeredResoTransBerechnen()
{
    BerechnungResoTrans = new AfuBerechnungResoTrans(this);
    BerechnungResoTrans->setWindowTitle(tr("Resonanztransformation berechnen"));
    BerechnungResoTrans->show();
}

void AfuBerechnung::triggeredDezibelBerechnenLeistung()
{    
    G_iMODE = WIDGETDEZIBELLEISTUNG;
    WidgetDezibel = new AfuBerechnungDezibel(this);
    WidgetDezibel->setWindowTitle(tr("Dezibelberechnung Leistung"));
    WidgetDezibel->show();
}

void AfuBerechnung::triggeredDezibelBerechnenSpannung()
{
    G_iMODE = WIDGETDEZIBELSPANNUNG;
    WidgetDezibel = new AfuBerechnungDezibel(this);
    WidgetDezibel->setWindowTitle(tr("Dezibelberechnung Spannung"));
    WidgetDezibel->show();
}

void AfuBerechnung::triggeredSwrBerechnen()
{
    WidgetSwr = new AfuBerechnungSwr(this);
    WidgetSwr->setWindowTitle(tr("SWR-Tabelle"));
    WidgetSwr->show();
}

void AfuBerechnung::triggeredInfo()
{
    QMessageBox::about(this, tr("Copyright und Rechtliches"),
                       tr("<h2>Amateurfunksoftware v1.0</h2>"
                          "<p>Copyright &copy; 2020 by DF1TC."
                          "<p>Für Amateurfunkanwendungen ist dieses Programm"
                          " Freeware, eine kommerzielle Nutzung ist ausschließlich mit der"
                          " Zustimmung des Autors gestattet!"));
}

void AfuBerechnung::triggeredAnzeigeFrequenz()
{
    AnzeigeFrequenz = new AfuBerechnungAnzeigeFrequenz(this);
    AnzeigeFrequenz->setWindowTitle(tr("Frequenzen - digitale Betriebsarten"));
    AnzeigeFrequenz->show();
}

void AfuBerechnung::triggeredAmateurfunkBaender()
{
    AmateurfunkBaender = new AfuBerechnungAmateurfunkBaender(this);
    AmateurfunkBaender->setWindowTitle(tr("Amateurfunk-Bänder"));
    AmateurfunkBaender->show();
}

void AfuBerechnung::triggeredFilter()
{
    WidgetFilter = new AfuBerechnungFilter(this);
    WidgetFilter->setWindowTitle(tr("Infos über Filter"));
    WidgetFilter->show();
}

void AfuBerechnung::triggeredWattDbm()
{
    UmrechnungWattDbm = new AfuBerechnungWattDbm(this);
    UmrechnungWattDbm->setWindowTitle(tr("Umrechnung Watt in dBm"));
    UmrechnungWattDbm->show();
}

void AfuBerechnung::triggeredWiderstand()
{
    Widerstand = new AfuBerechnungWiderstand(this);
    Widerstand->setWindowTitle(tr("Widerstands-Farbcodetabelle"));
    Widerstand->show();
}

void AfuBerechnung::triggeredEntfernungBerechnen()
{
    WidgetEntfernung = new AfuBerechnungEntfernung(this);
    WidgetEntfernung->setWindowTitle(tr("Exakte Entfernungsberechnung für die Kugeloberfläche"));
    WidgetEntfernung->show();
}

void AfuBerechnung::triggeredEinstellungen()
{
    /// TODO: Neues Fenster erstellen für Schriftart und -größe
    WidgetEinstellungen = new AfuBerechnungEinstellungen(this);
    WidgetEinstellungen->setWindowTitle(tr("Einstellungen"));
    WidgetEinstellungen->show();
}

void AfuBerechnung::triggeredSprache()
{
    WidgetSprache = new AfuBerechnungSprache(this);
    WidgetSprache->setWindowTitle(tr("Sprachumschaltung"));
    WidgetSprache->show();
}

void AfuBerechnung::triggeredCheckBoxChecked()
{
    if (CheckBoxFenster->isChecked())
    {
        /// TODO: Fenster bleibt nicht im Vordergrund...welcher Befehl bei QWidget???
        myWidget->activateWindow();
        myWidget->raise();
    }
    else
    {
        /// TODO: Fenster kann in den Hintergrund versetzt werden.
    }

    SaveConfig(); //Speichere Parameter
}

void AfuBerechnung::triggeredCut()
{

}

void AfuBerechnung::triggeredCopy()
{

}

void AfuBerechnung::triggeredPaste()
{

}

void AfuBerechnung::triggeredRedo()
{

}

void AfuBerechnung::triggeredUndo()
{

}

void AfuBerechnung::LoadConfig()
{
    if (bMerkerFenster == true)
    {
        CheckBoxFenster->setChecked(true);
    }
    else
    {
        CheckBoxFenster->setChecked(false);
    }
}

void AfuBerechnung::SaveConfig()
{
    ///TODO: Sinnvoll??? Fenster wird nicht erneut geoeffnet.
    SettingsAfuFenster.value("CheckBoxFenster", bMerkerFenster);
}
