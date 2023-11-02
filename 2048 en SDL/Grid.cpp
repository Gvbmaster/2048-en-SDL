#include "Grid.h"
#include "Case.h"
#include "SDL.h"

using namespace std;

Grid::Grid(SDL_Renderer* renderer, int gridSize, int tileSize) : renderer(renderer), gridSize(gridSize), tileSize(tileSize) {
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cases[i][j] = Case(j * tileSize, i * tileSize, tileSize, tileSize);
        }
    }
}

void Grid::render() {
    // Affichez la grille en utilisant la méthode render() de chaque case
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cases[i][j].render();
        }
    }
}

void Grid::generateRandomTile() {
    // Générez une nouvelle tuile aléatoire sur une case vide
    int row, col;
    do {
        row = std::rand() % gridSize;
        col = std::rand() % gridSize;
    } while (!cases[row][col].isEmpty());

    // À adapter : Définissez la valeur de la nouvelle tuile (ex. 2 ou 4)
    int newValue = 2;

    cases[row][col].setValue(newValue);
}

void Grid::moveTilesUp() {
    // Implémentez la logique de déplacement vers le haut
    // Mettez à jour les valeurs des cases en conséquence
    // ...
}

void Grid::moveTilesDown() {
    // Implémentez la logique de déplacement vers le bas
    // Mettez à jour les valeurs des cases en conséquence
    // ...
}

void Grid::moveTilesLeft() {
    // Implémentez la logique de déplacement vers la gauche
    // Mettez à jour les valeurs des cases en conséquence
    // ...
}

void Grid::moveTilesRight() {
    // Implémentez la logique de déplacement vers la droite
    // Mettez à jour les valeurs des cases en conséquence
    // ...
}

