#include "afuberechnungverlaengerungsspule.h"


// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungVerlaengerungsSpule::AfuBerechnungVerlaengerungsSpule(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelHoeheDipol = new QLabel(tr("Höhe Dipol"));
    LabelHoeheDipol->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDickeDraht = new QLabel(tr("Dicke Draht"));
    LabelDickeDraht->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLaengeSeite = new QLabel(tr("Länge Seite"));
    LabelLaengeSeite->setFont(QFont("Arial", 11, QFont::Normal));
    LabelPosSpule = new QLabel(tr("Position Spule"));
    LabelPosSpule->setFont(QFont("Arial", 11, QFont::Normal));
    LabelFrequenz = new QLabel(tr("Frequenz"));
    LabelFrequenz->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLoesungSpule = new QLabel(tr("Ergebnis Spule:"));
    LabelLoesungSpule->setFont(QFont("Arial", 11, QFont::Normal));

    LabelZNull = new QLabel(tr("Z null"));
    LabelZNull->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWinkelX1 = new QLabel(tr("Winkel X1"));
    LabelWinkelX1->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWinkelX2 = new QLabel(tr("Winkel X2"));
    LabelWinkelX2->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLambda = new QLabel(tr("Lambda/4"));
    LabelLambda->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLRest = new QLabel(tr("L Rest"));
    LabelLRest->setFont(QFont("Arial", 11, QFont::Normal));
    LabelX1 = new QLabel(tr("X1"));
    LabelX1->setFont(QFont("Arial", 11, QFont::Normal));
    LabelX2 = new QLabel(tr("X2"));
    LabelX2->setFont(QFont("Arial", 11, QFont::Normal));
    LabelXL = new QLabel(tr("XL"));
    LabelXL->setFont(QFont("Arial", 11, QFont::Normal));

    // Erstelle Ein- und Ausgabefelder
    EditHoeheDipol = new QLineEdit;
    EditHoeheDipol->setFont(QFont("Arial", 11, QFont::Normal));
    EditHoeheDipol->setInputMask("00");
    EditHoeheDipol->setCursorPosition(0);
    EditDickeDraht = new QLineEdit;
    EditDickeDraht->setFont(QFont("Arial", 11, QFont::Normal));
    EditDickeDraht->setInputMask("00");
    EditDickeDraht->setCursorPosition(0);
    EditLaengeSeite = new QLineEdit;
    EditLaengeSeite->setFont(QFont("Arial", 11, QFont::Normal));
    EditLaengeSeite->setInputMask("000");
    EditLaengeSeite->setCursorPosition(0);
    EditPosSpule = new QLineEdit;
    EditPosSpule->setFont(QFont("Arial", 11, QFont::Normal));
    EditPosSpule->setInputMask("000");
    EditPosSpule->setCursorPosition(0);
    EditFrequenz = new QLineEdit;
    EditFrequenz->setFont(QFont("Arial", 11, QFont::Normal));
    EditFrequenz->setInputMask("000000");
    EditFrequenz->setCursorPosition(0);
    ErgebnisSpule = new QLabel;
    ErgebnisSpule->setFont(QFont("Arial", 11, QFont::Normal));
    ErgebnisSpule->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");

    EditZNull = new QLineEdit;
    EditZNull->setFont(QFont("Arial", 11, QFont::Normal));
    EditZNull->setInputMask("00000");
    EditZNull->setCursorPosition(0);
    EditWinkelX1 = new QLineEdit;
    EditWinkelX1->setFont(QFont("Arial", 11, QFont::Normal));
    EditWinkelX1->setInputMask("000");
    EditWinkelX1->setCursorPosition(0);
    EditWinkelX2 = new QLineEdit;
    EditWinkelX2->setFont(QFont("Arial", 11, QFont::Normal));
    EditWinkelX2->setInputMask("000");
    EditWinkelX2->setCursorPosition(0);
    EditLambda = new QLineEdit;
    EditLambda->setFont(QFont("Arial", 11, QFont::Normal));
    EditLambda->setInputMask("000");
    EditLambda->setCursorPosition(0);
    EditLRest = new QLineEdit;
    EditLRest->setFont(QFont("Arial", 11, QFont::Normal));
    EditLRest->setInputMask("000");
    EditLRest->setCursorPosition(0);
    EditX1 = new QLineEdit;
    EditX1->setFont(QFont("Arial", 11, QFont::Normal));
    EditX1->setInputMask("00000");
    EditX1->setCursorPosition(0);
    EditX2 = new QLineEdit;
    EditX2->setFont(QFont("Arial", 11, QFont::Normal));
    EditX2->setInputMask("00000");
    EditX2->setCursorPosition(0);
    EditXL = new QLineEdit;
    EditXL->setFont(QFont("Arial", 11, QFont::Normal));
    EditXL->setInputMask("00000");
    EditXL->setCursorPosition(0);

    LabelEinheitHoeheDipol = new QLabel(tr("m"));
    LabelEinheitHoeheDipol->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitDickeDraht = new QLabel(tr("mm"));
    LabelEinheitDickeDraht->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitLaengeSeite = new QLabel(tr("m"));
    LabelEinheitLaengeSeite->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitPosSpule = new QLabel(tr("m"));
    LabelEinheitPosSpule->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitFrequenz = new QLabel(tr("MHz"));
    LabelEinheitFrequenz->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitSpule = new QLabel(tr("µH"));
    LabelEinheitSpule->setFont(QFont("Arial", 11, QFont::Normal));

    LabelEinheitZNull = new QLabel(tr("Ohm"));
    LabelEinheitZNull->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitWinkelX1 = new QLabel(tr("Grad"));
    LabelEinheitWinkelX1->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitWinkelX2 = new QLabel(tr("Grad"));
    LabelEinheitWinkelX2->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitLambda = new QLabel(tr("m"));
    LabelEinheitLambda->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitLRest = new QLabel(tr("m"));
    LabelEinheitLRest->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitX1 = new QLabel(tr("Ohm"));
    LabelEinheitX1->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitX2 = new QLabel(tr("Ohm"));
    LabelEinheitX2->setFont(QFont("Arial", 11, QFont::Normal));
    LabelEinheitXL = new QLabel(tr("Ohm"));
    LabelEinheitXL->setFont(QFont("Arial", 11, QFont::Normal));

    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Normal));
    ButtonBerechnen = new QPushButton(tr("Berechnen"));
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Normal));
    ButtonLeeren = new QPushButton(tr("Leeren"));
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Normal));

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
