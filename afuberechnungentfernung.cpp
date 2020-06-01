#include "afuberechnungentfernung.h"

AfuBerechnungEntfernung::AfuBerechnungEntfernung(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelLat1 = new QLabel(tr("Eingabe Standort A (Lat1)"));
    LabelLat1->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLat2 = new QLabel(tr("Eingabe Standort B (Lat2)"));
    LabelLat2->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLon1 = new QLabel(tr("Eingabe Standort A (Lon1)"));
    LabelLon1->setFont(QFont("Arial", 11, QFont::Thin));
    LabelLon2 = new QLabel(tr("Eingabe Standort B (Lon2)"));
    LabelLon2->setFont(QFont("Arial", 11, QFont::Thin));

    LabelErgebnis = new QLabel(tr("Distanz [km]: "));
    LabelErgebnis->setFont(QFont("Arial", 11, QFont::Thin));

    LabelEntfernung = new QLabel();
    LabelEntfernung->setFont(QFont("Arial", 11, QFont::Thin));
    LabelEntfernung->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    // Erstelle Ein- und Ausgabefelder
    EditEingabeLat1 = new QLineEdit;
    EditEingabeLat1->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeLat1->setInputMask("000.0000");
    EditEingabeLat1->setCursorPosition(0);
    EditEingabeLat1->setToolTip("Geben Sie hier Ihren Wert für Lat1 ein.");
    EditEingabeLat2 = new QLineEdit;
    EditEingabeLat2->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeLat2->setInputMask("000.0000");
    EditEingabeLat2->setCursorPosition(0);
    EditEingabeLat2->setToolTip("Geben Sie hier Ihren Wert für Lat2 ein.");
    EditEingabeLon1 = new QLineEdit;
    EditEingabeLon1->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeLon1->setInputMask("000.0000");
    EditEingabeLon1->setCursorPosition(0);
    EditEingabeLon1->setToolTip("Geben Sie hier Ihren Wert für Lon1 ein.");
    EditEingabeLon2 = new QLineEdit;
    EditEingabeLon2->setFont(QFont("Arial", 11, QFont::Thin));
    EditEingabeLon2->setInputMask("000.0000");
    EditEingabeLon2->setCursorPosition(0);
    EditEingabeLon2->setToolTip("Geben Sie hier Ihren Wert für Lon2 ein.");

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
    GridLayout->addWidget(LabelLat1,0,0);
    GridLayout->addWidget(EditEingabeLat1,0,2);
    GridLayout->addWidget(LabelLat2,1,0);
    GridLayout->addWidget(EditEingabeLat2,1,2);
    GridLayout->addWidget(LabelLon1,2,0);
    GridLayout->addWidget(EditEingabeLon1,2,2);
    GridLayout->addWidget(LabelLon2,3,0);
    GridLayout->addWidget(EditEingabeLon2,3,2);
    GridLayout->addWidget(LabelErgebnis,4,0);
    GridLayout->addWidget(LabelEntfernung,4,2);
    GridLayout->addWidget(ButtonBerechnen,6,0);
    GridLayout->addWidget(ButtonLeeren,7,0);
    GridLayout->addWidget(ButtonBeenden,8,0);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungEntfernung::triggeredButtonBeendenClicked()
{
    // Abfrage ob das Programm tatsaechlich beendet werden soll
    int ret {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle("Exakte Entfernungsberechnung für die Kugeloberfläche beenden?");
    msgBox.setText(tr("Wollen Sie das Programm wirklich beenden?\n"
                      "Alle bisher eingegebenen Daten gehen dadurch verloren."));
    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Ja"));
    msgBox.setButtonText(QMessageBox::No, tr("Nein"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setEscapeButton(QMessageBox::No);
    ret = msgBox.exec();

    if (ret == QMessageBox::Yes) // Programm wird beendet
    {
        triggeredButtonLeerenClicked();
        close();
    }
    else if (ret == QMessageBox::No)
    {
        return;
    }
}

void AfuBerechnungEntfernung::triggeredButtonBerechnenClicked()
{
    const float f_ErdRadius = 6'378.388; // Erdradius in km
    float f_Lat1 {0.0};
    float f_Lat2 {0.0};
    float f_Lon1 {0.0};
    float f_Lon2 {0.0};
    float f_Entfernung {0.0};

    // Hole eingegebene Werte
    f_Lat1 = EditEingabeLat1->text().toFloat();
    f_Lat2 = EditEingabeLat2->text().toFloat();
    f_Lon1 = EditEingabeLon1->text().toFloat();
    f_Lon2 = EditEingabeLon2->text().toFloat();

    /// TODO - Ergebnisse sind nicht korrekt
    /// TODO - Es muessen auch Werte mit "-" vorangestellt eingegeben werden koennen
    // Berechne Formel
    f_Entfernung = (f_ErdRadius * acos(sin(f_Lat1) * sin(f_Lat2) + cos(f_Lat1) * cos(f_Lat2) * cos(f_Lon2 - f_Lon1)));

    LabelEntfernung->setNum(f_Entfernung);


    // Visuelle Farbdarstellung, fuer Fehleingabe -> Felder nach Korrektur wieder weiß
    EditEingabeLat1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeLat2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeLon1->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");
    EditEingabeLon2->setStyleSheet("QLineEdit {background-color : rgb(255,255,255); color : black;}");

    QString s_EditLat1 = EditEingabeLat1->text();
    QString s_EditLat2 = EditEingabeLat2->text();
    QString s_EditLon1 = EditEingabeLon1->text();
    QString s_EditLon2 = EditEingabeLon2->text();

    // Fehlerausgabe bei leeren Feldern
    if (s_EditLat1 == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für Lat1 nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeLat1->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    else if (s_EditLat2 == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für Lat2 nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeLat2->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    else if (s_EditLon1 == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für Lon1 nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeLon1->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
    else if (s_EditLon2 == ".")
    {
        QMessageBox::warning(this, tr("Fehler bei der Eingabe!"),
                             tr("Es wurde das Feld für Lon2 nicht korrekt besetzt!\n"
                                "Bitte prüfen Sie Ihre Eingabe noch einmal."));
        EditEingabeLon2->setStyleSheet("QLineEdit {background-color : rgb(255,48,48); color : black;}");
    }
}

void AfuBerechnungEntfernung::triggeredButtonLeerenClicked()
{
    // Loesche alle Eingabefelder
    EditEingabeLat1->clear();
    EditEingabeLat2->clear();
    EditEingabeLon1->clear();
    EditEingabeLon2->clear();
    LabelEntfernung->clear();
}
