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
    LabelEinheitF = new QLabel(tr("MHz"));
    LabelEinheitF->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEinheitL = new QLabel(tr("µH"));
    LabelEinheitL->setFont(QFont("Arial", 11, QFont::Thin));

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeL->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeL->setInputMask("00000.00");
    EditEingabeL->setCursorPosition(0);
    EditEingabeL->setToolTip("Geben Sie hier Ihre Induktivität in [µH] ein.");
    EditEingabeF = new QLineEdit;
    EditEingabeF->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeF->setInputMask("00000.00");
    EditEingabeF->setCursorPosition(0);
    EditEingabeF->setToolTip("Geben Sie hier Ihre Frequenz in [MHz] ein.");

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
    GridLayout->addWidget(LabelEinheitF,0,3);
    GridLayout->addWidget(LabelEingabeL,1,0);
    GridLayout->addWidget(EditEingabeL,1,2);
    GridLayout->addWidget(LabelEinheitL,1,3);
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
    f_PufferF = EditEingabeF->text().toFloat();
    f_PufferL = EditEingabeL->text().toFloat();

    f_PufferC = 1 / ((2 * f_Pi * f_PufferF) * (2 * f_Pi * f_PufferF) * f_PufferL) / 0.001;
   // f_PufferCC = (int)(f_PufferC*100+0.5)/100.0;
    f_PufferCC = f_PufferC * 1000;

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
