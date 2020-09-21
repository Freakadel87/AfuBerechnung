#include "afuberechnungswr.h"

//Variablendeklaration
//QSettings Settings;

AfuBerechnungSwr::AfuBerechnungSwr(QWidget *parent) : QDialog(parent)
{
    LabelUeberschrift = new QLabel(tr("SWR-Tabelle"));

    LabelBandwahl = new QLabel(tr("Band"));
    ComboBoxBandwahl = new QComboBox();
    QStringList sListBand;
    sListBand<<"10m"<<"12m"<<"15m"<<"17m"<<"20m"<<"40m"<<"80m"<<"160m";
    ComboBoxBandwahl->addItems(sListBand);

    LabelSpalte1 = new QLabel(tr("Frequenz"));
    LabelSpalte2 = new QLabel(tr("SWR"));

    LabelZeile1 = new QLabel();
    LabelZeile2 = new QLabel();
    LabelZeile3 = new QLabel();
    LabelZeile4 = new QLabel();
    LabelZeile5 = new QLabel();
    LabelZeile6 = new QLabel();
    LabelZeile7 = new QLabel();
    LabelZeile8 = new QLabel();
    LabelZeile9 = new QLabel();
    LabelZeile10 = new QLabel();
    LabelZeile11 = new QLabel();
    LabelZeile12 = new QLabel();
    LabelZeile13 = new QLabel();
    LabelZeile14 = new QLabel();
    LabelZeile15 = new QLabel();
    LabelZeile16 = new QLabel();
    LabelZeile17 = new QLabel();
    LabelZeile18 = new QLabel();
    LabelZeile19 = new QLabel();
    LabelZeile20 = new QLabel();

    EditZeile1 = new QLineEdit();
    EditZeile2 = new QLineEdit();
    EditZeile3 = new QLineEdit();
    EditZeile4 = new QLineEdit();
    EditZeile5 = new QLineEdit();
    EditZeile6 = new QLineEdit();
    EditZeile7 = new QLineEdit();
    EditZeile8 = new QLineEdit();
    EditZeile9 = new QLineEdit();
    EditZeile10 = new QLineEdit();
    EditZeile11 = new QLineEdit();
    EditZeile12 = new QLineEdit();
    EditZeile13 = new QLineEdit();
    EditZeile14 = new QLineEdit();
    EditZeile15 = new QLineEdit();
    EditZeile16 = new QLineEdit();
    EditZeile17 = new QLineEdit();
    EditZeile18 = new QLineEdit();
    EditZeile19 = new QLineEdit();
    EditZeile20 = new QLineEdit();

    //Erstelle Buttons
    ButtonAbbrechen = new QPushButton(tr("Abbrechen"));
    ButtonAbbrechen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonAbbrechen->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));

    GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelUeberschrift,0,1);
    GridLayout->addWidget(LabelBandwahl,1,0);
    GridLayout->addWidget(ComboBoxBandwahl,1,1);
    GridLayout->addWidget(LabelSpalte1,2,1);
    GridLayout->addWidget(LabelZeile1,3,1);
    GridLayout->addWidget(LabelZeile2,4,1);
    GridLayout->addWidget(LabelZeile3,5,1);
    GridLayout->addWidget(LabelZeile4,6,1);
    GridLayout->addWidget(LabelZeile5,7,1);
    GridLayout->addWidget(LabelZeile6,8,1);
    GridLayout->addWidget(LabelZeile7,9,1);
    GridLayout->addWidget(LabelZeile8,10,1);
    GridLayout->addWidget(LabelZeile9,11,1);
    GridLayout->addWidget(LabelZeile10,12,1);
    GridLayout->addWidget(LabelZeile11,13,1);
    GridLayout->addWidget(LabelZeile12,14,1);
    GridLayout->addWidget(LabelZeile13,15,1);
    GridLayout->addWidget(LabelZeile14,16,1);
    GridLayout->addWidget(LabelZeile15,17,1);
    GridLayout->addWidget(LabelZeile16,18,1);
    GridLayout->addWidget(LabelZeile17,19,1);
    GridLayout->addWidget(LabelZeile18,20,1);
    GridLayout->addWidget(LabelZeile19,21,1);
    GridLayout->addWidget(LabelZeile20,22,1);

    GridLayout->addWidget(LabelSpalte2,2,2);
    GridLayout->addWidget(EditZeile1,3,2);
    GridLayout->addWidget(EditZeile2,4,2);
    GridLayout->addWidget(EditZeile3,5,2);
    GridLayout->addWidget(EditZeile4,6,2);
    GridLayout->addWidget(EditZeile5,7,2);
    GridLayout->addWidget(EditZeile6,8,2);
    GridLayout->addWidget(EditZeile7,9,2);
    GridLayout->addWidget(EditZeile8,10,2);
    GridLayout->addWidget(EditZeile9,11,2);
    GridLayout->addWidget(EditZeile10,12,2);
    GridLayout->addWidget(EditZeile11,13,2);
    GridLayout->addWidget(EditZeile12,14,2);
    GridLayout->addWidget(EditZeile13,15,2);
    GridLayout->addWidget(EditZeile14,16,2);
    GridLayout->addWidget(EditZeile15,17,2);
    GridLayout->addWidget(EditZeile16,18,2);
    GridLayout->addWidget(EditZeile17,19,2);
    GridLayout->addWidget(EditZeile18,20,2);
    GridLayout->addWidget(EditZeile19,21,2);
    GridLayout->addWidget(EditZeile20,22,2);

    GridLayout->addWidget(ButtonOk,24,1);
    GridLayout->addWidget(ButtonAbbrechen,25,1);

    //Objektkonnektivitaet
    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
    QObject::connect(ComboBoxBandwahl, SIGNAL(currentTextChanged(QString)), this, SLOT(triggeredComboBox()));
}

//Button ABBRECHEN betaetigt
void AfuBerechnungSwr::triggeredButtonAbbrechenClicked()
{
    ///TODO: Abfrage nur zeigen, wenn tatsächlich etwas geändert wurde (Registrierung Mausklick möglich?)

    //Abfrage ob Aenderung gespeichert werden soll
    int retAbbrechen {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle(tr("Änderungen speichern?"));
    msgBox.setText(tr("Die zuvor eingegebenen Daten gehen verloren.,\n"
                      "Wollen Sie speichern und beenden?"));
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
        destroy();
    }
    else if(retAbbrechen == QMessageBox::No) //Aenderung verwerfen und schließen
    {
        ///TODO: Funktion nicht gegeben, springt nicht auf die zuvor eingestellte Sprache zurueck
        LoadConfig();
        close();
        destroy();
    }
}

//Button OK betaetigt
void AfuBerechnungSwr::triggeredButtonOkClicked()
{
    ///TODO:
    ///Eingegebene Daten werden uebernommen und als Kurve in einem x/y-Koordinatensystem uebernommen.
//    if()
//    {
//        //Warnmeldung, wenn keine Sprache ausgewaehlt wurde
//        int retOk {0};
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Warning);
//        msgBox.setFont(QFont("Arial", 11, QFont::Normal));
//        msgBox.setWindowTitle(tr("Warnung!"));
//        msgBox.setInformativeText(tr("Achtung: Es wurde keine Sprache ausgewählt!"));
//        msgBox.addButton(QMessageBox::Ok);
//        retOk = msgBox.exec();
//    }
//    else
//    {
//        //Abfrage ob Aenderung gespeichert werden soll
//        int retOk {0};
//        QMessageBox msgBox;
//        msgBox.setIcon(QMessageBox::Information);
//        msgBox.setFont(QFont("Arial", 11, QFont::Normal));
//        msgBox.setWindowTitle(tr("Information Auswahl"));
//        msgBox.setInformativeText(sSprache);
//        msgBox.addButton(QMessageBox::Ok);
//        retOk = msgBox.exec();

//        SaveConfig(); //Speicher vorgenommene Parameter

//        if(retOk == QMessageBox::Ok) //Aenderung speichern und Fenster schließen
//        {
//            close();
//            destroy();
//        }
//    }
}

void AfuBerechnungSwr::triggeredComboBox()
{
    QString sBand = ComboBoxBandwahl->currentText();

    if(sBand == "10m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(true);
        LabelZeile12->setVisible(true);
        LabelZeile13->setVisible(true);
        LabelZeile14->setVisible(true);
        LabelZeile15->setVisible(true);
        LabelZeile16->setVisible(true);
        LabelZeile17->setVisible(true);
        LabelZeile18->setVisible(true);
        LabelZeile19->setVisible(true);
        LabelZeile20->setVisible(true);

        LabelZeile1->setText("28.000");
        LabelZeile2->setText("28.100");
        LabelZeile3->setText("28.200");
        LabelZeile4->setText("28.300");
        LabelZeile5->setText("28.400");
        LabelZeile6->setText("28.500");
        LabelZeile7->setText("28.600");
        LabelZeile8->setText("28.700");
        LabelZeile9->setText("28.800");
        LabelZeile10->setText("28.900");
        LabelZeile11->setText("29.000");
        LabelZeile12->setText("29.100");
        LabelZeile13->setText("29.200");
        LabelZeile14->setText("29.300");
        LabelZeile15->setText("29.400");
        LabelZeile16->setText("29.500");
        LabelZeile17->setText("29.600");
        LabelZeile18->setText("29.700");
        LabelZeile19->setText("29.800");
        LabelZeile20->setText("29.900");
    }

    else if(sBand == "12m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(true);
        LabelZeile12->setVisible(false);
        LabelZeile13->setVisible(false);
        LabelZeile14->setVisible(false);
        LabelZeile15->setVisible(false);
        LabelZeile16->setVisible(false);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("24.890");
        LabelZeile2->setText("24.900");
        LabelZeile3->setText("24.910");
        LabelZeile4->setText("24.920");
        LabelZeile5->setText("24.930");
        LabelZeile6->setText("24.940");
        LabelZeile7->setText("24.950");
        LabelZeile8->setText("24.960");
        LabelZeile9->setText("24.970");
        LabelZeile10->setText("24.980");
        LabelZeile11->setText("24.990");
    }

    else if(sBand == "15m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(false);
        LabelZeile12->setVisible(false);
        LabelZeile13->setVisible(false);
        LabelZeile14->setVisible(false);
        LabelZeile15->setVisible(false);
        LabelZeile16->setVisible(false);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("21.000");
        LabelZeile2->setText("21.050");
        LabelZeile3->setText("21.100");
        LabelZeile4->setText("21.150");
        LabelZeile5->setText("21.200");
        LabelZeile6->setText("21.250");
        LabelZeile7->setText("21.300");
        LabelZeile8->setText("21.350");
        LabelZeile9->setText("21.400");
        LabelZeile10->setText("21.450");
    }

    else if(sBand == "17m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(false);
        LabelZeile11->setVisible(false);
        LabelZeile12->setVisible(false);
        LabelZeile13->setVisible(false);
        LabelZeile14->setVisible(false);
        LabelZeile15->setVisible(false);
        LabelZeile16->setVisible(false);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("18.068");
        LabelZeile2->setText("18.100");
        LabelZeile3->setText("18.110");
        LabelZeile4->setText("18.120");
        LabelZeile5->setText("18.130");
        LabelZeile6->setText("18.140");
        LabelZeile7->setText("18.150");
        LabelZeile8->setText("18.160");
        LabelZeile9->setText("18.170");
    }

    else if(sBand == "20m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(false);
        LabelZeile10->setVisible(false);
        LabelZeile11->setVisible(false);
        LabelZeile12->setVisible(false);
        LabelZeile13->setVisible(false);
        LabelZeile14->setVisible(false);
        LabelZeile15->setVisible(false);
        LabelZeile16->setVisible(false);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("14.000");
        LabelZeile2->setText("14.050");
        LabelZeile3->setText("14.100");
        LabelZeile4->setText("14.150");
        LabelZeile5->setText("14.200");
        LabelZeile6->setText("14.250");
        LabelZeile7->setText("14.300");
        LabelZeile8->setText("14.350");
    }

    else if(sBand == "40m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(true);
        LabelZeile12->setVisible(true);
        LabelZeile13->setVisible(true);
        LabelZeile14->setVisible(true);
        LabelZeile15->setVisible(true);
        LabelZeile16->setVisible(true);
        LabelZeile17->setVisible(true);
        LabelZeile18->setVisible(true);
        LabelZeile19->setVisible(true);
        LabelZeile20->setVisible(true);

        LabelZeile1->setText("7.000");
        LabelZeile2->setText("7.010");
        LabelZeile3->setText("7.020");
        LabelZeile4->setText("7.030");
        LabelZeile5->setText("7.040");
        LabelZeile6->setText("7.050");
        LabelZeile7->setText("7.060");
        LabelZeile8->setText("7.070");
        LabelZeile9->setText("7.080");
        LabelZeile10->setText("7.090");
        LabelZeile11->setText("7.100");
        LabelZeile12->setText("7.110");
        LabelZeile13->setText("7.120");
        LabelZeile14->setText("7.130");
        LabelZeile15->setText("7.140");
        LabelZeile16->setText("7.150");
        LabelZeile17->setText("7.160");
        LabelZeile18->setText("7.170");
        LabelZeile19->setText("7.180");
        LabelZeile20->setText("7.190");
    }

    else if(sBand == "80m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(true);
        LabelZeile12->setVisible(true);
        LabelZeile13->setVisible(true);
        LabelZeile14->setVisible(true);
        LabelZeile15->setVisible(true);
        LabelZeile16->setVisible(true);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("3.500");
        LabelZeile2->setText("3.520");
        LabelZeile3->setText("3.540");
        LabelZeile4->setText("3.560");
        LabelZeile5->setText("3.580");
        LabelZeile6->setText("3.600");
        LabelZeile7->setText("3.620");
        LabelZeile8->setText("3.640");
        LabelZeile9->setText("3.660");
        LabelZeile10->setText("3.680");
        LabelZeile11->setText("3.700");
        LabelZeile12->setText("3.720");
        LabelZeile13->setText("3.740");
        LabelZeile14->setText("3.760");
        LabelZeile15->setText("3.780");
        LabelZeile16->setText("3.800");
    }

    else if(sBand == "160m")
    {
        LabelZeile1->setVisible(true);
        LabelZeile2->setVisible(true);
        LabelZeile3->setVisible(true);
        LabelZeile4->setVisible(true);
        LabelZeile5->setVisible(true);
        LabelZeile6->setVisible(true);
        LabelZeile7->setVisible(true);
        LabelZeile8->setVisible(true);
        LabelZeile9->setVisible(true);
        LabelZeile10->setVisible(true);
        LabelZeile11->setVisible(false);
        LabelZeile12->setVisible(false);
        LabelZeile13->setVisible(false);
        LabelZeile14->setVisible(false);
        LabelZeile15->setVisible(false);
        LabelZeile16->setVisible(false);
        LabelZeile17->setVisible(false);
        LabelZeile18->setVisible(false);
        LabelZeile19->setVisible(false);
        LabelZeile20->setVisible(false);

        LabelZeile1->setText("1.810");
        LabelZeile2->setText("1.820");
        LabelZeile3->setText("1.830");
        LabelZeile4->setText("1.840");
        LabelZeile5->setText("1.850");
        LabelZeile6->setText("1.860");
        LabelZeile7->setText("1.870");
        LabelZeile8->setText("1.880");
        LabelZeile9->setText("1.890");
        LabelZeile10->setText("2.000");
    }
}

//Lade gespeicherte Parameter und schreibe sie zurueck
void AfuBerechnungSwr::LoadConfig()
{

}

//Speichere vorgenommene Parameter
void AfuBerechnungSwr::SaveConfig()
{
    //Settings.value("RadioButtonDeu", bMerker_Deu);
}
