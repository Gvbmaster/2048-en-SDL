#include "Window.h"


void Window::loadBmpImg() {

    SDL_Surface* S0 = SDL_LoadBMP("img/board.bmp");
    SDL_Texture* Bmp0 = SDL_CreateTextureFromSurface(renderer, S0);
    tabBmpImg[0] = Bmp0;
    SDL_FreeSurface(S0);

    SDL_Surface* S1 = SDL_LoadBMP("img/2.bmp");
    SDL_Texture* Bmp1 = SDL_CreateTextureFromSurface(renderer, S1);
    tabBmpImg[1] = Bmp1;
    SDL_FreeSurface(S1);

    SDL_Surface* S2 = SDL_LoadBMP("img/4.bmp");
    SDL_Texture* Bmp2 = SDL_CreateTextureFromSurface(renderer, S2);
    tabBmpImg[2] = Bmp2;
    SDL_FreeSurface(S2);

    SDL_Surface* S3 = SDL_LoadBMP("img/8.bmp");
    SDL_Texture* Bmp3 = SDL_CreateTextureFromSurface(renderer, S3);
    tabBmpImg[3] = Bmp3;
    SDL_FreeSurface(S3);

    SDL_Surface* S4 = SDL_LoadBMP("img/16.bmp");
    SDL_Texture* Bmp4 = SDL_CreateTextureFromSurface(renderer, S4);
    tabBmpImg[4] = Bmp4;
    SDL_FreeSurface(S4);

    SDL_Surface* S5 = SDL_LoadBMP("img/32.bmp");
    SDL_Texture* Bmp5 = SDL_CreateTextureFromSurface(renderer, S5);
    tabBmpImg[5] = Bmp5;
    SDL_FreeSurface(S5);

    SDL_Surface* S6 = SDL_LoadBMP("img/64.bmp");
    SDL_Texture* Bmp6 = SDL_CreateTextureFromSurface(renderer, S6);
    tabBmpImg[6] = Bmp6;
    SDL_FreeSurface(S6);

    SDL_Surface* S7 = SDL_LoadBMP("img/128.bmp");
    SDL_Texture* Bmp7 = SDL_CreateTextureFromSurface(renderer, S7);
    tabBmpImg[7] = Bmp7;
    SDL_FreeSurface(S7);

    SDL_Surface* S8 = SDL_LoadBMP("img/256.bmp");
    SDL_Texture* Bmp8 = SDL_CreateTextureFromSurface(renderer, S8);
    tabBmpImg[8] = Bmp8;
    SDL_FreeSurface(S8);

    SDL_Surface* S9 = SDL_LoadBMP("img/512.bmp");
    SDL_Texture* Bmp9 = SDL_CreateTextureFromSurface(renderer, S9);
    tabBmpImg[9] = Bmp9;
    SDL_FreeSurface(S9);

    SDL_Surface* S10 = SDL_LoadBMP("img/1024.bmp");
    SDL_Texture* Bmp10 = SDL_CreateTextureFromSurface(renderer, S10);
    tabBmpImg[10] = Bmp10;
    SDL_FreeSurface(S10);

    SDL_Surface* S11 = SDL_LoadBMP("img/2048.bmp");
    SDL_Texture* Bmp11 = SDL_CreateTextureFromSurface(renderer, S11);
    tabBmpImg[11] = Bmp11;
    SDL_FreeSurface(S11);

    SDL_Surface* S12 = SDL_LoadBMP("img/0.bmp");
    SDL_Texture* Bmp12 = SDL_CreateTextureFromSurface(renderer, S12);
    tabBmpImg[12] = Bmp12;
    SDL_FreeSurface(S12);
}


Window::Window() {
    SDL_Init(SDL_INIT_VIDEO);

    window = SDL_CreateWindow("2048", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 800, SDL_WINDOW_SHOWN);

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