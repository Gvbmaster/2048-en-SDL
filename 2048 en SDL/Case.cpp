#include "Case.h"
#include "SDL_image.h" 

const char* texture2Path = "textures/2.bmp";
const char* texture4Path = "textures/4.bmp";
const char* texture8Path = "textures/8.bmp";
const char* texture16Path = "textures/16.bmp";
const char* texture32Path = "textures/32.bmp";
const char* texture64Path = "textures/64.bmp";
const char* texture128Path = "textures/128.bmp";
const char* texture256Path = "textures/256.bmp";
const char* texture512Path = "textures/512.bmp";
const char* texture1024Path = "textures/1024.bmp";
const char* texture2048Path = "textures/2048.bmp";

Case::Case(SDL_Renderer* renderer, int x, int y, int width, int height) : renderer(renderer){
    texture2 = IMG_LoadTexture(renderer, texture2Path);
    texture4 = IMG_LoadTexture(renderer, texture4Path);
    texture8 = IMG_LoadTexture(renderer, texture8Path);
    texture16 = IMG_LoadTexture(renderer, texture16Path);
    texture32 = IMG_LoadTexture(renderer, texture32Path);
    texture64 = IMG_LoadTexture(renderer, texture64Path);
    texture128 = IMG_LoadTexture(renderer, texture128Path);
    texture256 = IMG_LoadTexture(renderer, texture256Path);
    texture512 = IMG_LoadTexture(renderer, texture512Path);
    texture1024 = IMG_LoadTexture(renderer, texture1024Path);
    texture2048 = IMG_LoadTexture(renderer, texture2048Path);
}

Case::~Case() {
    if (texture2) {
        SDL_DestroyTexture(texture2);
    }
    if (texture4) {
        SDL_DestroyTexture(texture4);
    }
    if (texture8) {
		SDL_DestroyTexture(texture8);
	}
    if (texture16) {
		SDL_DestroyTexture(texture16);
	}
    if (texture32) {
		SDL_DestroyTexture(texture32);
	}
    if (texture64) {
		SDL_DestroyTexture(texture64);
	}
    if (texture128) {
		SDL_DestroyTexture(texture128);
	}
    if (texture256) {
		SDL_DestroyTexture(texture256);
	}
    if (texture512) {
		SDL_DestroyTexture(texture512);
	}
    if (texture1024) {
		SDL_DestroyTexture(texture1024);
	}
    if (texture2048) {
		SDL_DestroyTexture(texture2048);
	}
}

void Case::render() {
    if (value == 0) {
        SDL_RenderCopy(renderer, emptyTexture, NULL, &rect);
    }
    else if (value == 2) {
        SDL_RenderCopy(renderer, texture4, NULL, &rect);
    }
    else if (value == 4) {
        SDL_RenderCopy(renderer, texture2, NULL, &rect);
    }
    else if (value == 2) {
        SDL_RenderCopy(renderer, texture4, NULL, &rect);
    }
    else if (value == 4) {
        SDL_RenderCopy(renderer, texture2, NULL, &rect);
    }
    else if (value == 8) {
		SDL_RenderCopy(renderer, texture8, NULL, &rect);
	}
    else if (value == 16) {
		SDL_RenderCopy(renderer, texture16, NULL, &rect);
	}
    else if (value == 32) {
		SDL_RenderCopy(renderer, texture32, NULL, &rect);
	}
    else if (value == 64) {
		SDL_RenderCopy(renderer, texture64, NULL, &rect);
	}
    else if (value == 128) {
		SDL_RenderCopy(renderer, texture128, NULL, &rect);
	}
    else if (value == 256) {
		SDL_RenderCopy(renderer, texture256, NULL, &rect);
	}
    else if (value == 512) {
		SDL_RenderCopy(renderer, texture512, NULL, &rect);
	}
    else if (value == 1024) {
		SDL_RenderCopy(renderer, texture1024, NULL, &rect);
	}
    else if (value == 2048) {
		SDL_RenderCopy(renderer, texture2048, NULL, &rect);
	}
}

int Case::getValue() const {
    return value;
}

void Case::setValue(int newValue) {
    value = newValue;
}

bool Case::isEmpty() const {
    return (value == 0);
}
