#include <stdio.h>
#include <stdlib.h>
#include "liste.h"

cellule* NouvCel(point p) {
    cellule *cel = (cellule*)malloc(sizeof(cellule));
    if (cel != NULL) {
        cel->p = p;
        cel->prec = NULL;
        cel->suiv = NULL;
    }
    return cel;
}

void InsererCellule(int pl, cellule *cel, cellule *liste) {
    if (liste == NULL || cel == NULL) return;
    
    cellule *courant = liste;
    int pos = 1;
    
    // On avance jusqu'a la position voulue
    while (courant->suiv != NULL && pos < pl) {
        courant = courant->suiv;
        pos++;
    }
    
    // Insertion de la nouvelle cellule
    cel->suiv = courant->suiv;
    cel->prec = courant;
    
    if (courant->suiv != NULL) {
        courant->suiv->prec = cel;
    }
    courant->suiv = cel;
}

void SupprimeCellule(int pl, cellule *liste) {
    if (liste == NULL) return;
    
    cellule *courant = liste;
    int pos = 1;
    
    while (courant != NULL && pos < pl) {
        courant = courant->suiv;
        pos++;
    }
    
    if (courant == NULL) return; 
    
    // Raccordement des pointeurs pour exclure la cellule
    if (courant->prec != NULL) courant->prec->suiv = courant->suiv;
    if (courant->suiv != NULL) courant->suiv->prec = courant->prec;
    
    free(courant);
}

void Afficher(cellule *liste) {
    cellule *courant = liste;
    while (courant != NULL) {
        printf("Point(%d, %d) ", courant->p.x, courant->p.y);
        courant = courant->suiv;
    }
    printf("\n");
}