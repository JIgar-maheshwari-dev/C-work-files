#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480
#define ROTATION_RADIUS 150 // Adjust this value as needed

void drawSquare(SDL_Renderer* renderer, int x, int y, int size) {
    SDL_Rect rect = { x - size / 2, y - size / 2, size, size };
    SDL_RenderDrawRect(renderer, &rect);
}

void rotatePoint(int *x, int *y, float angle) {
    float newX = *x * cos(angle) - *y * sin(angle);
    float newY = *x * sin(angle) + *y * cos(angle);
    *x = (int)newX;
    *y = (int)newY;
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

    int centerX = WIDTH / 2;
    int centerY = HEIGHT / 2;
    int size = 80; // Reduced size to fit the screen better
    float angle = 0;

    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        int x1 = centerX + (int)(ROTATION_RADIUS * cos(angle));
        int y1 = centerY + (int)(ROTATION_RADIUS * sin(angle));
        int x2 = centerX + (int)(ROTATION_RADIUS * cos(M_PI / 2 + angle));
        int y2 = centerY + (int)(ROTATION_RADIUS * sin(M_PI / 2 + angle));
        int x3 = centerX + (int)(ROTATION_RADIUS * cos(M_PI + angle));
        int y3 = centerY + (int)(ROTATION_RADIUS * sin(M_PI + angle));
        int x4 = centerX + (int)(ROTATION_RADIUS * cos(3 * M_PI / 2 + angle));
        int y4 = centerY + (int)(ROTATION_RADIUS * sin(3 * M_PI / 2 + angle));

        rotatePoint(&x1, &y1, angle);
        rotatePoint(&x2, &y2, angle);
        rotatePoint(&x3, &y3, angle);
        rotatePoint(&x4, &y4, angle);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawSquare(renderer, x1, y1, size);
        drawSquare(renderer, x2, y2, size);
        drawSquare(renderer, x3, y3, size);
        drawSquare(renderer, x4, y4, size);

        SDL_RenderPresent(renderer);

        SDL_Delay(50);

        angle += 0.1;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
