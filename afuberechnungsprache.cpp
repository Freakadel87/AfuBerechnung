#include "afuberechnungsprache.h"

//Variablendeklaration
QSettings Settings;
QString sSprache{}; //Variable fuer ausgewaehlte Sprache
bool bMerker_Deu {false};
bool bMerker_Eng {false};
bool bMerker_Ita {false};
bool bMerker_Fra {false};
bool bMerker_Rus {false};
bool bMerker_Spa {false};
bool bMerker_Por {false};
bool bMerker_Pol {false};

///TODO: Es ist noch unklar, wie mit dem qt-Linguist gearbeitet werden muss.

AfuBerechnungSprache::AfuBerechnungSprache(QWidget *parent) : QDialog(parent)
{
    RadioButtonDeu = new QRadioButton(tr("deutsch"));
    RadioButtonDeu->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonDeu->setToolTip(tr("Deutsche Sprache auswählen."));
    RadioButtonEng = new QRadioButton(tr("englisch"));
    RadioButtonEng->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonEng->setToolTip(tr("Englische Sprache auswählen."));
    RadioButtonFra = new QRadioButton(tr("französisch"));
    RadioButtonFra->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonFra->setToolTip(tr("Französische Sprache auswählen."));
    RadioButtonRus = new QRadioButton(tr("russisch"));
    RadioButtonRus->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonRus->setToolTip(tr("Russische Sprache auswählen."));
    RadioButtonIta = new QRadioButton(tr("italienisch"));
    RadioButtonIta->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonIta->setToolTip(tr("Italienische Sprache auswählen."));
    RadioButtonSpa = new QRadioButton(tr("spanisch"));
    RadioButtonSpa->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonSpa->setToolTip(tr("Spanische Sprache auswählen."));
    RadioButtonPor = new QRadioButton(tr("portugisisch"));
    RadioButtonPor->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonPor->setToolTip(tr("Portugisische Sprache auswählen."));
    RadioButtonPol = new QRadioButton(tr("polnisch"));
    RadioButtonPol->setFont(QFont("Arial", 10, QFont::DemiBold));
    RadioButtonPol->setToolTip(tr("Polnische Sprache auswählen."));

    LayoutSpracheLinks = new QVBoxLayout; //Layout Linke Seite
    LayoutSpracheLinks->addWidget(RadioButtonDeu);
    LayoutSpracheLinks->addWidget(RadioButtonEng);
    LayoutSpracheLinks->addWidget(RadioButtonFra);
    LayoutSpracheLinks->addWidget(RadioButtonRus);
    LayoutSpracheRechts = new QVBoxLayout; //Layout Rechte Seite
    LayoutSpracheRechts->addWidget(RadioButtonIta);
    LayoutSpracheRechts->addWidget(RadioButtonSpa);
    LayoutSpracheRechts->addWidget(RadioButtonPor);
    LayoutSpracheRechts->addWidget(RadioButtonPol);

    GridSprache = new QGridLayout; //Layout Zusammensetzung
    GridSprache->addLayout(LayoutSpracheLinks,0,0);
    GridSprache->addLayout(LayoutSpracheRechts,0,1);

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

    LoadConfig(); //Lade gespeicherte Parameter aus Speicher, wenn Fenster neu aufgerufen wird

    MainLayout = new QVBoxLayout(this); //Erstelle Hauptansicht
    MainLayout->addLayout(GridSprache,0);
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
    QObject::connect(RadioButtonPol, SIGNAL(clicked(bool)), this, SLOT(triggeredRadioButtonPolClicked()));
}

//Button ABBRECHEN betaetigt
void AfuBerechnungSprache::triggeredButtonAbbrechenClicked()
{
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

    if (retAbbrechen == QMessageBox::Yes) //Aenderung speichern und Fenster schließen
    {
        SaveConfig(); //Speichere vorgenommene Parameter
        close();
        destroy();
    }
    else if (retAbbrechen == QMessageBox::No) //Aenderung verwerfen und schließen
    {
        ///TODO: Funktion nicht gegeben, springt nicht auf die zuvor eingestellte Sprache zurueck
        LoadConfig();
        close();
        destroy();
    }
}

//Button OK betaetigt
void AfuBerechnungSprache::triggeredButtonOkClicked()
{
    if (bMerker_Deu==false && bMerker_Eng==false && bMerker_Fra==false && bMerker_Ita==false &&
            bMerker_Pol==false && bMerker_Por==false && bMerker_Rus==false && bMerker_Spa==false)
    {
        //Warnmeldung, wenn keine Sprache ausgewaehlt wurde
        int retOk {0};
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setFont(QFont("Arial", 11, QFont::Normal));
        msgBox.setWindowTitle(tr("Warnung!"));
        msgBox.setInformativeText(tr("Achtung: Es wurde keine Sprache ausgewählt!"));
        msgBox.addButton(QMessageBox::Ok);
        retOk = msgBox.exec();
    }
    else
    {
        //Abfrage ob Aenderung gespeichert werden soll
        int retOk {0};
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Information);
        msgBox.setFont(QFont("Arial", 11, QFont::Normal));
        msgBox.setWindowTitle(tr("Information Auswahl"));
        msgBox.setInformativeText(sSprache);
        msgBox.addButton(QMessageBox::Ok);
        retOk = msgBox.exec();

        SaveConfig(); //Speicher vorgenommene Parameter

        if (retOk == QMessageBox::Ok) //Aenderung speichern und Fenster schließen
        {
            close();
            destroy();
        }
    }
}

//Sprache DEUTSCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonDeuClicked()
{
    ///TODO: Sprache wird ausgewählt und erst übernommen, wenn Ok-Button betätigt wird.
    sSprache = (tr("Gewählte Sprache: <b>Deutsch</b> wird übernommen und gespeichert."));

    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(true);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Deu = true;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Sprache ENGLISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonEngClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Englisch</b> wird übernommen und gespeichert."));

    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(true);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Eng = true;
    bMerker_Deu = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Sprache FRANZOESISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonFraClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Französisch</b> wird übernommen und gespeichert."));

    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(true);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Fra = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Sprache RUSSISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonRusClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Russisch</b> wird übernommen und gespeichert."));

    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(true);
    RadioButtonSpa->setChecked(false);

    bMerker_Rus = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Spa = false;
}

//Sprache ITALIENISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonItaClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Italienisch</b> wird übernommen und gespeichert."));

    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(true);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Ita = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Sprache SPANISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonSpaClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Spanisch</b> wird übernommen und gespeichert."));

    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(true);

    bMerker_Spa = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Por = false;
    bMerker_Rus = false;
}

//Sprache PORTUGISISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonPorClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Portugisisch</b> wird übernommen und gespeichert."));

    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(false);
    RadioButtonPor->setChecked(true);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Por = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Pol = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Sprache POLNISCH ausgewaehlt
void AfuBerechnungSprache::triggeredRadioButtonPolClicked()
{
    sSprache = (tr("Gewählte Sprache: <b>Polnisch</b> wird übernommen und gespeichert."));

    RadioButtonPol->setStyleSheet("QRadioButton {background-color : rgb(202,255,112); color : black;}");
    RadioButtonEng->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonFra->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonIta->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonDeu->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonPor->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonRus->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");
    RadioButtonSpa->setStyleSheet("QRadioButton {background-color : rgb(240,240,240); color : black;}");

    RadioButtonDeu->setChecked(false);
    RadioButtonEng->setChecked(false);
    RadioButtonFra->setChecked(false);
    RadioButtonIta->setChecked(false);
    RadioButtonPol->setChecked(true);
    RadioButtonPor->setChecked(false);
    RadioButtonRus->setChecked(false);
    RadioButtonSpa->setChecked(false);

    bMerker_Pol = true;
    bMerker_Deu = false;
    bMerker_Eng = false;
    bMerker_Fra = false;
    bMerker_Ita = false;
    bMerker_Por = false;
    bMerker_Rus = false;
    bMerker_Spa = false;
}

//Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungSprache::LoadConfig()
{
    bool bSpeicherDeu = bMerker_Deu;
    bool bSpeicherEng = bMerker_Eng;
    bool bSpeicherFra = bMerker_Fra;
    bool bSpeicherIta = bMerker_Ita;
    bool bSpeicherPol = bMerker_Pol;
    bool bSpeicherPor = bMerker_Por;
    bool bSpeicherRus = bMerker_Rus;
    bool bSpeicherSpa = bMerker_Spa;

    if (bSpeicherDeu == true)
    {
        RadioButtonDeu->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherEng == true)
    {
        RadioButtonEng->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherFra == true)
    {
        RadioButtonFra->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherIta == true)
    {
        RadioButtonIta->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherPol == true)
    {
        RadioButtonPol->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherPor == true)
    {
        RadioButtonPor->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherRus == true)
    {
        RadioButtonRus->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }

    if (bSpeicherSpa == true)
    {
        RadioButtonSpa->setChecked(true);
        RadioButtonDeu->setChecked(false);
        RadioButtonEng->setChecked(false);
        RadioButtonFra->setChecked(false);
        RadioButtonIta->setChecked(false);
        RadioButtonPol->setChecked(false);
        RadioButtonPor->setChecked(false);
        RadioButtonRus->setChecked(false);
        RadioButtonSpa->setChecked(false);
    }
}

//Speichere vorgenommene Parameter
void AfuBerechnungSprache::SaveConfig()
{
    Settings.value("RadioButtonDeu", bMerker_Deu);
    Settings.value("RadioButtonEng", bMerker_Eng);
    Settings.value("RadioButtonFra", bMerker_Fra);
    Settings.value("RadioButtonIta", bMerker_Ita);
    Settings.value("RadioButtonPol", bMerker_Pol);
    Settings.value("RadioButtonPor", bMerker_Por);
    Settings.value("RadioButtonRus", bMerker_Rus);
    Settings.value("RadioButtonSpa", bMerker_Spa);
}
