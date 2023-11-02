#include "GameObject.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

GameObject::GameObject(SDL_Renderer* renderer, const char* imagePath, int x, int y, int width, int height)
    : renderer(renderer) {
    // Initialisation de SDL_image (assurez-vous d'avoir appelé SDL_Init(SDL_INIT_EVERYTHING) ailleurs dans votre programme)
    IMG_Init(IMG_INIT_PNG);

    // Chargez l'image au format PNG depuis le chemin spécifié en utilisant SDL_image
    SDL_Surface* surface = IMG_Load(imagePath);
    if (surface) {
        texture = SDL_CreateTextureFromSurface(renderer, surface);
        SDL_FreeSurface(surface);

        rect.x = x;
        rect.y = y;
        rect.w = width;
        rect.h = height;
    }
    else {
        std::cerr << "Erreur lors du chargement de l'image : " << IMG_GetError() << std::endl;
    }
}

GameObject::~GameObject() {
    if (texture) {
        SDL_DestroyTexture(texture);
    }
}

void GameObject::render() {
    if (texture) {
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}