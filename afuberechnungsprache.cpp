#include "afuberechnungsprache.h"

//Variablendeklaration
//QSettings Config;
QString sSprache{}; //Variable fuer ausgewaehlte Sprache

///TODO: Es ist noch unklar, wie mit dem qt-Linguist gearbeitet werden muss.

AfuBerechnungSprache::AfuBerechnungSprache(QWidget *parent) : QDialog(parent)
{
    RadioButtonDeu = new QRadioButton(tr("de"));
    RadioButtonDeu->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonDeu->setToolTip(tr("Deutsche Sprache auswählen."));
    RadioButtonEng = new QRadioButton(tr("en"));
    RadioButtonEng->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonEng->setToolTip(tr("Englische Sprache auswählen."));
    RadioButtonFra = new QRadioButton(tr("fr"));
    RadioButtonFra->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonFra->setToolTip(tr("Französische Sprache auswählen."));
    RadioButtonRus = new QRadioButton(tr("ru"));
    RadioButtonRus->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonRus->setToolTip(tr("Russische Sprache auswählen."));
    RadioButtonIta = new QRadioButton(tr("it"));
    RadioButtonIta->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonIta->setToolTip(tr("Italienische Sprache auswählen."));
    RadioButtonSpa = new QRadioButton(tr("spa"));
    RadioButtonSpa->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonSpa->setToolTip(tr("Spanische Sprache auswählen."));
    RadioButtonPor = new QRadioButton(tr("por"));
    RadioButtonPor->setFont(QFont("Arial", 10, QFont::Normal));
    RadioButtonPor->setToolTip(tr("Portugisische Sprache auswählen."));

    LayoutSprache = new QVBoxLayout; //Layout Zusammensetzung
    LayoutSprache->addWidget(RadioButtonDeu);
    LayoutSprache->addWidget(RadioButtonEng);
    LayoutSprache->addWidget(RadioButtonFra);
    LayoutSprache->addWidget(RadioButtonRus);
    LayoutSprache->addWidget(RadioButtonIta);
    LayoutSprache->addWidget(RadioButtonSpa);
    LayoutSprache->addWidget(RadioButtonPor);

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

    LoadConfig(); //Lade gespeicherte Parameter aus Speicher

    MainLayout = new QVBoxLayout(this); //Erstelle Hauptansicht
    MainLayout->addLayout(LayoutSprache,0);
    MainLayout->addLayout(LayoutButton,1);

    //Objektkonnektivitaet
    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
    QObject::connect(RadioButtonDeu, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonDeuClicked()));
    QObject::connect(RadioButtonEng, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonEngClicked()));
    QObject::connect(RadioButtonFra, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonFraClicked()));
    QObject::connect(RadioButtonRus, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonRusClicked()));
    QObject::connect(RadioButtonIta, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonItaClicked()));
    QObject::connect(RadioButtonSpa, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonSpaClicked()));
    QObject::connect(RadioButtonPor, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonPorClicked()));
}

//Button ABBRECHEN betaetigt
void AfuBerechnungSprache::triggeredButtonAbbrechenClicked()
{
    ///TODO: Das Fenster muss nach Beendung noch zerstoert werden, um keine Zombies im RAM zu haben
    ///TODO: Abfrage nur zeigen, wenn tatsächlich etwas geändert wurde (Registrierung Mausklick möglich?)

    //Abfrage ob Aenderung gespeichert werden soll
    int retAbbrechen {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle(tr("Änderungen speichern?"));
    msgBox.setText(tr("Es wurde eine andere Sprache ausgewählt,\n"
                      "Wollen Sie die ausgewählte Sprache anwenden und speichern?"));
    msgBox.addButton(QMessageBox::Yes);
    msgBox.addButton(QMessageBox::No);
    msgBox.setButtonText(QMessageBox::Yes, tr("Ja"));
    msgBox.setButtonText(QMessageBox::No, tr("Nein"));
    msgBox.setDefaultButton(QMessageBox::No);
    msgBox.setEscapeButton(QMessageBox::No);
    retAbbrechen = msgBox.exec();

    if(retAbbrechen == QMessageBox::Yes) //Aenderung speichern und Fenster schließen
    {
        SaveConfig(); //Speichere vorgenommene Parameter
        close();
    }
    else if(retAbbrechen == QMessageBox::No) //Aenderung verwerfen und schließen
    {
        close();
        destroy();
    }
}

//Button OK betaetigt
void AfuBerechnungSprache::triggeredButtonOkClicked()
{
    //Abfrage ob Aenderung gespeichert werden soll
    int retOk {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle(tr("Änderung übernehmen und speichern"));
    msgBox.setInformativeText(sSprache);
    msgBox.addButton(QMessageBox::Ok);
    retOk = msgBox.exec();

    SaveConfig(); //Speicher vorgenommene Parameter

    if(retOk == QMessageBox::Ok) //Aenderung speichern und Fenster schließen
    {
       close();
       destroy();
    }
}

//Sprache DEUTSCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonDeuClicked()
{
    ///TODO: Sprache wird ausgewählt und erst übernommen, wenn Ok-Button betätigt wird.
    sSprache = (tr("Gewählte Sprache: <b>Deutsch</b> wird übernommen und gespeichert."));
}

//Sprache ENGLISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonEngClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Englisch</b> wird übernommen und gespeichert."));
}

//Sprache FRANZOESISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonFraClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Französisch</b> wird übernommen und gespeichert."));
}

//Sprache RUSSISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonRusClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Russisch</b> wird übernommen und gespeichert."));
}

//Sprache ITALIENISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonItaClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Italienisch</b> wird übernommen und gespeichert."));
}

//Sprache SPANISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonSpaClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Spanisch</b> wird übernommen und gespeichert."));
}

//Sprache PORTUGISISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonPorClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Portugisisch</b> wird übernommen und gespeichert."));
}

//Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungSprache::LoadConfig()
{
    ///TODO: Fehlt noch
}

//Speichere vorgenommene Parameter
void AfuBerechnungSprache::SaveConfig()
{
    ///TODO: Noch nicht komplett
    //Config.setValue("/Schriftart", )
}
