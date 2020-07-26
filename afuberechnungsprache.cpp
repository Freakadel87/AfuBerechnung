#include "afuberechnungsprache.h"

// Variablendeklaration
//QSettings Config;

AfuBerechnungSprache::AfuBerechnungSprache(QWidget *parent) : QDialog(parent)
{
    RadioButtonDeu = new QRadioButton(tr("de"));
    RadioButtonDeu->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonEng = new QRadioButton(tr("en"));
    RadioButtonEng->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonFra = new QRadioButton(tr("fr"));
    RadioButtonFra->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonRus = new QRadioButton(tr("ru"));
    RadioButtonRus->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonIta = new QRadioButton(tr("it"));
    RadioButtonIta->setFont(QFont("Arial", 10, QFont::Normal));

    LayoutSprache = new QVBoxLayout; //Layout Zusammensetzung
    LayoutSprache->addWidget(RadioButtonDeu);
    LayoutSprache->addWidget(RadioButtonEng);
    LayoutSprache->addWidget(RadioButtonFra);
    LayoutSprache->addWidget(RadioButtonRus);
    LayoutSprache->addWidget(RadioButtonIta);

    ///TODO: Aufruf und Umschaltung fehlt noch

    //Erstelle Buttons
    ButtonAbbrechen = new QPushButton(tr("Abbrechen"));
    ButtonAbbrechen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonAbbrechen->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));

    LayoutButton = new QHBoxLayout; //Layout Zusammensetzung
    LayoutButton->addWidget(ButtonOk);
    LayoutButton->addWidget(ButtonAbbrechen);

    LoadConfig(); //Lade gespeicherte Parameter

    //Erstelle Hauptansicht
    MainLayout = new QVBoxLayout(this);
    MainLayout->addLayout(LayoutSprache,0);
    MainLayout->addLayout(LayoutButton,1);

    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
}

void AfuBerechnungSprache::triggeredButtonAbbrechenClicked()
{
    /// TODO: Das Fenster muss nach Beendung noch zerstoert werden, um keine Zombies im RAM zu haben
    close();
    destroy();
}

void AfuBerechnungSprache::triggeredButtonOkClicked()
{
    SaveConfig(); //Merke eingestellte Parameter
    close();
    destroy();
}

/// Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungSprache::LoadConfig()
{
    ///TODO: Fehlt noch
}

/// Merke eingestellte Parameter
void AfuBerechnungSprache::SaveConfig()
{
    ///TODO: Noch nicht komplett
    //Config.setValue("/Schriftart", )
}
