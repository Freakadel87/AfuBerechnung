#include "afuberechnungdrahtlaenge.h"

// Destruktor
//AfuBerechnungFrequenz::~AfuBerechnungFrequenz()
//{

//}

AfuBerechnungDrahtlaenge::AfuBerechnungDrahtlaenge(QWidget *parent) : QDialog(parent)
{
    // Erstelle Textfelder
    LabelLicht = new QLabel("Lichtgeschwindigkeit");
    LabelLicht->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFrequenz = new QLabel("Frequenz");
    LabelFrequenz->setFont(QFont("Arial", 10, QFont::Normal));
    LabelErgebnisLaenge = new QLabel("Länge:");
    LabelErgebnisLaenge->setFont(QFont("Arial", 10, QFont::Normal));
    LabelErgebnisLaengeOVF = new QLabel("Länge:");
    LabelErgebnisLaengeOVF->setFont(QFont("Arial", 10, QFont::Normal));
    LabelLambda = new QLabel("Lambda                      1 /");
    LabelLambda->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktorVer = new QLabel("Verkürzungsfaktor");
    LabelFaktorVer->setFont(QFont("Arial", 10, QFont::Normal));

    LabelInfo = new QLabel("Drahtlänge +5%, um Anpassungen beim Abstimmen vornehmen zu können. \nWichtig! Die Dezimalstelle muss mit einem Punkt '.' getrennt werden.");
    LabelInfo->setFont(QFont("Arial", 10, QFont::Normal));

    LabelFaktoren1 = new QLabel("Gebräuchliche Verkürzungsfaktoren:");
    LabelFaktoren1->setFont(QFont("Arial", 10, QFont::Bold));
    LabelFaktoren2 = new QLabel("Koaxkabel normal");
    LabelFaktoren2->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren3 = new QLabel("k = 0,66");
    LabelFaktoren3->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren4 = new QLabel("Koaxkabel mit Luftisolation");
    LabelFaktoren4->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren5 = new QLabel("k = 0,85");
    LabelFaktoren5->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren6 = new QLabel("Offene 600 Ohm Speiseleitung");
    LabelFaktoren6->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren7 = new QLabel("k = 0,98");
    LabelFaktoren7->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren8 = new QLabel("Flachleitung 300 Ohm");
    LabelFaktoren8->setFont(QFont("Arial", 10, QFont::Normal));
    LabelFaktoren9 = new QLabel("k = 0,82");
    LabelFaktoren9->setFont(QFont("Arial", 10, QFont::Normal));

    LabelEinheitLicht = new QLabel("km/s");
    LabelEinheitLicht->setFont(QFont("Arial", 10, QFont::Normal));
    LabelEinheitFrequenz = new QLabel("MHz");
    LabelEinheitFrequenz->setFont(QFont("Arial", 10, QFont::Normal));
    LabelEinheitLaenge = new QLabel("m  --> mit Verkürzungsfaktor");
    LabelEinheitLaenge->setFont(QFont("Arial", 10, QFont::Normal));
    LabelEinheitLaengeOVF = new QLabel("m  --> ohne Verkürzungsfaktor");
    LabelEinheitLaengeOVF->setFont(QFont("Arial", 10, QFont::Normal));


    EditEingabeFrequenz = new QLineEdit;
    EditEingabeFrequenz->setFont(QFont("Arial", 10, QFont::Normal));
    EditEingabeFrequenz->setCursorPosition(0);
    EditEingabeFrequenz->setInputMask("00000.00");
    EditEingabeFrequenz->setToolTip("Geben Sie hier Ihre Frequenz in MHZ ein. \nBeispiel: 7.2 oder 14.35");
    EditEingabeLambda = new QLineEdit;
    EditEingabeLambda->setFont(QFont("Arial", 10, QFont::Normal));
    EditEingabeLambda->setToolTip("Geben Sie '2' für Lambda-Halbe oder '4' für Lambda-Viertel ein. \nAuch jede ander Zahl wird in der Berechnung akzeptiert.");
    EditEingabeLambda->setCursorPosition(0);
    EditEingabeLambda->setText("2");
    LabelLichtWert = new QLabel("299,792");
    LabelLichtWert->setFont(QFont("Arial", 10, QFont::Normal));
    EditEingabeVKF = new QLineEdit;
    EditEingabeVKF->setFont(QFont("Arial", 10, QFont::Normal));
    EditEingabeVKF->setText("0.855");
    EditEingabeVKF->setToolTip("Sie können hier einen anderen Wert eingeben, als Standard wurde 0,855 gewählt.");
    LabelErgebnis = new QLabel;
    LabelErgebnis->setFont(QFont("Arial", 10, QFont::Normal));
    LabelErgebnis->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
    LabelErgebnisOVF = new QLabel;
    LabelErgebnisOVF->setFont(QFont("Arial", 10, QFont::Normal));
    LabelErgebnisOVF->setStyleSheet("QLabel {background-color : rgb(255,222,173); color : black;}");
    ButtonBeenden = new QPushButton("Beenden");
    ButtonBeenden->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonBerechnen = new QPushButton("Berechnen");
    ButtonBerechnen->setFont(QFont("Arial", 10, QFont::Normal));
    ButtonBerechnen->setPalette(Qt::green);
    ButtonLeeren = new QPushButton("Leeren");
    ButtonLeeren->setFont(QFont("Arial", 10, QFont::Normal));


    QGridLayout *GridLayout = new QGridLayout;
    GridLayout->addWidget(LabelLicht, 0, 0);
    GridLayout->addWidget(LabelLichtWert, 0, 1);
    GridLayout->addWidget(LabelEinheitLicht, 0, 2);
    GridLayout->addWidget(LabelFrequenz, 1, 0);
    GridLayout->addWidget(EditEingabeFrequenz, 1, 1);
    GridLayout->addWidget(LabelEinheitFrequenz, 1, 2);
    GridLayout->addWidget(LabelLambda, 2, 0);
    GridLayout->addWidget(EditEingabeLambda, 2, 1);
    GridLayout->addWidget(LabelFaktorVer, 3, 0);
    GridLayout->addWidget(EditEingabeVKF, 3, 1);
    GridLayout->addWidget(LabelErgebnisLaenge, 5, 0);
    GridLayout->addWidget(LabelErgebnis, 5, 1);
    GridLayout->addWidget(LabelEinheitLaenge, 5, 2);
    GridLayout->addWidget(LabelErgebnisLaengeOVF, 6, 0);
    GridLayout->addWidget(LabelErgebnisOVF, 6, 1);
    GridLayout->addWidget(LabelEinheitLaengeOVF, 6, 2);
    GridLayout->addWidget(ButtonBerechnen, 9, 0);
    GridLayout->addWidget(ButtonLeeren, 10, 0);
    GridLayout->addWidget(ButtonBeenden, 11, 0);
    GridLayout->addWidget(LabelInfo, 13, 0, 1, 3);

    LayoutGrid = new QGridLayout;
    LayoutGrid->addWidget(LabelFaktoren2,0,0);
    LayoutGrid->addWidget(LabelFaktoren3,0,1);
    LayoutGrid->addWidget(LabelFaktoren4,1,0);
    LayoutGrid->addWidget(LabelFaktoren5,1,1);
    LayoutGrid->addWidget(LabelFaktoren6,2,0);
    LayoutGrid->addWidget(LabelFaktoren7,2,1);
    LayoutGrid->addWidget(LabelFaktoren8,3,0);
    LayoutGrid->addWidget(LabelFaktoren9,3,1);

    LayoutVBox = new QVBoxLayout(this);
    LayoutVBox->addLayout(GridLayout);
    LayoutVBox->addWidget(LabelFaktoren1);
    LayoutVBox->addLayout(LayoutGrid);

    QObject::connect(ButtonBerechnen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBerechnenClicked()));
    QObject::connect(ButtonLeeren, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonLeerenClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
}

void AfuBerechnungDrahtlaenge::triggeredButtonBeendenClicked()
{
    triggeredButtonLeerenClicked();
    close();
}

void AfuBerechnungDrahtlaenge::triggeredButtonBerechnenClicked()
{
    // Thomsonsche Schwingungsformel
    f_PufferF = EditEingabeFrequenz->text().toFloat();
    f_PufferLamda = EditEingabeLambda->text().toFloat();
    f_PufferVKF = EditEingabeVKF->text().toFloat();

    // Formel mit Verkuerzungsfaktor
    f_Ergebnis = f_Licht / f_PufferF / f_PufferLamda * f_PufferVKF;
    // Formel ohne Verkuerzungsfaktor
    f_ErgebnisOVF = f_Licht / f_PufferF / f_PufferLamda;

    LabelErgebnis->setNum(f_Ergebnis);
    LabelErgebnis->setFont(QFont("Arial", 10, QFont::Thin));
    LabelErgebnisOVF->setNum(f_ErgebnisOVF);
    LabelErgebnisOVF->setFont(QFont("Arial", 10, QFont::Thin));
}

void AfuBerechnungDrahtlaenge::triggeredButtonLeerenClicked()
{
    LabelErgebnis->clear();
    LabelErgebnisOVF->clear();
    EditEingabeFrequenz->clear();
    EditEingabeVKF->setText("0.855");
    EditEingabeLambda->setText("2");
}
