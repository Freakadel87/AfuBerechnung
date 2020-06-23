#include "afuberechnungeinstellungen.h"

// Variablendeklaration
QSettings Config;

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
    ButtonAbbrechen = new QPushButton(tr("Abbrechen"));
    ButtonAbbrechen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonAbbrechen->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));

    LoadConfig(); // Lade gespeicherte Parameter

    // Zusammenstellung der Layouts
    OberesLayout->addWidget(ButtonSchriftart);
    OberesLayout->addWidget(ButtonSchriftfarbe);
    UnteresLayout->addWidget(ButtonOk);
    UnteresLayout->addWidget(ButtonAbbrechen);
    MainLayout->addLayout(OberesLayout,0);
    MainLayout->addLayout(UnteresLayout,4);

    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
    QObject::connect(ButtonSchriftart, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftartClicked()));
    QObject::connect(ButtonSchriftfarbe, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftfarbeClicked()));
}

void AfuBerechnungEinstellungen::triggeredButtonAbbrechenClicked()
{
    /// TODO: Das Fenster muss nach Beendung noch zerstoert werden, um keine Zombies im RAM zu haben
    close();
}

void AfuBerechnungEinstellungen::triggeredButtonOkClicked()
{
    SaveConfig(); // Merke eingestellte Parameter
}

void AfuBerechnungEinstellungen::triggeredButtonSchriftartClicked()
{
    // Variablendeklaration
    bool b_Ok;
    QFont AktFont;
    QFont NeuFont = QFontDialog::getFont(&b_Ok, AktFont);

    if (b_Ok == true)
    {
        //...Benutzer hat einen neuen Font ausgewaehlt
        ButtonOk->setFont(AktFont = NeuFont);
        ButtonOk->repaint();
        ButtonAbbrechen->setFont(AktFont = NeuFont);
        ButtonAbbrechen->repaint();
        ButtonSchriftart->setFont(AktFont = NeuFont);
        ButtonSchriftart->repaint();
        ButtonSchriftfarbe->setFont(AktFont = NeuFont);
        ButtonSchriftfarbe->repaint();
    }
}

void AfuBerechnungEinstellungen::triggeredButtonSchriftfarbeClicked()
{
    ///TODO: Muss wahrscheinlich genauso aufgebaut werden, wie QFont-Dialog
    ColorDialog->show();
}

/// Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungEinstellungen::LoadConfig()
{
    ///TODO: Fehlt noch
}

/// Merke eingestellte Parameter
void AfuBerechnungEinstellungen::SaveConfig()
{
    ///TODO: Noch nicht komplett
    //Config.setValue("/Schriftart", )
}
