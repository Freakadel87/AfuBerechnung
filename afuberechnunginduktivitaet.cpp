#include "afuberechnunginduktivitaet.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungInduktivitaet::AfuBerechnungInduktivitaet(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeF = new QLabel("Eingabe Frequenz:");
    LabelEingabeC = new QLabel("Eingabe Kapazität:");
    LabelAusgabeL = new QLabel("Ergebnis Induktivität:");
    LabelLoesung = new QLabel();
    LabelLoesung->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    LabelEinheitC = new QLabel("pF");
    LabelEinheitF = new QLabel("MHz");
    LabelEinheitL = new QLabel("µH");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeF = new QLineEdit;
    EditEingabeF->setInputMask("00000.00");
    EditEingabeF->setCursorPosition(0);
    EditEingabeC = new QLineEdit;
    EditEingabeC->setInputMask("00000.00");
    EditEingabeC->setCursorPosition(0);

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelEingabeC, 0, 0);
    GridLayout->addWidget(EditEingabeC, 0, 2);
    GridLayout->addWidget(LabelEinheitC, 0, 3);
    GridLayout->addWidget(LabelEingabeF, 1, 0);
    GridLayout->addWidget(EditEingabeF, 1, 2);
    GridLayout->addWidget(LabelEinheitF, 1, 3);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(LabelAusgabeL, 5, 0);
    GridLayout->addWidget(LabelLoesung, 5, 2);
    GridLayout->addWidget(LabelEinheitL, 5, 3);
    GridLayout->addWidget(ButtonBerechnen, 6, 0);
    GridLayout->addWidget(ButtonLeeren, 6, 1);
    GridLayout->addWidget(ButtonBeenden, 6, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungInduktivitaet::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungInduktivitaet::triggeredButtonBerechnenClicked()
{
    /// Noch zu erledigen:
    /// Die Formel arbeitet nicht richtig, oder die Formel von Frank ist falsch
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeF->text().toFloat();
    f_PufferC = EditEingabeC->text().toFloat();

    f_PufferL = (1 / ((2 * f_Pi * f_PufferF) * (2 * f_Pi * f_PufferF)) * f_PufferC) / 0.001;
    f_PufferLL = (int)(f_PufferL*100+0.5)/100.0;

    LabelLoesung->setNum(f_PufferLL);
    LabelLoesung->setFont(QFont("Arial", 10, QFont::Thin));
}

void AfuBerechnungInduktivitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeF->clear();
}
