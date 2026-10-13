#ifndef ARBRE_H
#define ARBRE_H

typedef struct noeud {
    char val;
    int num;
    struct noeud *filsG;
    struct noeud *filsD;
} noeud;

extern int numero_creation; 

noeud* nouvNoeud(char carac);
noeud* rechercheNoeud(noeud *n, int num_noeud);
void insererFG(noeud *a_inserer, noeud *arbre, int num_noeud);
void insererFD(noeud *a_inserer, noeud *arbre, int num_noeud);
void parcoursPrefixe(noeud *n);

#endif