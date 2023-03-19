#pragma once

#include <QtWidgets/QWidget>
#include "ui_CellularAutomataAlgorithm.h"
#include <QGraphicsView>
#include <iostream>
#include <QTimer>

class CellularAutomataAlgorithm : public QGraphicsView
{
    Q_OBJECT

public:
    CellularAutomataAlgorithm();
    ~CellularAutomataAlgorithm();

    //void algorithm();
    void set_grid();
    void gamelife();
    void drawTest();


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
    bool first = true;

    std::vector <int> quad_x;
    std::vector <std::vector <int> >square;
    std::vector <std::vector <int> >square_cp;

};
