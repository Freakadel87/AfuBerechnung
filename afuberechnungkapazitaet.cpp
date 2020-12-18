#include "afuberechnungkapazitaet.h"


// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungKapazitaet::AfuBerechnungKapazitaet(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeL = new QLabel(tr("Eingabe Induktivität:"));
    LabelEingabeL->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEingabeF = new QLabel(tr("Eingabe Frequenz:"));
    LabelEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeC = new QLabel(tr("Ergebnis Kapazität:"));
    LabelAusgabeC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLoesung = new QLabel();
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLoesung->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    LabelEinheitC = new QLabel(tr("pF"));
    LabelEinheitC->setFont(QFont("Arial", 11, QFont::Thin));

    QStringList sLEinhF;
    sLEinhF<<"MHz"<<"kHz"<<"Hz";
    ComboEinheitF = new QComboBox();
    ComboEinheitF->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitF->addItems(sLEinhF);

    QStringList sLEinhL;
    sLEinhL<<"H"<<"mH"<<"µH"<<"nH"<<"pH";
    ComboEinheitL = new QComboBox();
    ComboEinheitL->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitL->addItems(sLEinhL);

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeL->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeL->setCursorPosition(0);
    EditEingabeL->setToolTip("Geben Sie hier Ihre Induktivität ein.");
    EditEingabeF = new QLineEdit;
    EditEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeF->setCursorPosition(0);
    EditEingabeF->setToolTip("Geben Sie hier Ihre Frequenz ein.");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonBerechnen = new QPushButton(tr("Berechnen"));
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonLeeren = new QPushButton(tr("Leeren"));
    ButtonLeeren->setWhatsThis("Mit Klick auf diesen Button, werden alle \nEingabe- und Ausgabefelder gelöscht.");
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Thin));

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelEingabeF,0,0);
    GridLayout->addWidget(EditEingabeF,0,2);
    GridLayout->addWidget(ComboEinheitF,0,3);
    GridLayout->addWidget(LabelEingabeL,1,0);
    GridLayout->addWidget(EditEingabeL,1,2);
    GridLayout->addWidget(ComboEinheitL,1,3);
    GridLayout->addWidget(LabelLoesung,3,0);
    GridLayout->addWidget(LabelAusgabeC,5,0);
    GridLayout->addWidget(LabelLoesung,5,2);
    GridLayout->addWidget(LabelEinheitC,5,3);
    GridLayout->addWidget(ButtonBerechnen,6,0);
    GridLayout->addWidget(ButtonLeeren,7,0);
    GridLayout->addWidget(ButtonBeenden,8,0);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungKapazitaet::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungKapazitaet::triggeredButtonBerechnenClicked()
{
    QString s_TextF = EditEingabeF->text();
    QString s_TextL = EditEingabeL->text();
    QString sEinhF = ComboEinheitF->currentText();
    QString sEinhL = ComboEinheitL->currentText();
    float f_PufferC {0.0};
    float f_PufferCC {0.0};
    float f_PufferL = EditEingabeL->text().toFloat();
    float f_PufferF = EditEingabeF->text().toFloat();
    float fFaktorL {0.0};
    float fFaktorF {0.0};

    if (sEinhL == "H")
    {
        fFaktorL = 1;
    }
    else if (sEinhL == "mH")
    {
        fFaktorL = 0.001;
    }
    else if (sEinhL == "µH")
    {
        fFaktorL = 0.000001;
    }
    else if (sEinhL == "nH")
    {
        fFaktorL = 0.000000001;
    }
    else if (sEinhL == "pH")
    {
        fFaktorL = 0.000000000001;
    }

    if (sEinhF == "MHz")
    {
        fFaktorF = 1000000;
    }
    else if (sEinhF == "kHz")
    {
        fFaktorF = 1000;
    }
    else if (sEinhF == "Hz")
    {
        fFaktorF = 1;
    }

    // Felder nach Korrektur wieder weiß
    EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

    if (s_TextF == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Frequenz nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    if (s_TextL == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Induktivität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }

    // Thomsonsche Schwingungsformel
    f_PufferC = 1 / ((2 * f_Pi * (f_PufferF*fFaktorF)) * (2 * f_Pi * (f_PufferF*fFaktorF)) * (f_PufferL*fFaktorL)) / 0.001;
    f_PufferCC = f_PufferC * 1,000,000,000;

    LabelLoesung->setNum(f_PufferCC);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungKapazitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeF->clear();
    EditEingabeL->clear();
    EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
}
