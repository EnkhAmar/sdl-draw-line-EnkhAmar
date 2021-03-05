#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

static const int width = 800;
static const int height = 600;

// Get a random number between 0 and 254 (255 deer tsagaan bgaa)
int randCol()
{
    return rand() % 254 + 0;
}
int randLen ()
{
    return rand() % 700 + 50;
}

int main(int argc, char *argv[])
{
    srand (time(NULL));
    // Initialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create an SDL windows
    SDL_Window *window = SDL_CreateWindow("Drawing Line | BG color change", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    // Create a renderer (accelerated and in sync with the display refresh rate)
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    // Initial color
    SDL_SetRenderDrawColor(renderer, randCol(), randCol(), randCol(), 255);

    bool running = true;
    Uint32 old_time = 0, change_color_time = 1000, new_time;
    SDL_Event event;
    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_KEYDOWN)
            {
                const char* key = SDL_GetKeyName(event.key.keysym.sym);
                if (strcmp(key, "Q") == 0 || strcmp(key, "Escape") == 0)
                {
                    running = false;
                }
            }
            else if (event.type == SDL_QUIT)
            {
                running = false;
            }
        }


        // Clear screen
        SDL_RenderClear(renderer);
        SDL_Delay(1000);

        // Draw
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDrawLine(renderer, 50, 150, randLen(), 150);
        SDL_RenderDrawLine(renderer, 50, 300, randLen(), 300);

        SDL_Rect rect = {50, 450, randLen(), 50};
        SDL_RenderFillRect(renderer, &rect);


        // Show what was drawn
        SDL_RenderPresent(renderer);


        new_time = SDL_GetTicks();
        if (new_time - old_time > change_color_time)
        {
            SDL_SetRenderDrawColor(renderer, randCol(), randCol(), randCol(), 255);
            old_time = new_time;
        }
    }

    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    printf("G. Enkh-Amar 18B1NUM0399\n");
    return 0;
}
