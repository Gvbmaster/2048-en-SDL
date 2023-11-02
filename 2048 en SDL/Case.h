#pragma once
#include "SDL.h"

class Case{
public:
    Case(SDL_Renderer* renderer, int x, int y, int width, int height); 

    int getValue() const;
    void setValue(int newValue);
    void render(); 
    void loadBMPImg();
    bool isEmpty() const;

private:
    SDL_Renderer* renderer; //rendu SDL
    int value;
    SDL_Rect rect; 
};