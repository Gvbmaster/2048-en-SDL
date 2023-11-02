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
    // Affichez la grille en utilisant la m�thode render() de chaque case
    for (int i = 0; i < gridSize; i++) {
        for (int j = 0; j < gridSize; j++) {
            cases[i][j].render();
        }
    }
}

void Grid::generateRandomTile() {
    // G�n�rez une nouvelle tuile al�atoire sur une case vide
    int row, col;
    do {
        row = std::rand() % gridSize;
        col = std::rand() % gridSize;
    } while (!cases[row][col].isEmpty());

    // � adapter : D�finissez la valeur de la nouvelle tuile (ex. 2 ou 4)
    int newValue = 2;

    cases[row][col].setValue(newValue);
}

void Grid::moveTilesUp() {
    // Impl�mentez la logique de d�placement vers le haut
    // Mettez � jour les valeurs des cases en cons�quence
    // ...
}

void Grid::moveTilesDown() {
    // Impl�mentez la logique de d�placement vers le bas
    // Mettez � jour les valeurs des cases en cons�quence
    // ...
}

void Grid::moveTilesLeft() {
    // Impl�mentez la logique de d�placement vers la gauche
    // Mettez � jour les valeurs des cases en cons�quence
    // ...
}

void Grid::moveTilesRight() {
    // Impl�mentez la logique de d�placement vers la droite
    // Mettez � jour les valeurs des cases en cons�quence
    // ...
}

