#pragma once
#include "SDL.h"

class Case{
public:
    Case(SDL_Renderer* renderer, int x, int y, int width, int height); // Constructeur

    int getValue() const;
    void setValue(int newValue);
    void render(); // Méthode pour afficher la case
    bool isEmpty() const;

private:
    SDL_Renderer* renderer; //rendu SDL
    int value;
    SDL_Rect rect; // Rectangle pour l'emplacement et la taille de la case
};