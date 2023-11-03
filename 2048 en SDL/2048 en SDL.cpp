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

        // Effacez l'écran
        window.clear();

        // Affichez la grille de jeu
        gameGrid.render();

        // Mettez à jour l'affichage
        window.render();
    }
    return 0;
}

