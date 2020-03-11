#include "afuberechnunganzeigefrequenz.h"


// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungAnzeigeFrequenz::AfuBerechnungAnzeigeFrequenz(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    Layout = new QHBoxLayout;
    LabelEingabe = new QLabel("Betriebsart:");
    ComboBetriebsart = new QComboBox;
    EditText = new QTextEdit;
    EditText->clear();
    LayoutVertical = new QVBoxLayout(this);
    ButtonBeenden = new QPushButton("Beenden");

    /// Noch zu erledigen - Darstellung der Frequenzen als Text, je nach Wahl der ComboBox

    QStringList s_Betriebsart;
    s_Betriebsart << "PSK" << "RTTY" << "FT8" << "FT4";
    ComboBetriebsart->addItems(s_Betriebsart);
    ComboBetriebsart->setEnabled(true);

    if (s_Betriebsart[2] == "FT8")
    {
        EditText->setText("test");
    }

    Layout->addWidget(LabelEingabe);
    Layout->addWidget(ComboBetriebsart);

    LayoutVertical->addLayout(Layout);
    LayoutVertical->addWidget(EditText);
    LayoutVertical->addWidget(ButtonBeenden);

    // Erstelle Button

    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungAnzeigeFrequenz::triggeredButtonBeendenClicked()
{
    close();
}
