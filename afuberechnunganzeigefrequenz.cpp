#include "afuberechnunganzeigefrequenz.h"

AfuBerechnungAnzeigeFrequenz::AfuBerechnungAnzeigeFrequenz(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    Layout = new QHBoxLayout;
    LabelEingabe = new QLabel("Betriebsart:");
    ComboBetriebsart = new QComboBox;
    ComboBetriebsart->setPalette(Qt::lightGray);
    EditText = new QTextEdit;
    EditText->clear();
    EditText->setReadOnly(true);
    LayoutVertical = new QVBoxLayout(this);
    ButtonBeenden = new QPushButton("Beenden");

    /// Noch zu erledigen - Darstellung der Frequenzen als Text, je nach Wahl der ComboBox

    QStringList s_Betriebsart;
    s_Betriebsart << "PSK" << "RTTY" << "FT8" << "FT4";
    ComboBetriebsart->addItems(s_Betriebsart);
    ComboBetriebsart->setEnabled(true);
    ComboBetriebsart->setToolTip("Wählen Sie hier die Betriebsart aus.");


    Layout->addWidget(LabelEingabe);
    Layout->addWidget(ComboBetriebsart);

    LayoutVertical->addLayout(Layout);
    LayoutVertical->addWidget(EditText);
    LayoutVertical->addWidget(ButtonBeenden);

    // Erstelle Verbindung fuer Button
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungAnzeigeFrequenz::triggeredButtonBeendenClicked()
{
    close();
}
