#pragma once
#include "SDL.h"

class Case{
public:
    Case(); 

    int getValue() const;
    void setValue(int newValue);
    bool isEmpty() const;

private:
    SDL_Renderer* renderer; //rendu SDL
    int value;
    SDL_Rect rect; 
};