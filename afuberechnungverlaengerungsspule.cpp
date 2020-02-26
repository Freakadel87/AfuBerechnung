#include "afuberechnungverlaengerungsspule.h"


// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungVerlaengerungsSpule::AfuBerechnungVerlaengerungsSpule(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelHoeheDipol = new QLabel("Höhe Dipol");
    LabelDickeDraht = new QLabel("Dicke Draht");
    LabelLaengeSeite = new QLabel("Länge Seite");
    LabelPosSpule = new QLabel("Position Spule");
    LabelFrequenz = new QLabel("Frequenz");
    LabelLoesungSpule = new QLabel("Ergebnis Spule:");

    // Erstelle Ein- und Ausgabefelder
    EditHoeheDipol = new QLineEdit;
    EditDickeDraht = new QLineEdit;
    EditLaengeSeite = new QLineEdit;
    EditPosSpule = new QLineEdit;
    EditFrequenz = new QLineEdit;
    ErgebnisSpule = new QLabel;

    LabelEinheitHoeheDipol = new QLabel("m");
    LabelEinheitDickeDraht = new QLabel("mm");
    LabelEinheitLaengeSeite = new QLabel("m");
    LabelEinheitPosSpule = new QLabel("m");
    LabelEinheitFrequenz = new QLabel("MHz");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelHoeheDipol, 0, 0);
    GridLayout->addWidget(LabelDickeDraht, 1, 0);
    GridLayout->addWidget(LabelLaengeSeite, 2, 0);
    GridLayout->addWidget(LabelPosSpule, 3, 0);
    GridLayout->addWidget(LabelFrequenz, 4, 0);
    GridLayout->addWidget(LabelLoesungSpule, 5, 0);

    GridLayout->addWidget(EditHoeheDipol, 0, 1);
    GridLayout->addWidget(EditDickeDraht, 1, 1);
    GridLayout->addWidget(EditLaengeSeite, 2, 1);
    GridLayout->addWidget(EditPosSpule, 3, 1);
    GridLayout->addWidget(EditFrequenz, 4, 1);
    GridLayout->addWidget(ErgebnisSpule, 5, 1);

    GridLayout->addWidget(LabelEinheitHoeheDipol, 0, 2);
    GridLayout->addWidget(LabelEinheitDickeDraht, 1, 2);
    GridLayout->addWidget(LabelEinheitLaengeSeite, 2, 2);
    GridLayout->addWidget(LabelEinheitPosSpule, 3, 2);
    GridLayout->addWidget(LabelEinheitFrequenz, 4, 2);
    GridLayout->addWidget(LabelEinheitSpule, 5, 2);

    GridLayout->addWidget(ButtonBerechnen, 6, 0);
    GridLayout->addWidget(ButtonLeeren, 6, 1);
    GridLayout->addWidget(ButtonBeenden, 6, 2);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungVerlaengerungsSpule::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungVerlaengerungsSpule::triggeredButtonBerechnenClicked()
{ //// Formel muss korrigiert werden
    d_PufferFrequenz = EditFrequenz->text().toDouble();
    d_PufferSpule = (1/(2*d_Pi*d_PufferFrequenz))*(2/3);

    ErgebnisSpule->setNum(d_PufferSpule);
    ErgebnisSpule->setFont(QFont("Arial", 11, QFont::Thin));
}

void AfuBerechnungVerlaengerungsSpule::triggeredButtonLeerenClicked()
{
    EditHoeheDipol->clear();
    EditDickeDraht->clear();
    EditLaengeSeite->clear();
    EditPosSpule->clear();
    EditFrequenz->clear();
    ErgebnisSpule->clear();
}
