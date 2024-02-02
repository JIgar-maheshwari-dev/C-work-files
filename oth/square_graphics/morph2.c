#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define WIDTH 640
#define HEIGHT 480
#define TEXT_SIZE 60
#define MORPH_INTERVAL 2000 // in milliseconds

void renderText(SDL_Renderer* renderer, TTF_Font* font, const char* text, int x, int y, SDL_Color color) {
    SDL_Surface* surface = TTF_RenderText_Solid(font, text, color);
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);

    SDL_Rect rect = {x, y, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &rect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}

char* morphText(const char* text1, const char* text2, float ratio) {
    int len1 = strlen(text1);
    int len2 = strlen(text2);
    int maxLength = len1 > len2 ? len1 : len2;

    char* result = (char*)malloc(maxLength + 1);

    for (int i = 0; i < maxLength; ++i) {
        char ch1 = (i < len1) ? text1[i] : '\0';
        char ch2 = (i < len2) ? text2[i] : '\0';

        if (ch1 == '\0' || ch2 == '\0' || ch1 == ch2) {
            result[i] = ch1;
        } else {
            float blend = ratio * (ch2 - ch1) + ch1;
            result[i] = (char)blend;
        }
    }

    result[maxLength] = '\0';
    return result;
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Text Morphing");

    TTF_Font* font = TTF_OpenFont("1.ttf", TEXT_SIZE);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    int x = WIDTH / 2 - 200;
    int y = HEIGHT / 2 - TEXT_SIZE / 2;

    const char* text1 = "JIGAR";
    const char* text2 = "MAHESHWARI";

    int forward = 1;
    Uint32 lastMorphTime = SDL_GetTicks();
    Uint32 currentTime;

    while (1) {
        currentTime = SDL_GetTicks();

        float elapsedTime = currentTime - lastMorphTime;
        if (elapsedTime >= MORPH_INTERVAL) {
            lastMorphTime = currentTime;

            if (forward) {
                const char* temp = text1;
                text1 = text2;
                text2 = temp;
            } else {
                const char* temp = text2;
                text2 = text1;
                text1 = temp;
            }

            forward = !forward;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        float ratio = (float)elapsedTime / MORPH_INTERVAL;
        if (!forward) {
            ratio = 1.0 - ratio;
        }
        char* morphedText = morphText(text1, text2, ratio);
        renderText(renderer, font, morphedText, x, y, (SDL_Color){0, 0, 0, 255});
        free(morphedText);

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

