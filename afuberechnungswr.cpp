#include "afuberechnungswr.h"

//Variablendeklaration
//QSettings Settings;

AfuBerechnungSwr::AfuBerechnungSwr(QWidget *parent) : QDialog(parent)
{
    LabelBandwahl = new QLabel(tr("Band"));
    ComboBoxBandwahl = new QComboBox();
    QStringList sListBand;
    sListBand<<"<Auswahl>"<<"10m"<<"12m"<<"15m"<<"17m"<<"20m"<<"40m"<<"60m"<<"80m"<<"160m";
    ComboBoxBandwahl->addItems(sListBand);

    TableWidget = new QTableWidget(20,2); // 20 Zeilen und 2 Spalten
    TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
    TableWidget->setGeometry(300,300,1000,1000);

    WidgetTrend = new QWidget();
    WidgetTrend->show();

    //Erstelle Buttons
    ButtonAbbrechen = new QPushButton(tr("Abbrechen"));
    ButtonAbbrechen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonAbbrechen->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonAbbrechen->setGeometry(10,10,50,50);
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk->setGeometry(10,10,50,50);
    ButtonAuswertung = new QPushButton(tr("Auswertung starten"));
    ButtonAuswertung->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonAuswertung->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonAuswertung->setGeometry(10,10,100,50);
    ButtonAuswertung->setDisabled(true);
    ButtonAuswertung->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : gray;}");

    /// TODO: Aktivierung des Button nur, wenn min. ein SWR-Feld ausgefuellt worden ist.
    ButtonAuswertung->setDisabled(false);
    ButtonAuswertung->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");

    GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelBandwahl,0,1);
    GridLayout->addWidget(ComboBoxBandwahl,0,2);
    GridLayout->addWidget(ButtonOk,3,1);
    GridLayout->addWidget(ButtonAbbrechen,4,1);
    GridLayout->addWidget(ButtonAuswertung,4,2);
    GridLayout->addWidget(TableWidget,1,2);
    GridLayout->addWidget(WidgetTrend,1,3);

    //Objektkonnektivitaet
    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonAbbrechen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAbbrechenClicked()));
    QObject::connect(ButtonAuswertung, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonAuswertungClicked()));
    QObject::connect(ComboBoxBandwahl, SIGNAL(currentTextChanged(QString)), this, SLOT(triggeredComboBox()));
}

// Button ABBRECHEN betaetigt
void AfuBerechnungSwr::triggeredButtonAbbrechenClicked()
{
    ///TODO: Abfrage nur zeigen, wenn tatsächlich etwas geändert wurde (Registrierung Mausklick möglich?)

    //Abfrage ob Aenderung gespeichert werden soll
    int retAbbrechen {0};
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Question);
    msgBox.setFont(QFont("Arial", 11, QFont::Normal));
    msgBox.setWindowTitle(tr("Änderungen speichern?"));
    msgBox.setText(tr("Die zuvor eingegebenen Daten gehen verloren.\n"
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

// Button OK betaetigt
void AfuBerechnungSwr::triggeredButtonOkClicked()
{

}

void AfuBerechnungSwr::triggeredButtonAuswertungClicked()
{
    ///TODO:
    ///Eingegebene Daten werden uebernommen und als Kurve in einem x/y-Koordinatensystem uebernommen.
    /// Button Auswertung muss auf true gesetzt werden.


}

void AfuBerechnungSwr::triggeredComboBox()
{
    QString sBand = ComboBoxBandwahl->currentText();

    if (sBand == tr("<Auswahl>"))
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
    }

    if (sBand == "10m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("28.000"));
        TableWidget->setItem(1,0, new QTableWidgetItem("28.100"));
        TableWidget->setItem(2,0, new QTableWidgetItem("28.200"));
        TableWidget->setItem(3,0, new QTableWidgetItem("28.300"));
        TableWidget->setItem(4,0, new QTableWidgetItem("28.400"));
        TableWidget->setItem(5,0, new QTableWidgetItem("28.500"));
        TableWidget->setItem(6,0, new QTableWidgetItem("28.600"));
        TableWidget->setItem(7,0, new QTableWidgetItem("28.700"));
        TableWidget->setItem(8,0, new QTableWidgetItem("28.800"));
        TableWidget->setItem(9,0, new QTableWidgetItem("28.900"));
        TableWidget->setItem(10,0, new QTableWidgetItem("29.000"));
        TableWidget->setItem(11,0, new QTableWidgetItem("29.100"));
        TableWidget->setItem(12,0, new QTableWidgetItem("29.200"));
        TableWidget->setItem(13,0, new QTableWidgetItem("29.300"));
        TableWidget->setItem(14,0, new QTableWidgetItem("29.400"));
        TableWidget->setItem(15,0, new QTableWidgetItem("29.500"));
        TableWidget->setItem(16,0, new QTableWidgetItem("29.600"));
        TableWidget->setItem(17,0, new QTableWidgetItem("29.700"));
    }
    else if (sBand == "12m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("24.890"));
        TableWidget->setItem(1,0, new QTableWidgetItem("24.900"));
        TableWidget->setItem(2,0, new QTableWidgetItem("24.910"));
        TableWidget->setItem(3,0, new QTableWidgetItem("24.920"));
        TableWidget->setItem(4,0, new QTableWidgetItem("24.930"));
        TableWidget->setItem(5,0, new QTableWidgetItem("24.940"));
        TableWidget->setItem(6,0, new QTableWidgetItem("24.950"));
        TableWidget->setItem(7,0, new QTableWidgetItem("24.960"));
        TableWidget->setItem(8,0, new QTableWidgetItem("24.970"));
        TableWidget->setItem(9,0, new QTableWidgetItem("24.980"));
        TableWidget->setItem(10,0, new QTableWidgetItem("24.990"));
    }
    else if (sBand == "15m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("21.000"));
        TableWidget->setItem(1,0, new QTableWidgetItem("21.050"));
        TableWidget->setItem(2,0, new QTableWidgetItem("21.100"));
        TableWidget->setItem(3,0, new QTableWidgetItem("21.150"));
        TableWidget->setItem(4,0, new QTableWidgetItem("21.200"));
        TableWidget->setItem(5,0, new QTableWidgetItem("21.250"));
        TableWidget->setItem(6,0, new QTableWidgetItem("21.300"));
        TableWidget->setItem(7,0, new QTableWidgetItem("21.350"));
        TableWidget->setItem(8,0, new QTableWidgetItem("21.400"));
        TableWidget->setItem(9,0, new QTableWidgetItem("21.450"));
    }
    else if (sBand == "17m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("18.068"));
        TableWidget->setItem(1,0, new QTableWidgetItem("18.078"));
        TableWidget->setItem(2,0, new QTableWidgetItem("18.088"));
        TableWidget->setItem(3,0, new QTableWidgetItem("18.098"));
        TableWidget->setItem(4,0, new QTableWidgetItem("18.108"));
        TableWidget->setItem(5,0, new QTableWidgetItem("18.118"));
        TableWidget->setItem(6,0, new QTableWidgetItem("18.128"));
        TableWidget->setItem(7,0, new QTableWidgetItem("18.138"));
        TableWidget->setItem(8,0, new QTableWidgetItem("18.148"));
        TableWidget->setItem(9,0, new QTableWidgetItem("18.158"));
        TableWidget->setItem(10,0, new QTableWidgetItem("18.168"));
    }
    else if (sBand == "20m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("14.000"));
        TableWidget->setItem(1,0, new QTableWidgetItem("14.050"));
        TableWidget->setItem(2,0, new QTableWidgetItem("14.100"));
        TableWidget->setItem(3,0, new QTableWidgetItem("14.150"));
        TableWidget->setItem(4,0, new QTableWidgetItem("14.200"));
        TableWidget->setItem(5,0, new QTableWidgetItem("14.250"));
        TableWidget->setItem(6,0, new QTableWidgetItem("14.300"));
        TableWidget->setItem(7,0, new QTableWidgetItem("14.350"));
    }
    else if (sBand == "40m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("7.000"));
        TableWidget->setItem(1,0, new QTableWidgetItem("7.050"));
        TableWidget->setItem(2,0, new QTableWidgetItem("7.100"));
        TableWidget->setItem(3,0, new QTableWidgetItem("7.150"));
        TableWidget->setItem(4,0, new QTableWidgetItem("7.200"));
    }
    else if (sBand == "60m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("5.351,5"));
        TableWidget->setItem(1,0, new QTableWidgetItem("5.320"));
        TableWidget->setItem(2,0, new QTableWidgetItem("5.330"));
        TableWidget->setItem(3,0, new QTableWidgetItem("5.340"));
        TableWidget->setItem(4,0, new QTableWidgetItem("5.350"));
        TableWidget->setItem(5,0, new QTableWidgetItem("5.360"));
        TableWidget->setItem(6,0, new QTableWidgetItem("5.366,5"));
    }
    else if (sBand == "80m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("3.500"));
        TableWidget->setItem(1,0, new QTableWidgetItem("3.550"));
        TableWidget->setItem(2,0, new QTableWidgetItem("3.600"));
        TableWidget->setItem(3,0, new QTableWidgetItem("3.650"));
        TableWidget->setItem(4,0, new QTableWidgetItem("3.700"));
        TableWidget->setItem(5,0, new QTableWidgetItem("3.750"));
        TableWidget->setItem(6,0, new QTableWidgetItem("3.800"));
    }
    else if (sBand == "160m")
    {
        TableWidget->clear();
        TableWidget->setHorizontalHeaderLabels(QStringList()<<tr("Frequenz")<<tr("SWR"));
        TableWidget->setItem(0,0, new QTableWidgetItem("1.800"));
        TableWidget->setItem(1,0, new QTableWidgetItem("1.850"));
        TableWidget->setItem(2,0, new QTableWidgetItem("1.900"));
        TableWidget->setItem(3,0, new QTableWidgetItem("1.950"));
        TableWidget->setItem(4,0, new QTableWidgetItem("2.000"));
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
//    int row = TableWidget->rowCount();

//    TableWidget->insertRow(row);

//    QTableWidgetItem *item0 = new QTableWidgetItem;
//    item0->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
//    TableWidget->setItem(row,0,item0);

//    QTableWidgetItem *item1 = new QTableWidgetItem;
//    item1->setTextAlignment(Qt::AlignRight | Qt::AlignVCenter);
//    TableWidget->setItem(row,0,item1);

//    TableWidget->setCurrentItem(item0);
}

void AfuBerechnungSwr::MousePressEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton)
    {
        QMessageBox::information(this, "LMT","OK");
    }
    else if (event->buttons() & Qt::RightButton)
    {
        QMessageBox::information(this, "RMT","OK");
    }
}
