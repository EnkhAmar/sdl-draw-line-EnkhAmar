#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

const int width = 800;
const int height = 600;


void moveUp (int x) {
    x++;
}

int main(int argc, char* argv[])
{
    printf("G.Enkh-Amar");
    printf("18B1NUM0399");
    // Intialize SDL
    SDL_Init(SDL_INIT_VIDEO);

    // Create an SDL window
    SDL_Window *window = SDL_CreateWindow("Move object", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);

    // Create a renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    int x = 50, y = 50, w=200, h=200;
    bool running = true;
    SDL_Event event;
    while (running) {
        while(SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_LEFT:
                        x-=5;
                        break;
                    case SDLK_RIGHT:
                        x+=5;
                        break;
                    case SDLK_UP:
                        y-=5;
                        break;
                    case SDLK_DOWN:
                        y+=5;
                        break;
                    case SDLK_KP_MINUS:
                        w-=5;
                        h-=5;
                        break;
                    case SDLK_KP_PLUS:
                        w+=5;
                        h+=5;
                        break;
                    case SDLK_ESCAPE:
                        running = false;
                        break;
                }
            }
        }
        SDL_SetRenderDrawColor(renderer, 0, 59, 89, 255);
        SDL_RenderClear(renderer);

        SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
        SDL_Rect rect = {x, y, w, h};
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }


    // Release resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
