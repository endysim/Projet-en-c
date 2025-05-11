#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "stb_image_write.h"
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// Constantes pour la taille d’un personnage
#define Largeur 96
#define Hauteur 96
// Dimensions de la grille d’affichage
#define COLONNE 3
#define LIGNE 3
#define NOMBRE_PERSO 9

// Structure représentant un personnage
typedef struct {
    SDL_Rect pos;  // Position et taille
    SDL_Texture* texture; // Texture chargée depuis une image
} Guerrier;

// Fonction pour créer un personnage à partir d’une image donnée
Guerrier createGuerrier(SDL_Renderer* renderer, const char* imagePath, int x, int y) {
    Guerrier g;
    SDL_Surface* surface = IMG_Load(imagePath); charge une image à partir d’un fichier
    // Chargement de l'image PNG en surface
    if (!surface) {
        printf("Erreur chargement image %s : %s\n", imagePath, IMG_GetError());
        exit(1);
    }
    // Conversion de la surface en texture
    g.texture = SDL_CreateTextureFromSurface(renderer, surface);
    if (!g.texture) {
        printf("Erreur création texture : %s\n", SDL_GetError());
        SDL_FreeSurface(surface);
        exit(1);
    }
    // Position et dimensions du personnage sur l’écran
    g.pos.x = x;
    g.pos.y = y;
    g.pos.w = Largeur;
    g.pos.h = Hauteur;

    SDL_FreeSurface(surface); // Libération de la surface après création de la texture
    return g;
}
// Fonction pour afficher un personnage à l’écran
void renderGuerrier(SDL_Renderer* renderer, Guerrier* g) {
    SDL_RenderCopy(renderer, g->texture, NULL, &g->pos);
}

int main(int argc, char* argv[]) {
    //setenv("SDL_VIDEODRIVER", "dummy", 1);
    // Initialisation de la SDL 
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur SDL_Init : %s\n", SDL_GetError());
        return 1;
    }
    // Initialisation de SDL_image pour charger des PNG
    if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
        printf("Erreur IMG_Init : %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }
     // Calcul des dimensions de la fenêtre
    int largeur_ecran = COLONNE * Largeur;
    int hauteur_ecran = LIGNE * Hauteur;

    // Création de la fenêtre SDL
    SDL_Window* fenetre = SDL_CreateWindow("Sélection de Personnages",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        largeur_ecran, hauteur_ecran, SDL_WINDOW_SHOWN);

    if (!fenetre) {
        printf("Erreur création fenêtre : %s\n", SDL_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Création du renderer SDL (moteur de rendu) qui fait le lien entre les textures et la fenêtre ,prépare et affiche les images (textures) sur la fenêtre
    SDL_Renderer* moteur = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
     if (!moteur) {
        printf("Erreur création renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(fenetre);
        IMG_Quit();
        SDL_Quit();
        return 1;
    }
    // Tableau contenant les chemins des images pour chaque personnage
    const char* imagePaths[NOMBRE_PERSO] = {
        "aizen_sel.png", "archer_sel.png", "itachi_sel.png",
        "naruto_sel.png", "shoto_sel.png", "sonic_sel.png",
        "Zoro_sel.png", "guerrier_sel.png", "soigneur_sel.png"
    };
    
    // Création de tous les personnages à partir des images
    Guerrier guerriers[NOMBRE_PERSO];
    int index = 0;

    // Placement des personnages dans une grille
    for (int ligne = 0; ligne < LIGNE; ++ligne) {
        for (int col = 0; col < COLONNE; ++col) {
            int x = col * Largeur;
            int y = ligne * Hauteur;
            guerriers[index] = createGuerrier(moteur, imagePaths[index], x, y);
            index++;
        }
    }
   
    bool cour = true;  //controle la boucle principale
    SDL_Event e; // contient les informations sur les événements reçus par SDL

    while (cour) {
        while (SDL_PollEvent(&e)) { // SDL_PollEvent récupère les événements (fermeture)
            if (e.type == SDL_QUIT)
                cour = false;
        }
        // On définit la couleur de fond
        SDL_SetRenderDrawColor(moteur, 20, 20, 20, 255);
        // On efface tout l'écran avec la couleur définie
        SDL_RenderClear(moteur);

        // Affichage de tous les personnages
        for (int i = 0; i < NOMBRE_PERSO; ++i) {
            renderGuerrier(moteur, &guerriers[i]);
        }
        // Met à jour l’écran
        SDL_RenderPresent(moteur);
        //Marque une petite pause
        SDL_Delay(16);
    }

    // Libération mémoire
    for (int i = 0; i < NOMBRE_PERSO; ++i) {
        SDL_DestroyTexture(guerriers[i].texture);
    }

    SDL_DestroyRenderer(moteur);
    SDL_DestroyWindow(fenetre);
    IMG_Quit();
    SDL_Quit();
    return 0;
}
