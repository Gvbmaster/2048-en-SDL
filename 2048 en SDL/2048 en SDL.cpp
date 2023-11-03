#include "SDL.h"
#include "Window.h"
#include "GameObject.h"
#include "Grid.h"

int main(int argc, char* argv[]) {
    // Initialisez SDL et créez une fenêtre
    SDL_Init(SDL_INIT_VIDEO);
    Window window("2048", 800, 600);

    // Initialisez la grille de jeu
    Grid grid;
    grid.initializeGrid();
    grid.generateRandomTile();
    grid.generateRandomTile();

    // Créez un GameObject pour afficher la grille
    GameObject gameGrid(window.getRenderer(), "img/board.png", 0, 0, 800, 600);

    // Boucle de jeu principale
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
            else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                case SDLK_UP:
                    grid.moveTilesUp();
                    // Vérifiez les conditions de victoire ou de défaite ici
                    // ...
                    break;
                case SDLK_DOWN:
                    grid.moveTilesDown();
                    // Vérifiez les conditions de victoire ou de défaite ici
                    // ...
                    break;
                case SDLK_LEFT:
                    grid.moveTilesLeft();
                    // Vérifiez les conditions de victoire ou de défaite ici
                    // ...
                    break;
                case SDLK_RIGHT:
                    grid.moveTilesRight();
                    // Vérifiez les conditions de victoire ou de défaite ici
                    // ...
                    break;
                default:
                    break;
                }
            }
        }

        for (int row = 0; row < SIZE; row++) {
            for (int col = 0; col < SIZE; col++) {
                int value = grid.grid[row][col].getValue(); // Obtenez la valeur de la case

                // Calculez les coordonnées d'affichage pour l'objet GameObject en fonction de la position dans la grille
                int x = col * TILE_SIZE; // TILE_SIZE est la taille d'une tuile
                int y = row * TILE_SIZE;

                // Recherchez l'objet GameObject correspondant à cette case dans votre structure de données (par exemple, un tableau d'objets GameObject)
                // Mettez à jour la texture de l'objet GameObject en fonction de la valeur de la case
                if (value == 0) {
                    // Si la valeur est 0, l'objet doit être vide, vous pouvez utiliser une texture vide ou rien
                    // gameObjectArray[row][col].setTexture(emptyTexture);
                }
                else {
                    // Chargez la texture correspondante à la valeur
                    // gameObjectArray[row][col].setTexture(texture2); // par exemple
                }

                // Mettez à jour la position de l'objet GameObject
                // gameObjectArray[row][col].setPosition(x, y);
            }
        }


        // Effacez l'écran
        window.clear();

        // Affichez la grille de jeu
        gameGrid.render();

        // Mettez à jour l'affichage
        window.render();
    }
    return 0;
}

