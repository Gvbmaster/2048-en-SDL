#include "Case.h"
#pragma once
const int SIZE = 4;

class Grid
{
private:
    Case grid[SIZE][SIZE];
public:
    Grid();
    void initializeGrid();
    void displayGrid();
    void generateRandomTile();
    void moveTilesUp();
    void moveTilesDown();
    void moveTilesRight();
    void moveTilesLeft();
    void winCondition();
    void loseCondition();
};