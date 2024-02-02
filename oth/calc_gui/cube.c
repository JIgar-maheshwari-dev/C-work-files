#include <SDL2/SDL.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h> // Add this line for bool type and true/false constants

#define WIDTH 800
#define HEIGHT 600
#define PI 3.14159265

typedef struct {
    float x, y, z;
} Vertex;

void drawLine(SDL_Renderer *renderer, int x1, int y1, int x2, int y2) {
    SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}



void drawCube(SDL_Renderer *renderer, float angle) {
    // Define cube vertices
    Vertex vertices[] = {
        {0, 0, 0},
        {100, 0, 0},
        {100, 100, 0},
        {0, 100, 0},
        {0, 0, 100},
        {100, 0, 100},
        {100, 100, 100},
        {0, 100, 100}
    };

    // Rotate cube around y-axis
    for (int i = 0; i < 8; ++i) {
        float x = vertices[i].x;
        float z = vertices[i].z;
        vertices[i].x = x * cos(angle) - z * sin(angle);
        vertices[i].z = z * cos(angle) + x * sin(angle);
    }

    // Translate cube to center of window
    float translateX = WIDTH / 2;
    float translateY = HEIGHT / 2;
    for (int i = 0; i < 8; ++i) {
        vertices[i].x += translateX;
        vertices[i].y += translateY;
    }

    // Draw lines
    drawLine(renderer, vertices[0].x, vertices[0].y, vertices[1].x, vertices[1].y);
    drawLine(renderer, vertices[1].x, vertices[1].y, vertices[2].x, vertices[2].y);
    drawLine(renderer, vertices[2].x, vertices[2].y, vertices[3].x, vertices[3].y);
    drawLine(renderer, vertices[3].x, vertices[3].y, vertices[0].x, vertices[0].y);

    drawLine(renderer, vertices[4].x, vertices[4].y, vertices[5].x, vertices[5].y);
    drawLine(renderer, vertices[5].x, vertices[5].y, vertices[6].x, vertices[6].y);
    drawLine(renderer, vertices[6].x, vertices[6].y, vertices[7].x, vertices[7].y);
    drawLine(renderer, vertices[7].x, vertices[7].y, vertices[4].x, vertices[4].y);

    drawLine(renderer, vertices[0].x, vertices[0].y, vertices[4].x, vertices[4].y);
    drawLine(renderer, vertices[1].x, vertices[1].y, vertices[5].x, vertices[5].y);
    drawLine(renderer, vertices[2].x, vertices[2].y, vertices[6].x, vertices[6].y);
    drawLine(renderer, vertices[3].x, vertices[3].y, vertices[7].x, vertices[7].y);
}




int main() {
    SDL_Window *window;
    SDL_Renderer *renderer;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("Isometric Cube", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
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
    bool running = true; // Use bool type here
    float angle = 0.0;

    while (running) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // Draw isometric cube
        drawCube(renderer, angle);

        SDL_RenderPresent(renderer);

        // Rotate angle
        angle += 0.01;
        if (angle > 2 * PI) {
            angle -= 2 * PI;
        }

        SDL_Delay(1000); // Adjust the speed of rotation
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
