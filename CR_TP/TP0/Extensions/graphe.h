// Maillon generique pour la liste doublement chainee des voisins
typedef struct maillon {
    struct maillon *prec; 
    struct maillon *suiv; 
    void *sommet_cible; // Pointeur vers le sommet voisin
} maillon;

// Representation d'un sommet
typedef struct sommet {
    int id;
    void *valeur;     // Contenu du sommet
    maillon *voisins; // Tete de la liste des sommets adjacents
} sommet;

// Structure globale du graphe
typedef struct graphe {
    int nb_sommets;
    sommet *tableau_sommets; // Tableau contenant tous les sommets
} graphe;