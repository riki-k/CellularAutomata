#pragma once

#include <QtWidgets/QWidget>
#include "ui_CellularAutomataAlgorithm.h"
#include <QGraphicsView>

class CellularAutomataAlgorithm : public QGraphicsView
{
    Q_OBJECT

public:
    CellularAutomataAlgorithm();
    ~CellularAutomataAlgorithm();

    //void algorithm();
    void gamelife();

private:
    Ui::CellularAutomataAlgorithmClass ui;
    QGraphicsScene *scene;
    
    int dim_x = 60;
    int dim_y = 60;

    std::vector <int> quad_x;
    std::vector <std::vector <int> >square;

};
