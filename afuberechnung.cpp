#include "afuberechnung.h"

AfuBerechnung::AfuBerechnung(QWidget *parent)
    : QMainWindow(parent)
{

}

AfuBerechnung::~AfuBerechnung()
{

}

void AfuBerechnung::Programm()
{
    QMenuBar *menuDatei = new QMenuBar;
    menuDatei->addAction(actionNeu);
    menuDatei->addAction(actionOeffnen);
    menuDatei->addAction(actionSpeichern);
    menuDatei->addSeparator();
    menuDatei->addAction(actionBeenden);

    menuOptionen = new QMenu(this);
    menuOptionen->addAction(actionFrequenz);
    menuOptionen->addAction(actionKapazitaet);
    menuOptionen->addAction(actionInduktivitaet);

    menuHilfe = new QMenu(this);
    menuHilfe->addAction(actionInfo);


    connect(actionNeu, SIGNAL(triggered()), this, SLOT(triggeredNeu()));
    connect(actionNeu, SIGNAL(triggered()), this, SLOT(triggeredOeffnen()));
    connect(actionNeu, SIGNAL(triggered()), this, SLOT(triggeredSpeichern()));
    connect(actionNeu, SIGNAL(triggered()), this, SLOT(triggeredBeenden()));

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

}

void AfuBerechnung::triggeredBeenden()
{
    close();
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
