#include "afuberechnungtrapantenne.h"


AfuBerechnungTrapantenne::AfuBerechnungTrapantenne(QWidget *parent) : QDialog(parent)
{
    LabelResoFreq = new QLabel(tr("Resonanzfrequenz Ist"));
    LabelResoFreq->setFont(QFont("Arial", 11, QFont::Normal));
    EinheitResoFreq = new QLabel(tr("MHz"));
    EinheitResoFreq->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLaengeIst = new QLabel(tr("Länge Ist"));
    LabelLaengeIst->setFont(QFont("Arial", 11, QFont::Normal));
    EinheitLaengeIst = new QLabel(tr("m"));
    EinheitLaengeIst->setFont(QFont("Arial", 11, QFont::Normal));
    LabelFreqSoll = new QLabel("Frequenz Soll");
    LabelFreqSoll->setFont(QFont("Arial", 11, QFont::Normal));
    EinheitFreqSoll = new QLabel(tr("MHz"));
    EinheitFreqSoll->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWelle = new QLabel(tr("Halbwelle / Viertelwelle"));
    LabelWelle->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDraht = new QLabel(tr("VF Draht"));
    LabelDraht->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLaengeResoIst = new QLabel(tr("Länge Resonanz Ist"));
    LabelLaengeResoIst->setFont(QFont("Arial", 11, QFont::Normal));
    EinheitLaengeResoIst = new QLabel(tr("m"));
    EinheitLaengeResoIst->setFont(QFont("Arial", 11, QFont::Normal));
    LabelLaengeSoll = new QLabel(tr("Länge Soll"));
    LabelLaengeSoll->setFont(QFont("Arial", 11, QFont::Normal));
    EinheitLaengeSoll = new QLabel(tr("m"));
    EinheitLaengeSoll->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDrahtIst = new QLabel(tr("VF Ist"));
    LabelDrahtIst->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDiff = new QLabel(tr("Differenz"));
    LabelDiff->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDiffErgebnis = new QLabel;
    LabelDiffErgebnis->setFont(QFont("Arial", 11, QFont::Normal));
    LabelDiffErgebnis->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
    EinheitDiff = new QLabel(tr("m"));
    EinheitDiff->setFont(QFont("Arial", 11, QFont::Normal));

    EditResoFreq = new QLineEdit;
    EditResoFreq->setFont(QFont("Arial", 11, QFont::Normal));
    EditResoFreq->setInputMask("000.00");
    EditResoFreq->setCursorPosition(0);

    EditLaengeIst = new QLineEdit;
    EditLaengeIst->setFont(QFont("Arial", 11, QFont::Normal));
    EditLaengeIst->setInputMask("00.00");
    EditLaengeIst->setCursorPosition(0);

    EditFreqSoll = new QLineEdit;
    EditFreqSoll->setFont(QFont("Arial", 11, QFont::Normal));
    EditFreqSoll->setInputMask("000.00");
    EditFreqSoll->setCursorPosition(0);

    EditWelle = new QLineEdit;
    EditWelle->setFont(QFont("Arial", 11, QFont::Normal));
    EditWelle->setReadOnly(true);

    ComboWelle = new QComboBox;
    QStringList s_ListWelle;
    s_ListWelle << "Halbwelle" << "Viertelwelle";
    ComboWelle->addItems(s_ListWelle);
    ComboWelle->setFont(QFont("Arial", 11, QFont::Normal));

    EditLaengeResoIst = new QLineEdit;
    EditLaengeResoIst->setFont(QFont("Arial", 11, QFont::Normal));
    EditLaengeResoIst->setInputMask("00.00");
    EditLaengeResoIst->setCursorPosition(0);

    EditLaengeSoll = new QLineEdit;
    EditLaengeSoll->setFont(QFont("Arial", 11, QFont::Normal));
    EditLaengeSoll->setInputMask("00.00");
    EditLaengeSoll->setCursorPosition(0);

    EditDraht = new QLineEdit;
    EditDraht->setFont(QFont("Arial", 11, QFont::Normal));
    EditDraht->setInputMask("00.00");
    EditDraht->setCursorPosition(0);

    LabelDrahtIst = new QLabel;
    LabelDrahtIst->setFont(QFont("Arial", 11, QFont::Normal));

    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 11, QFont::Normal));
    ButtonBerechnen = new QPushButton(tr("Berechnen"));
    ButtonBerechnen->setFont(QFont("Arial", 11, QFont::Normal));
    ButtonBerechnen->setStyleSheet("QPushButton {background-color : rgb(202,255,112); color : black;}");
    ButtonLeeren = new QPushButton(tr("Leeren"));
    ButtonLeeren->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonLeeren->setFont(QFont("Arial", 11, QFont::Normal));

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
    // Auswahl der Welle
    QString s_AuswahlWelle = ComboWelle->currentText();
    if (s_AuswahlWelle == "Halbwelle")
    {
        QString s_Halbwelle = "2";
        EditWelle->setText(s_Halbwelle);
    }
    else if (s_AuswahlWelle == "Viertelwelle")
    {
        QString s_Viertelwelle = "4";
        EditWelle->setText(s_Viertelwelle);
    }


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

//    LabelDrahtIstErgebnis->setNum(f_PufferRound1);
//    LabelDrahtIstErgebnis->setFont(QFont("Arial", 11, QFont::Thin));

}

void AfuBerechnungTrapantenne::triggeredButtonLeerenClicked()
{
    EditDraht->clear();
    LabelDiffErgebnis->clear();
    ///LabelDrahtIstErgebnis->clear();
    EditFreqSoll->clear();
    EditLaengeIst->clear();
    EditLaengeResoIst->clear();
    EditLaengeSoll->clear();
    EditResoFreq->clear();
}
