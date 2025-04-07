#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  int pv;
  char nom[100];
  int damage1;
  int damage2;
  int spe;
  int soin;
} Stat;

void Init(Stat j[]) {
  strcpy(j[0].nom, "Archer");
  j[0].pv = 100;
  j[0].damage1 = 7;
  j[0].damage2 = 15;
  j[0].spe = 50;
  j[0].soin = 0;

  strcpy(j[1].nom, "Guerrier");
  j[1].pv = 150;
  j[1].damage1 = 10;
  j[1].damage2 = 20;
  j[1].spe = 30;
  j[1].soin = 0;

  strcpy(j[2].nom, "Mage");
  j[2].pv = 80;
  j[2].damage1 = 40;
  j[2].damage2 = 50;
  j[2].spe = 60;
  j[2].soin = 0;

  strcpy(j[3].nom, "Soigneur");
  j[3].pv = 100;
  j[3].damage1 = 0;
  j[3].damage2 = 0;
  j[3].spe = 0;
  j[3].soin = 40;
}

void ChoixJoueur(Stat dest[], Stat source[]) {
  int p1, p2, p3;
  printf("Entrez les numéros des 3 personnages à choisir (0 à 3) : ");
  scanf("%d %d %d", &p1, &p2, &p3);

  if (p1 < 0 || p1 > 3 || p2 < 0 || p2 > 3 || p3 < 0 || p3 > 3) {
    printf("Erreur : numéro invalide.\n");
    exit(1);
  }

  dest[0] = source[p1];
  dest[1] = source[p2];
  dest[2] = source[p3];
}

int main(void) {
  Stat joueurs[4]; // 4 personnages
  Stat j1[3], j2[3];
  int choix;

  Init(joueurs);

  printf("Adversaire :\n");
  printf("1 -> Joueur 2      2 -> Bot\n");
  scanf("%d", &choix);

  if (choix == 1 || choix == 2) {
    printf("Choix joueur 1 :\n");
    ChoixJoueur(j1, joueurs);

    if (choix == 1) {
      printf("Choix joueur 2 :\n");
      ChoixJoueur(j2, joueurs);
    }
  } else {
    printf("Erreur : choix invalide.\n");
    exit(1);
  }

  printf("Joueur 1 a choisi :\n");
  for (int i = 0; i < 3; i++) {
    printf("-%s\n", j1[i].nom);
  }

  if (choix == 1) {
    printf("Joueur 2 a choisi :\n");
    for (int i = 0; i < 3; i++) {
      printf("-%s\n", j2[i].nom);
    }
  }

  return 0;
}
