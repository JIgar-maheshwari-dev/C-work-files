#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

const int WINDOW_WIDTH = 800;
const int WINDOW_HEIGHT = 600;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Texture *boardTexture = NULL;
SDL_Texture *snakeTexture = NULL;
SDL_Texture *ladderTexture = NULL;

// Function to initialize SDL
bool initializeSDL() {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    window = SDL_CreateWindow("Snake and Ladder",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH,
                              WINDOW_HEIGHT,
                              SDL_WINDOW_SHOWN);

    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// Function to load textures
bool loadMedia() {
    boardTexture = IMG_LoadTexture(renderer, "./board.jpg");
    if (boardTexture == NULL) {
        printf("Failed to load board texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    snakeTexture = IMG_LoadTexture(renderer, "snake.png");
    if (snakeTexture == NULL) {
        printf("Failed to load snake texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    ladderTexture = IMG_LoadTexture(renderer, "ladder.png");
    if (ladderTexture == NULL) {
        printf("Failed to load ladder texture! SDL_Error: %s\n", SDL_GetError());
        return false;
    }

    return true;
}

// Function to render game objects
void render() {
    SDL_RenderClear(renderer);

    // Render board
    SDL_RenderCopy(renderer, boardTexture, NULL, NULL);

    // Render snakes and ladders

    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]) {
    if (!initializeSDL()) {
        printf("Failed to initialize SDL\n");
        return -1;
    }

    if (!loadMedia()) {
        printf("Failed to load media\n");
        return -1;
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        render();
    }

    SDL_DestroyTexture(boardTexture);
    SDL_DestroyTexture(snakeTexture);
    SDL_DestroyTexture(ladderTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    SDL_Quit();
    return 0;
}

