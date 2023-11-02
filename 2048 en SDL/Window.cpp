#include "Window.h"

Window::Window(const char* title, int width, int height) {
    // Initialise SDL
    SDL_Init(SDL_INIT_VIDEO);

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