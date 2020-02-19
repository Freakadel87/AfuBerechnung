#ifndef AFUBERECHNUNG_H
#define AFUBERECHNUNG_H

/// Qt-includes
#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMessageBox>
#include <QIcon>

class QAction;
class QLabel;

class AfuBerechnung : public QMainWindow
{
    Q_OBJECT

public:
    AfuBerechnung(QWidget *parent = 0);
    ~AfuBerechnung();

    void Programm();

protected:
    void closeEvent(QCloseEvent *event);

private slots:
    void dateiOeffnen();
    void dateiSpeichern();
    void dateiBeenden();

    void hilfeInfo();



};

#endif // AFUBERECHNUNG_H
