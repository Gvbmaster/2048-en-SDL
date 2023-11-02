#include "Window.h"
#include <iostream>

Window::Window(const char* title, int width, int height) {
    // Initialisez SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        // Gérez les erreurs d'initialisation de SDL
        std::cerr << "Erreur lors de l'initialisation de SDL : " << SDL_GetError() << std::endl;
    }

    // Créez la fenêtre SDL
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    // Créez le rendu SDL
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

Window::~Window() {
    // Libérez les ressources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Window::clear() {
    SDL_RenderClear(renderer);
}

void Window::render() {
    SDL_RenderPresent(renderer);
}

SDL_Renderer* Window::getRenderer() const {
    return renderer;
}