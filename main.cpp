#include "afuberechnung.h"
#include "afuberechnungfrequenz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    AfuBerechnung w;
    w.show();

    return a.exec();
}
