#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>

#define WIDTH 400
#define HEIGHT 600
#define BUTTON_WIDTH 80
#define BUTTON_HEIGHT 80
#define BUTTON_PADDING 10
#define FONT_SIZE 32

typedef struct {
    SDL_Rect rect;
    char label[16];
} Button;


void drawButton(SDL_Renderer* renderer, const Button* button, TTF_Font* font) {
    SDL_Color buttonColor = {64, 64, 64, 255};
    SDL_SetRenderDrawColor(renderer, buttonColor.r, buttonColor.g, buttonColor.b, buttonColor.a);
    SDL_RenderFillRect(renderer, &button->rect);

    SDL_Surface* surface = TTF_RenderText_Solid(font, button->label, (SDL_Color){255, 255, 255, 255});
    if (!surface) {
        printf("Failed to render text: %s\n", TTF_GetError());
        return;
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!texture) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        return;
    }

    SDL_Rect textRect = {button->rect.x + button->rect.w / 2 - surface->w / 2, button->rect.y + button->rect.h / 2 - surface->h / 2, surface->w, surface->h};
    SDL_RenderCopy(renderer, texture, NULL, &textRect);

    SDL_FreeSurface(surface);
    SDL_DestroyTexture(texture);
}


void drawCalculator(SDL_Renderer* renderer, TTF_Font* font, const Button* buttons, int buttonCount) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    for (int i = 0; i < buttonCount; ++i) {
        drawButton(renderer, &buttons[i], font);
    }

    SDL_RenderPresent(renderer);
}

int main() {
    SDL_Window* window;
    SDL_Renderer* renderer;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();

    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Simple Calculator");

    TTF_Font* font = TTF_OpenFont("1.ttf", FONT_SIZE);
    if (!font) {
        printf("Failed to load font: %s\n", TTF_GetError());
        return 1;
    }

    Button buttons[] = {
        {{0, 0, BUTTON_WIDTH, BUTTON_HEIGHT}, "7"},
        {{BUTTON_WIDTH + BUTTON_PADDING, 0, BUTTON_WIDTH, BUTTON_HEIGHT}, "8"},
        {{2 * (BUTTON_WIDTH + BUTTON_PADDING), 0, BUTTON_WIDTH, BUTTON_HEIGHT}, "9"},
        {{3 * (BUTTON_WIDTH + BUTTON_PADDING), 0, BUTTON_WIDTH, BUTTON_HEIGHT}, "/"},

        {{0, BUTTON_HEIGHT + BUTTON_PADDING, BUTTON_WIDTH, BUTTON_HEIGHT}, "4"},
        {{BUTTON_WIDTH + BUTTON_PADDING, BUTTON_HEIGHT + BUTTON_PADDING, BUTTON_WIDTH, BUTTON_HEIGHT}, "5"},
        {{2 * (BUTTON_WIDTH + BUTTON_PADDING), BUTTON_HEIGHT + BUTTON_PADDING, BUTTON_WIDTH, BUTTON_HEIGHT}, "6"},
        {{3 * (BUTTON_WIDTH + BUTTON_PADDING), BUTTON_HEIGHT + BUTTON_PADDING, BUTTON_WIDTH, BUTTON_HEIGHT}, "*"},

        {{0, 2 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "1"},
        {{BUTTON_WIDTH + BUTTON_PADDING, 2 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "2"},
        {{2 * (BUTTON_WIDTH + BUTTON_PADDING), 2 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "3"},
        {{3 * (BUTTON_WIDTH + BUTTON_PADDING), 2 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "-"},

        {{0, 3 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "C"},
        {{BUTTON_WIDTH + BUTTON_PADDING, 3 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "0"},
        {{2 * (BUTTON_WIDTH + BUTTON_PADDING), 3 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "="},
        {{3 * (BUTTON_WIDTH + BUTTON_PADDING), 3 * (BUTTON_HEIGHT + BUTTON_PADDING), BUTTON_WIDTH, BUTTON_HEIGHT}, "+"}
    };

    int buttonCount = sizeof(buttons) / sizeof(buttons[0]);

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        drawCalculator(renderer, font, buttons, buttonCount);
        SDL_Delay(10); // To prevent high CPU usage
    }

    TTF_CloseFont(font);
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
