#include "afuberechnungdrahtlaenge.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungDrahtlaenge::AfuBerechnungDrahtlaenge(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder

    LabelLicht = new QLabel("Lichtgeschwindigkeit");
    LabelFrequenz = new QLabel("Frequenz");
    LabelErgebnisLaenge = new QLabel("Länge:");
    LabelErgebnisLaengeOVF = new QLabel("Länge:");
    LabelLambda = new QLabel("Lambda                      1 /");
    LabelFaktorVer = new QLabel("Verkürzungsfaktor");
    LabelInfo = new QLabel("Drahtlänge +5%, um Anpassungen beim Abstimmen vornehmen zu können.");

    LabelEinheitLicht = new QLabel("km/s");
    LabelEinheitFrequenz = new QLabel("MHz");
    LabelEinheitLaenge = new QLabel("m  --> mit Verkürzungsfaktor");
    LabelEinheitLaengeOVF = new QLabel("m  --> ohne Verkürzungsfaktor");

    EditEingabeFrequenz = new QLineEdit;
    ///EditEingabeFrequenz->setMask("00000.00");
    EditEingabeFrequenz->setCursorPosition(0);
    EditEingabeLambda = new QLineEdit;
    ///EditEingabeLambda->setMask("0");
    EditEingabeLambda->setCursorPosition(0);
    LabelLichtWert = new QLabel("299,972");
    LabelFaktorVerWert = new QLabel("0,955");
    LabelErgebnis = new QLabel;
    LabelErgebnisOVF = new QLabel;

    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelLicht, 0, 0);
    GridLayout->addWidget(LabelLichtWert, 0, 1);
    GridLayout->addWidget(LabelEinheitLicht, 0, 2);
    GridLayout->addWidget(LabelFrequenz, 1, 0);
    GridLayout->addWidget(EditEingabeFrequenz, 1, 1);
    GridLayout->addWidget(LabelEinheitFrequenz, 1, 2);
    GridLayout->addWidget(LabelLambda, 2, 0);
    GridLayout->addWidget(EditEingabeLambda, 2, 1);
    GridLayout->addWidget(LabelFaktorVer, 3, 0);
    GridLayout->addWidget(LabelFaktorVerWert, 3, 1);
    GridLayout->addWidget(LabelErgebnisLaenge, 5, 0);
    GridLayout->addWidget(LabelErgebnis, 5, 1);
    GridLayout->addWidget(LabelEinheitLaenge, 5, 2);
    GridLayout->addWidget(LabelErgebnisLaengeOVF, 6, 0);
    GridLayout->addWidget(LabelErgebnisOVF, 6, 1);
    GridLayout->addWidget(LabelEinheitLaengeOVF, 6, 2);
    GridLayout->addWidget(ButtonBerechnen, 9, 0);
    GridLayout->addWidget(ButtonLeeren, 10, 0);
    GridLayout->addWidget(ButtonBeenden, 11, 0);
    GridLayout->addWidget(LabelInfo, 13, 0, 1, 3);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungDrahtlaenge::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungDrahtlaenge::triggeredButtonBerechnenClicked()
{
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeFrequenz->text().toFloat();
    f_PufferLamda = EditEingabeLambda->text().toFloat();

    // Formel mit Verkuerzungsfaktor
    f_Ergebnis = f_Licht / f_PufferF / f_PufferLamda * f_FaktorVer;
    // Formel ohne Verkuerzungsfaktor
    f_ErgebnisOVF = f_Licht / f_PufferF / f_PufferLamda;

    LabelErgebnis->setNum(f_Ergebnis);
    LabelErgebnis->setFont(QFont("Arial", 11, QFont::Thin));
    LabelErgebnisOVF->setNum(f_ErgebnisOVF);
    LabelErgebnisOVF->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungDrahtlaenge::triggeredButtonLeerenClicked()
{
    LabelErgebnis->clear();
    LabelErgebnisOVF->clear();
    EditEingabeFrequenz->clear();
    EditEingabeLambda->clear();
}