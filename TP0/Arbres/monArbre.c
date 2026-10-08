#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main() {
    noeud *arbre = NULL;
    int choix, num_parent;
    char val;

    printf("--- ARBRE BINAIRE ---\n");

    do {
        printf("\nMenu :\n");
        printf("1. Creer la racine\n");
        printf("2. Ajouter un fils gauche\n");
        printf("3. Ajouter un fils droit\n");
        printf("4. Afficher (parcours prefixe)\n");
        printf("5. Charger l'arbre du TD\n");
        printf("6. Quitter\n");
        printf("Votre choix : ");
        
        if(scanf("%d", &choix) != 1) {
            while(getchar() != '\n');
            continue;
        }

        switch(choix) {
            case 1:
                printf("Lettre de la racine : ");
                scanf(" %c", &val);
                arbre = nouvNoeud(val);
                printf("Racine creee (Numero %d).\n", arbre->num);
                break;
            case 2:
                printf("Numero du parent : ");
                scanf("%d", &num_parent);
                printf("Lettre du fils gauche : ");
                scanf(" %c", &val);
                insererFG(nouvNoeud(val), arbre, num_parent);
                break;
            case 3:
                printf("Numero du parent : ");
                scanf("%d", &num_parent);
                printf("Lettre du fils droit : ");
                scanf(" %c", &val);
                insererFD(nouvNoeud(val), arbre, num_parent);
                break;
            case 4:
                printf("Parcours prefixe : ");
                parcoursPrefixe(arbre);
                printf("\n");
                break;
            case 5:
                arbre = nouvNoeud('B'); 
                insererFG(nouvNoeud('A'), arbre, 1); 
                insererFD(nouvNoeud('O'), arbre, 1); 
                insererFG(nouvNoeud('R'), arbre, 1);
                insererFD(nouvNoeud('V'), arbre, 4);
                printf("Arbre d'exemple genere.\n");
                break;
            case 6:
                printf("Fin.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while (choix != 6);

    return 0;
}