#include "afuberechnungresotrans.h"

AfuBerechnungResoTrans::AfuBerechnungResoTrans(QWidget *parent) : QDialog(parent)
{    
    // Erstelle Textfelder
    LabelZEingang = new QLabel("Z-Eingang R2");
    LabelZEingang->setFont(QFont("Arial", 11, QFont::Thin));
    EditZEingang = new QLineEdit;
    EditZEingang->setFont(QFont("Arial", 11, QFont::Thin));
    EditZEingang->setInputMask("00000.00");
    EditZEingang->setCursorPosition(0);
    LabelEinheitZEingang = new QLabel("Ohm");
    LabelEinheitZEingang->setFont(QFont("Arial", 11, QFont::Thin));

    LabelZAusgang = new QLabel("Z-Ausgang R1");
    LabelZAusgang->setFont(QFont("Arial", 11, QFont::Thin));
    EditZAusgang = new QLineEdit;
    EditZAusgang->setFont(QFont("Arial", 11, QFont::Thin));
    EditZAusgang->setInputMask("00000.00");
    EditZAusgang->setCursorPosition(0);
    LabelEinheitZAusgang = new QLabel("Ohm");
    LabelEinheitZAusgang->setFont(QFont("Arial", 11, QFont::Thin));

    LabelFrequenz = new QLabel("Frequenz");
    LabelFrequenz->setFont(QFont("Arial", 11, QFont::Thin));
    EditFrequenz = new QLineEdit;
    EditFrequenz->setFont(QFont("Arial", 11, QFont::Thin));
    EditFrequenz->setInputMask("00000.00");
    EditFrequenz->setCursorPosition(0);
    LabelEinheitFrequenz = new QLabel("MHz");
    LabelEinheitFrequenz->setFont(QFont("Arial", 11, QFont::Thin));

    LabelQ = new QLabel("Güte (Q)");
    LabelQ->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeQ = new QLabel;
    LabelAusgabeQ->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeQ->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    LabelC = new QLabel("Kapazität (C)");
    LabelC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeC = new QLabel;
    LabelAusgabeC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeC->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
    LabelEinheitC = new QLabel("pF");
    LabelEinheitC->setFont(QFont("Arial", 11, QFont::Thin));

    LabelL = new QLabel("Induktivität (L)");
    LabelL->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeL = new QLabel;
    LabelAusgabeL->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeL->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
    LabelEinheitL = new QLabel("µH");
    LabelEinheitL->setFont(QFont("Arial", 11, QFont::Thin));

    LabelTextInfo = new QLabel("Eine hohe Güte eines Systems besagt, \ndass das System schwach gedämpft ist.");
    LabelTextInfo->setFont(QFont("Arial", 11, QFont::Thin));

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonLeeren = new QPushButton("Leeren");
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Thin));

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
