#ifndef STRUCTURES_Q1_H
#define STRUCTURES_Q1_H


// --- Arbre N-aire (Modèle Premier-Fils / Frère-Droit) ---
typedef struct NoeudArbre {
    char *nom;
    struct NoeudArbre *premier_fils; 
    struct NoeudArbre *frere_droit;  
} NoeudArbre;


// --- Graphe (Listes d'adjacence) ---
typedef struct MaillonVoisin {
    int id_voisin;
    struct MaillonVoisin *suivant;
} MaillonVoisin;

typedef struct Sommet {
    char *nom;
    MaillonVoisin *liste_voisins;
} Sommet;

typedef struct GrapheListes {
    int nb_sommets;
    Sommet *tableau_sommets;
} GrapheListes;


// Prototypes Arbres
NoeudArbre* creerNoeudArbre(char *nom);
void ajouterFils(NoeudArbre *parent, NoeudArbre *fils);
void afficherArbre(NoeudArbre *racine, int niveau);
void libererArbre(NoeudArbre *racine);


// Prototypes Graphes
GrapheListes* creerGraphe(int nb_sommets);
void definirNomSommet(GrapheListes *g, int id, char *nom);
void ajouterArete(GrapheListes *g, int src, int dest);
void afficherGraphe(GrapheListes *g);
void libererGraphe(GrapheListes *g);

#endif