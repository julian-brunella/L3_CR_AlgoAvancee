typedef struct noeud_naire {
    void *valeur; // Contenu du noeud (void* pour que ce soit generique)
    struct noeud_naire *premier_fils; // Pointeur vers le premier enfant
    struct noeud_naire *frere_droit;  // Pointeur vers le frere suivant (meme parent)
} noeud_naire;