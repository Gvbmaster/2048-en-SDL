#pragma once
#include <SDL.h>

class GameObject {
public:
    GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height); //constructeur
    ~GameObject(); //destructeur

    void render();


private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    SDL_Rect rect;
};
