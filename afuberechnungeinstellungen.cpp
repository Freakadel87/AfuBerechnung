#include "afuberechnungeinstellungen.h"

// Variablendeklaration
QSettings Config;
QFont AktFont, NeuFont, AltFont;

AfuBerechnungEinstellungen::AfuBerechnungEinstellungen(QWidget *parent) : QDialog(parent)
{
    FontDialog = new QFontDialog;
    ColorDialog = new QColorDialog;
    MainLayout = new QVBoxLayout(this);
    OberesLayout = new QHBoxLayout;
    UnteresLayout = new QHBoxLayout;

    ButtonSchriftart = new QPushButton(tr("Schriftart\nwählen"));
    ButtonSchriftart->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSchriftfarbe = new QPushButton(tr("Schriftfarbe\nwählen"));
    ButtonSchriftfarbe->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");

    // Erstelle Buttons
//    ButtonAbbrechen = new QPushButton(tr("Abbrechen"));
//    ButtonAbbrechen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
//    ButtonAbbrechen->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));

    LoadConfig(); // Lade gespeicherte Parameter

    // Zusammenstellung der Layouts
    OberesLayout->addWidget(ButtonSchriftart);
    OberesLayout->addWidget(ButtonSchriftfarbe);
    UnteresLayout->addWidget(ButtonOk);
    //UnteresLayout->addWidget(ButtonAbbrechen);
    MainLayout->addLayout(OberesLayout,0);
    MainLayout->addLayout(UnteresLayout,4);

    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    //QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
    QObject::connect(ButtonSchriftart, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftartClicked()));
    QObject::connect(ButtonSchriftfarbe, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftfarbeClicked()));
}

void AfuBerechnungEinstellungen::triggeredButtonAbbrechenClicked()
{
    /// TODO: Das Fenster muss nach Beendung noch zerstoert werden, um keine Zombies im RAM zu haben
    //close();
}

void AfuBerechnungEinstellungen::triggeredButtonOkClicked()
{
    SaveConfig(); // Merke vorgenommene Einstellung
    close();
}

void AfuBerechnungEinstellungen::triggeredButtonSchriftartClicked()
{
    bool bOk;
    NeuFont = QFontDialog::getFont(&bOk, AktFont);

    if (bOk == true)
    {
        // Button "OK" im QFontDialog
        ButtonOk->setFont(NeuFont);
        //ButtonAbbrechen->setFont(NeuFont);
        ButtonSchriftart->setFont(NeuFont);
        ButtonSchriftfarbe->setFont(NeuFont);
        AltFont = NeuFont;
    }
    else
    {
        // Button "Cancel" QFontDialog
        ButtonOk->setFont(AltFont);
        //ButtonAbbrechen->setFont(AltFont);
        ButtonSchriftart->setFont(AltFont);
        ButtonSchriftfarbe->setFont(AltFont);
    }
}

void AfuBerechnungEinstellungen::triggeredButtonSchriftfarbeClicked()
{
    ///TODO: Muss wahrscheinlich genauso aufgebaut werden, wie QFont-Dialog
    QColor AktColor;
    QColor NeuColor = QColorDialog::getColor(AktColor);
}

/// Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungEinstellungen::LoadConfig()
{
    Config.value("QFont", AltFont);
    ButtonOk->setFont(AltFont);
    //ButtonAbbrechen->setFont(AltFont);
    ButtonSchriftart->setFont(AltFont);
    ButtonSchriftfarbe->setFont(AltFont);
}

/// Merke eingestellte Parameter
void AfuBerechnungEinstellungen::SaveConfig()
{
    Config.setValue("QFont", NeuFont); // Einstellung Schriftart speichern
    Config.setValue("QFont", AltFont);
}
