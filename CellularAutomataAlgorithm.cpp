#include "CellularAutomataAlgorithm.h"
#include <QGraphicsView>

CellularAutomataAlgorithm::CellularAutomataAlgorithm() : QGraphicsView()
{
    //ui.setupUi(this);

    scene = new QGraphicsScene();
    setScene(scene);
    setInteractive(false);
    scene->setSceneRect(0, 0, 600, 600);

    /*cellular automata è un sistema di celle con le seguenti caratteristiche
    le celle sono delimitate da una griglia finita
    ogni cella ha uno stato definito
    ogni cella ha un vicinato di celle
    ogni cella ha una sua vita
    ogni interazione rappressenta una generazione
    il nuovo stato della cella è determinato dallo stato della generazione precedente di quelle adiacenti*/

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

	//Qualsiasi cella viva con meno di due celle vive adiacenti muore, come per effetto d'isolamento;
	//Qualsiasi cella viva con due o tre celle vive adiacenti sopravvive alla generazione successiva;
    //Qualsiasi cella viva con più di tre celle vive adiacenti muore, come per effetto di sovrappopolazione;
    //Qualsiasi cella morta con esattamente tre celle vive adiacenti diventa una cella viva, come per effetto di riproduzione.

    //provo a disegnare



    //game_life(quad_y, dim_x, dim_y);
}

    function game_life(quad, n_row, n_col) {
        var width = 600;
        var height = 600;
        var x = 0;
        var y = 0;
        var cell_size_x = width / n_row;
        var cell_size_y = height / n_col;
        var quad_cp = quad;
        var a = 50;

        for (let j = 0; j < n_row; j++) {
            for (let z = 0; z < n_col; z++) {
                let n_neighborood = 0;

                if (quad[j][z] == 1) {
                    if (n_neighborood < 2 || n_neighborood > 3) {
                        quad_cp[j][z] == 0;
                    }

                    else if (n_neighborood > 1 && n_neighborood < 4) {
                        //nothing
                    }
                }

                else {
                    if (n_neighborood == 3) {
                        quad_cp[j][z] == 1;
                    }
                }
            }
        }

        quad = quad_cp;
        for (let j = 0; j < n_row; j++) {
            for (let z = 0; z < n_col; z++) {
                var canvas = document.getElementById("screen");
                var ctx = canvas.getContext("2d");
                if (quad[j][z] == 0) {
                    ctx.fillStyle = "#000000";
                }
                else {
                    ctx.fillStyle = "#FFFFFF";
                }
                ctx.fillRect(x, y, cell_size_x, cell_size_y)
                    x += cell_size_x;
            }
            y += cell_size_y;
            x = 0;
        }
        sleep(1000);
        if (a == 0) {
            //nothing
        }

        else {
            a++;
            game_life();
        }
    }

}

CellularAutomataAlgorithm::~CellularAutomataAlgorithm()
{}



void CellularAutomataAlgorithm::gamelife() {

}
