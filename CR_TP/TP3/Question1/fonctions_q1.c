#include <stdio.h>
#include <stdlib.h>
#include "structures_q1.h"

// ==========================================
// ARBRES N-AIRES
// ==========================================

NoeudArbre* creerNoeudArbre(char *nom) {
    NoeudArbre *nouveau = (NoeudArbre*)malloc(sizeof(NoeudArbre));
    if (nouveau) {
        nouveau->nom = nom;
        nouveau->premier_fils = NULL;
        nouveau->frere_droit = NULL;
    }
    return nouveau;
}

void ajouterFils(NoeudArbre *parent, NoeudArbre *fils) {
    if (parent == NULL || fils == NULL){
        return;
    }
    
    if (parent->premier_fils == NULL) {
        parent->premier_fils = fils;
    } else {
        // Parcours des frères pour insertion en fin de fratrie
        NoeudArbre *courant = parent->premier_fils;
        while (courant->frere_droit != NULL) {
            courant = courant->frere_droit;
        }
        courant->frere_droit = fils;
    }
}

void afficherArbre(NoeudArbre *racine, int niveau) {
    if (racine == NULL){
        return;
    }
    
    for (int i = 0; i < niveau; i++) printf("  ");
    printf("|- %s\n", racine->nom);
    
    afficherArbre(racine->premier_fils, niveau + 1);
    afficherArbre(racine->frere_droit, niveau);
}

void libererArbre(NoeudArbre *racine) {
    if (racine == NULL){
        return;
    }

    libererArbre(racine->premier_fils);
    libererArbre(racine->frere_droit);
    free(racine);
}


// ==========================================
// GRAPHES (LISTES D'ADJACENCE)
// ==========================================

GrapheListes* creerGraphe(int nb_sommets) {
    GrapheListes *g = (GrapheListes*)malloc(sizeof(GrapheListes));
    g->nb_sommets = nb_sommets;
    g->tableau_sommets = (Sommet*)malloc(nb_sommets * sizeof(Sommet));
    
    for (int i = 0; i < nb_sommets; i++) {
        g->tableau_sommets[i].nom = "Inconnu";
        g->tableau_sommets[i].liste_voisins = NULL;
    }
    return g;
}

void definirNomSommet(GrapheListes *g, int id, char *nom) {
    if (g && id >= 0 && id < g->nb_sommets) {
        g->tableau_sommets[id].nom = nom;
    }
}

void ajouterArete(GrapheListes *g, int src, int dest) {
    if (!g) {
        return;
    }

    // Insertion en tête de liste pour src -> dest (Complexité O(1))
    MaillonVoisin *n1 = (MaillonVoisin*)malloc(sizeof(MaillonVoisin));
    n1->id_voisin = dest;
    n1->suivant = g->tableau_sommets[src].liste_voisins;
    g->tableau_sommets[src].liste_voisins = n1;
    
    // Graphe non orienté : insertion pour dest -> src
    MaillonVoisin *n2 = (MaillonVoisin*)malloc(sizeof(MaillonVoisin));
    n2->id_voisin = src;
    n2->suivant = g->tableau_sommets[dest].liste_voisins;
    g->tableau_sommets[dest].liste_voisins = n2;
}

void afficherGraphe(GrapheListes *g) {
    if (!g) {
        return;
    }

    for (int i = 0; i < g->nb_sommets; i++) {
        printf("[%s] -> ", g->tableau_sommets[i].nom);
        MaillonVoisin *courant = g->tableau_sommets[i].liste_voisins;
        while (courant != NULL) {
            printf("%s ", g->tableau_sommets[courant->id_voisin].nom);
            courant = courant->suivant;
        }
        printf("\n");
    }
}

void libererGraphe(GrapheListes *g) {
    if (g == NULL) {
        return;
    }

    // Libération de tous les maillons pour chaque sommet
    for (int i = 0; i < g->nb_sommets; i++) {
        MaillonVoisin *courant = g->tableau_sommets[i].liste_voisins;
        while (courant != NULL) {
            MaillonVoisin *tmp = courant;
            courant = courant->suivant;
            free(tmp);
        }
    }
    free(g->tableau_sommets);
    free(g);
}