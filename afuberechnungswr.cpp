#include "afuberechnungswr.h"

//Variablendeklaration
//QSettings Settings;

AfuBerechnungSwr::AfuBerechnungSwr(QWidget *parent) : QDialog(parent)
{
    LabelUeberschrift = new QLabel(tr("SWR-Tabelle"));

    LabelBandwahl = new QLabel(tr("Band"));
    ComboBoxBandwahl = new QComboBox();
    QStringList sListBand;
    sListBand<<"<Auswahl>"<<"10m"<<"12m"<<"15m"<<"17m"<<"20m"<<"40m"<<"80m"<<"160m";
    ComboBoxBandwahl->addItems(sListBand);

    TableWidget = new QTableWidget(20,2);
    TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));


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
    GridLayout->addWidget(ButtonOk,24,1);
    GridLayout->addWidget(ButtonAbbrechen,25,1);
    GridLayout->addWidget(TableWidget,3,1);

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
void AfuBerechnungSwr::triggeredButtonOkClicked()
{
    ///TODO:
    ///Eingegebene Daten werden uebernommen und als Kurve in einem x/y-Koordinatensystem uebernommen.
    //    if ()
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

    //        if (retOk == QMessageBox::Ok) //Aenderung speichern und Fenster schließen
    //        {
    //            close();
    //            destroy();
    //        }
    //    }
}

void AfuBerechnungSwr::triggeredComboBox()
{
    QString sBand = ComboBoxBandwahl->currentText();

    if (sBand == "<Auswahl>")
    {

    }

    if (sBand == "10m")
    {

    }

    else if (sBand == "12m")
    {

    }

    else if (sBand == "15m")
    {


    }

    else if (sBand == "17m")
    {

    }

    else if (sBand == "20m")
    {

    }

    else if (sBand == "40m")
    {
        QStringList sBand40m {""};
        sBand40m<<"7.000"<<"7.050";

        ///addRow();
       // TableWidget->item(0,0)->setText(QString::number(7.000));
       // TableWidget->item(1,0)->setText(QString::number(7.050));


                TableWidget->item(0,0)->setText("7.050");
                TableWidget->item(1,0)->setText("7.100");
        //        TableWidget->item(row,3)->setText("7.150");
        //        TableWidget->item(row,4)->setText("7.200");
    }

    else if (sBand == "80m")
    {

    }

    else if (sBand == "160m")
    {

    }
}

void AfuBerechnungSwr::CreatePlotter()
{

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

void AfuBerechnungSwr::addRow()
{
    int row = TableWidget->rowCount();

    TableWidget->insertRow(row);

    QTableWidgetItem *item0 = new QTableWidgetItem;
    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    TableWidget->setItem(row,0,item0);

    QTableWidgetItem *item1 = new QTableWidgetItem;
    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
    TableWidget->setItem(row,0,item1);

    TableWidget->setCurrentItem(item0);
}
