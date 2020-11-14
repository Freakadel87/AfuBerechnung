#include "afuberechnungdezibel.h"

AfuBerechnungDezibel::AfuBerechnungDezibel(QWidget *parent) : QDialog(parent)
{
    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonBerechnen = new QPushButton(tr("Berechnen"));
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Thin));
    ButtonLeeren = new QPushButton(tr("Leeren"));
    ButtonLeeren->setWhatsThis(tr("Mit Klick auf diesen Button, werden alle \nEingabe- und Ausgabefelder gelöscht."));
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Thin));

    switch (G_iMODE)
    {
    case WIDGETDEZIBELLEISTUNG:
    {
        // Erstelle Textfelder
        LabelAusgangsLeistungP2 = new QLabel(tr("Ausgangsleistung P2:"));
        LabelAusgangsLeistungP2->setFont(QFont("Arial", 11, QFont::Thin));
        LabelEingangsLeistungP1 = new QLabel(tr("Eingangsleistung P1:"));
        LabelEingangsLeistungP1->setFont(QFont("Arial", 11, QFont::Thin));
        LabelAusgabeText = new QLabel(tr("Ergebnis Dezibel:"));
        LabelAusgabeText->setFont(QFont("Arial", 11, QFont::Thin));
        LabelAusgabeDezibel = new QLabel("");
        LabelAusgabeDezibel->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
        LabelAusgabeDezibel->setFont(QFont("Arial", 11, QFont::Thin));

        // Erstelle Ein- und Ausgabefelder
        EditEingabeEingangsLeistungP1 = new QLineEdit;
        EditEingabeEingangsLeistungP1->setFont(QFont("Arial", 11, QFont::Thin));
        EditEingabeEingangsLeistungP1->setInputMask("00000.00");
        EditEingabeEingangsLeistungP1->setCursorPosition(0);
        EditEingabeEingangsLeistungP1->setToolTip(tr("Geben Sie hier Ihre Eingangsleistung P1 in [W] ein."));
        EditEingabeAusgangsLeistungP2 = new QLineEdit;
        EditEingabeAusgangsLeistungP2->setFont(QFont("Arial", 11, QFont::Thin));
        EditEingabeAusgangsLeistungP2->setInputMask("00000.00");
        EditEingabeAusgangsLeistungP2->setCursorPosition(0);
        EditEingabeAusgangsLeistungP2->setToolTip(tr("Geben Sie hier Ihre Ausgangsleistung P2 [W] ein."));
        EditErgebnis = new QLineEdit;
        EditErgebnis->setFont(QFont("Arial", 11, QFont::Thin));
        EditErgebnis->setInputMask("00000.00");
        EditErgebnis->setCursorPosition(0);
        EditErgebnis->setToolTip(tr("Ergebnis Dezibel Leistung [W]."));

        QGridLayout *GridLayout = new QGridLayout(this);
        GridLayout->addWidget(LabelEingangsLeistungP1,0,0);
        GridLayout->addWidget(EditEingabeEingangsLeistungP1,0,2);
        GridLayout->addWidget(LabelAusgangsLeistungP2,1,0);
        GridLayout->addWidget(EditEingabeAusgangsLeistungP2,1,2);
        GridLayout->addWidget(LabelAusgabeText,2,0);
        GridLayout->addWidget(LabelAusgabeDezibel,2,2);
        GridLayout->addWidget(ButtonBerechnen,6,0);
        GridLayout->addWidget(ButtonLeeren,7,0);
        GridLayout->addWidget(ButtonBeenden,8,0);
        break;
    }
    case WIDGETDEZIBELSPANNUNG:
    {
        // Erstelle Textfelder
        LabelAusgangsSpannungU2 = new QLabel(tr("Ausgangsspannung U2:"));
        LabelAusgangsSpannungU2->setFont(QFont("Arial", 11, QFont::Thin));
        LabelEingangsSpannungU1 = new QLabel(tr("Eingangsspannung U1:"));
        LabelEingangsSpannungU1->setFont(QFont("Arial", 11, QFont::Thin));
        LabelAusgabeText = new QLabel(tr("Ergebnis Dezibel:"));
        LabelAusgabeText->setFont(QFont("Arial", 11, QFont::Thin));
        LabelAusgabeDezibel = new QLabel("");
        LabelAusgabeDezibel->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
        LabelAusgabeDezibel->setFont(QFont("Arial", 11, QFont::Thin));

        // Erstelle Ein- und Ausgabefelder
        EditEingabeEingangsSpannungU1 = new QLineEdit;
        EditEingabeEingangsSpannungU1->setFont(QFont("Arial", 11, QFont::Thin));
        EditEingabeEingangsSpannungU1->setInputMask("00000.00");
        EditEingabeEingangsSpannungU1->setCursorPosition(0);
        EditEingabeEingangsSpannungU1->setToolTip(tr("Geben Sie hier Ihre Eingangsspannung U1 in [mV] ein."));
        EditEingabeAusgangsSpannungU2 = new QLineEdit;
        EditEingabeAusgangsSpannungU2->setFont(QFont("Arial", 11, QFont::Thin));
        EditEingabeAusgangsSpannungU2->setInputMask("00000.00");
        EditEingabeAusgangsSpannungU2->setCursorPosition(0);
        EditEingabeAusgangsSpannungU2->setToolTip(tr("Geben Sie hier Ihre Ausgangsspannung U2 [mV] ein."));
        EditErgebnis = new QLineEdit;
        EditErgebnis->setFont(QFont("Arial", 11, QFont::Thin));
        EditErgebnis->setInputMask("00000.00");
        EditErgebnis->setCursorPosition(0);
        EditErgebnis->setToolTip(tr("Ergebnis Dezibel Spannung [dB]."));

        QGridLayout *GridLayout = new QGridLayout(this);
        GridLayout->addWidget(LabelEingangsSpannungU1,0,0);
        GridLayout->addWidget(EditEingabeEingangsSpannungU1,0,2);
        GridLayout->addWidget(LabelAusgangsSpannungU2,1,0);
        GridLayout->addWidget(EditEingabeAusgangsSpannungU2,1,2);
        GridLayout->addWidget(LabelAusgabeText,2,0);
        GridLayout->addWidget(LabelAusgabeDezibel,2,2);
        GridLayout->addWidget(ButtonBerechnen,6,0);
        GridLayout->addWidget(ButtonLeeren,7,0);
        GridLayout->addWidget(ButtonBeenden,8,0);
        break;
    }
    default:
    {
        QMessageBox::critical(this,"Fehler(100)"
                                   "Der G_iMODE wurde nicht korrekt besetzt. Das Fenster konnte nicht aufgebaut werden. "
                                   "Das Programm wird abgebrochen.","OK");
        exit(100);
    }
    }
    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungDezibel::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
    parent()->destroyed(nullptr); // Zerstoere Widget, damit im Hauptspeicerh keine Zombies entstehen
}

void AfuBerechnungDezibel::triggeredButtonBerechnenClicked()
{
    switch (G_iMODE)
    {
    case WIDGETDEZIBELLEISTUNG:
    {
        double dP1 = EditEingabeEingangsLeistungP1->text().toFloat(nullptr); // Eingabe der Eingangsleistung in Watt P1
        double dP2 = EditEingabeAusgangsLeistungP2->text().toFloat(nullptr); // Eingabe der Ausgangsleistung in Watt P2
        double dErgebnis {0.0}; // Ausgabe der Verstaerkung/Daempfung

        dErgebnis = log10(dP2 / dP1) * 10;
        LabelAusgabeDezibel->setNum(dErgebnis);
        LabelAusgabeDezibel->setFont(QFont("Arial", 11, QFont::Thin));

        // Felder nach Korrektur wieder weiß
        EditEingabeEingangsLeistungP1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        EditEingabeAusgangsLeistungP2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

        if (EditEingabeEingangsLeistungP1->text() == ".")
        {
            QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                                 tr("Es wurde das Feld für die Eingangsleistung P1 nicht korrekt besetzt!\n"
                                    "Bitte prüfen Sie Ihre Eingabe noch einmal."));
            EditEingabeEingangsLeistungP1->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
        }
        else if (EditEingabeAusgangsLeistungP2->text() == ".")
        {
            QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                                 tr("Es wurde das Feld für die Ausgangsleistung P2 nicht korrekt besetzt!\n"
                                    "Bitte prüfen Sie Ihre Eingabe noch einmal."));
            EditEingabeAusgangsLeistungP2->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
        }
        break;
    }
    case WIDGETDEZIBELSPANNUNG:
    {
        double dU1 = EditEingabeEingangsSpannungU1->text().toFloat(nullptr); // Eingabe der Eingangsspannung in mV U1
        double dU2 = EditEingabeAusgangsSpannungU2->text().toFloat(nullptr); // Eingabe der Ausgangsspannung in mV U2
        double dErgebnis {0.0}; // Ausgabe der Verstaerkung/Daempfung

        dErgebnis = log10(dU2 / dU1) * 20;
        LabelAusgabeDezibel->setNum(dErgebnis);
        LabelAusgabeDezibel->setFont(QFont("Arial", 11, QFont::Thin));

        // Felder nach Korrektur wieder weiß
        EditEingabeEingangsSpannungU1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        EditEingabeAusgangsSpannungU2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

        if (EditEingabeEingangsSpannungU1->text() == ".")
        {
            QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                                 tr("Es wurde das Feld für die Eingangsspannung U1 nicht korrekt besetzt!\n"
                                    "Bitte prüfen Sie Ihre Eingabe noch einmal."));
            EditEingabeEingangsSpannungU1->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
        }
        else if (EditEingabeAusgangsSpannungU2->text() == ".")
        {
            QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                                 tr("Es wurde das Feld für die Ausgangsspannung U2 nicht korrekt besetzt!\n"
                                    "Bitte prüfen Sie Ihre Eingabe noch einmal."));
            EditEingabeAusgangsSpannungU2->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
        }
        break;
    }
    default:
    {
        QMessageBox::critical(this,"Fehler(101)"
                                   "Der G_iMODE wurde nicht korrekt besetzt. Die eingegebenen Daten konnten zur Berechnung nicht eingesetzt werden. "
                                   "Das Programm wird abgebrochen.","OK");
        exit(101);
    }
    }
}

void AfuBerechnungDezibel::triggeredButtonLeerenClicked()
{
    switch (G_iMODE)
    {
    case WIDGETDEZIBELLEISTUNG:
    {
        LabelAusgabeDezibel->clear();
        EditEingabeEingangsLeistungP1->clear();
        EditEingabeAusgangsLeistungP2->clear();
        EditEingabeEingangsLeistungP1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        EditEingabeAusgangsLeistungP2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        break;
    }
    case WIDGETDEZIBELSPANNUNG:
    {
        LabelAusgabeDezibel->clear();
        EditEingabeEingangsSpannungU1->clear();
        EditEingabeAusgangsSpannungU2->clear();
        EditEingabeEingangsSpannungU1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        EditEingabeAusgangsSpannungU2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
        break;
    }
    default:
    {
        QMessageBox::warning(this,"Warnung(102)"
                                   "Der G_iMODE wurde nicht korrekt besetzt. Die Eingabefelder können nicht gelöscht werden.", "OK");
    }
    }
}
