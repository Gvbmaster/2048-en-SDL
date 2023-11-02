#pragma once
#include "SDL.h"

class Window
{
public:
    Window(const char* title, int width, int height); //constructeur
    ~Window(); //destructeur

    void clear();
    void render();
    SDL_Renderer* getRenderer() const;

private:
    SDL_Window* window;
    SDL_Renderer* renderer;
};