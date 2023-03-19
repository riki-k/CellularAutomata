#include "CellularAutomataAlgorithm.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CellularAutomataAlgorithm w;
    w.show();

    QTimer timer;
    QObject::connect(&timer, &QTimer::timeout, &w, &CellularAutomataAlgorithm::gamelife);
    timer.start(2000);

    return a.exec();
}

