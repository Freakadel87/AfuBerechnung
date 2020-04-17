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

    EditWiderstandswert = new QLineEdit;
    EditWiderstandswert->setReadOnly(true);
    EditWiderstandswert->setFont(QFont("Arial", 11, QFont::Normal));
    LabelWiderstandswert = new QLabel(tr("Widerstandswert:"));
    //  }

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
    GridLayout->addWidget(LabelSchritt_1, 0, 0);
    GridLayout->addWidget(ComboBox_1, 0, 1);
    GridLayout->addWidget(LabelSchritt_2, 2, 0);
    GridLayout->addWidget(ComboFirstRing, 3, 0);
    GridLayout->addWidget(ComboSecondRing, 3, 1);
    GridLayout->addWidget(ComboThirdRing, 3, 2);
    GridLayout->addWidget(ComboMultiplier, 3, 3);
    GridLayout->addWidget(ComboTolerance, 3, 4);
    GridLayout->addWidget(ComboTemperatur, 3, 5);
    GridLayout->addWidget(LabelWiderstandswert, 5,2);
    GridLayout->addWidget(EditWiderstandswert, 5,3);
    GridLayout->addWidget(ButtonBerechnen, 7,0);
    GridLayout->addWidget(ButtonLeeren, 8,0);
    GridLayout->addWidget(ButtonBeenden, 9,0);

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


}

void AfuBerechnungWiderstand::triggeredButtonLeerenClicked()
{
    EditWiderstandswert->clear();
}
