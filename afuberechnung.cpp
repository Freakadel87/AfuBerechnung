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
    menuBearbeiten = menuBar()->addMenu(tr("Bearbeiten"));
    menuBearbeitenFrequenz = menuBearbeiten->addAction("Frequenz berechnen...", this, SLOT(triggeredFrequenzBerechnen()));
    menuBearbeitenKapazitaet = menuBearbeiten->addAction("Kapazität berechnen...", this, SLOT(triggeredKapazitaetBerechnen()));
    menuBearbeitenInduktivitaet = menuBearbeiten->addAction("Induktivität berechnen...", this, SLOT(triggeredInduktivitaetBerechnen()));

    // erstelle Menue --> Hilfe --> ...
    menuHilfe = menuBar()->addMenu(tr("Hilfe"));
    menuHilfeInfo = menuHilfe->addAction("Info", this, SLOT(triggeredInfo()));
}

void AfuBerechnung::Programm()
{

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
    ///frequenzBerechnung = new afuberechnungfrequenz(dynamic_cast<QWidget*>(this));
}

void AfuBerechnung::triggeredKapazitaetBerechnen()
{

}

void AfuBerechnung::triggeredInduktivitaetBerechnen()
{

}

void AfuBerechnung::triggeredInfo()
{
    QMessageBox::about(this, tr("Über Formelberechnung von Thomson"),
                       tr("<h2>Gleichungsberechnung 1.0</h2>"
                          "<p>Copyright &copy; 2020 by DF1TC."
                          "<p>Für Amateurfunkanwendungen ist dieses Programm"
                          " Freeware, eine kommerzielle Nutzung ist ausschließlich mit der"
                          " Zustimmung des Autors gestattet!"));
}
