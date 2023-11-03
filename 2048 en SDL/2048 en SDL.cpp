#include <SDL.h>
#include <iostream>
#include "Grid.h"


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

using namespace std;
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("2048 Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if (window == nullptr) {
        std::cerr << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 2;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == nullptr) {
        std::cerr << "Renderer could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return 3;
    }

    SDL_Surface* boardImage = SDL_LoadBMP("img/board.bmp"); 
    SDL_Surface* tile0Image = SDL_LoadBMP("img/0.bmp");
    SDL_Surface* tile2Image = SDL_LoadBMP("img/2.bmp"); 
    SDL_Surface* tile4Image = SDL_LoadBMP("img/4.bmp"); 
    SDL_Surface* tile8Image = SDL_LoadBMP("img/8.bmp");
    SDL_Surface* tile16Image = SDL_LoadBMP("img/16.bmp");
    SDL_Surface* tile32Image = SDL_LoadBMP("img/32.bmp");
    SDL_Surface* tile64Image = SDL_LoadBMP("img/64.bmp");
    SDL_Surface* tile128Image = SDL_LoadBMP("img/128.bmp");
    SDL_Surface* tile256Image = SDL_LoadBMP("img/256.bmp");
    SDL_Surface* tile512Image = SDL_LoadBMP("img/512.bmp");
    SDL_Surface* tile1024Image = SDL_LoadBMP("img/1024.bmp");
    SDL_Surface* tile2048Image = SDL_LoadBMP("img/2048.bmp");
    
    
    SDL_Texture* boardTexture = SDL_CreateTextureFromSurface(renderer, boardImage); 
    SDL_Texture* tile0Texture = SDL_CreateTextureFromSurface(renderer, tile0Image);
    SDL_Texture* tile2Texture = SDL_CreateTextureFromSurface(renderer, tile2Image);  
    SDL_Texture* tile4Texture = SDL_CreateTextureFromSurface(renderer, tile4Image);  
    SDL_Texture* tile8Texture = SDL_CreateTextureFromSurface(renderer, tile8Image);
    SDL_Texture* tile16Texture = SDL_CreateTextureFromSurface(renderer, tile16Image);
    SDL_Texture* tile32Texture = SDL_CreateTextureFromSurface(renderer, tile32Image);
    SDL_Texture* tile64Texture = SDL_CreateTextureFromSurface(renderer, tile64Image);
    SDL_Texture* tile128Texture = SDL_CreateTextureFromSurface(renderer, tile128Image); 
    SDL_Texture* tile256Texture = SDL_CreateTextureFromSurface(renderer, tile256Image); 
    SDL_Texture* tile512Texture = SDL_CreateTextureFromSurface(renderer, tile512Image); 
    SDL_Texture* tile1024Texture = SDL_CreateTextureFromSurface(renderer, tile1024Image); 
    SDL_Texture* tile2048Texture = SDL_CreateTextureFromSurface(renderer, tile2048Image); 
    
    
    
    Grid grid;

    bool theGame = true;
    grid.generateRandomTile();
    grid.generateRandomTile(); 
    while (theGame) {
        // Effacez l'écran à chaque itération.
        SDL_RenderClear(renderer);

        SDL_Event e;
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                theGame = false;
            }
            else if (e.type == SDL_KEYDOWN) {
                switch (e.key.keysym.sym) {
                case SDLK_UP:
                    grid.moveTilesUp();
                    grid.generateRandomTile();
                    grid.winCondition(); 
                    grid.loseCondition(); 
                    break;
                case SDLK_DOWN:
                    grid.moveTilesDown();
                    grid.generateRandomTile(); 
                    grid.winCondition(); 
                    grid.loseCondition(); 
                    break;
                case SDLK_LEFT:
                    grid.moveTilesLeft();
                    grid.generateRandomTile(); 
                    grid.winCondition(); 
                    grid.loseCondition(); 
                    break;
                case SDLK_RIGHT:
                    grid.moveTilesRight(); 
                    grid.generateRandomTile(); 
                    grid.winCondition(); 
                    grid.loseCondition(); 
                    break;
                case SDLK_q:
                    theGame = false;
                    break;
                }
            }
        }
        

        int tileSize = 200; // Taille d'une tuile
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                int tileValue = grid.getTileValue(i, j); // Remplacez getTileValue par la méthode appropriée dans votre classe Grid
                SDL_Texture* tileTexture;

                // Choisissez la texture en fonction de la valeur de la tuile
                switch (tileValue) {
                case 2:
                    tileTexture = tile2Texture;
                    break;
                case 4:
                    tileTexture = tile4Texture;
                    break;
                case 8:
                    tileTexture = tile8Texture;
                    break;
                case 16:
                    tileTexture = tile16Texture;
                    break;
                case 32:
                    tileTexture = tile32Texture;
                    break;
                case 64:
                    tileTexture = tile64Texture; 
                    break;
                case 128:
                    tileTexture = tile128Texture; 
                    break;
                case 256:
                    tileTexture = tile256Texture;
                    break;
                case 512:
                    tileTexture = tile512Texture;
                    break;
                case 1024:
                    tileTexture = tile1024Texture;
                    break;
                case 2048:
                    tileTexture = tile2048Texture;
                    break;
                default:
                    tileTexture = tile0Texture; // Texture par défaut pour une case vide
                    break;
                }

                // Dessinez la tuile à la position (i, j) en utilisant la texture appropriée
                SDL_Rect destRect = { i * tileSize, j * tileSize, tileSize, tileSize };
                SDL_RenderCopy(renderer, tileTexture, NULL, &destRect);
            }
        }

        // Mettez à jour l'affichage.
        SDL_RenderPresent(renderer);

        
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
