#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "stb_image_write.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define Largeur 96
#define Hauteur 96
#define GRID_COLS 3
#define GRID_ROWS 3
#define NUM_CHARACTERS 9

typedef struct {
    SDL_Rect pos;
    SDL_Texture* texture;
} Guerrier;

Guerrier createGuerrier(SDL_Renderer* renderer, const char* imagePath, int x, int y) {
    Guerrier g;
    SDL_Surface* surface = IMG_Load(imagePath);
    if (!surface) {
        printf("Erreur chargement image %s : %s\n", imagePath, IMG_GetError());
        exit(1);
    }

    g.texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!g.texture) {
        printf("Erreur création texture : %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        exit(1);
    }

    g.pos.x = x;
    g.pos.y = y;
    g.pos.w = Largeur;
    g.pos.h = Hauteur;

    SDL_FreeSurface(surface);
    return g;
}

void renderGuerrier(SDL_Renderer* renderer, Guerrier* g) {
    SDL_RenderCopy(renderer, g->texture, NULL, &g->pos);
}

int main(int argc, char* argv[]) {
    //setenv("SDL_VIDEODRIVER", "dummy", 1);

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }

    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Erreur IMG_Init : %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    int screenWidth = GRID_COLS * Largeur;
    int screenHeight = GRID_ROWS * Hauteur;

    SDL_Window* fenetre = SDL_CreateWindow("Sélection de Personnages",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        screenWidth, screenHeight, SDL_WINDOW_SHOWN);

    if (!fenetre) {
        printf("Erreur création fenêtre : %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
        
    SDL_Renderer* moteur = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);

     if (!moteur) {
        printf("Erreur création renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Liste des chemins d’images pour chaque personnage
    const char* imagePaths[NUM_CHARACTERS] = {
        "aizen_sel.png", "archer_sel.png", "itachi_sel.png",
        "naruto_sel.png", "shoto_sel.png", "sonic_sel.png",
        "Zoro_sel.png", "guerrier_sel.png", "soigneur_sel.png"
    };

    Guerrier guerriers[NUM_CHARACTERS];
    int index = 0;

    for (int ligne = 0; ligne < GRID_ROWS; ++ligne) {
        for (int col = 0; col < GRID_COLS; ++col) {
            int x = col * Largeur;
            int y = ligne * Hauteur;
            guerriers[index] = createGuerrier(moteur, imagePaths[index], x, y);
            index++;
        }
    }

    bool cour = true;
    SDL_Event e;

    while (cour) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT)
                cour = false;
        }

        SDL_SetRenderDrawColor(moteur, 20, 20, 20, 255);
        SDL_RenderClear(moteur);

        for (int i = 0; i < NUM_CHARACTERS; ++i) {
            renderGuerrier(moteur, &guerriers[i]);
        }

        SDL_RenderPresent(moteur);
        SDL_Delay(16);
    }

    // Libération mémoire
    for (int i = 0; i < NUM_CHARACTERS; ++i) {
        SDL_DestroyTexture(guerriers[i].texture);
    }

    SDL_DestroyRenderer(moteur);
    SDL_DestroyWindow(fenetre);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
