#include <stdio.h>
#include <stdlib.h>
#include "liste.h" 

int main() {
    cellule *liste = NULL;
    int choix, x, y, pos;

    printf("--- MANIPULATION DE FORME POLYGONALE ---\n");

    do {
        printf("\nMenu :\n");
        printf("1. Ajouter un point\n");
        printf("2. Supprimer un point\n");
        printf("3. Afficher le polygone\n");
        printf("4. Charger l'exemple du TD\n");
        printf("5. Quitter\n");
        printf("Votre choix : ");
        
        if(scanf("%d", &choix) != 1) {
            while(getchar() != '\n');
            continue;
        }

        switch(choix) {
            case 1:
                printf("Coordonnees x et y (ex: 10 20) : ");
                scanf("%d %d", &x, &y);
                printf("Position d'insertion (1 pour le debut) : ");
                scanf("%d", &pos);
                point p = {x, y};
                if (liste == NULL && pos == 1) {
                    liste = NouvCel(p);
                } else {
                    InsererCellule(pos, NouvCel(p), liste);
                }
                printf("Point ajoute !\n");
                break;
            case 2:
                printf("Position du point a supprimer : ");
                scanf("%d", &pos);
                SupprimeCellule(pos, liste);
                printf("Point supprime.\n");
                break;
            case 3:
                printf("Points actuels : \n");
                Afficher(liste);
                break;
            case 4:
                liste = NouvCel((point){0, 0});
                InsererCellule(1, NouvCel((point){10, 0}), liste);
                InsererCellule(2, NouvCel((point){10, 10}), liste);
                printf("Exemple charge.\n");
                break;
            case 5:
                printf("Fin.\n");
                break;
            default:
                printf("Choix invalide.\n");
        }
    } while(choix != 5);

    return 0;
}