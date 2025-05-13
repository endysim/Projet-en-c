#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <unistd.h>

typedef struct {
  int pv;
  char nom[100];
  char attaque1[100];
  int damage1;
  char attaque2[100];
  int damage2;
  int attDelay2;
  char attaque3[100];
  int attDelay3;
  int spe;
  int speedAtt;
  int strengh;
  float counter;
  int soin;
  int agility;
  int reflex;
  int speedDodge;
  int index;
} Stat;

void effacerEcran() {
  printf("\033[2J"); // Efface tout l’écran
  printf("\033[H");  // Replace le curseur en haut à gauche
}
void sonicDraw(){

    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣀⣀⣤⣤⣤⣄⣀⣀⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡤⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣠⠤⠖⣚⣩⣭⣥⣶⣶⣶⣶⣶⣶⣶⣬⣭⣙⣛⠲⢦⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣸⢰⣮⣧⡀⠀⠀⠀⠀⣀⠴⢚⣩⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⡿⢿⣛⢻⣿⣿⣿⣿⣿⣷⣮⣝⡳⢦⣄⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⡇⣿⣿⣿⣿⣦⣀⡴⢚⣵⣾⣿⣿⣿⣿⣿⢿⣟⣿⡽⣛⣭⡶⠿⢿⣿⣹⣿⣿⡿⣿⣿⣿⣿⣿⣿⣷⣜⡻⢦⡀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣯⣿⣿⣿⣿⡿⢫⣶⣿⣿⣿⣿⡿⣿⣽⣾⣿⡿⣽⡾⠛⠉⠀⠀⣼⣟⣿⣿⣿⣿⣿⣷⣿⣿⣿⣿⣿⣿⡿⠮⠿⠷⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⣹⣿⣿⢟⣼⣿⣿⣿⣿⢿⣷⣿⣿⣟⣿⡿⣿⣿⣦⣄⠀⠀⢠⣿⣽⣿⣿⣿⣿⣿⠟⠛⠉⠁⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⡾⣛⢻⣾⣿⣿⡿⣿⣾⣿⣿⣽⣾⣿⣟⣿⣿⣻⣿⣿⣷⣀⣾⢿⣿⣿⡿⣿⣿⣿⣳⣄⡀⠀⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣿⣇⣿⣿⣟⣿⣿⣯⣷⣿⡿⣯⣷⣿⣿⣻⣿⣷⣿⣿⣿⣿⣿⣿⡿⣿⣿⣷⣿⣿⣿⣷⣝⢦⡀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢻⣿⠟⣿⣹⣿⢿⣻⣷⣿⣿⣽⣿⡿⣿⡿⢛⣩⣤⣦⣭⡻⣷⣿⣿⣻⣿⢿⣷⡿⣿⣾⡿⣿⣿⣷⡝⢦⡀⠀⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠸⣿⠀⣿⣿⣻⣿⣿⢿⣷⣿⣻⣷⡿⣣⣾⣿⠟⠛⠻⣿⣿⣿⣿⣽⣿⢿⣿⣻⣿⡿⣷⣿⣿⢿⣿⣿⣦⠳⡄⠀⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢳⠀⠸⣿⣿⣿⣾⣿⣿⣽⣿⢯⣿⠟⠋⠀⠀⠀⠀⠘⣿⣿⣾⣿⣻⣿⣿⣟⣿⣿⢿⣯⣿⣿⢿⣿⣿⣧⠹⡄⠀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢸⠀⠀⢹⣿⢿⣿⣿⣾⢟⣽⠟⠁⢀⡶⡀⠀⠀⠀⢰⣿⣿⣷⣿⢿⣟⣿⣿⣿⣿⣿⣿⣯⣿⣿⡿⣿⣿⣇⢳⡀⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⡀⠀⠀⠈⡧⣾⡶⣿⡿⢭⣫⢵⠟⠁⠀⠀⣼⣿⡇⠀⠀⢠⣿⣿⣿⣾⣿⡿⣿⣿⣿⣿⣻⣿⣿⣿⣿⣷⣿⣿⣿⣿⡈⣇⠀\n");
    printf("⠀⠀⠀⠀⠀⠀⠀⢀⣠⣀⠀⠀⠀⠀⢀⠞⠁⠈⢱⠀⠀⢳⡈⠻⢾⣷⠉⠒⠠⣀⠀⠀⠀⢿⣿⠀⢀⠴⠿⢿⣿⣯⣷⣿⣿⢿⣷⣿⣿⣷⡽⣿⢿⣿⣿⣽⣿⣿⡇⣿⠀\n");
    printf("⠀⠀⠀⠀⠀⢠⠞⡁⠄⠀⠙⣆⠀⡰⠃⠀⠀⡀⡼⠀⠀⠀⠙⢤⡀⠀⠀⠀⠀⠀⠉⠀⠒⠚⠃⠈⢠⣶⠀⣼⣿⣿⣿⣿⣾⣿⣿⣽⣾⣿⣷⡝⣆⠈⠛⢿⣿⣿⣗⣸⡀\n");
    printf("⠀⠀⠀⡠⠖⠾⡆⡀⠀⠀⠀⢸⠋⠀⠀⠀⣐⡤⠃⠀⠀⠀⠀⠀⠉⠲⢤⣀⠀⠀⠀⠀⠤⠄⠐⠒⣁⣤⣾⣿⣿⣿⣿⣷⣿⢿⣾⡿⣟⣿⣿⣿⠸⡆⠀⠀⠙⢿⣿⣷⢸⡇\n");
    printf("⠀⢀⠞⡀⠁⠐⣷⠰⠀⠀⠀⠀⡄⠀⢀⠵⠋⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⠽⢿⡶⣶⣶⣾⣿⡟⢻⣻⣿⠿⣿⣿⣿⣿⣿⣿⣿⢿⣿⣿⣿⣿⡇⢿⠀⠀⠀⠀⠹⣿⢼⡃\n");
    printf("⠀⢘⣆⠃⠀⠀⠘⣆⠆⠀⠀⠀⣇⠔⣯⡄⠀⠀⠀⠀⠀⠀⠀⠀⣀⣴⢋⠀⠀⠀⠙⠶⣽⣿⣿⣧⣆⡴⠋⠓⡬⡛⢿⣿⣿⣿⣿⣿⣿⣾⣿⣿⣿⢸⡄⠀⠀⠀⠀⠈⠿⠀\n");
    printf("⡔⠁⠘⣄⠀⠀⠀⠘⡌⠄⠀⠀⣸⢠⠰⠧⡀⠀⠀⠀⢀⣠⣖⡫⣵⠣⠁⠀⠀⠀⠀⠀⠀⣿⣿⣿⣿⣷⣄⠀⠈⠊⢢⡍⠻⢿⣿⣿⣷⣿⣿⣿⣿⢘⡇⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⢧⠀⠀⠈⠂⡀⠀⠀⠈⠒⣤⠾⣡⢎⠂⢠⡗⠒⠒⠋⠅⠀⣹⣴⠇⠂⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⣿⣿⣿⡏⠀⢀⢠⠃⠀⠀⠉⢿⣿⣽⣿⣿⢸⡇⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⢈⠷⣄⠀⠀⠈⠒⠤⡄⣴⣥⠶⠣⠟⢀⡞⡇⠀⠀⠀⣀⡴⠋⢹⠀⠀⠀⠀⠀⠀⢀⣾⣿⣿⣿⡿⠿⣛⡟⠀⠀⣊⡞⠀⠀⠀⠀⠀⠙⣿⣿⣿⣿⢸⡇⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠸⡀⠀⠒⠀⠤⠤⣤⢳⣡⡏⠀⠀⢀⠾⠾⠖⠒⠚⠋⠁⠀⠀⢸⠀⠀⠀⠀⠀⣠⣿⣿⣿⣿⣻⡇⠀⠻⢦⣀⣈⣼⡳⡄⠀⠀⠀⠀⠀⠈⢿⣿⡏⣾⠁⠀⠀⠀⠀⠀⠀⠀\n");
    printf("⠀⠉⠒⠦⠤⠤⠤⠞⠛⠶⠾⠒⠒⠉⠀⠀⠀⠀⠀⠀⠀⠀⠀⢿⣦⣀⣀⣤⣾⣿⣿⣿⢿⡟⣿⠋⢆⠀⠀⠈⠉⠉⢀⡇⠀⠀⠀⠀⠀⠀⠈⢻⣟⡟⠀⠀⠀⠀⠀⠀⠀⠀\n");

}

void ecranAccueil() {
    printf("\033[1;32m"); // Vert clair pour le cadre
    printf("╔═════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║\033[1;36m                         BIENVENUE DANS                                      \033[1;32m║\n");
    printf("║\033[1;34m       ██████╗ ██╗   ██╗    ███████╗██╗ ██████╗ ██╗   ██╗████████╗           \033[1;32m║\n");
    printf("║\033[1;34m      ██╔═══██╗╚██╗ ██╔╝    ██╔════╝██║██╔═══██ ██║   ██║   ██ ╔═╝           \033[1;32m║\n");
    printf("║\033[1;34m      ██║       ╚████╔╝     █████╗  ██║██║ ___  ████████║   ██ ║             \033[1;32m║\n");
    printf("║\033[1;34m      ██║   ██║  ╚██╔╝      ██╔══╝  ██║██║   ██║██║   ██║   ██ ║             \033[1;32m║\n");
    printf("║\033[1;34m      ╚██████╔╝   ██║       ██║     ██║╚██████╔╝██║   ██║   ██ ║             \033[1;32m║\n");
    printf("║\033[1;34m       ╚═════╝    ╚═╝       ╚═╝     ╚═╝ ╚═════╝ ╚═╝   ╚═╝    ╚═╝             \033[1;32m║\n");
    printf("╚═════════════════════════════════════════════════════════════════════════════╝\n");
    
    printf("\033[1;33m\n");
    printf("                  Appuyez sur Entrée pour commencer...\n");
    printf("\033[0m"); // Réinitialisation couleur

    getchar();
}

void zoro1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc zoro1.c -o zoro1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./zoro1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void zoro2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc zoro2.c -o zoro2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./zoro2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void zoro3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc zoro3.c -o zoro3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./zoro3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void guerrier1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc guerrier1.c -o guerrier1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./guerrier1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void guerrier2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc guerrier2.c -o guerrier2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./guerrier2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void guerrier3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc guerrier3.c -o guerrier3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./guerrier3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void shoto1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc shoto1.c -o shoto1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./shoto1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void shoto2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc shoto2.c -o shoto2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./shoto2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void shoto3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc shoto3.c -o shoto3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./shoto3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void aizen1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc aizen1.c -o aizen1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./aizen1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}
void aizen2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc aizen2.c -o aizen2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_2...\n");
    int resultat_execution = system("./aizen2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}
void aizen3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc aizen3.c -o aizen3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_3...\n");
    int resultat_execution = system("./aizen3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}
void archer1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc archer1.c -o archer1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./archer1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}

void archer2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc archer2.c -o archer2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_2...\n");
    int resultat_execution = system("./archer2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void archer3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc archer3.c -o archer3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_3...\n");
    int resultat_execution = system("./archer3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void itachi1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc itachi1.c -o itachi1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./itachi1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }

}
void itachi2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc itachi2.c -o itachi2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_2...\n");
    int resultat_execution = system("./itachi2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void itachi3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc itachi3.c -o itachi3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_3...\n");
    int resultat_execution = system("./itachi3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void naruto1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc naruto1.c -o naruto1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./naruto1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void naruto2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc naruto2.c -o naruto2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_2...\n");
    int resultat_execution = system("./naruto2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void naruto3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc naruto3.c -o naruto3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_3...\n");
    int resultat_execution = system("./naruto3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void sonic1Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc sonic1.c -o sonic1 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_1...\n");
    int resultat_execution = system("./sonic1");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void sonic2Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc sonic2.c -o sonic2 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_2...\n");
    int resultat_execution = system("./sonic2");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}
void sonic3Att(){
   // Compilation (si ce n'est pas déjà fait)
    int resultat_compilation = system("gcc sonic3.c -o sonic3 $(sdl2-config --cflags --libs) -lSDL2_image");
   
    if (resultat_compilation != 0) {
        printf("Erreur lors de la compilation\n");
    }
   
    // Exécution
    printf("Lancement de l'animation ATTAQUE_3...\n");
    int resultat_execution = system("./sonic3");
   
    if (resultat_execution == 0) {
        printf("Animation terminée avec succès\n");
    } else {
        printf("Erreur lors de l'exécution\n");
    }
}

void Intro() {

  effacerEcran();
  sonicDraw();
  sleep(1);
  ecranAccueil();
}

void afficherBarreVie(int pv, int maxPV);
void Affichage(Stat j1[], Stat j2[], int choix, int a, int c);

void Init(Stat j[]) {
  strcpy(j[0].nom, "ARCHER");
  j[0].pv = 100;
  strcpy(j[0].attaque1, "Flèche");
  j[0].damage1 = 7;
  j[0].attDelay2 = 2;
  strcpy(j[0].attaque2, "Flèche explosive");
  j[0].damage2 = 15;
  j[0].attDelay3 = 3;
  strcpy(j[0].attaque3, "Flèche empoisonnée");
  j[0].spe = 50;
  j[0].speedAtt = 110;
  j[0].strengh = 60;
  j[0].counter = 85;
  j[0].agility = 75;
  j[0].reflex = 65;
  j[0].speedDodge = 71;
  j[0].soin = 0;
  j[0].index = 0;

  strcpy(j[1].nom, "GUERRIER");
  j[1].pv = 150;
  strcpy(j[1].attaque1, "Coup d'épée");
  j[1].damage1 = 10;
  j[1].attDelay2 = 2;
  strcpy(j[1].attaque2, "Coup de hache");
  j[1].damage2 = 20;
  j[1].attDelay3 = 3;
  strcpy(j[1].attaque3, "Coup de masse");
  j[1].spe = 30;
  j[1].speedAtt = 70;
  j[1].strengh = 100;
  j[1].counter = 85;
  j[1].agility = 40;
  j[1].reflex = 30;
  j[1].speedDodge = 36;
  j[1].soin = 0;
  j[1].index = 1;

  strcpy(j[2].nom, "SHOTO");
  j[2].pv = 80;
  strcpy(j[2].attaque1, "Point de feu");
  j[2].damage1 = 40;
  j[2].attDelay2 = 2;
  strcpy(j[2].attaque2, "Boule de glace");
  j[2].damage2 = 50;
  j[2].attDelay3 = 3;
  strcpy(j[2].attaque3, "Super point de feu");
  j[2].spe = 60;
  j[2].speedAtt = 90;
  j[2].strengh = 40;
  j[2].counter = 65;
  j[2].agility = 30;
  j[2].reflex = 70;
  j[2].speedDodge = 46;
  j[2].soin = 20;
  j[2].index = 2;

  strcpy(j[3].nom, "SONIC");
  j[3].pv = 100;
  strcpy(j[3].attaque1, "Charge rapide");
  j[3].damage1 = 15;
  j[3].attDelay2 = 2;
  strcpy(j[3].attaque2, "Bouclier destructeur");
  j[3].damage2 = 25;
  j[3].attDelay3 = 3;
  strcpy(j[3].attaque3, "Spin dash");
  j[3].spe = 35;
  j[3].speedAtt = 130;
  j[3].strengh = 70;
  j[3].counter = 100;
  j[3].agility = 90;         
  j[3].reflex = 80;
  j[3].speedDodge = 86;
  j[3].soin = 5;
  j[3].index = 3;

  strcpy(j[4].nom, "NARUTO");
  j[4].pv = 120;
  strcpy(j[4].attaque1, "Rasengan");
  j[4].damage1 = 28;
  j[4].attDelay2 = 2;
  strcpy(j[4].attaque2, "Clones de l’ombre");
  j[4].damage2 = 20;
  j[4].attDelay3 = 3;
  strcpy(j[4].attaque3, "Rasengan géant");
  j[4].speedAtt = 90;
  j[4].strengh = 80;
  j[4].counter = (j[6].speedAtt + j[6].strengh) / 2;
  j[4].agility = 85;
  j[4].reflex = 80;
  j[4].speedDodge = j[6].agility * 0.6 + j[6].reflex * 0.4;
  j[4].spe = 50;
  j[4].soin = 15;
  j[4].index = 4;

  strcpy(j[5].nom, "ZORO");
  j[5].pv = 130;
  strcpy(j[5].attaque1, "Tranchant du démon");
  j[5].damage1 = 30;
  j[5].attDelay2 = 2;
  strcpy(j[5].attaque2, "Tora Gari");
  j[5].damage2 = 35;
  j[5].attDelay3 = 3;
  strcpy(j[5].attaque3, "Asura : Ichibugin");
  j[5].speedAtt = 70;
  j[5].strengh = 110;
  j[5].counter = (j[7].speedAtt + j[7].strengh) / 2;
  j[5].agility = 60;
  j[5].reflex = 50;
  j[5].speedDodge = j[7].agility * 0.6 + j[7].reflex * 0.4;
  j[5].spe = 60;
  j[5].soin = 5;
  j[5].index = 5;

  strcpy(j[6].nom, "ITACHI");
  j[6].pv = 100;
  strcpy(j[6].attaque1, "Shuriken");
  j[6].damage1 = 18;
  j[6].attDelay2 = 2;
  strcpy(j[6].attaque2, "Amaterasu");
  j[6].damage2 = 35;
  j[6].attDelay3 = 3;
  strcpy(j[6].attaque3, "Tsukuyomi");
  j[6].speedAtt = 95;
  j[6].strengh = 65;
  j[6].counter = (j[8].speedAtt + j[8].strengh) / 2;
  j[6].agility = 75;
  j[6].reflex = 95;
  j[6].speedDodge = j[8].agility * 0.6 + j[8].reflex * 0.4;
  j[6].spe = 60;
  j[6].soin = 10;
  j[6].index = 6;

  strcpy(j[7].nom, "AIZEN");
  j[7].pv = 125;
  strcpy(j[7].attaque1, "Coup de sabre");
  j[7].damage1 = 22;
  j[7].attDelay2 = 2;
  strcpy(j[7].attaque2, "Hadō 90 : Kurohitsugi");
  j[7].damage2 = 40;
  j[7].attDelay3 = 3;
  strcpy(j[7].attaque3, "Kyoka Suigetsu");
  j[7].speedAtt = 80;
  j[7].strengh = 90;
  j[7].counter = (j[9].speedAtt + j[9].strengh) / 2;
  j[7].agility = 70;
  j[7].reflex = 85;
  j[7].speedDodge = j[9].agility * 0.6 + j[9].reflex * 0.4;
  j[7].spe = 70;
  j[7].soin = 5;
  j[7].index = 7;

}
void AttAnim(int index, int att){
  if(index == 0){
    if(att == 1){
      archer1Att();
    }
    else if(att == 2){
      archer2Att();
    }
    else if(att == 3){
      archer3Att();
    }
  }
   else if(index == 1){
      if(att == 1){
        guerrier1Att();
      }
    
      else if(att == 2){
      guerrier2Att();
    }
      else if(att == 3){
        guerrier3Att();
    }
  }
   else if(index == 2){
      if(att == 1){
      shoto1Att();
      }
      else if(att == 2){
      shoto2Att();
    }
      else if(att == 3){
      shoto3Att();
    }
  }
  else if(index == 3){
      if(att == 1){
      sonic1Att();
      }
      else if(att == 2){
      sonic2Att();
    }
      else if(att == 3){
      sonic3Att();
    }
  }
  else if(index == 4){
      if(att == 1){
      naruto1Att();
      }
      else if(att == 2){
      naruto2Att();
    }
      else if(att == 3){
      naruto3Att();
    }
  }
  else if(index == 5){
      if(att == 1){
      zoro1Att();
      }
      else if(att == 2){
      zoro2Att();
    }
      else if(att == 3){
      zoro3Att();
    }
  }
  else if(index == 6){
      if(att == 1){
      itachi1Att();
      }
      else if(att == 2){
        itachi2Att();
      }
      else if(att == 3){
        itachi3Att();
      }
  }
  else if(index == 7){
      if(att == 1){
      aizen1Att();
      }
      else if(att == 2){
      aizen2Att();
    }
      else if(att == 3){
      aizen3Att();
    }
  }
  printf("%d\n", index);
}
void Liste(Stat j[], int n) {
  printf("Liste des personnages :\n");

  for (int i = 0; i < n + 1; i += 2) {
    printf("%2d -> %-12s                %15d -> %-12s\n", i, j[i].nom, i + 1, j[i + 1].nom);
    printf("| pv:   %17d   |                | pv:   %17d   |\n", j[i].pv, j[i + 1].pv);
    printf("| %-20s: %3d |                | %-20s: %3d |\n", j[i].attaque1, j[i].damage1, j[i + 1].attaque1, j[i + 1].damage1);
    printf("| %-20s: %3d |                | %-20s: %3d |\n", j[i].attaque2, j[i].damage2, j[i + 1].attaque2, j[i + 1].damage2);
    printf("| %-20s: %3d |                | %-20s: %3d |\n", j[i].attaque3, j[i].spe, j[i + 1].attaque3, j[i + 1].spe);
    printf("| soin:   %17d |                | soin:   %17d |\n", j[i].soin, j[i + 1].soin);
    printf("\n");
  }

}

void ChoixJoueur(Stat dest[], Stat source[]) {
  int p1, p2, p3;
  printf("Entrez les numéros des 3 personnages à choisir (0 à 5) : ");
  scanf("%d %d %d", &p1, &p2, &p3);

  if (p1 < 0 || p1 > 7 || p2 < 0 || p2 > 7 || p3 < 0 || p3 > 7) {
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
  char *d1 = "";
  char *d2 = "";

  printf("\033[1;44m🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\033[0m\n");
  if (choix == 1) {
    printf("\033[1mJoueur 1:                          Joueur 2:\033[0m\n");
    for (int i = 0; i < 3; i++) {
      p1 = (a == i) ? "💥" : "";
      p2 = (c == i) ? "💥" : "";
      printf("-%s%s                         %s-%s\n", j1[i].nom, p1, p2, j2[i].nom);
      afficherBarreVie(j1[i].pv, 150);
      printf("                             ");
      afficherBarreVie(j2[i].pv, 150);
    }
  }
  else if (choix == 2) {
    printf("\033[1mJoueur 1:                         Bot:\033[0m\n");
    for (int i = 0; i < 3; i++) {
      printf("-%s                         -%s\n", j1[i].nom, j2[i].nom);
      afficherBarreVie(j1[i].pv, 150);
      printf("                             ");
      afficherBarreVie(j2[i].pv, 150);
    }
  
  printf("\033[1;44m🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\033[0m\n");


  
  } else if (choix == 2) {
    printf("Joueur 1:                         Bot:\n");
    for (int i = 0; i < 3; i++) {
      if (a == i) p1 = "💥"; else p1 = "  ";
      if (c == i) p2 = "💥"; else p2 = "  ";
      if (j1[i].pv <= 0) d1 = "💀"; else d1 = "  ";
      if (j2[i].pv <= 0) d2 = "💀"; else d2 = "  ";
  
      // Nom formaté à largeur fixe (ex: 10 caractères max, ajustable)
      printf("-%s%-10s (pv: %3d) %s    |    %s-%-10s (pv: %3d)%s\n",
             d1, j1[i].nom, j1[i].pv, p1,
             p2, j2[i].nom, j2[i].pv, d2);
    }
  }
  printf("🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥🔥\n");
}

void Esquive(Stat att[], Stat cib[], int choixDefense, int degats, int choixAttack, int choixCible, int attacNum)
{
    switch(choixDefense)
    {
        case 1: // Esquive basée sur speedDodge
            if (att[choixAttack].speedAtt < cib[choixCible].speedDodge) {
                printf("💨 %s esquive l'attaque avec grâce !\n", cib[choixCible].nom);
                cib[choixCible].pv += degats;
            } else {
                printf("❌ %s rate son esquive et prend les dégâts.\n", cib[choixCible].nom);
            }
            AttAnim(att[choixAttack].index, attacNum);
            break;

        case 2: // Blocage
          if(cib[choixCible].strengh >= att[choixAttack].strengh){

            printf("🛡️ %s bloque l'attaque et réduit les dégâts à %d !\n", cib[choixCible].nom, cib[choixCible].strengh - att[choixAttack].strengh);
            cib[choixCible].pv += (degats * (att[choixAttack].strengh/cib[choixCible].strengh));
          }else{
            printf("%s n'est pas assez fort pour bloquer l'attaque!", cib[choixCible].nom);
          }
          AttAnim(att[choixAttack].index, attacNum);
          break;

        case 3: // Contre-attaque si assez rapide
            if (cib[choixCible].counter > att[choixAttack].speedAtt) {
                printf("⚔️ %s contre-attaque avec %s !\n", cib[choixCible].nom, cib[choixCible].attaque1);
                cib[choixCible].pv += degats;
                att[choixAttack].pv -= cib[choixCible].damage1;
                AttAnim(att[choixAttack].index, attacNum);
                AttAnim(cib[choixCible].index, 1);
            } else {
                printf("❌ %s tente de contre-attaquer, mais échoue !\n", cib[choixCible].nom);
                AttAnim(att[choixAttack].index, attacNum);
            }
            break;

        case 4: // Ne rien faire
            printf("😐 %s ne fait rien et encaisse l'attaque.\n", cib[choixCible].nom);
            AttAnim(att[choixAttack].index, attacNum);
            break;

        default:
            printf("❌ Choix invalide. %s prend l'attaque en pleine face !\n", cib[choixCible].nom);
            AttAnim(att[choixAttack].index, attacNum);
            break;
    }
}


void AttaqueJ1(Stat j1[], Stat j2[], int *joueur1, int *joueur2, int c) {
    int choix, cible, attaque, defence;

    choix = rand() % 3;
    cible = rand() % 3;
    while (j2[cible].pv <= 0 || j1[choix].pv <= 0) {
      choix = rand() % 3;
      cible = rand() % 3;
    }

    effacerEcran();
    Affichage(j1, j2, c, choix, cible);

    printf("🔫 MENU D'ATTAQUE 🔫\n");
    printf("1 -> %s (%d dmg)\n", j1[choix].attaque1, j1[choix].damage1);
    printf("2 -> %s(%d) (%d dmg)\n", j1[choix].attaque2, j1[choix].attDelay2, j1[choix].damage2);
    printf("3 -> %s(%d) (%d dmg)\n", j1[choix].attaque3, j1[choix].attDelay3, j1[choix].spe);
    printf("4 -> Soin (+%d pv)\n", j1[choix].soin);
    int entreeValide = 0;

    do {
        printf("joueur1 (%s) attaque joueur2 (%s) avec : ", j1[choix].nom, j2[cible].nom);
    
        if (scanf("%d", &attaque) != 1) {
            printf("❌ Entrée invalide. Veuillez saisir un nombre entre 1 et 4.\n");
            while (getchar() != '\n'); // Vider le buffer
            continue;
        }
    
        if (attaque < 1 || attaque > 4) {
            printf("❌ Veuillez saisir un nombre entre 1 et 4.\n");
            continue;
        }
    
        if (attaque == 2 && j1[choix].attDelay2 > 0) {
            printf("❌ Vous ne pouvez pas encore utiliser %s (rechargement en cours).\n", j1[choix].attaque2);
            continue;
        }
    
        if (attaque == 3 && j1[choix].attDelay3 > 0) {
            printf("❌ Vous ne pouvez pas encore utiliser %s (rechargement en cours).\n", j1[choix].attaque3);
            continue;
        }
    
        // Si on arrive ici, l'entrée est valide
        entreeValide = 1;
    
    } while (!entreeValide);

    if(c == 1)
    {
      if(attaque != 4){
        printf("%s doit choisir une action défensive :\n", j2[cible].nom);
        printf("1. Esquiver\n");
        printf("2. Bloquer\n");
        printf("3. Contre-attaquer\n");
        printf("4. Ne rien faire\n");
        printf("Votre choix : ");
        scanf("%d", &defence);
      }
    }else{
      if(attaque != 4){
        defence = (rand() % 4) + 1;
        printf("\n");
      }
    }
    

    if (attaque == 1) {
        Esquive(j1, j2, defence, j1[choix].damage1, choix, cible, attaque);
        j2[cible].pv -= j1[choix].damage1;
    } else if (attaque == 2 && j1[choix].attDelay2 <= 0) {
        Esquive(j1, j2, defence, j1[choix].damage2, choix, cible, attaque);
        j2[cible].pv -= j1[choix].damage2;
        j1[choix].attDelay2 = 2;
    } else if (attaque == 3 && j1[choix].attDelay3 <= 0) {
        Esquive(j1, j2, defence, j1[choix].spe, choix, cible, attaque);
        j2[cible].pv -= j1[choix].spe;
        j1[choix].attDelay3 = 3;
    } else {
        j1[choix].pv += j1[choix].soin;
        if (j1[choix].pv > j1[choix].pv) j1[choix].pv = j1[choix].pv;
    }

    for(int i = 0; i < 3; i++){
      if(j2[i].attDelay2 > 0){
        j2[i].attDelay2--;
      }
      if(j2[i].attDelay3 > 0){
        j2[i].attDelay3--;
      }
    }

    if (j2[cible].pv <= 0) {
        j2[cible].pv = 0;
        (*joueur2)--;
        printf("💀 %s est K.O. ! Joueur 2 a %d personnages restants.\n", j2[cible].nom, *joueur2);
    }
    if (j1[choix].pv <= 0) {
        j1[choix].pv = 0;
        (*joueur1)--;
        printf("💀 %s est K.O. ! Joueur 2 a %d personnages restants.\n", j1[choix].nom, *joueur1);
    }
}

void AttaqueJ2(Stat j1[], Stat j2[], int *joueur1, int *joueur2, int c) {
    int choix, cible, attaque, defence;

    choix = rand() % 3;
    cible = rand() % 3;
    while (j1[cible].pv <= 0 || j2[choix].pv <= 0) {
      choix = rand() % 3;
      cible = rand() % 3;
    }

    effacerEcran();
    Affichage(j1, j2, c, cible, choix);

    printf("🔫 MENU D'ATTAQUE 🔫\n");
    printf("1 -> %s (%d dmg)\n", j2[choix].attaque1, j2[choix].damage1);
    printf("2 -> %s(%d) (%d dmg)\n", j2[choix].attaque2, j2[choix].attDelay2, j2[choix].damage2);
    printf("3 -> %s(%d) (%d dmg)\n", j2[choix].attaque3, j2[choix].attDelay3, j2[choix].spe);
    printf("4 -> Soin (+%d pv)\n", j2[choix].soin);
    int entreeValide = 0;

  do {
      printf("joueur2 (%s) attaque joueur1 (%s) avec : ", j2[choix].nom, j1[cible].nom);

      if (scanf("%d", &attaque) != 1) {
          printf("❌ Entrée invalide. Veuillez saisir un nombre entre 1 et 4.\n");
          while (getchar() != '\n'); // Vider le buffer
          continue;
      }

      if (attaque < 1 || attaque > 4) {
          printf("❌ Veuillez saisir un nombre entre 1 et 4.\n");
          continue;
      }

      if (attaque == 2 && j2[choix].attDelay2 > 0) {
          printf("❌ Vous ne pouvez pas encore utiliser %s (rechargement en cours).\n", j2[choix].attaque2);
          continue;
      }

      if (attaque == 3 && j2[choix].attDelay3 > 0) {
          printf("❌ Vous ne pouvez pas encore utiliser %s (rechargement en cours).\n", j2[choix].attaque3);
          continue;
      }

      // Si on arrive ici, l'entrée est valide
      entreeValide = 1;

  } while (!entreeValide);

    printf("%s doit choisir une action défensive :\n", j1[cible].nom);
    printf("1. Esquiver\n");
    printf("2. Bloquer\n");
    printf("3. Contre-attaquer\n");
    printf("4. Ne rien faire\n");
    printf("Votre choix : ");
    scanf("%d", &defence);


    if (attaque == 1) {
        Esquive(j2, j1, defence, j2[choix].damage1, choix, cible, attaque);
        j1[cible].pv -= j2[choix].damage1;
    } else if (attaque == 2 && j2[choix].attDelay2 <= 0) {
        Esquive(j2, j1, defence, j2[choix].damage2, choix, cible, attaque);
        j1[cible].pv -= j2[choix].damage2;
        j2[choix].attDelay2 = 2;
    } else if (attaque == 3 && j2[choix].attDelay3 <= 0) {
        Esquive(j2, j1, defence, j2[choix].spe, choix, cible, attaque);
        j1[cible].pv -= j2[choix].spe;
        j2[choix].attDelay3 = 3;
    } else {
        j2[choix].pv += j2[choix].soin;
        if (j2[choix].pv > j2[choix].pv) j2[choix].pv = j2[choix].pv;
    }

    for(int i = 0; i < 3; i++){
      if(j1[i].attDelay2 > 0){
        j1[i].attDelay2--;
      }
      if(j1[i].attDelay3 > 0){
        j1[i].attDelay3--;
      }
    }

    if (j1[cible].pv <= 0) {
        j1[cible].pv = 0;
        (*joueur1)--;
        printf("💀 %s est K.O. ! Joueur 1 a %d personnages restants.\n", j1[cible].nom, *joueur1);
    }
    if (j2[choix].pv <= 0) {
        j2[choix].pv = 0;
        (*joueur2)--;
        printf("💀 %s est K.O. ! Joueur 2 a %d personnages restants.\n", j2[choix].nom, *joueur2);
    }
}

void AttaqueBot(Stat j1[], Stat j2[], int *joueur1, int *joueur2, int c) {
    int choix, cible, attaque, defence;

    choix = rand() % 3;
    cible = rand() % 3;
    while (j1[cible].pv <= 0 || j2[choix].pv <= 0) {
      choix = rand() % 3;
      cible = rand() % 3;
    }

    effacerEcran();
    Affichage(j1, j2, c, cible, choix);

    printf("🔫 MENU D'ATTAQUE 🔫\n");
    printf("1 -> %s (%d dmg)\n", j2[choix].attaque1, j2[choix].damage1);
    printf("2 -> %s(%d) (%d dmg)\n", j2[choix].attaque2, j2[choix].attDelay2, j2[choix].damage2);
    printf("3 -> %s(%d) (%d dmg)\n", j2[choix].attaque3, j2[choix].attDelay3, j2[choix].spe);
    printf("4 -> Soin (+%d pv)\n", j2[choix].soin);
    int entreeValide = 0;

  do {
      attaque = (rand() % 4) + 1;

      if (attaque < 1 || attaque > 4) {
          continue;
      }

      if (attaque == 2 && j2[choix].attDelay2 > 0) {
          continue;
      }

      if (attaque == 3 && j2[choix].attDelay3 > 0) {
          continue;
      }

      // Si on arrive ici, l'entrée est valide
      entreeValide = 1;
      if(attaque == 1){
        printf("Bot (%s) attaque joueur1 (%s) avec : %s", j2[choix].nom, j1[cible].nom, j2[choix].attaque1);
        printf("\n");
      }else if(attaque == 2){
        printf("Bot (%s) attaque joueur1 (%s) avec : %s", j2[choix].nom, j1[cible].nom, j2[choix].attaque2);
        printf("\n");
      }else if(attaque == 3){
        printf("Bot (%s) attaque joueur1 (%s) avec : %s", j2[choix].nom, j1[cible].nom, j2[choix].attaque3);
        printf("\n");
      }else if(attaque == 4){
        printf("Bot (%s) se soigne", j2[choix].nom);
        printf("\n");
      }

  } while (!entreeValide);

    if(attaque != 4){
      printf("%s doit choisir une action défensive :\n", j1[cible].nom);
      printf("1. Esquiver\n");
      printf("2. Bloquer\n");
      printf("3. Contre-attaquer\n");
      printf("4. Ne rien faire\n");
      printf("Votre choix : ");
      scanf("%d", &defence);
    }

    if (attaque == 1) {
        Esquive(j2, j1, defence, j2[choix].damage1, choix, cible, attaque);
        j1[cible].pv -= j2[choix].damage1;
    } else if (attaque == 2 && j2[choix].attDelay2 <= 0) {
        Esquive(j2, j1, defence, j2[choix].damage2, choix, cible, attaque);
        j1[cible].pv -= j2[choix].damage2;
        j2[choix].attDelay2 = 2;
    } else if (attaque == 3 && j2[choix].attDelay3 <= 0) {
        Esquive(j2, j1, defence, j2[choix].spe, choix, cible, attaque);
        j1[cible].pv -= j2[choix].spe;
        j2[choix].attDelay3 = 3;
    } else {
        j2[choix].pv += j2[choix].soin;
        if (j2[choix].pv > j2[choix].pv) j2[choix].pv = j2[choix].pv;
    }

    for(int i = 0; i < 3; i++){
      if(j1[i].attDelay2 > 0){
        j1[i].attDelay2--;
      }
      if(j1[i].attDelay3 > 0){
        j1[i].attDelay3--;
      }
    }

    if (j1[cible].pv <= 0) {
        j1[cible].pv = 0;
        (*joueur1)--;
        printf("💀 %s est K.O. ! Joueur 1 a %d personnages restants.\n", j1[cible].nom, *joueur1);
    }
    if (j2[choix].pv <= 0) {
        j2[choix].pv = 0;
        (*joueur2)--;
        printf("💀 %s est K.O. ! Bot a %d personnages restants.\n", j2[choix].nom, *joueur2);
    }
}

void Combat(Stat j1[], Stat j2[], int *joueur1, int *joueur2, int c) {
    int startFirst = rand() % 11;

    while (*joueur1 > 0 && *joueur2 > 0) {
      if(c == 1)
      {
        if (startFirst % 2 == 0) {
            AttaqueJ1(j1, j2, joueur1, joueur2, c);
            if (*joueur2 <= 0) break;
            AttaqueJ2(j1, j2, joueur1, joueur2, c);
        } else {
            AttaqueJ2(j1, j2, joueur1, joueur2, c);
            if (*joueur1 <= 0) break;
            AttaqueJ1(j1, j2, joueur1, joueur2, c);
        }
      }
      else{
        if (startFirst % 2 == 0) {
            AttaqueJ1(j1, j2, joueur1, joueur2, c);
            if (*joueur2 <= 0) break;
            AttaqueBot(j1, j2, joueur1, joueur2, c);
        } else {
            AttaqueBot(j1, j2, joueur1, joueur2, c);
            if (*joueur1 <= 0) break;
            AttaqueJ1(j1, j2, joueur1, joueur2, c);
        }
      }
    }
    if(c == 1){
      if (*joueur1 <= 0) {
        printf("🎉 Joueur 2 a gagné 🏆\n");
      } else {
        printf("🎉 Joueur 1 a gagné 🏆\n");
      }
    }else{
      if (*joueur1 <= 0) {
        printf("🎉 Le Bot a gagné 🏆\n");
      } else {
        printf("🎉 Joueur 1 a gagné 🏆\n");
      }
    }
}

void Start(Stat j1[], Stat j2[], int c, int *joueur1, int *joueur2) {
  Combat(j1, j2, joueur1, joueur2, c);
}
void afficherBarreVie(int pv, int maxPV) {
  int barres = (pv * 20) / maxPV;
  printf("[");
  for (int i = 0; i < 20; i++) {
    if (i < barres) {
      if (barres > 14) printf("\033[32m█"); // vert
      else if (barres > 7) printf("\033[33m█"); // jaune
      else printf("\033[31m█"); // rouge
    } else {
      printf("\033[0m "); // vide
    }
  }
  printf("\033[0m] \033[1m(%d PV)\033[0m\n", pv);
}


int main(void) {
  srand(time(NULL));
  Stat joueurs[10]; // 4 personnages
  int joueur1 = 3, joueur2 = 3;
  Stat j1[3], j2[3];
  int choix;
  Intro();
  Init(joueurs);

  printf("1 -> Joueur 2      2 -> Bot\n");
  printf("Adversaire : ");
  scanf("%d", &choix);
  Liste(joueurs, 6);
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
  Start(j1, j2, choix, &joueur1, &joueur2);
  return 0;
}
