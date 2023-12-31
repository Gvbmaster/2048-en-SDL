#include "Grid.h"
#include "Case.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

Grid::Grid() {
    srand(time(0));
}

void Grid::initializeGrid() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = Case();
        }
    }
}

void Grid::displayGrid() {
    system("cls"); // On �fface l'�cran pour n'avoir qu'une seule grille
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "+-------";
        }
        cout << "+" << endl;

        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                cout << "|       ";
            }
            else {
                cout << "| " << setw(6) << grid[i][j].getValue();
            }
        }
        cout << "|" << endl;
    }

    for (int j = 0; j < SIZE; j++) {
        cout << "+-------";
    }
    cout << "+" << endl;

    cout << endl;
}

void Grid::generateRandomTile() {
    // Liste des cellules vides
    std::vector<std::pair<int, int>> emptyCells;

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                emptyCells.push_back(std::make_pair(i, j));
            }
        }
    }

    // Si des cellules vides existent
    if (!emptyCells.empty()) {
        // S�lectionnez une cellule vide al�atoirement
        int randomIndex = std::rand() % emptyCells.size();
        int selectedRow = emptyCells[randomIndex].first;
        int selectedCol = emptyCells[randomIndex].second;

        // D�finissez la valeur de la cellule s�lectionn�e comme 2 ou 4 (50% de chances)
        int randomValue = (std::rand() % 2 == 0) ? 2 : 4;
        grid[selectedRow][selectedCol].setValue(randomValue);
    }
}

void Grid::winCondition() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].getValue() == 2048) {
                cout << "GG, tu as gagn�" << endl;
                return;
            }
        }
    }
}

void Grid::loseCondition() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j].isEmpty()) {
                return;
            }
            // On regarde s'il est encore possible de fusionner des cases
            if ((i > 0 && grid[i][j].getValue() == grid[i - 1][j].getValue()) ||
                (j > 0 && grid[i][j].getValue() == grid[i][j - 1].getValue())) {
                return;
            }
        }
    }
    cout << "Dommage,tu as perdu." << endl;
    // Ajoutez ici la logique pour g�rer la d�faite, par exemple, demander si le joueur souhaite rejouer, etc.
}


void Grid::moveTilesUp() {
    for (int col = 0; col < SIZE; col++) {
        for (int row = 1; row < SIZE; row++) {
            if (!grid[row][col].isEmpty()) {
                int currentRow = row;
                while (currentRow > 0 && grid[currentRow - 1][col].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[currentRow - 1][col].setValue(grid[currentRow][col].getValue());
                    grid[currentRow][col].setValue(0);
                    currentRow--;
                }
                if (currentRow > 0 && grid[currentRow - 1][col].getValue() == grid[currentRow][col].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[currentRow][col].getValue() * 2;
                    grid[currentRow - 1][col].setValue(newValue);
                    grid[currentRow][col].setValue(0);
                }
            }
        }
    }
}

void Grid::moveTilesDown() {
    for (int col = 0; col < SIZE; col++) {
        for (int row = SIZE - 2; row >= 0; row--) {
            if (!grid[row][col].isEmpty()) {
                int currentRow = row;
                while (currentRow < SIZE - 1 && grid[currentRow + 1][col].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[currentRow + 1][col].setValue(grid[currentRow][col].getValue());
                    grid[currentRow][col].setValue(0);
                    currentRow++;
                }
                if (currentRow < SIZE - 1 && grid[currentRow + 1][col].getValue() == grid[currentRow][col].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[currentRow][col].getValue() * 2;
                    grid[currentRow + 1][col].setValue(newValue);
                    grid[currentRow][col].setValue(0);
                }
            }
        }
    }
}


void Grid::moveTilesRight() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = SIZE - 2; col >= 0; col--) {
            if (!grid[row][col].isEmpty()) {
                int currentCol = col;
                while (currentCol < SIZE - 1 && grid[row][currentCol + 1].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[row][currentCol + 1].setValue(grid[row][currentCol].getValue());
                    grid[row][currentCol].setValue(0);
                    currentCol++;
                }
                if (currentCol < SIZE - 1 && grid[row][currentCol + 1].getValue() == grid[row][currentCol].getValue()) {
                    // On s'occupe de la fusion des cases
                    int newValue = grid[row][currentCol].getValue() * 2;
                    grid[row][currentCol + 1].setValue(newValue);
                    grid[row][currentCol].setValue(0);
                }
            }
        }
    }
}

void Grid::moveTilesLeft() {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 1; col < SIZE; col++) {
            if (!grid[row][col].isEmpty()) {
                int currentCol = col;
                while (currentCol > 0 && grid[row][currentCol - 1].isEmpty()) {
                    //Ici on s'occupe des d�placements
                    grid[row][currentCol - 1].setValue(grid[row][currentCol].getValue());
                    grid[row][currentCol].setValue(0);
                    currentCol--;
                }
                if (currentCol > 0 && grid[row][currentCol - 1].getValue() == grid[row][currentCol].getValue()) {
                    // Fuuuuu-sion Haa!
                    int newValue = grid[row][currentCol].getValue() * 2;
                    grid[row][currentCol - 1].setValue(newValue);
                    grid[row][currentCol].setValue(0);
                }
            }
        }
    }
}

int Grid::getTileValue(int col, int row) const {
    if (row >= 0 && row < SIZE && col >= 0 && col < SIZE) {
        return grid[row][col].getValue();
    }
    else {
        // G�rez les coordonn�es invalides, par exemple, retournez -1 ou une valeur par d�faut.
        return 0; // Remplacez -1 par la valeur par d�faut souhait�e.
    }
}