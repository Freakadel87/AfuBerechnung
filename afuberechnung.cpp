#include "afuberechnung.h"

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
    // Erstelle Menue --> Datei --> ...
    menuProgramm = menuBar()->addMenu(tr("Programm"));
    menuProgramm->setFont(QFont("Arial", 10, QFont::Normal));
    menuDateiBeenden = menuProgramm->addAction("Beenden", this, SLOT(triggeredBeenden()));
    menuDateiBeenden->setIcon(QIcon::fromTheme("application-exit"));

    // Erstelle Menue --> Bearbeiten --> ...
    menuBearbeiten = menuBar()->addMenu(tr("Bearbeiten"));
    menuBearbeiten->setFont(QFont("Arial", 10, QFont::Normal));
    menuBearbeitenRedo = menuBearbeiten->addAction("Wiederherstellen", this, SLOT(triggeredRedo()));
    menuBearbeitenRedo->setIcon(QIcon::fromTheme("document-redo"));
    menuBearbeitenUndo = menuBearbeiten->addAction("Rückgängig", this, SLOT(triggeredUndo()));
    menuBearbeitenUndo->setIcon(QIcon::fromTheme("document-undo"));
    menuBearbeiten->addSeparator();
    menuBearbeitenCut = menuBearbeiten->addAction("Ausschneiden", this, SLOT(triggeredCut()));
    menuBearbeitenCut->setIcon(QIcon::fromTheme("C:/Users/Büro/Desktop/edit-cut.svg"));
    menuBearbeiten->addSeparator();
    menuBearbeitenCopy = menuBearbeiten->addAction("Kopieren", this, SLOT(triggeredCopy()));
    menuBearbeitenCopy->setIcon(QIcon::fromTheme("copy.png"));
    menuBearbeitenPaste = menuBearbeiten->addAction("Einfügen", this, SLOT(triggeredPaste()));
    menuBearbeitenPaste->setIcon(QIcon::fromTheme("document-paste"));

    // Erstelle Menue --> Berechnen --> ...
    menuBerechnen = menuBar()->addMenu(tr("Berechnen"));
    menuBerechnen->setFont(QFont("Arial", 10, QFont::Normal));
    menuBerechnenFrequenz = menuBerechnen->addAction("Frequenz berechnen...", this, SLOT(triggeredFrequenzBerechnen()));
    menuBerechnenKapazitaet = menuBerechnen->addAction("Kapazität berechnen...", this, SLOT(triggeredKapazitaetBerechnen()));
    menuBerechnenInduktivitaet = menuBerechnen->addAction("Induktivität berechnen...", this, SLOT(triggeredInduktivitaetBerechnen()));
    menuBerechnen->addSeparator();
    menuBerechnenDrahtlaenge = menuBerechnen->addAction("Drahtlänge berechnen...", this, SLOT(triggeredDrahtlaengeBerechnen()));
    menuBerechnenVerlaengerungsSpule = menuBerechnen->addAction("Verlängerungsspule berechnen...", this, SLOT(triggeredVerlaengerungBerechnen()));
    menuBerechnenLuftspule = menuBerechnen->addAction("Luftspule berechnen...", this, SLOT(triggeredLuftspuleBerechnen()));
    menuBerechnenTrap = menuBerechnen->addAction("Trapantenne berechnen...", this, SLOT(triggeredTrapBerechnen()));
    menuBerechnenResoTrans = menuBerechnen->addAction("Resonanztransformator berechnen...", this, SLOT(triggeredResoTransBerechnen()));
    menuBerechnen->addSeparator();
    menuBerechnenWiderstand = menuBerechnen->addAction("Widerstand bestimmen...", this, SLOT(triggeredWiderstand()));

    // Erstelle Menue --> Optionen --> ...
    menuOptionen = menuBar()->addMenu(tr("Optionen"));
    menuOptionen->setFont(QFont("Arial", 10, QFont::Normal));
    menuEinstellungen = menuOptionen->addAction("Einstellungen...", this, SLOT(triggeredEinstellungen()));

    // erstelle Menue --> Hilfe --> ...
    menuHilfe = menuBar()->addMenu(tr("Hilfe"));
    menuHilfe->setFont(QFont("Arial", 10, QFont::Normal));
    menuHilfeInfo = menuHilfe->addAction("Informationen", this, SLOT(triggeredInfo()));
    menuHilfe->addSeparator();
    menuHilfeFilter = menuHilfe->addAction("Infos-Filter...", this, SLOT(triggeredFilter()));
    menuHilfeWattDbm = menuHilfe->addAction("Umrechnung Watt >>> dBm...", this, SLOT(triggeredWattDbm()));
    menuHilfe->addSeparator();
    menuHilfeFrequenzen = menuHilfe->addAction("Frequenzen...", this, SLOT(triggeredAnzeigeFrequenz()));
    menuHilfeAmateurfunk = menuHilfe->addAction("Amateurfunk-Bänder...", this, SLOT(triggeredAmateurfunkBaender()));

    LabelButton1 = new QLabel("Thomsonscher Schwingungskreis:", this);
    LabelButton1->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    LabelButton1->setFont(QFont("Arial", 10, QFont::Bold));
    LabelButton1->setGeometry(25,35,450,25); //x, y, Laenge, Breite
    ButtonFrequenz = new QPushButton("Frequenz \n berechnen", this);
    ButtonFrequenz->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonFrequenz->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonFrequenz->setGeometry(25,75,85,85);
    ButtonInduktivitaet = new QPushButton("Induktivität \n berechnen", this);
    ButtonInduktivitaet->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonInduktivitaet->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonInduktivitaet->setGeometry(125,75,85,85);
    ButtonKapazitaet = new QPushButton("Kapazität \n berechnen", this);
    ButtonKapazitaet->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonKapazitaet->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonKapazitaet->setGeometry(225,75,85,85);
    ButtonSpule = new QPushButton("Spule \n berechnen", this);
    ButtonSpule->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSpule->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonSpule->setGeometry(25,185,85,85);
    ButtonLuftspule = new QPushButton("Luftspule \n berechnen", this);
    ButtonLuftspule->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLuftspule->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonLuftspule->setGeometry(125,185,85,85);
    ButtonTrap = new QPushButton("Traps \n berechnen", this);
    ButtonTrap->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonTrap->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonTrap->setGeometry(225,185,85,85);
    ButtonDrahtlaenge = new QPushButton("Drahtlänge \n berechnen", this);
    ButtonDrahtlaenge->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonDrahtlaenge->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonDrahtlaenge->setGeometry(325,185,85,85);
    ButtonBeenden = new QPushButton("Beenden", this);
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonBeenden->setGeometry(25,395,85,42);
    ButtonResoTrans = new QPushButton("Resonanz- \n transform. \n berechnen", this);
    ButtonResoTrans->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonResoTrans->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonResoTrans->setGeometry(25,295,85,85);
    ButtonWiderstand = new QPushButton("Widerstand\n bestimmen", this);
    ButtonWiderstand->setStyleSheet("QPushButton {image: url(H:/Github/Bilder/Widerstand.jpg);}");
    ButtonWiderstand->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonWiderstand->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonWiderstand->setGeometry(125,295,85,85);

//    QIcon iconBildWiderstand;
//    iconBildWiderstand.addFile("H:/Github/Bilder/Widerstand.jpg");
//    ButtonWiderstand->setIcon(iconBildWiderstand);

    // Bild auf der Startseite einfuegen
    QPixmap Startbild("C:/Users/Büro/Pictures/Amateurfunk_Wellenlaenge.JPG");

/// Zu erledigen: Bei Projektweitergabe (Release) kann der C:/ -Pfad nicht bestehen bleiben?
    LabelStartbild = new QLabel(this);
    LabelStartbild->setPixmap(Startbild);
    LabelStartbild->setGeometry(325,250,250,250);

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
}

void AfuBerechnung::triggeredBeenden()
{
    // Abfrage ob das Programm tatsaechlich beendet werden soll
    int ret {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle("AfuBerechnung beenden?");
    msgBox.setText(tr("Wollen Sie das Programm wirklich beenden?\n"
                      "Alle bisher eingegebenen Daten gehen dadurch verloren."));
    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Ja"));
    msgBox.setButtonText(QMessageBox::No, tr("Nein"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setEscapeButton(QMessageBox::No);
    ret = msgBox.exec();

    if (ret == QMessageBox::Yes) // Programm wird beendet
    {
        close();
    }
    else if (ret == QMessageBox::No)
    {
        return;
    }
}

void AfuBerechnung::triggeredFrequenzBerechnen()
{
    BerechnungFrequenz = new AfuBerechnungFrequenz(this);
    BerechnungFrequenz->setWindowTitle("Berechnung der Frequenz");
    BerechnungFrequenz->show();
}

void AfuBerechnung::triggeredKapazitaetBerechnen()
{
    BerechnungKapazitaet = new AfuBerechnungKapazitaet(this);
    BerechnungKapazitaet->setWindowTitle("Berechnung der Kapazität");
    BerechnungKapazitaet->show();
}

void AfuBerechnung::triggeredInduktivitaetBerechnen()
{
    BerechnungInduktivitaet = new AfuBerechnungInduktivitaet(this);
    BerechnungInduktivitaet->setWindowTitle("Berechnung der Induktivität");
    BerechnungInduktivitaet->show();
}

void AfuBerechnung::triggeredVerlaengerungBerechnen()
{
    BerechnungVerlaengerungsSpule = new AfuBerechnungVerlaengerungsSpule(this);
    BerechnungVerlaengerungsSpule->setWindowTitle("Berechnung der Spulenverlängerung");
    BerechnungVerlaengerungsSpule->show();
}

void AfuBerechnung::triggeredDrahtlaengeBerechnen()
{
    BerechnungDrahtlaenge = new AfuBerechnungDrahtlaenge(this);
    BerechnungDrahtlaenge->setWindowTitle("Berechnung der Drahtlänge");
    BerechnungDrahtlaenge->show();
}

void AfuBerechnung::triggeredLuftspuleBerechnen()
{
    /// Zu erledigen
    //    BerechnungLuftspule = new AfuBerechnungLuftspule(this);
    //    BerechnungLuftspule->setWindowTitle("Berechnung der Luftspule");
    //    BerechnungLuftspule->show();
}

void AfuBerechnung::triggeredTrapBerechnen()
{
    BerechnungTrap = new AfuBerechnungTrapantenne(this);
    BerechnungTrap->setWindowTitle("Trapantenne berechnen");
    BerechnungTrap->show();
}

void AfuBerechnung::triggeredResoTransBerechnen()
{
    BerechnungResoTrans = new AfuBerechnungResoTrans(this);
    BerechnungResoTrans->setWindowTitle("Resonanztransformation berechnen");
    BerechnungResoTrans->show();
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
    AnzeigeFrequenz->setWindowTitle("Frequenzen - digitale Betriebsarten");
    AnzeigeFrequenz->show();
}

void AfuBerechnung::triggeredAmateurfunkBaender()
{
    AmateurfunkBaender = new AfuBerechnungAmateurfunkBaender(this);
    AmateurfunkBaender->setWindowTitle("Amateurfunk-Bänder");
    AmateurfunkBaender->show();
}

void AfuBerechnung::triggeredFilter()
{
    WidgetFilter = new AfuBerechnungFilter(this);
    WidgetFilter->setWindowTitle("Infos über Filter");
    WidgetFilter->show();
}

void AfuBerechnung::triggeredWattDbm()
{
    UmrechnungWattDbm = new AfuBerechnungWattDbm(this);
    UmrechnungWattDbm->setWindowTitle("Umrechnung Watt in dBm");
    UmrechnungWattDbm->show();
}

void AfuBerechnung::triggeredWiderstand()
{
    Widerstand = new AfuBerechnungWiderstand(this);
    Widerstand->setWindowTitle("Widerstands-Farbcodetabelle");
    Widerstand->show();
}

void AfuBerechnung::triggeredEinstellungen()
{
    /// Zu erledigen: Neues Fenster erstellen für Schriftart und -größe
    WidgetEinstellungen = new AfuBerechnungEinstellungen(this);
    WidgetEinstellungen->setWindowTitle("Einstellungen");
    WidgetEinstellungen->show();
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
