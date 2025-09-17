# Cellular Automata
Cellular Automata Algorithm

This is the first nonrecursive implementation of the "Cellular Automata" algorithm.

Cellular automata is a cell system with the following characteristics:
- the cells are bounded by a finite grid
- each cell has a defined state
- each cell has a cell neighborhood
- each cell has a lifetime
- each interaction represents a generation
- the new state of the cell is determined by the state of the previous generation of adjacent cells

The implementation presents a grid of 60x60 cells. The cells can assume the state of "alive or dead" ("black or white").
With this algorithm an attempt is made to replicate the game of life developed by Jhon Conway, below are the rules of the game:

- Any living cell with less than two adjacent living cells dies, as by isolation effect;
- Any live cell with two or three adjacent live cells survives to the next generation;
- Any live cell with more than three adjacent live cells dies, as by overpopulation effect;
- Any dead cell with exactly three adjacent live cells becomes a live cell, as by effect of reproduction.


Here the result of the code:

https://github.com/riki-k/CellularAutomata/assets/56576188/25372747-ebd3-44c6-bad7-f7b1d3e88d8b

