#include "afuberechnungeinstellungen.h"

AfuBerechnungEinstellungen::AfuBerechnungEinstellungen(QWidget *parent) : QDialog(parent)
{
    /// Zu erledigen: [...]
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
    EditEingabeC = new QLineEdit;
    EditEingabeC->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeC->setInputMask("00000.00");
    EditEingabeC->setCursorPosition(0);

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

void AfuBerechnungEinstellungen::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungEinstellungen::triggeredButtonBerechnenClicked()
{
    QString s_TextC = EditEingabeC->text();
    QString s_TextL = EditEingabeL->text();

    if (s_TextC == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Kapazität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
    }
    if (s_TextL == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für die Induktivität nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
    }

}

void AfuBerechnungEinstellungen::triggeredButtonLeerenClicked()
{
    LabelLoesung->clear();
    EditEingabeC->clear();
    EditEingabeL->clear();
}
