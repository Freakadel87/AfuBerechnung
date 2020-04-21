#include "afuberechnungfilter.h"

AfuBerechnungFilter::AfuBerechnungFilter(QWidget *parent) : QDialog(parent)
{
    LabelUeberschrift = new QLabel(tr("Filter"));
    LabelUeberschrift->setFont(QFont("Arial", 12, QFont::Bold));
    Label1 = new QLabel(tr("Kondensator an Gleichspannung -> Z ≈ ∞ (sperrt)"));
    Label1->setFont(QFont("Arial", 11, QFont::Normal));
    Label2 = new QLabel(tr("Kondensator an Hochfrequenz -> Z ≈ 0 (leitet)"));
    Label2->setFont(QFont("Arial", 11, QFont::Normal));
    Label3 = new QLabel(tr("Spule an Gleichspannung -> Z ≈ 0 (leitet)"));
    Label3->setFont(QFont("Arial", 11, QFont::Normal));
    Label4 = new QLabel(tr("Spule an Hochfrequenz -> Z ≈ ∞ (sperrt)"));
    Label4->setFont(QFont("Arial", 11, QFont::Normal));

    // Erstelle Textfelder
    Layout = new QVBoxLayout(this);

    ButtonSchliessen = new QPushButton(tr("Schließen"));
    ButtonSchliessen->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSchliessen->setFont(QFont("Arial", 11, QFont::Normal));

    Layout->addWidget(LabelUeberschrift);
    Layout->addWidget(Label1);
    Layout->addWidget(Label2);
    Layout->addWidget(Label3);
    Layout->addWidget(Label4);
    Layout->addWidget(ButtonSchliessen);

    // Erstelle Verbindung fuer Button
    QObject::connect(ButtonSchliessen, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchliessenClicked()));
}

void AfuBerechnungFilter::triggeredButtonSchliessenClicked()
{
    close();
}
