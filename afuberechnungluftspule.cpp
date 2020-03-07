//#include "afuberechnungluftspule.h"

//AfuBerechnungLuftspule::AfuBerechnungLuftspule(QWidget *parent) : QDialog(parent)
//{
//    // Erstelle Textfelder
//    EditDurchmesser = new QLineEdit;
//    EditWindungszahl = new QLineEdit;
//    EditDurchmesserAder = new QLineEdit;
//    EditKap = new QLineEdit;

//    LabelDurchmesser = new QLabel("Durchmesser d");
//    EinheitDurchmesser = new QLabel("[mm]");
//    LabelWindungszahl = new QLabel("Windungszahl");
//    EinheitWindungen = new QLabel("[N]");
//    LabelDurchmesserAder = new QLabel("Aderdurchmesser");
//    EinheitDurchmesserAder = new QLabel("[mm]");
//    LabelKap = new QLabel("C");
//    EinheitKap = new QLabel("[pF]");

//    ButtonBeenden = new QPushButton("Beenden");
//    ButtonBerechnen = new QPushButton("Berechnen");
//    ButtonLeeren = new QPushButton("Leeren");

//    QGridLayout *GridLayout = new QGridLayout(this);
//    GridLayout->addWidget(LabelDurchmesser, 0, 0);
//    GridLayout->addWidget(EditDurchmesser, 0, 1);
//    GridLayout->addWidget(EinheitDurchmesser, 0, 2);
//    GridLayout->addWidget(LabelWindungszahl, 1, 0);
//    GridLayout->addWidget(EditWindungszahl, 1, 1);
//    GridLayout->addWidget(EinheitWindungen, 1, 2);
//    GridLayout->addWidget(LabelDurchmesserAder, 2, 0);
//    GridLayout->addWidget(EditDurchmesserAder, 2, 1);
//    GridLayout->addWidget(EinheitDurchmesserAder, 2, 2);
//    GridLayout->addWidget(LabelKap, 3, 0);
//    GridLayout->addWidget(EditKap, 3, 1);
//    GridLayout->addWidget(EinheitKap, 3, 2);
//    GridLayout->addWidget(ButtonBerechnen, 5, 0);
//    GridLayout->addWidget(ButtonLeeren, 6, 0);
//    GridLayout->addWidget(ButtonBeenden, 7, 0);

//    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
//    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
//    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
//}

//void AfuBerechnungLuftspule::triggeredButtonBeendenClicked()
//{
//    triggeredButtonLeerenClicked();
//    close();
//}

//void AfuBerechnungLuftspule::triggeredButtonBerechnenClicked()
//{
////    // Thomsonsche Schwingungsformel
////    f_PufferF = EditEingabeFrequenz->text().toFloat();
////    f_PufferLamda = EditEingabeLambda->text().toFloat();

////    // Formel mit Verkuerzungsfaktor
////    f_Ergebnis = f_Licht / f_PufferF / f_PufferLamda * f_FaktorVer;
////    // Formel ohne Verkuerzungsfaktor
////    f_ErgebnisOVF = f_Licht / f_PufferF / f_PufferLamda;

////    LabelErgebnis->setNum(f_Ergebnis);
////    LabelErgebnis->setFont(QFont("Arial", 11, QFont::Thin));
////    LabelErgebnisOVF->setNum(f_ErgebnisOVF);
////    LabelErgebnisOVF->setFont(QFont("Arial", 11, QFont::Thin));
//}

//void AfuBerechnungLuftspule::triggeredButtonLeerenClicked()
//{
//    EditDurchmesser->clear();
//    EditDurchmesserAder->clear();
//    EditKap->clear();
//    EditWindungszahl->clear();
//}
