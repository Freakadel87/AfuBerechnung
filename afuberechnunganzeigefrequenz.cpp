#include "afuberechnunganzeigefrequenz.h"

AfuBerechnungAnzeigeFrequenz::AfuBerechnungAnzeigeFrequenz(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    Layout = new QHBoxLayout;
    LabelEingabe = new QLabel(tr("Betriebsart:"));
    LabelEingabe->setFont(QFont("Arial", 11, QFont::Normal));
    ComboBetriebsart = new QComboBox;
    ComboBetriebsart->setStyleSheet("QComboBox {background-color : rgb(255,245,238); color : black;}");
    EditText = new QTextEdit;
    EditText->setFont(QFont("Arial", 11, QFont::Normal));
    EditText->clear();
    EditText->setReadOnly(true);
    LayoutVertical = new QVBoxLayout(this);
    ButtonBeenden = new QPushButton(tr("Schließen"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Normal));

    /// Noch zu erledigen - Darstellung der Frequenzen als Text, je nach Wahl der ComboBox

    QStringList s_Betriebsart;
    s_Betriebsart <<"<Bitte auswählen>"<<"PSK"<<"RTTY"<<"FT8"<<"FT4";
    ComboBetriebsart->setFont(QFont("Arial", 11, QFont::Normal));
    ComboBetriebsart->addItems(s_Betriebsart);
    ComboBetriebsart->setEnabled(true);
    ComboBetriebsart->setToolTip(tr("Wählen Sie hier die Betriebsart aus."));

    Layout->addWidget(LabelEingabe);
    Layout->addWidget(ComboBetriebsart);

    LayoutVertical->addLayout(Layout);
    LayoutVertical->addWidget(EditText);
    LayoutVertical->addWidget(ButtonBeenden);

    // Erstelle Verbindung fuer Button
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
    QObject::connect(ComboBetriebsart, SIGNAL(currentTextChanged(QString)), this, SLOT(triggeredComboBox()));
}

void AfuBerechnungAnzeigeFrequenz::triggeredComboBox()
{
    QString s_AuswahlCombo = ComboBetriebsart->currentText();

    if (s_AuswahlCombo == "<Bitte auswählen>")
    {
        EditText->clear();
    }
    if (s_AuswahlCombo == "PSK")
    {
        EditText->setText("160m = 1.838 MHz\n"
                          "80m = 3.580 MHz\n"
                          "40m = 7.040 MHz\n"
                          "30m = 10.141 MHz\n"
                          "20m = 14.070 MHz\n"
                          "17m = 18.098 MHz\n"
                          "15m = 21.070 MHz\n"
                          "12m = 24.920 MHz\n"
                          "10m = 28.070 MHz\n"
                          "        = 28.120 MHz\n"
                          "6m   = 50.305 MHz");
    }
    if (s_AuswahlCombo == "RTTY")
    {
        EditText->setText("160m = ??? MHz\n"
                          "80m = 3.590 MHz\n"
                          "40m = 7.043 MHz\n"
                          "30m = 10.143 MHz\n"
                          "20m = 14.080 MHz\n"
                          "17m = 18.105 MHz\n"
                          "15m = 21.080 MHz\n"
                          "12m = 24.925 MHz\n"
                          "10m = 28.080 MHz\n"
                          " 6m  = 50.600 MHz");
    }
    if (s_AuswahlCombo == "FT4")
    {
        EditText->setText("160m = 1.840 MHz\n"
                          "80m = 3.573 MHz\n"
                          "60m = 5.357 MHZ\n"
                          "40m = 7.074 MHz\n"
                          "30m = 10.136 MHz\n"
                          "20m = 14.074 MHz\n"
                          "17m = 18.100 MHz\n"
                          "15m = 21.074 MHz\n"
                          "12m = 24.915 MHz\n"
                          "10m = 28.074 MHz\n"
                          " 6m  = 50.313 MHz");
    }
    if (s_AuswahlCombo == "FT8")
    {
        EditText->setText("160m = ??? MHz\n"
                          "80m = 3.575 MHz\n"
                          "60m = ??? MHZ\n"
                          "40m = 7.0475 MHz\n"
                          "30m = 10.140 MHz\n"
                          "20m = 14.080 MHz\n"
                          "17m = 18.104 MHz\n"
                          "15m = 21.140 MHz\n"
                          "12m = 24.919 MHz\n"
                          "10m = 28.180 MHz\n"
                          " 6m  = 50.318 MHz");
    }
}

void AfuBerechnungAnzeigeFrequenz::triggeredButtonBeendenClicked()
{
    close();
}
