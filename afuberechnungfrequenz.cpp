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

    QStringList sLEinhC;
    sLEinhC<<"F"<<"mF"<<"µF"<<"nF"<<"pF";
    ComboEinheitC = new QComboBox();
    ComboEinheitC->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitC->addItems(sLEinhC);

    QStringList sLEinhL;
    sLEinhL<<"H"<<"mH"<<"µH"<<"nH"<<"pH";
    ComboEinheitL = new QComboBox();
    ComboEinheitL->setFont(QFont("Arial", 11, QFont::Thin));
    ComboEinheitL->addItems(sLEinhL);

    LabelEinheitF = new QLabel(tr("MHz"));
    LabelEinheitF->setFont(QFont("Arial", 11, QFont::Thin));

    // Erstelle Ein- und Ausgabefelder
    EditEingabeL = new QLineEdit;
    EditEingabeL->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeL->setCursorPosition(0);
    EditEingabeL->setToolTip("Geben Sie hier Ihre Induktivität ein.");
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
    GridLayout->addWidget(LabelEingabeL,1,0);
    GridLayout->addWidget(EditEingabeL,1,2);
    GridLayout->addWidget(ComboEinheitL,1,3);
    GridLayout->addWidget(LabelLoesung,3,0);
    GridLayout->addWidget(LabelAusgabeF,5,0);
    GridLayout->addWidget(LabelLoesung,5,2);
    GridLayout->addWidget(LabelEinheitF,5,3);
    GridLayout->addWidget(ButtonBerechnen,6,0);
    GridLayout->addWidget(ButtonLeeren,7,0);
    GridLayout->addWidget(ButtonBeenden,8,0);

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
    QString sEinhC = ComboEinheitC->currentText();
    QString sEinhL = ComboEinheitL->currentText();
    QString s_TextC = EditEingabeC->text();
    QString s_TextL = EditEingabeL->text();
    float fPufferC = EditEingabeC->text().toFloat();
    float fPufferL = EditEingabeL->text().toFloat();
    float fPufferF {0.0};
    float fPufferFF {0.0};
    float fFaktorC {0.0};
    float fFaktorL {0.0};

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

    /// Zu erledigen: Formel berechnen - Rundungsfehler vorhanden?
    // Thomsonsche Schwingungsformel
    fPufferF = 1 / (2 * fPi * sqrt(fPufferL*fFaktorL * fPufferC*fFaktorC)) / 0.001;
    fPufferFF = (float)(fPufferF*100.0+0.5)/100.0;

    LabelLoesung->setNum(fPufferFF);
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
