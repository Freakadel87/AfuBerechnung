#include "afuberechnungfrequenz.h"

AfuBerechnungFrequenz::AfuBerechnungFrequenz(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeL = new QLabel("Eingabe Induktivität:");
    LabelEingabeC = new QLabel("Eingabe Kapazität:");
    LabelAusgabeF = new QLabel("Ergebnis Frequenz:");
    LabelLoesung = new QLabel();
    LabelLoesung->setStyleSheet("QLabel {background-color : lightgray; color : black;}");

    LabelEinheitC = new QLabel("pF");
    LabelEinheitF = new QLabel("MHz");
    LabelEinheitL = new QLabel("µH");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeL->setInputMask("00000.00");
    EditEingabeL->setCursorPosition(0);
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
    GridLayout->addWidget(LabelEingabeL, 1, 0);
    GridLayout->addWidget(EditEingabeL, 1, 2);
    GridLayout->addWidget(LabelEinheitL, 1, 3);
    GridLayout->addWidget(LabelLoesung, 3, 0);
    GridLayout->addWidget(LabelAusgabeF, 5, 0);
    GridLayout->addWidget(LabelLoesung, 5, 2);
    GridLayout->addWidget(LabelEinheitF, 5, 3);
    GridLayout->addWidget(ButtonBerechnen, 6, 0);
    GridLayout->addWidget(ButtonLeeren, 6, 1);
    GridLayout->addWidget(ButtonBeenden, 6, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungFrequenz::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungFrequenz::triggeredButtonBerechnenClicked()
{
    // Thomsonsche Schwingungsformel
    d_PufferC = EditEingabeC->text().toFloat();
    d_PufferL = EditEingabeL->text().toFloat();

    d_PufferF = (1 / (2 * d_Pi * sqrt(d_PufferL * d_PufferC))) / 0.001;
    d_PufferFF = (int)(d_PufferF*100+0.5)/100.0;

    LabelLoesung->setNum(d_PufferFF);
    LabelLoesung->setFont(QFont("Arial", 10, QFont::Thin));
}

void AfuBerechnungFrequenz::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeL->clear();
}
