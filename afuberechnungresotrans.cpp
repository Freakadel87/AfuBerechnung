#include "afuberechnungresotrans.h"

AfuBerechnungResoTrans::AfuBerechnungResoTrans(QWidget *parent) : QDialog(parent)
{    
    // Erstelle Textfelder
    LabelZEingang = new QLabel("Z-Eingang R2");
    EditZEingang = new QLineEdit;
    EditZEingang->setInputMask("00000.00");
    EditZEingang->setCursorPosition(0);
    LabelEinheitZEingang = new QLabel("Ohm");

    LabelZAusgang = new QLabel("Z-Ausgang R1");
    EditZAusgang = new QLineEdit;
    EditZAusgang->setInputMask("00000.00");
    EditZAusgang->setCursorPosition(0);
    LabelEinheitZAusgang = new QLabel("Ohm");

    LabelFrequenz = new QLabel("Frequenz");
    EditFrequenz = new QLineEdit;
    EditFrequenz->setInputMask("00000.00");
    EditFrequenz->setCursorPosition(0);
    LabelEinheitFrequenz = new QLabel("MHz");

    LabelQ = new QLabel("Güte (Q)");
    LabelAusgabeQ = new QLabel;
    LabelAusgabeQ->setStyleSheet("QLabel {background-color : lightgray; color : black;}");

    LabelC = new QLabel("Kapazität (C)");
    LabelAusgabeC = new QLabel;
    LabelAusgabeC->setStyleSheet("QLabel {background-color : lightgray; color : black;}");
    LabelEinheitC = new QLabel("pF");

    LabelL = new QLabel("Induktivität (L)");
    LabelAusgabeL = new QLabel;
    LabelAusgabeL->setStyleSheet("QLabel {background-color : lightgray; color : black;}");
    LabelEinheitL = new QLabel("µH");

    LabelTextInfo = new QLabel("Eine hohe Güte eines Systems besagt, \ndass das System schwach gedämpft ist.");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout;
    GridLayout->addWidget(LabelFrequenz, 0, 0);
    GridLayout->addWidget(EditFrequenz, 0, 1);
    GridLayout->addWidget(LabelEinheitFrequenz, 0, 2);
    GridLayout->addWidget(LabelZEingang, 1, 0);
    GridLayout->addWidget(EditZEingang, 1, 1);
    GridLayout->addWidget(LabelEinheitZEingang, 1, 2);
    GridLayout->addWidget(LabelZAusgang, 2, 0);
    GridLayout->addWidget(EditZAusgang, 2, 1);
    GridLayout->addWidget(LabelEinheitZAusgang, 2, 2);
    GridLayout->addWidget(LabelC, 4, 0);
    GridLayout->addWidget(LabelAusgabeC, 4, 1);
    GridLayout->addWidget(LabelEinheitC, 4, 2);
    GridLayout->addWidget(LabelL, 5, 0);
    GridLayout->addWidget(LabelAusgabeL, 5, 1);
    GridLayout->addWidget(LabelEinheitL, 5, 2);
    GridLayout->addWidget(LabelQ, 7, 0);
    GridLayout->addWidget(LabelAusgabeQ, 7, 1);
    GridLayout->addWidget(ButtonBerechnen, 9, 0);
    GridLayout->addWidget(ButtonLeeren,10, 0);
    GridLayout->addWidget(ButtonBeenden, 11, 0);

    LayoutVBox = new QVBoxLayout(this);
    LayoutVBox->addLayout(GridLayout);
    LayoutVBox->addWidget(LabelTextInfo);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungResoTrans::triggeredButtonBerechnenClicked()
{
    // Eingabe in Float umwandeln
    f_PufferZAusgang = EditZAusgang->text().toFloat();
    f_PufferZEingang = EditZEingang->text().toFloat();
    f_PufferFrequenz = EditFrequenz->text().toFloat();

    // Berechnung von Guete (Q)
    f_PufferQ = sqrt((f_PufferZAusgang / f_PufferZEingang) -1);
    f_PufferQQ = (int)(f_PufferQ*100+0.5)/100.0;
    LabelAusgabeQ->setNum(f_PufferQQ);
    LabelAusgabeQ->setFont(QFont("Arial", 11, QFont::Thin));

    // Berechnung Kapazitaet (C)
    f_PufferC = (f_PufferQQ / (f_PufferZAusgang * 2 * f_Pi * f_PufferFrequenz * 1000000) * 1000000000000);
    LabelAusgabeC->setNum(f_PufferC);
    LabelAusgabeC->setFont(QFont("Arial", 11, QFont::Thin));

    // Berechnung Induktivitaet (L)
    f_PufferL = (((f_PufferQQ * f_PufferZEingang) / (2 * f_Pi * f_PufferFrequenz * 1000000)) * 1000000);
    LabelAusgabeL->setNum(f_PufferL);
    LabelAusgabeL->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungResoTrans::triggeredButtonLeerenClicked()
{
    EditFrequenz->clear();
    EditZAusgang->clear();
    EditZEingang->clear();
    LabelAusgabeC->clear();
    LabelAusgabeL->clear();
    LabelAusgabeQ->clear();
}

void AfuBerechnungResoTrans::triggeredButtonBeendenClicked()
{
    close();
}
