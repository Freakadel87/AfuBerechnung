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

    LabelEinheitC = new QLabel(tr("pF"));
    LabelEinheitC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEinheitF = new QLabel(tr("MHz"));
    LabelEinheitF->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEinheitL = new QLabel(tr("µH"));
    LabelEinheitL->setFont(QFont("Arial", 11, QFont::Thin));

    // Erstelle Ein- und Ausgabefelder
    EditEingabeF = new QLineEdit;
    EditEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeF->setInputMask("00000.00");
    EditEingabeF->setCursorPosition(0);
    EditEingabeF->setToolTip("Geben Sie hier Ihre Frequenz in [MHz] ein.");
    EditEingabeC = new QLineEdit;
    EditEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeC->setInputMask("00000.00");
    EditEingabeC->setCursorPosition(0);
    EditEingabeC->setToolTip("Geben Sie hier Ihre Kapazität in [pF] ein.");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonBerechnen = new QPushButton(tr("Berechnen"));
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonLeeren = new QPushButton(tr("Leeren"));
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Thin));

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
    QString s_TextC = EditEingabeC->text();
    QString s_TextF = EditEingabeF->text();

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
    /// Noch zu erledigen:
    /// Die Formel arbeitet nicht richtig, oder die Formel von Frank ist falsch
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeF->text().toFloat();
    f_PufferC = EditEingabeC->text().toFloat();

    f_PufferL = (1 / ((2 * f_Pi * f_PufferF) * (2 * f_Pi * f_PufferF)) * f_PufferC) / 0.001;
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
