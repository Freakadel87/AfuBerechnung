#include "afuberechnung.h"

AfuBerechnung::~AfuBerechnung()
{

}

AfuBerechnung::AfuBerechnung(QWidget *parent)
    : QMainWindow(parent)
{
    // Erstelle Menue --> Datei --> ...
    menuDatei = menuBar()->addMenu(tr("Datei"));
    menuDateiNeu = menuDatei->addAction("Neu", this, SLOT(triggeredNeu()));
    menuDateiNeu->setIcon(QIcon::fromTheme("document-new"));
    menuDateiOeffnen = menuDatei->addAction("Öffnen", this, SLOT(triggeredOeffnen()));
    menuDateiOeffnen->setIcon(QIcon::fromTheme("document-open"));
    menuDateiSpeichern = menuDatei->addAction("Speichern", this, SLOT(triggeredSpeichern()));
    menuDateiSpeichern->setIcon(QIcon::fromTheme("document-save"));
    menuDatei->addSeparator();
    menuDateiBeenden = menuDatei->addAction("Beenden", this, SLOT(triggeredBeenden()));
    menuDateiBeenden->setIcon(QIcon::fromTheme("application-exit"));

    // Erstelle Menue --> Bearbeiten --> ...
    menuBearbeiten = menuBar()->addMenu("Bearbeiten");
    menuBearbeitenFrequenz = menuBearbeiten->addAction("&Frequenz berechnen...", this, SLOT(triggeredFrequenzBerechnen()));
    menuBearbeitenKapazitaet = menuBearbeiten->addAction("&Kapazität berechnen...", this, SLOT(triggeredKapazitaetBerechnen()));
    menuBearbeitenInduktivitaet = menuBearbeiten->addAction("&Induktivität berechnen...", this, SLOT(triggeredInduktivitaetBerechnen()));
    menuBearbeitenDrahtlaenge = menuBearbeiten->addAction("&Drahtlänge berechnen...", this, SLOT(triggeredDrahtlaengeBerechnen()));
    menuBearbeitenVerlaengerungsSpule = menuBearbeiten->addAction("&Verlängerungsspule berechnen...", this, SLOT(triggeredVerlaengerungBerechnen()));
    menuBearbeitenLuftspule = menuBearbeiten->addAction("&Luftspule berechnen...", this, SLOT(triggeredLuftspuleBerechnen()));


    // erstelle Menue --> Hilfe --> ...
    menuHilfe = menuBar()->addMenu("Hilfe");
    menuHilfeInfo = menuHilfe->addAction("Info", this, SLOT(triggeredInfo()));

    ButtonFrequenz = new QPushButton("Frequenz");
    ButtonInduktivitaet = new QPushButton("Induktivität");
    ButtonKapazitaet = new QPushButton("Kapazität");
    ButtonSpule = new QPushButton("Spule");

    GridLayoutButton = new QGridLayout();
    GridLayoutButton->addWidget(ButtonFrequenz, 0, 0, 4, 4);
    GridLayoutButton->addWidget(ButtonInduktivitaet, 0, 1, 4, 4);
    GridLayoutButton->addWidget(ButtonKapazitaet, 0, 2, 4, 4);
    GridLayoutButton->addWidget(ButtonSpule, 0, 3, 4, 4);

    QObject::connect(ButtonFrequenz, SIGNAL(clicked(bool)), this, SLOT(triggeredFrequenzBerechnen()));
    QObject::connect(ButtonInduktivitaet, SIGNAL(clicked(bool)), this, SLOT(triggeredInduktivitaetBerechnen()));
    QObject::connect(ButtonKapazitaet, SIGNAL(clicked(bool)), this, SLOT(triggeredKapazitaetBerechnen()));
    QObject::connect(ButtonSpule, SIGNAL(clicked(bool)), this, SLOT(triggeredVerlaengerungBerechnen()));
}

void AfuBerechnung::triggeredNeu()
{

}

void AfuBerechnung::triggeredOeffnen()
{
    QString fileName = QFileDialog::getOpenFileName(this, "Öffne Datei.");
    QFile file(fileName);
    QString currentFile = fileName;

    if (!file.open(QIODevice::ReadOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warnung!", "Datei konnte nicht geöffnet werden." + file.errorString());
        return;
    }

    setWindowTitle(fileName);
    QTextStream in(&file);
    QString text = in.readAll();
    file.close();
}

void AfuBerechnung::triggeredSpeichern()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Speichern unter ...");
    QFile file(fileName);

    // Datei konnte nicht gespeichert werden
    if (!file.open(QIODevice::WriteOnly | QFile::Text))
    {
        QMessageBox::warning(this, "Warnung!", "Datei konnte nicht gespeichert werden!" + file.errorString());
        return;
    }

    QString currentFile = fileName;
    setWindowTitle(fileName);
    QTextStream out(&file);
    file.close();
}

void AfuBerechnung::triggeredBeenden()
{
    close();
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
    BerechnungLuftspule = new AfuBerechnungLuftspule(this);
    BerechnungLuftspule->setWindowTitle("Berechnung der Luftspule");
    BerechnungLuftspule->show();
}

void AfuBerechnung::triggeredInfo()
{
    QMessageBox::about(this, tr("Über Formelsammlung für Amateurfunk"),
                       tr("<h2>Formelberechnung v1.0</h2>"
                          "<p>Copyright &copy; 2020 by DF1TC."
                          "<p>Für Amateurfunkanwendungen ist dieses Programm"
                          " Freeware, eine kommerzielle Nutzung ist ausschließlich mit der"
                          " Zustimmung des Autors gestattet!"));
}
