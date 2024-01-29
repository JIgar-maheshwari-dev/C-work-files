#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#define WIDTH 800
#define HEIGHT 600
#define PI 3.14159265

void drawTree(SDL_Renderer *renderer, int x1, int y1, double length, double angle, int depth, double thickness) {
    if (depth == 0) return;

    int x2 = x1 + (int) (cos(angle) * length);
    int y2 = y1 - (int) (sin(angle) * length);

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);

    drawTree(renderer, x2, y2, length * 0.75, angle - PI / 6, depth - 1, thickness * 0.8);
    drawTree(renderer, x2, y2, length * 0.75, angle + PI / 6, depth - 1, thickness * 0.8);

    if (thickness <= 1) return;

    SDL_SetRenderDrawColor(renderer, 139, 69, 19, 255);
    SDL_RenderDrawLine(renderer, x1 - (thickness / 2), y1, x2 - (thickness / 2), y2);
    SDL_RenderDrawLine(renderer, x1 + (thickness / 2), y1, x2 + (thickness / 2), y2);
}

int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Fractal Tree", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Event event;
    bool running = true;

    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Set background color to white
        SDL_RenderClear(renderer);

        drawTree(renderer, WIDTH / 2, HEIGHT, 150, -PI / 2, 10, 10); // Adjust the parameters as needed

        SDL_RenderPresent(renderer);

        SDL_Delay(10); // Adjust the delay for smoother rendering
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
