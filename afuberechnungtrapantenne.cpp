#include "afuberechnungtrapantenne.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungTrapantenne::AfuBerechnungTrapantenne(QWidget *parent) : QDialog(parent)
{
    LabelResoFreq = new QLabel("Resonanzfrequenz Ist");
    EinheitResoFreq = new QLabel("MHz");
    LabelLaengeIst = new QLabel("Länge Ist");
    EinheitLaengeIst = new QLabel("m");
    LabelFreqSoll = new QLabel("Frequenz Soll");
    EinheitFreqSoll = new QLabel("MHz");
    LabelWelle = new QLabel("Halbwelle / Viertelwelle");
    LabelDraht = new QLabel("VF Draht");
    LabelLaengeResoIst = new QLabel("Länge Resonanz Ist");
    EinheitLaengeResoIst = new QLabel("m");
    LabelLaengeSoll = new QLabel("Länge Soll");
    EinheitLaengeSoll = new QLabel("m");
    LabelDrahtIst = new QLabel("VF Ist");
    LabelDiff = new QLabel("Differenz");
    LabelDiffErgebnis = new QLabel;
    EinheitDiff = new QLabel("m");

    EditResoFreq = new QLineEdit;
    EditResoFreq->setInputMask("000.00");
    EditResoFreq->setCursorPosition(0);

    EditLaengeIst = new QLineEdit;
    EditLaengeIst->setInputMask("00.00");
    EditLaengeIst->setCursorPosition(0);

    EditFreqSoll = new QLineEdit;
    EditFreqSoll->setInputMask("000.00");
    EditFreqSoll->setCursorPosition(0);

    EditWelle = new QLineEdit;
    EditWelle->setReadOnly(true);

    ComboWelle = new QComboBox;
    QStringList s_ListWelle;
    s_ListWelle << "Halbwelle" << "Viertelwelle";
    ComboWelle->addItems(s_ListWelle);

    if (s_ListWelle[0] == "Halbwelle")
    {
        QString s_Halbwelle = "2";
        EditWelle->setText(s_Halbwelle);
    }
    else
    {
        QString s_Viertelwelle = "4";
        EditWelle->setText(s_Viertelwelle);
    }


    EditLaengeResoIst = new QLineEdit;
    EditLaengeResoIst->setInputMask("00.00");
    EditLaengeResoIst->setCursorPosition(0);

    EditLaengeSoll = new QLineEdit;
    EditLaengeSoll->setInputMask("00.00");
    EditLaengeSoll->setCursorPosition(0);

    EditDraht = new QLineEdit;
    EditDraht->setInputMask("00.00");
    EditDraht->setCursorPosition(0);

    LabelDrahtIst = new QLabel;

    // Erstelle Buttons
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelResoFreq, 0, 0);
    GridLayout->addWidget(EditResoFreq, 0, 2);
    GridLayout->addWidget(EinheitResoFreq, 0, 3);
    GridLayout->addWidget(LabelLaengeIst, 1, 0);
    GridLayout->addWidget(EditLaengeIst, 1, 2);
    GridLayout->addWidget(EinheitLaengeIst, 1, 3);
    GridLayout->addWidget(LabelFreqSoll, 2,0);
    GridLayout->addWidget(EditFreqSoll, 2,2);
    GridLayout->addWidget(EinheitFreqSoll, 2,3);
    GridLayout->addWidget(LabelWelle, 3,0);
    GridLayout->addWidget(EditWelle, 3,2);
    GridLayout->addWidget(ComboWelle, 3,3);
    GridLayout->addWidget(LabelLaengeResoIst, 4,0);
    GridLayout->addWidget(EditLaengeResoIst, 4,2);
    GridLayout->addWidget(EinheitLaengeResoIst, 4,3);
    GridLayout->addWidget(LabelLaengeSoll, 5,0);
    GridLayout->addWidget(EditLaengeSoll, 5, 2);
    GridLayout->addWidget(EinheitLaengeSoll, 5, 3);
    GridLayout->addWidget(LabelDraht, 6, 0);
    GridLayout->addWidget(EditDraht, 6, 2);
    GridLayout->addWidget(LabelDrahtIst, 7,0);
    GridLayout->addWidget(LabelDiff, 8,0);
    GridLayout->addWidget(LabelDiffErgebnis, 8,2);
    GridLayout->addWidget(EinheitDiff, 8, 3);
    GridLayout->addWidget(ButtonBerechnen, 10,0);
    GridLayout->addWidget(ButtonLeeren, 11,0);
    GridLayout->addWidget(ButtonBeenden, 12,0);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungTrapantenne::triggeredButtonBeendenClicked()
{
    close();
}

void AfuBerechnungTrapantenne::triggeredButtonBerechnenClicked()
{
    f_PufferFreqIst = EditResoFreq->text().toFloat();
    f_PufferWelle = EditWelle->text().toFloat();

    // Berechnung der Laenge fuer Resonanz Ist
    f_Puffer = f_Licht / f_PufferFreqIst / f_PufferWelle;

    f_PufferRound = (int)(f_Puffer*100+0.5)/100.0;

    LabelDiffErgebnis->setNum(f_PufferRound);
    LabelDiffErgebnis->setFont(QFont("Arial", 11, QFont::Thin));

    // Berechnung VF Ist
    f_PufferLaengeIst = EditLaengeIst->text().toFloat();
    f_PufferLaengeResoIst = EditLaengeResoIst->text().toFloat();

    f_PufferVFIst = f_PufferLaengeIst / f_PufferLaengeResoIst;

    f_PufferRound1 = (int)(f_PufferVFIst*100+0.5)/100.0;

    LabelDrahtIstErgebnis->setNum(f_PufferRound1);
    LabelDrahtIstErgebnis->setFont(QFont("Arial", 11, QFont::Thin));

}

void AfuBerechnungTrapantenne::triggeredButtonLeerenClicked()
{
    EditDraht->clear();
    LabelDrahtIstErgebnis->clear();
    EditFreqSoll->clear();
    EditLaengeIst->clear();
    EditLaengeResoIst->clear();
    EditLaengeSoll->clear();
    EditResoFreq->clear();
}
