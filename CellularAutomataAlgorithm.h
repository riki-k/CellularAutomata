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
    QPen pen;
    QBrush brush = Qt::SolidPattern;
    
    int width = 600;
    int height = 600;
    int dim_x = 60;
    int dim_y = 60;
    int cell_size_x = width / dim_x;
    int cell_size_y = height / dim_y;
    int x = 0;
    int y = 0;

    std::vector <int> quad_x;
    std::vector <std::vector <int> >square;

};
