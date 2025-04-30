#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

typedef struct {
  int pv;
  char nom[100];
  char attaque1[100];
  int damage1;
  char attaque2[100];
  int damage2;
  char attaque3[100];
  int spe;
  int soin;
} Stat;

void effacerEcran() {
  printf("\033[2J"); // Efface tout l’écran
  printf("\033[H");  // Replace le curseur en haut à gauche
}

void Init(Stat j[]) {
  strcpy(j[0].nom, "ARCHER");
  j[0].pv = 100;
  strcpy(j[0].attaque1, "Flèche");
  j[0].damage1 = 7;
  strcpy(j[0].attaque2, "Flèche explosive");
  j[0].damage2 = 15;
  strcpy(j[0].attaque3, "Flèche empoisonnée");
  j[0].spe = 50;
  j[0].soin = 0;

  strcpy(j[1].nom, "GUERRIER");
  j[1].pv = 150;
  strcpy(j[1].attaque1, "Coup d'épée");
  j[1].damage1 = 10;
  strcpy(j[1].attaque2, "Coup de hache");
  j[1].damage2 = 20;
  strcpy(j[1].attaque3, "Coup de masse");
  j[1].spe = 30;
  j[1].soin = 0;

  strcpy(j[2].nom, "MAGE");
  j[2].pv = 80;
  strcpy(j[2].attaque1, "Boule de feu");
  j[2].damage1 = 40;
  strcpy(j[2].attaque2, "Boule de glace");
  j[2].damage2 = 50;
  strcpy(j[2].attaque3, "Boule de foudre");
  j[2].spe = 60;
  j[2].soin = 0;

  strcpy(j[3].nom, "SOIGNER");
  j[3].pv = 100;
  strcpy(j[3].attaque1, "Soin léger");
  j[3].damage1 = 5;
  strcpy(j[3].attaque2, "Soin modéré");
  j[3].damage2 = 10;
  strcpy(j[3].attaque3, "Soin puissant");
  j[3].spe = 15;
  j[3].soin = 40;

  strcpy(j[4].nom, "SONIC");
  j[4].pv = 100;
  strcpy(j[4].attaque1, "Charge rapide");
  j[4].damage1 = 15;
  strcpy(j[4].attaque2, "Bouclier destructeur");
  j[4].damage2 = 25;
  strcpy(j[4].attaque3, "Spin dash");
  j[4].spe = 35;
  j[4].soin = 5;

  strcpy(j[5].nom, "MARIO");
  j[5].pv = 100;
  strcpy(j[5].attaque1, "Coup de marteau");
  j[5].damage1 = 15;
  strcpy(j[5].attaque2, "Coup de feu");
  j[5].damage2 = 25;
  strcpy(j[5].attaque3, "Super saut");
  j[5].spe = 35;
  j[5].soin = 10;
}
void Liste(Stat j[], int n) {
  printf("Liste des personnages :\n");

  for (int i = 0; i < n; i++) {
    printf("%d -> %s                           %d -> %s\n", i, j[i].nom, i + 1,
           j[i + 1].nom);
    printf("| pv: %d |                           | pv: %d |\n", j[i].pv,
           j[i + 1].pv);
    printf("| %s: %d |                           | %s: %d |\n", j[i].attaque1,
           j[i].damage1, j[i + 1].attaque1, j[i + 1].damage1);
    printf("| %s: %d |                           | %s: %d |\n", j[i].attaque2,
           j[i].damage2, j[i + 1].attaque2, j[i + 1].damage2);
    printf("| %s: %d |                           | %s: %d |\n", j[i].attaque3,
           j[i].spe, j[i + 1].attaque3, j[i + 1].spe);
    printf("| soin: %d |                           | soin: %d |\n", j[i].soin,
           j[i + 1].soin);
  }
  /*printf("%d -> | %s |\n| pv: %d |\n| %s: %d | \n| %s: %d |\n| %s: %d |\n|
soin: %d |\n \n",i,j[i].nom,j[i].pv, j[i].attaque1,j[i].damage1,
j[i].attaque2,j[i].damage2, j[i].attaque3,j[i].spe,j[i].soin);
}
printf("0 -> Archer (pv: 100, damage1: 7, damage2: 15, spe: 50, soin: 0)\n");
printf(
    "1 -> Guerrier (pv: 150, damage1: 10, damage2: 20, spe: 30, soin: 0)\n");
printf("2 -> Mage (pv: 80, damage1: 40, damage2: 50, spe: 60, soin: 0)\n");
printf(
    "3 -> Soigneur (pv: 100, damage1: 5, damage2: 10, spe: 15, soin: 40)\n");
printf("4 -> Sonic (pv: 100, damage1: 5, damage2: 10, spe: 15, soin: 40)\n");
printf("5 -> Mario (pv: 100, damage1: 5, damage2: 10, spe: 15, soin: 40)\n");*/
}

void ChoixJoueur(Stat dest[], Stat source[]) {
  int p1, p2, p3;
  printf("Entrez les numéros des 3 personnages à choisir (0 à 3) : ");
  scanf("%d %d %d", &p1, &p2, &p3);

  if (p1 < 0 || p1 > 5 || p2 < 0 || p2 > 5 || p3 < 0 || p3 > 5) {
    printf("Erreur : numéro invalide.\n");
    exit(1);
  }

  dest[0] = source[p1];
  dest[1] = source[p2];
  dest[2] = source[p3];
}

void Affichage(Stat j1[], Stat j2[], int choix, int a, int c) {
  char *p1 = "";
  char *p2 = "";
  printf("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
  if (choix == 1) {
    printf("Joueur 1:                          Joueur 2:\n");
    for (int i = 0; i < 3; i++) {
      if (a == i) {
        p1 = "💥";
      } else {
        p1 = "";
      }
      if (c == i) {
        p2 = "💥";
      } else {
        p2 = "";
      }
      printf("-%s (pv: %d)%s                   %s-%s (pv: %d)\n", j1[i].nom,
             j1[i].pv, p1, p2, j2[i].nom, j2[i].pv);
    }
  } else if (choix == 2) {
    printf("Joueur 1:                         Bot:\n");
    for (int i = 0; i < 3; i++) {
      printf("-%s (pv: %d)                   -%s (pv: %d)\n", j1[i].nom,
             j1[i].pv, j2[i].nom, j2[i].pv);
    }
  }
  printf("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
}

void Combat(Stat j1[], Stat j2[], int joueur1, int joueur2, int c) {
  int choix, cible, attaque;
  while (joueur1 >= 0 && joueur2 >= 0) {
    // attaque joueur 1
    choix = rand() % 5;
    cible = rand() % 5;
    while (j2[cible].pv <= 0 || j1[choix].pv <= 0) {
      choix = rand() % 5;
      cible = rand() % 5;
    }
    effacerEcran();
    Affichage(j1, j2, c, choix, cible);
    printf("🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫 :\n");
    printf("1 -> %s(%d)\n2 -> %s(%d)\n3 -> %s(%d)\n4 -> Soin(%d)\n",
           j1[choix].attaque1, j1[choix].damage1, j1[choix].attaque2,
           j1[choix].damage2, j1[choix].attaque3, j1[choix].spe,
           j1[choix].soin);
    printf("🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫 :\n");
    printf("Joueur1(%s) attaque joueur2(%s) avec: ", j1[choix].nom,
           j2[cible].nom);
    scanf("%d", &attaque);
    if (attaque == 1) {
      j2[cible].pv -= j1[choix].damage1;
    } else if (attaque == 2) {
      j2[cible].pv -= j1[choix].damage2;
    } else if (attaque == 3) {
      j2[cible].pv -= j1[choix].spe;
    } else {
      j1[choix].pv += j1[choix].soin;
    }
    if (j2[cible].pv <= 0) {
      joueur2--;
      printf("Joueur 2 a %d personnages restants\n", joueur2);
      if (joueur2 <= 0) {
        break;
      }
    }
    // Affichage(j1, j2, c, choix, cible);
    //  attaque joueur 2
    choix = rand() % 5;
    cible = rand() % 5;
    while (j1[cible].pv <= 0 || j2[choix].pv <= 0) {
      choix = rand() % 5;
      cible = rand() % 5;
    }
    effacerEcran();
    Affichage(j1, j2, c, cible, choix);
    printf("🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫 :\n");
    printf("1 -> %s(%d)\n2 -> %s(%d)\n3 -> %s(%d)\n4 -> Soin(%d)\n",
           j2[choix].attaque1, j2[choix].damage1, j2[choix].attaque2,
           j2[choix].damage2, j2[choix].attaque3, j2[choix].spe,
           j2[choix].soin);
    printf("🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫🔫 :\n");
    printf("joueur2(%s) attaque joueur1(%s) avec: ", j2[choix].nom,
           j1[cible].nom);
    scanf("%d", &attaque);
    if (attaque == 1) {
      j1[cible].pv -= j2[choix].damage1;
    } else if (attaque == 2) {
      j1[cible].pv -= j2[choix].damage2;
    } else if (attaque == 3) {
      j1[cible].pv -= j2[choix].spe;
    } else {
      j2[choix].pv += j2[choix].soin;
    }
    if (j1[cible].pv <= 0) {
      joueur1--;
      printf("Joueur 1 a %d personnages restants\n", joueur1);
      if (joueur1 <= 0) {
        break;
      }
    }
    // Affichage(j1, j2, c, choix, cible);
  }

  if (joueur1 <= 0) {
    printf("Joueur 2 a gagné🏆\n");
  } else {
    printf("Joueur 1 a gagné🏆\n");
  }
}

void Start(Stat j1[], Stat j2[], int c, int joueur1, int joueur2) {
  Combat(j1, j2, joueur1, joueur2, c);
}

int main(void) {
  srand(time(NULL));
  Stat joueurs[5]; // 4 personnages
  int joueur1 = 3, joueur2 = 3;
  Stat j1[3], j2[3];
  int choix;

  Init(joueurs);

  printf("1 -> Joueur 2      2 -> Bot\n");
  printf("Adversaire : ");
  scanf("%d", &choix);
  Liste(joueurs, 4);
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
  // Affichage(j1, j2, choix, -1, -1);
  Start(j1, j2, choix, joueur1, joueur2);
  return 0;
}
