#ifndef AFUBERECHNUNGSWR_H
#define AFUBERECHNUNGSWR_H

// Interne Includes

// Systeminterne Includes
#include <math.h>

// Qt Includes
#include <QMainWindow>
#include <QApplication>
#include <QFontDialog>
#include <QDesktopWidget>
#include <QWidget>
#include <QPushButton>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QSettings>
#include <QRadioButton>
#include <QMessageBox>
#include <QFont>
#include <QIcon>
#include <QSize>
#include <QLineEdit>
#include <QComboBox>
#include <QLabel>
#include <QDialog>
#include <QTableWidget>
#include <QTableWidgetItem>
#include <QMenu>
#include <QMenuBar>
#include <QAction>
#include <QMouseEvent>


class AfuBerechnungSwr : public QDialog
{
    Q_OBJECT

public:
    //Konstruktor
    AfuBerechnungSwr(QWidget *parent);

private:
    //Objekterstellung
    QGridLayout *GridLayout;
    QVBoxLayout *MainLayout;

    QPushButton *ButtonAbbrechen;
    QPushButton *ButtonOk;

    QComboBox *ComboBoxBandwahl;
    QLabel *LabelBandwahl;

    QTableWidget *TableWidget;
private slots:
    void triggeredButtonAbbrechenClicked(); //Button ABBRECHEN betaetigt
    void triggeredButtonOkClicked(); //Button OK betaetigt
    void triggeredComboBox();
    void CreatePlotter();
    void LoadConfig(); //Lade zuvor gespeicherte Parameter zurueck
    void SaveConfig(); //Speichere vorgenommene Parameter
    void addRow();
    void MousePressEvent(QMouseEvent *event);
};
#endif // AFUBERECHNUNGSWR_H
