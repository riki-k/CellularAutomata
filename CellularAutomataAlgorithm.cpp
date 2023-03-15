#include "CellularAutomataAlgorithm.h"
#include <QGraphicsView>
#include <iostream>

CellularAutomataAlgorithm::CellularAutomataAlgorithm() : QGraphicsView()
{
    //ui.setupUi(this);

    scene = new QGraphicsScene();
    setScene(scene);
    setInteractive(false);
    scene->setSceneRect(0, 0, width, height);

    /*cellular automata è un sistema di celle con le seguenti caratteristiche
    le celle sono delimitate da una griglia finita
    ogni cella ha uno stato definito
    ogni cella ha un vicinato di celle
    ogni cella ha una sua vita
    ogni interazione rappressenta una generazione
    il nuovo stato della cella è determinato dallo stato della generazione precedente di quelle adiacenti

    //Qualsiasi cella viva con meno di due celle vive adiacenti muore, come per effetto d'isolamento;
    //Qualsiasi cella viva con due o tre celle vive adiacenti sopravvive alla generazione successiva;
    //Qualsiasi cella viva con più di tre celle vive adiacenti muore, come per effetto di sovrappopolazione;
    //Qualsiasi cella morta con esattamente tre celle vive adiacenti diventa una cella viva, come per effetto di riproduzione.
    */
}

void CellularAutomataAlgorithm::set_grid() {
    //riempo array con stati della cella (0, 1)
    srand(time(NULL));
    for (int i = 0; i < dim_x; i++) {
        for (int j = 0; j < dim_y; j++) {
            int color = rand() % 2;
            quad_x.push_back(color);
        }
        square.push_back(quad_x);
        quad_x.clear();
    }
}

void CellularAutomataAlgorithm::drawTest() {
    //test disegno quadrato
    /*
    pen.setColor(Qt::red);
    brush = Qt::SolidPattern;
    brush.setColor(Qt::green);
    scene->addRect(0, 0, 100, 100, pen, brush);*/

    //provo a disegnare
    for (int j = 0; j < dim_x; j++) {
        for (int z = 0; z < dim_y; z++) {

            if (square[j][z] == 0) {
                pen.setColor(Qt::black);
                brush.setColor(Qt::black);
            }
            else {
                pen.setColor(Qt::white);
                brush.setColor(Qt::white);
            }

            scene->addRect(x, y, cell_size_x, cell_size_y, pen, brush);
            x += cell_size_x;
        }
        y += cell_size_y;
        x = 0;
    }
}

void CellularAutomataAlgorithm::gamelife(){

    square_cp = square;
    int gen = 10;
    for (int j = 0; j < dim_x; j++) {
        for (int z = 0; z < dim_y; z++) {
            int n_neighborood = 0;
            if (square[j][z] == 1) {
                if (n_neighborood < 2 || n_neighborood > 3) {
                    square_cp[j][z] == 0;
                }
                else if (n_neighborood > 1 && n_neighborood < 4) {
                        //nothing
                }
            }
            else {
                if (n_neighborood == 3) {
                    square_cp[j][z] == 1;
                }
            }
        }
    }

    square = square_cp;
    for (int j = 0; j < dim_x; j++) {
        for (int z = 0; z < dim_y; z++) {

            if (square[j][z] == 0) {
                pen.setColor(Qt::black);
                brush.setColor(Qt::black);
            }
            else {
                pen.setColor(Qt::white);
                brush.setColor(Qt::white);
            }

            scene->addRect(x, y, cell_size_x, cell_size_y, pen, brush);
            x += cell_size_x;
        }
        y += cell_size_y;
        x = 0;
    }

    if (gen > 0) {
        _sleep(1);
        gamelife();
        gen--;
    }
}

CellularAutomataAlgorithm::~CellularAutomataAlgorithm()
{}
