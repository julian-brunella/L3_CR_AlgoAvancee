#ifndef LISTE_H
#define LISTE_H

// Coordonnees d'un point pour la forme polygonale
typedef struct {
    int x;
    int y;
} point;

// Maillon de la liste doublement chainee
typedef struct cellule {
    point p;
    struct cellule *prec;
    struct cellule *suiv;
} cellule;

cellule* NouvCel(point p);
void InsererCellule(int pl, cellule *cel, cellule *liste);
void SupprimeCellule(int pl, cellule *liste);
void Afficher(cellule *liste);

#endif