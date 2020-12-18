#include "afuberechnunginduktivitaet.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungInduktivitaet::AfuBerechnungInduktivitaet(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeF = new QLabel(tr("Eingabe Frequenz:"));
    LabelEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEingabeC = new QLabel(tr("Eingabe Kapazität:"));
    LabelEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeL = new QLabel(tr("Ergebnis Induktivität:"));
    LabelAusgabeL->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLoesung = new QLabel();
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLoesung->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    QStringList sLEinhC;
    sLEinhC<<"F"<<"mF"<<"µF"<<"nF"<<"pF";
    ComboEinheitC = new QComboBox();
    ComboEinheitC->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitC->addItems(sLEinhC);

    QStringList sLEinhF;
    sLEinhF<<"MHz"<<"kHz"<<"Hz";
    ComboEinheitF = new QComboBox();
    ComboEinheitF->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitF->addItems(sLEinhF);

    LabelEinheitL = new QLabel(tr("µH"));
    LabelEinheitL->setFont(QFont("Arial", 11, QFont::Thin));

    // Erstelle Ein- und Ausgabefelder
    EditEingabeF = new QLineEdit;
    EditEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeF->setCursorPosition(0);
    EditEingabeF->setToolTip("Geben Sie hier Ihre Frequenz ein.");
    EditEingabeC = new QLineEdit;
    EditEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeC->setCursorPosition(0);
    EditEingabeC->setToolTip("Geben Sie hier Ihre Kapazität ein.");

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
    GridLayout->addWidget(LabelEingabeC,0,0);
    GridLayout->addWidget(EditEingabeC,0,2);
    GridLayout->addWidget(ComboEinheitC,0,3);
    GridLayout->addWidget(LabelEingabeF,1,0);
    GridLayout->addWidget(EditEingabeF,1,2);
    GridLayout->addWidget(ComboEinheitF,1,3);
    GridLayout->addWidget(LabelLoesung,3,0);
    GridLayout->addWidget(LabelAusgabeL,5,0);
    GridLayout->addWidget(LabelLoesung,5,2);
    GridLayout->addWidget(LabelEinheitL,5,3);
    GridLayout->addWidget(ButtonBerechnen,6,0);
    GridLayout->addWidget(ButtonLeeren,7,0);
    GridLayout->addWidget(ButtonBeenden,8,0);

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
    QString s_TextC = EditEingabeC->text();
    QString s_TextF = EditEingabeF->text();
    QString sEinhC = ComboEinheitC->currentText();
    QString sEinhF = ComboEinheitF->currentText();
    float f_PufferC;
    float f_PufferL;
    float f_PufferLL;
    float f_PufferF;
    float fFaktorC {0.0};
    float fFaktorF {0.0};

    if (sEinhC == "F")
    {
        fFaktorC = 1;
    }
    else if (sEinhC == "mF")
    {
        fFaktorC = 0.001;
    }
    else if (sEinhC == "µF")
    {
        fFaktorC = 0.000001;
    }
    else if (sEinhC == "nF")
    {
        fFaktorC = 0.000000001;
    }
    else if (sEinhC == "pF")
    {
        fFaktorC = 0.000000000001;
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
    EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

    if (s_TextC == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Kapazität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    if (s_TextF == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Frequenz nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }

    /// Zu erledigen: Die Formel ueberarbeiten
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeF->text().toFloat();
    f_PufferC = EditEingabeC->text().toFloat();

    f_PufferL = (1 / ((2 * f_Pi * ((f_PufferF*fFaktorF)) * (2 * f_Pi * (f_PufferF*fFaktorF))) * (f_PufferC*fFaktorC))) / 0.001;
    f_PufferLL = (int)(f_PufferL*100+0.5)/100.0;

    LabelLoesung->setNum(f_PufferLL);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungInduktivitaet::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeF->clear();
    EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeF->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
}
