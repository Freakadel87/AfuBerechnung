#include "afuberechnungwiderstand.h"

AfuBerechnungWiderstand::AfuBerechnungWiderstand(QWidget *parent) : QDialog(parent)
{
    LabelSchritt_1 = new QLabel("Schritt 1: Wählen Sie bitte die Anzahl der Bänder.");
    LabelSchritt_1->setFont(QFont("Arial", 11, QFont::Normal));
    ComboBox_1 = new QComboBox;
    QStringList s_ListRinge;
    s_ListRinge<<"<leer>"<<"4 Ringe"<<"5 Ringe"<<"6 Ringe";
    ComboBox_1->addItems(s_ListRinge);
    ComboBox_1->setFont(QFont("Arial", 11, QFont::Normal));
    LabelSchritt_2  = new QLabel("Schritt 2: Wählen Sie bitte den Farbcode aus");
    LabelSchritt_2->setFont(QFont("Arial", 11, QFont::Normal));

    QString s_Auswahl = ComboBox_1->currentText();

    //if (s_Auswahl == "5 Ringe")
    //   {
    ComboFirstRing = new QComboBox;
    QStringList s_ListFirst;
    s_ListFirst <<"<leer>"<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    ComboFirstRing->addItems(s_ListFirst);
    ComboFirstRing->setFont(QFont("Arial", 11, QFont::Normal));
    ComboFirstRing->setItemData(0, QBrush(QColor::fromRgb(250,235,215)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(1, QBrush(Qt::black), Qt::BackgroundRole);
    ComboFirstRing->setItemData(1, QBrush(Qt::white), Qt::TextColorRole);
    ComboFirstRing->setItemData(2, QBrush(QColor::fromRgb(165,42,42)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(3, QBrush(Qt::red), Qt::BackgroundRole);
    ComboFirstRing->setItemData(4, QBrush(QColor::fromRgb(255,140,0)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(5, QBrush(Qt::yellow), Qt::BackgroundRole);
    ComboFirstRing->setItemData(6, QBrush(QColor::fromRgb(0,139,69)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(7, QBrush(QColor::fromRgb(24,116,205)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(8, QBrush(QColor::fromRgb(255,0,255)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(9, QBrush(QColor::fromRgb(105,105,105)), Qt::BackgroundRole);
    ComboFirstRing->setItemData(10, QBrush(QColor::fromRgb(255,255,255)), Qt::BackgroundRole);

    ComboSecondRing = new QComboBox;
    QStringList s_ListSecond;
    s_ListSecond <<"<leer>"<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    ComboSecondRing->addItems(s_ListSecond);
    ComboSecondRing->setFont(QFont("Arial", 11, QFont::Normal));
    ComboSecondRing->setItemData(0, QBrush(QColor::fromRgb(250,235,215)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(1, QBrush(Qt::black), Qt::BackgroundRole);
    ComboSecondRing->setItemData(1, QBrush(Qt::white), Qt::TextColorRole);
    ComboSecondRing->setItemData(2, QBrush(QColor::fromRgb(165,42,42)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(3, QBrush(Qt::red), Qt::BackgroundRole);
    ComboSecondRing->setItemData(4, QBrush(QColor::fromRgb(255,140,0)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(5, QBrush(Qt::yellow), Qt::BackgroundRole);
    ComboSecondRing->setItemData(6, QBrush(QColor::fromRgb(0,139,69)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(7, QBrush(QColor::fromRgb(24,116,205)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(8, QBrush(QColor::fromRgb(255,0,255)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(9, QBrush(QColor::fromRgb(105,105,105)), Qt::BackgroundRole);
    ComboSecondRing->setItemData(10, QBrush(QColor::fromRgb(255,255,255)), Qt::BackgroundRole);

    ComboThirdRing = new QComboBox;
    QStringList s_ListThird;
    s_ListThird <<"<leer>"<<"0"<<"1"<<"2"<<"3"<<"4"<<"5"<<"6"<<"7"<<"8"<<"9";
    ComboThirdRing->addItems(s_ListThird);
    ComboThirdRing->setFont(QFont("Arial", 11, QFont::Normal));
    ComboThirdRing->setItemData(0, QBrush(QColor::fromRgb(250,235,215)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(1, QBrush(Qt::black), Qt::BackgroundRole);
    ComboThirdRing->setItemData(1, QBrush(Qt::white), Qt::TextColorRole);
    ComboThirdRing->setItemData(2, QBrush(QColor::fromRgb(165,42,42)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(3, QBrush(Qt::red), Qt::BackgroundRole);
    ComboThirdRing->setItemData(4, QBrush(QColor::fromRgb(255,140,0)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(5, QBrush(Qt::yellow), Qt::BackgroundRole);
    ComboThirdRing->setItemData(6, QBrush(QColor::fromRgb(0,139,69)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(7, QBrush(QColor::fromRgb(24,116,205)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(8, QBrush(QColor::fromRgb(255,0,255)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(9, QBrush(QColor::fromRgb(105,105,105)), Qt::BackgroundRole);
    ComboThirdRing->setItemData(10, QBrush(QColor::fromRgb(255,255,255)), Qt::BackgroundRole);

    ComboMultiplier = new QComboBox;
    QStringList s_ListMultiplier;
    s_ListMultiplier <<"<leer>"<<"0.01"<<"0.1"<<"1"<<"10"<<"100"<<"1k"<<"10k"<<"100k"<<"1M"<<"10M";
    ComboMultiplier->addItems(s_ListMultiplier);
    ComboMultiplier->setFont(QFont("Arial", 11, QFont::Normal));

    ComboTolerance = new QComboBox;
    QStringList s_ListTolerance;
    s_ListTolerance <<"<leer>"<<"10%"<<"5%"<<"1%"<<"2%"<<"0.5%"<<"0.25%"<<"0.1%"<<"0.05%";
    ComboTolerance->addItems(s_ListTolerance);
    ComboTolerance->setFont(QFont("Arial", 11, QFont::Normal));

    ComboTemperatur = new QComboBox;
    QStringList s_ListTemperature;
    s_ListTemperature <<"<leer>"<<"100ppm"<<"50ppm"<<"15ppm"<<"25ppm";
    ComboTemperatur->addItems(s_ListTemperature);
    ComboTemperatur->setFont(QFont("Arial", 11, QFont::Normal));

    HLayoutCombo = new QHBoxLayout();
    HLayoutCombo->addWidget(ComboFirstRing);
    HLayoutCombo->addWidget(ComboSecondRing);
    HLayoutCombo->addWidget(ComboThirdRing);
    HLayoutCombo->addWidget(ComboMultiplier);
    HLayoutCombo->addWidget(ComboTolerance);

    LabelErgebnisOhm = new QLabel;
    LabelErgebnisOhm->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWiderstandswertOhm = new QLabel(tr("Widerstandswert in Ohm:"));
    LabelWiderstandswertOhm->setFont(QFont("Arial", 11, QFont::Normal));
    LabelErgebnisKiloOhm = new QLabel;
    LabelErgebnisKiloOhm->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWiderstandswertKiloOhm = new QLabel(tr("Widerstandswert in kOhm:"));
    LabelWiderstandswertKiloOhm->setFont(QFont("Arial", 11, QFont::Normal));
    LabelErgebnisMegaOhm = new QLabel;
    LabelErgebnisMegaOhm->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWiderstandswertMegaOhm = new QLabel(tr("Widerstandswert in MOhm:"));
    LabelWiderstandswertMegaOhm->setFont(QFont("Arial", 11, QFont::Normal));

    LabelMaxTolWert = new QLabel(tr("Maximaler Widerstandswert:"));
    LabelMaxTolWert->setFont(QFont("Arial", 11, QFont::Normal));
    LabelErgebnisMaxTol = new QLabel();
    LabelErgebnisMaxTol->setFont(QFont("Arial", 11, QFont::Normal));
    LabelMinTolWert = new QLabel(tr("Minimaler Widerstandswert:"));
    LabelMinTolWert->setFont(QFont("Arial", 11, QFont::Normal));
    LabelErgebnisMinTol = new QLabel();
    LabelErgebnisMinTol->setFont(QFont("Arial", 11, QFont::Normal));

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

    VLayoutButton = new QVBoxLayout();
    VLayoutButton->addWidget(ButtonBerechnen);
    VLayoutButton->addWidget(ButtonLeeren);
    VLayoutButton->addWidget(ButtonBeenden);

    QGridLayout *GridLayout = new QGridLayout(this);
    GridLayout->addWidget(LabelSchritt_1, 0, 0);
    GridLayout->addWidget(ComboBox_1, 0, 1);
    GridLayout->addWidget(LabelSchritt_2, 2, 0);
    GridLayout->addLayout(HLayoutCombo,4,0);
    GridLayout->addWidget(LabelWiderstandswertOhm, 6,0);
    GridLayout->addWidget(LabelErgebnisOhm, 6,1);
    GridLayout->addWidget(LabelMaxTolWert, 9,0);
    GridLayout->addWidget(LabelErgebnisMaxTol, 9,1);
    GridLayout->addWidget(LabelWiderstandswertKiloOhm, 7,0);
    GridLayout->addWidget(LabelErgebnisKiloOhm, 7,1);
    GridLayout->addWidget(LabelMinTolWert, 10,0);
    GridLayout->addWidget(LabelErgebnisMinTol, 10,1);
    GridLayout->addWidget(LabelWiderstandswertMegaOhm, 8,0);
    GridLayout->addWidget(LabelErgebnisMegaOhm, 8,1);
    GridLayout->addLayout(VLayoutButton,12,0);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungWiderstand::triggeredButtonBeendenClicked()
{
    close();
}

void AfuBerechnungWiderstand::triggeredButtonBerechnenClicked()
{
    // Variablendefinition fuer Multiplikator
    double d_WertFirst = 0;
    double d_WertSecond = 0;
    double d_WertThird = 0;
    double d_WertPuffer = 0;
    double d_WertErgebnis = 0;
    double d_WertOhmPuffer = 0;
    double d_WertMultiplier = 0.0;
    double d_WertOhm = 0.0;
    double d_WertKiloOhm = 0.0;
    double d_WertMegaOhm = 0.0;

    // Auslesen der Pull-Down Menues
    d_WertFirst = ComboFirstRing->currentText().toDouble();
    d_WertSecond = ComboSecondRing->currentText().toDouble();
    d_WertThird = ComboThirdRing->currentText().toDouble();

    d_WertPuffer = d_WertFirst * 10 + d_WertSecond;
    d_WertErgebnis = d_WertPuffer * 10 + d_WertThird;

    // Auswertung des vierten Ringes (Multiplikator)
    QString s_WertMultiplier = ComboMultiplier->currentText();

    if (s_WertMultiplier == "0.01") /// Zu erledigen: Datentyp double benoetigt
    {
        d_WertMultiplier = 0.0100;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }

    else if (s_WertMultiplier == "0.1")
    {
        d_WertMultiplier = 0.100;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }

    else if (s_WertMultiplier == "1")
    {
        d_WertMultiplier = 1.0;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "10")
    {
        d_WertMultiplier = 10.0;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "100")
    {
        d_WertMultiplier = 100.0;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "1k")
    {
        d_WertMultiplier = 1'000.0;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "10k")
    {
        d_WertMultiplier = 10'000;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "100k")
    {
        d_WertMultiplier = 100'000;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "1M")
    {
        d_WertMultiplier = 1'000'000;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }
    else if (s_WertMultiplier == "10M")
    {
        d_WertMultiplier = 10'000'000;
        d_WertOhmPuffer = d_WertErgebnis * d_WertMultiplier;
    }

    d_WertOhm = d_WertOhmPuffer;
    d_WertKiloOhm = d_WertOhmPuffer / 1'000;
    d_WertMegaOhm = d_WertOhmPuffer / 1'000'000;

    LabelErgebnisOhm->setNum(d_WertOhm);
    LabelErgebnisKiloOhm->setNum(d_WertKiloOhm);
    LabelErgebnisMegaOhm->setNum(d_WertMegaOhm);

    // Variablendefinition fuer Toleranz
    double d_WertMinTol = 0.0;
    double d_WertMaxTol = 0.0;
    double d_WertTolPuffer = 0.0;

    // Auswertung des fuenften Ringes (Toleranz)
    QString s_WertToleranz = ComboTolerance->currentText();

    if (s_WertToleranz == "0.05%") /// Zu erledigen: Datentyp double benoetigt
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 0.05;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "0.1%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 0.1;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "0.25%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 0.25;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "0.5%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 0.5;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "1%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 1;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "2%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 2;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "5%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 5;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "10%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 10;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "20%")
    {
        d_WertTolPuffer = d_WertOhm /100.0 * 20;
        d_WertMinTol = d_WertOhm - d_WertTolPuffer;
        d_WertMaxTol = d_WertOhm + d_WertTolPuffer;
    }
    else if (s_WertToleranz == "<leer>")
    {
        d_WertMinTol = 9999999;
        d_WertMaxTol = 9999999;
    }
    LabelErgebnisMinTol->setNum(d_WertMinTol);
    LabelErgebnisMaxTol->setNum(d_WertMaxTol);
}

void AfuBerechnungWiderstand::triggeredButtonLeerenClicked()
{
    LabelErgebnisOhm->clear();
    LabelErgebnisKiloOhm->clear();
    LabelErgebnisMegaOhm->clear();
    LabelErgebnisMinTol->clear();
    LabelErgebnisMaxTol->clear();
}
