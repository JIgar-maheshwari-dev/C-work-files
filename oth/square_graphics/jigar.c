#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define TEXT_SIZE 60
#define COLOR_CHANGE_INTERVAL 500 // in milliseconds
#define FADE_DURATION 2000         // in milliseconds

void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

SDL_Color randomColor() {
    SDL_Color color;
    color.r = rand() % 256;
    color.g = rand() % 256;
    color.b = rand() % 256;
    color.a = 255;
    return color;
}

SDL_Color interpolateColor(SDL_Color startColor, SDL_Color endColor, float ratio) {
    SDL_Color result;
    result.r = startColor.r + (endColor.r - startColor.r) * ratio;
    result.g = startColor.g + (endColor.g - startColor.g) * ratio;
    result.b = startColor.b + (endColor.b - startColor.b) * ratio;
    result.a = 255;
    return result;
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Colorful JIGAR");

    TTF_Font* font = TTF_OpenFont("1.ttf", TEXT_SIZE);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    int x = WIDTH / 2 - 100;
    int y = HEIGHT / 2 - TEXT_SIZE / 2;

    SDL_Color currentColor = {0, 0, 0, 255};
    SDL_Color nextColor = randomColor();
    Uint32 lastColorChangeTime = SDL_GetTicks();
    Uint32 currentTime;

    while (1) {
        currentTime = SDL_GetTicks();

        float elapsedTime = currentTime - lastColorChangeTime;
        if (elapsedTime >= COLOR_CHANGE_INTERVAL) {
            lastColorChangeTime = currentTime;
            currentColor = nextColor;
            nextColor = randomColor();
        }

        SDL_SetRenderDrawColor(renderer, 32, 32, 32, 255);
        SDL_RenderClear(renderer);

        float ratio = elapsedTime / FADE_DURATION;
        if (ratio > 1.0) {
            ratio = 1.0;
        }
        SDL_Color blendedColor = interpolateColor(currentColor, nextColor, ratio);

        renderText(renderer, font, "Jigar Maheshwari", x, y, blendedColor);

        SDL_RenderPresent(renderer);
        SDL_Delay(10); // To prevent high CPU usage
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
