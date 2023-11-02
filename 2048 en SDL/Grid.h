#pragma once
#include "SDL.h"
#include "Case.h"

class Grid {
public:
    Grid(SDL_Renderer* renderer, int x, int y, int gridSize, int tileSpacing); // Constructeur

    void initializeGrid(); 
    void render(); 

    void generateRandomTile();
    void moveTilesUp();
    void moveTilesDown();
    void moveTilesRight();
    void moveTilesLeft();
    void winCondition();
    void loseCondition();

private:
    SDL_Renderer* renderer; //rendu SDL
    int gridSize; // Taille de la grille (nombre de cases par côté)
    int tileSpacing; // Espacement entre les cases
    Case** grid; // Grille de cases (tableau 2D de tuiles)
    int x, y; // Coordonnées d'affichage de la grille
};