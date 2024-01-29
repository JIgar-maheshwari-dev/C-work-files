#include <SDL2/SDL.h>
#include <math.h>

#define WIDTH 640
#define HEIGHT 480

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
    int size = 100;
    float angle = 0;

    while (1) {
        SDL_Event event;
        if (SDL_PollEvent(&event) && event.type == SDL_QUIT) {
            break;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        int x1 = centerX - size / 2;
        int y1 = centerY - size / 2;
        int x2 = centerX + size / 2;
        int y2 = centerY + size / 2;

        rotatePoint(&x1, &y1, angle);
        rotatePoint(&x2, &y2, angle);

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        drawSquare(renderer, x1, y1, size);

        SDL_RenderPresent(renderer);

        SDL_Delay(50);

        angle += 0.1;
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
