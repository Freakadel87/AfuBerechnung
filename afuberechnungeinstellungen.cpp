#include "afuberechnungeinstellungen.h"

AfuBerechnungEinstellungen::AfuBerechnungEinstellungen(QWidget *parent) : QDialog(parent)
{
    FontDialog = new QFontDialog;
    ColorDialog = new QColorDialog;
    MainLayout = new QVBoxLayout(this);
    OberesLayout = new QHBoxLayout;
    UnteresLayout = new QHBoxLayout;

    ButtonSchriftart = new QPushButton(tr("Schriftart\nwählen"));
    ButtonSchriftart->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonSchriftfarbe = new QPushButton(tr("Schriftfarbe\nwählen"));
    ButtonSchriftfarbe->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");

    // Erstelle Buttons
    ButtonBeenden = new QPushButton(tr("Beenden"));
    ButtonBeenden->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonBeenden->setFont(QFont("Arial", 10, QFont::Thin));
    ButtonOk = new QPushButton(tr("OK"));
    ButtonOk->setStyleSheet("QPushButton {background-color : rgb(211,211,211); color : black;}");
    ButtonOk->setFont(QFont("Arial", 10, QFont::Thin));

    // Zusammenstellung der Layouts
    OberesLayout->addWidget(ButtonSchriftart);
    OberesLayout->addWidget(ButtonSchriftfarbe);
    UnteresLayout->addWidget(ButtonOk);
    UnteresLayout->addWidget(ButtonBeenden);
    MainLayout->addLayout(OberesLayout,0);
    MainLayout->addLayout(UnteresLayout,4);

    QObject::connect(ButtonOk, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonOkClicked()));
    QObject::connect(ButtonBeenden, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonBeendenClicked()));
    QObject::connect(ButtonSchriftart, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftartClicked()));
    QObject::connect(ButtonSchriftfarbe, SIGNAL(clicked(bool)), this, SLOT(triggeredButtonSchriftfarbeClicked()));
}

void AfuBerechnungEinstellungen::triggeredButtonBeendenClicked()
{
    close();
}

void AfuBerechnungEinstellungen::triggeredButtonOkClicked()
{

}

void AfuBerechnungEinstellungen::triggeredButtonSchriftartClicked()
{
    FontDialog->show();
}

void AfuBerechnungEinstellungen::triggeredButtonSchriftfarbeClicked()
{
    ColorDialog->show();
}
