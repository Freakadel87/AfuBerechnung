#include "afuberechnungresotrans.h"

AfuBerechnungResoTrans::AfuBerechnungResoTrans(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelLoesung = new QLabel("Q");
    LabelErgebnis = new QLabel();
    LabelErgebnis->setStyleSheet("QLabel {background-color : lightgray; color : black;}");
    LabelAusgabeC = new QLabel("Kapazität");
    LabelAusgabeL = new QLabel("Induktivität");
    LabelEinheitC = new QLabel("pF");
    LabelEinheitL = new QLabel("µH");
    LabelEingabeFrequenz = new QLabel("Frequenz");
    LabelEingabeZAusgang = new QLabel("Z-Ausgang R1");
    LabelEingabeZEingang = new QLabel("Z-Eingang R2");
    LabelEinheitFrequenz = new QLabel("MHz");
    LabelEinheitZAusgang = new QLabel("Ohm");
    LabelEinheitZEingang = new QLabel("Ohm");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeFrequenz = new QLineEdit;
    EditEingabeFrequenz->setInputMask("00000.00");
    EditEingabeFrequenz->setCursorPosition(0);
    EditEingabeZAusgang = new QLineEdit;
    EditEingabeZAusgang->setInputMask("00000.00");
    EditEingabeZAusgang->setCursorPosition(0);
    EditEingabeZEingang = new QLineEdit;
    EditEingabeZEingang->setInputMask("00000.00");
    EditEingabeZEingang->setCursorPosition(0);
    EditAnzeigeC = new QLineEdit;
    EditAnzeigeC->setReadOnly(true);
    EditAnzeigeL = new QLineEdit;
    EditAnzeigeL->setReadOnly(true);

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelEingabeFrequenz, 0, 0);
    GridLayout->addWidget(EditEingabeFrequenz, 0, 1);
    GridLayout->addWidget(LabelEinheitFrequenz, 0, 2);
    GridLayout->addWidget(LabelEingabeZEingang, 1, 0);
    GridLayout->addWidget(EditEingabeZEingang, 1, 1);
    GridLayout->addWidget(LabelEinheitZEingang, 1, 2);
    GridLayout->addWidget(LabelEingabeZAusgang, 2, 0);
    GridLayout->addWidget(EditEingabeZAusgang, 2, 1);
    GridLayout->addWidget(LabelEinheitZAusgang, 2, 2);
    GridLayout->addWidget(LabelAusgabeC, 4, 0);
    GridLayout->addWidget(EditAnzeigeC, 4, 1);
    GridLayout->addWidget(LabelEinheitC, 4, 2);
    GridLayout->addWidget(LabelAusgabeL, 5, 0);
    GridLayout->addWidget(EditAnzeigeL, 5, 1);
    GridLayout->addWidget(LabelEinheitL, 5, 2);
    GridLayout->addWidget(LabelLoesung, 7, 0);
    GridLayout->addWidget(LabelErgebnis, 7, 1);
    GridLayout->addWidget(ButtonBerechnen, 9, 0);
    GridLayout->addWidget(ButtonLeeren,10, 0);
    GridLayout->addWidget(ButtonBeenden, 11, 0);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungResoTrans::triggeredButtonBeendenClicked()
{
    close();
}

void AfuBerechnungResoTrans::triggeredButtonBerechnenClicked()
{
    /// Noch zu erledigen
//    // Thomsonsche Schwingungsformel
//    d_PufferC = EditEingabeC->text().toFloat();
//    d_PufferL = EditEingabeL->text().toFloat();

//    d_PufferF = (1 / (2 * d_Pi * sqrt(d_PufferL * d_PufferC))) / 0.001;
//    d_PufferFF = (int)(d_PufferF*100+0.5)/100.0;

//    LabelLoesung->setNum(d_PufferFF);
//    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungResoTrans::triggeredButtonLeerenClicked()
{
//    LabelLoesung->clear();
//    EditEingabeC->clear();
//    EditEingabeL->clear();
}
