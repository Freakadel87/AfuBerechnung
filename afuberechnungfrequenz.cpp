#include "afuberechnungfrequenz.h"

AfuBerechnungFrequenz::AfuBerechnungFrequenz(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelEingabeL = new QLabel(tr("Eingabe Induktivität:"));
    LabelEingabeL->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEingabeC = new QLabel(tr("Eingabe Kapazität:"));
    LabelEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    LabelAusgabeF = new QLabel(tr("Ergebnis Frequenz:"));
    LabelAusgabeF->setFont(QFont("Arial", 11, QFont::Thin));
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
    EditEingabeL->setToolTip("Geben Sie hier Ihre Indultivität in [µH] ein.");
    EditEingabeC = new QLineEdit;
    EditEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeC->setInputMask("00000.00");
    EditEingabeC->setCursorPosition(0);
    EditEingabeC->setToolTip("Geben Sie hier Ihre Kapazität [pF] ein.");

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
    QString s_TextC = EditEingabeC->text();
    QString s_TextL = EditEingabeL->text();

    // Felder nach Korrektur wieder weiß
    EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

    if (s_TextC == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Kapazität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    if (s_TextL == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Induktivität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }

    // Thomsonsche Schwingungsformel
    d_PufferC = EditEingabeC->text().toFloat();
    d_PufferL = EditEingabeL->text().toFloat();

    d_PufferF = (1 / (2 * d_Pi * sqrt(d_PufferL * d_PufferC))) / 0.001;
    d_PufferFF = (int)(d_PufferF*100+0.5)/100.0;

    LabelLoesung->setNum(d_PufferFF);
    LabelLoesung->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungFrequenz::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeL->clear();
    EditEingabeC->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeL->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
}
