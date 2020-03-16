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

    LabelZNull = new QLabel("Z null");
    LabelWinkelX1 = new QLabel("Winkel X1");
    LabelWinkelX2 = new QLabel("Winkel X2");
    LabelLambda = new QLabel("Lambda/4");
    LabelLRest = new QLabel("L Rest");
    LabelX1 = new QLabel("X1");
    LabelX2 = new QLabel("X2");
    LabelXL = new QLabel("XL");

    // Erstelle Ein- und Ausgabefelder
    EditHoeheDipol = new QLineEdit;
    EditHoeheDipol->setInputMask("00");
    EditHoeheDipol->setCursorPosition(0);
    EditDickeDraht = new QLineEdit;
    EditDickeDraht->setInputMask("00");
    EditDickeDraht->setCursorPosition(0);
    EditLaengeSeite = new QLineEdit;
    EditLaengeSeite->setInputMask("000");
    EditLaengeSeite->setCursorPosition(0);
    EditPosSpule = new QLineEdit;
    EditPosSpule->setInputMask("000");
    EditPosSpule->setCursorPosition(0);
    EditFrequenz = new QLineEdit;
    EditFrequenz->setInputMask("000000");
    EditFrequenz->setCursorPosition(0);
    ErgebnisSpule = new QLabel;
    ErgebnisSpule->setStyleSheet("QLabel {background-color : lightgray; color : black;}");

    EditZNull = new QLineEdit;
    EditZNull->setInputMask("00000");
    EditZNull->setCursorPosition(0);
    EditWinkelX1 = new QLineEdit;
    EditWinkelX1->setInputMask("000");
    EditWinkelX1->setCursorPosition(0);
    EditWinkelX2 = new QLineEdit;
    EditWinkelX2->setInputMask("000");
    EditWinkelX2->setCursorPosition(0);
    EditLambda = new QLineEdit;
    EditLambda->setInputMask("000");
    EditLambda->setCursorPosition(0);
    EditLRest = new QLineEdit;
    EditLRest->setInputMask("000");
    EditLRest->setCursorPosition(0);
    EditX1 = new QLineEdit;
    EditX1->setInputMask("00000");
    EditX1->setCursorPosition(0);
    EditX2 = new QLineEdit;
    EditX2->setInputMask("00000");
    EditX2->setCursorPosition(0);
    EditXL = new QLineEdit;
    EditXL->setInputMask("00000");
    EditXL->setCursorPosition(0);

    LabelEinheitHoeheDipol = new QLabel("m");
    LabelEinheitDickeDraht = new QLabel("mm");
    LabelEinheitLaengeSeite = new QLabel("m");
    LabelEinheitPosSpule = new QLabel("m");
    LabelEinheitFrequenz = new QLabel("MHz");
    LabelEinheitSpule = new QLabel("µH");

    LabelEinheitZNull = new QLabel("Ohm");
    LabelEinheitWinkelX1 = new QLabel("Grad");
    LabelEinheitWinkelX2 = new QLabel("Grad");
    LabelEinheitLambda = new QLabel("m");
    LabelEinheitLRest = new QLabel("m");
    LabelEinheitX1 = new QLabel("Ohm");
    LabelEinheitX2 = new QLabel("Ohm");
    LabelEinheitXL = new QLabel("Ohm");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
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

    GridLayout->addWidget(LabelZNull, 0, 6);
    GridLayout->addWidget(LabelWinkelX1,1, 6);
    GridLayout->addWidget(LabelWinkelX2, 2, 6);
    GridLayout->addWidget(LabelLambda, 3, 6);
    GridLayout->addWidget(LabelLRest, 4, 6);
    GridLayout->addWidget(LabelX1, 5, 6);
    GridLayout->addWidget(LabelX2, 6, 6);
    GridLayout->addWidget(LabelXL, 7, 6);

    GridLayout->addWidget(EditZNull, 0, 7);
    GridLayout->addWidget(EditWinkelX1, 1, 7);
    GridLayout->addWidget(EditWinkelX2, 2, 7);
    GridLayout->addWidget(EditLambda, 3, 7);
    GridLayout->addWidget(EditLRest , 4, 7);
    GridLayout->addWidget(EditX1, 5, 7);
    GridLayout->addWidget(EditX2, 6, 7);
    GridLayout->addWidget(EditXL, 7, 7);

    GridLayout->addWidget(LabelEinheitZNull, 0, 8);
    GridLayout->addWidget(LabelEinheitWinkelX1, 1, 8);
    GridLayout->addWidget(LabelEinheitWinkelX2 , 2, 8);
    GridLayout->addWidget(LabelEinheitLambda, 3, 8);
    GridLayout->addWidget(LabelEinheitLRest, 4, 8);
    GridLayout->addWidget(LabelEinheitX1, 5, 8);
    GridLayout->addWidget(LabelEinheitX2, 6, 8);
    GridLayout->addWidget(LabelEinheitXL, 7, 8);

    GridLayout->addWidget(ButtonBerechnen, 9, 0, 1, 2);
    GridLayout->addWidget(ButtonLeeren, 10, 0, 1, 2);
    GridLayout->addWidget(ButtonBeenden, 11, 0, 1, 2);

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
    EditZNull->clear();
    EditWinkelX1->clear();
    EditWinkelX2->clear();
    EditLambda->clear();
    EditLRest->clear();
    EditX1->clear();
    EditX2->clear();
    EditXL->clear();
}
