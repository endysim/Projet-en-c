#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdbool.h>

// Constantes pour la taille d’une case et le nombre de frames par animation d’attaque
#define LARGEUR_CASE 96
#define HAUTEUR_CASE 96
#define FRAMES_PAR_ATTAQUE 3

// Enumération des états possibles du personnage
typedef enum {
    ETAT_REPOS,
    ATTAQUE_1,
    ATTAQUE_2,
    ATTAQUE_3
} EtatAction;

// Structure représentant un personnage
typedef struct {
    SDL_Rect position;
    SDL_Texture* repos;
    SDL_Texture* attaques[3][FRAMES_PAR_ATTAQUE];
    EtatAction etat;
    int indice_frame;
    int compteur_frame;
    Uint32 dernier_changement;  // Dernier changement d'image (temps en ms).Uint32 est un type entier non signé de 32 bits fourni par SDL.
} Personnage;

// Fonction pour charger une image et la convertir en texture SDL
SDL_Texture* chargerTexture(SDL_Renderer* rendu, const char* chemin) {
    SDL_Surface* surface = IMG_Load(chemin); //Charger une image depuis un fichier
    if (!surface) {
        printf("Erreur chargement image %s : %s\n", chemin, IMG_GetError());
        exit(1);
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(rendu, surface);
    SDL_FreeSurface(surface);
    return texture;
}

// Initialise un personnage avec ses textures et sa position
Personnage creerPersonnage(SDL_Renderer* rendu, int x, int y) {
    Personnage p;
    p.position.x = x;
    p.position.y = y;
    p.position.w = LARGEUR_CASE;
    p.position.h = HAUTEUR_CASE;
    p.etat = ETAT_REPOS;
    p.indice_frame = 0;
    p.compteur_frame = 0;
    p.dernier_changement = SDL_GetTicks(); // Initialiser avec l'heure actuelle

    // Chargement de l’image de repos
    p.repos = chargerTexture(rendu,"aizen_sel.jpeg");

    // Chargement des textures pour les animations d’attaque
    char chemin[100];
    for (int attaque = 0; attaque < 3; ++attaque) {
        for (int i = 0; i < FRAMES_PAR_ATTAQUE; ++i) {
            snprintf(chemin, sizeof(chemin), "aizen_coup%d_%d.jpeg", attaque + 1, i);
            p.attaques[attaque][i] = chargerTexture(rendu, chemin); // Charge une frame d'attaque et la stocke dans le tableau de textures du personnage
        }
    }
    return p;
}
// Met à jour le personnage, change la frame de l’animation si nécessaire
void mettreAJourPersonnage(Personnage* p) {
    if (p->etat == ETAT_REPOS)
        return;

    Uint32 temps_courant = SDL_GetTicks();
    if (temps_courant - p->dernier_changement > 200) { // Attendre 200 ms avant de changer l'image
        p->dernier_changement = temps_courant; // Mettre à jour le dernier changement
        p->indice_frame++;
        
        if (p->indice_frame >= FRAMES_PAR_ATTAQUE) {
            p->etat = ETAT_REPOS;  // Revenir au repos après avoir passé toutes les frames d'attaque
            p->indice_frame = 0;
        }
    }
}

// Affiche le personnage à l’écran selon son état actuel
void afficherPersonnage(SDL_Renderer* rendu, Personnage* p) {
    if (p->etat == ETAT_REPOS) {
        SDL_RenderCopy(rendu, p->repos, NULL, &p->position);
    } else {
        SDL_RenderCopy(rendu, p->attaques[p->etat - 1][p->indice_frame], NULL, &p->position);
    }
}
// Libère toutes les textures allouées pour un personnage
void detruirePersonnage(Personnage* p) {
    SDL_DestroyTexture(p->repos);
    for (int attaque = 0; attaque < 3; ++attaque) {
        for (int i = 0; i < FRAMES_PAR_ATTAQUE; ++i) {
            SDL_DestroyTexture(p->attaques[attaque][i]);
        }
    }
}

int main(int argc, char* argv[]) {
     // Initialisation de SDL et SDL_image
    SDL_Init(SDL_INIT_VIDEO);
    IMG_Init(IMG_INIT_PNG);

     // Création de la fenêtre
    SDL_Window* fenetre = SDL_CreateWindow("Animations d'Attaques",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        LARGEUR_CASE, HAUTEUR_CASE, SDL_WINDOW_SHOWN);

    // Création du rendu (renderer)
    SDL_Renderer* rendu = SDL_CreateRenderer(fenetre, -1, SDL_RENDERER_ACCELERATED);
    // Création du personnage
    Personnage joueur = creerPersonnage(rendu, 0, 0);

    bool enCours = true;
    SDL_Event evenement;

    while (enCours) {
        while (SDL_PollEvent(&evenement)) {
            if (evenement.type == SDL_QUIT)
                enCours = false;// Quitte le programme si la fenêtre est fermée

            if (evenement.type == SDL_KEYDOWN) { 
             // Vérifie quelle touche a été appuyée
                switch (evenement.key.keysym.sym) {
                    case SDLK_1: joueur.etat = ATTAQUE_1; joueur.indice_frame = 0; break; // La touche "1" active l'attaque 1
                    case SDLK_2: joueur.etat = ATTAQUE_2; joueur.indice_frame = 0; break; // La touche "2" active l'attaque 2
                    case SDLK_3: joueur.etat = ATTAQUE_3; joueur.indice_frame = 0; break; // La touche "3" active l'attaque 3
                }
            }
        }

        mettreAJourPersonnage(&joueur);
        // Efface l’écran et dessine le fond
        SDL_SetRenderDrawColor(rendu, 30, 30, 30, 255);
        SDL_RenderClear(rendu);

        afficherPersonnage(rendu, &joueur);
        
        // Rafraîchit l’écran
        SDL_RenderPresent(rendu);
        // Pause d'environ 16 ms pour viser un affichage à 60 images par seconde (1000 ms / 60 FPS)
        SDL_Delay(1000 / 60);
    }
    // Nettoyage mémoire
    detruirePersonnage(&joueur);
    SDL_DestroyRenderer(rendu);
    SDL_DestroyWindow(fenetre);
    IMG_Quit();
    SDL_Quit();
    return 0;
}


