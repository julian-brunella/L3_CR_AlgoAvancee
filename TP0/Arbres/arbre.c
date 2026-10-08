#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int numero_creation = 1;

noeud* nouvNoeud(char carac) {
    noeud *n = (noeud*)malloc(sizeof(noeud));
    if (n != NULL) {
        n->val = carac;
        n->num = numero_creation++;
        n->filsG = NULL;
        n->filsD = NULL;
    }
    return n;
}

noeud* rechercheNoeud(noeud *n, int num_noeud) {
    noeud *tmpNoeud;
    if(n == NULL) return NULL;
    if(n->num == num_noeud) return n;
    
    tmpNoeud = rechercheNoeud(n->filsG, num_noeud);
    if(tmpNoeud != NULL) return tmpNoeud;
    
    return rechercheNoeud(n->filsD, num_noeud);
}

void insererFG(noeud *a_inserer, noeud *arbre, int num_noeud) {
    noeud *cible = rechercheNoeud(arbre, num_noeud);
    if (cible != NULL && a_inserer != NULL) {
        if (cible->filsG != NULL) {
            a_inserer->filsG = cible->filsG;
        }
        cible->filsG = a_inserer;
    }
}

void insererFD(noeud *a_inserer, noeud *arbre, int num_noeud) {
    noeud *cible = rechercheNoeud(arbre, num_noeud);
    if (cible != NULL && a_inserer != NULL) {
        cible->filsD = a_inserer;
    }
}

void parcoursPrefixe(noeud *n) {
    if (n != NULL) {
        printf("%c ", n->val);       
        parcoursPrefixe(n->filsG);   
        parcoursPrefixe(n->filsD);   
    }
}