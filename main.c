#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
  j[3].damage1 = 5;
  j[3].damage2 = 10;
  j[3].spe = 15;
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

void Affichage(Stat j1[], Stat j2[], int choix) {
  printf(
      "********************************************************************\n");
  if (choix == 1) {
    printf("Joueur 1:                          Joueur 2:\n");
    for (int i = 0; i < 3; i++) {
      printf("-%s (pv: %d)                   -%s (pv: %d)\n", j1[i].nom,
             j1[i].pv, j2[i].nom, j2[i].pv);
    }
  } else if (choix == 2) {
    printf("Joueur 1:                         Bot:\n");
    for (int i = 0; i < 3; i++) {
      printf("-%s (pv: %d)                   -%s (pv: %d)\n", j1[i].nom,
             j1[i].pv, j2[i].nom, j2[i].pv);
    }
  }
}

void Start(Stat j1[], Stat j2[], int c, int joueur1, int joueur2) {
  int choix, cible, attaque;
  while (joueur1 >= 0 && joueur2 >= 0) {
    // attaque joueur 1
    choix = rand() % 3;
    cible = rand() % 3;
    while (j2[cible].pv <= 0 || j1[choix].pv <= 0) {
      choix = rand() % 3;
      cible = rand() % 3;
    }
    printf("1 -> Attaque 1  2 -> Attaque 2  3 -> Attaque spéciale\n");
    printf("Joueur1(%s) attaque joueur2(%s) avec: ", j1[choix].nom,
           j2[cible].nom);
    scanf("%d", &attaque);
    if (attaque == 1) {
      j2[cible].pv -= j1[choix].damage1;
    } else if (attaque == 2) {
      j2[cible].pv -= j1[choix].damage2;
    } else {
      j2[cible].pv -= j1[choix].spe;
    }
    if (j2[cible].pv <= 0) {
      joueur2--;
    }
    Affichage(j1, j2, c);
    // attaque joueur 2
    choix = rand() % 3;
    cible = rand() % 3;
    while (j1[cible].pv <= 0 || j2[choix].pv <= 0) {
      choix = rand() % 3;
      cible = rand() % 3;
    }
    printf("1 -> Attaque 1  2 -> Attaque 2  3 -> Attaque spéciale\n");
    printf("joueur2(%s) attaque joueur1(%s) avec: ", j2[choix].nom,
           j1[cible].nom);
    scanf("%d", &attaque);
    if (attaque == 1) {
      j1[cible].pv -= j2[choix].damage1;
    } else if (attaque == 2) {
      j1[cible].pv -= j2[choix].damage2;
    } else {
      j1[cible].pv -= j2[choix].spe;
    }
    if (j1[cible].pv <= 0) {
      joueur1--;
    }
    Affichage(j1, j2, c);
  }
}

int main(void) {
  srand(time(NULL));
  Stat joueurs[4]; // 4 personnages
  int joueur1 = 3, joueur2 = 3;
  Stat j1[3], j2[3];
  int choix;

  Init(joueurs);

  printf("1 -> Joueur 2      2 -> Bot\n");
  printf("Adversaire : ");
  scanf("%d", &choix);

  if (choix == 1 || choix == 2) {
    printf("Choix joueur 1 :\n");
    ChoixJoueur(j1, joueurs);

    if (choix == 1) {
      printf("Choix joueur 2 :\n");
      ChoixJoueur(j2, joueurs);
    } else if (choix == 2) {
      printf("Choix bot :\n");
      ChoixJoueur(j2, joueurs);
    }
  } else {
    printf("Erreur : choix invalide.\n");
    exit(1);
  }

  /*printf("Joueur 1 a choisi :\n");
  for (int i = 0; i < 3; i++) {
    printf("-%s\n", j1[i].nom);
  }*/
  Affichage(j1, j2, choix);
  Start(j1, j2, choix, joueur1, joueur2);

  return 0;
}
