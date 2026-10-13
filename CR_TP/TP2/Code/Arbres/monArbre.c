#include <stdio.h>
#include <stdlib.h>
#include "arbre.h"

int main() {
    printf("--- CONSTRUCTION ET PARCOURS DE L'ARBRE 22403298 ---\n\n");

    // Racine : A
    noeud *arbre = nouvNoeud('A');
    
    // Niveau 1 : B et C
    insererFG(nouvNoeud('B'), arbre, 1); // 1 est le num de A
    insererFD(nouvNoeud('C'), arbre, 1);
    
    // Niveau 2 : Sous B (fantôme à gauche, D à droite)
    // Pas besoin d'insérer le fantôme. Le noeud D aura le num 4.
    insererFD(nouvNoeud('D'), arbre, 2); // 2 est le num de B
    
    // Niveau 2 : Sous C (E à gauche, F à droite)
    insererFG(nouvNoeud('E'), arbre, 3); // 3 est le num de C
    insererFD(nouvNoeud('F'), arbre, 3);
    
    // Niveau 3 : Sous D (G à gauche, H à droite)
    insererFG(nouvNoeud('G'), arbre, 4); // 4 est le num de D
    insererFD(nouvNoeud('H'), arbre, 4);

    // Niveau 3 : Sous E (fantôme à gauche, I à droite)
    insererFD(nouvNoeud('I'), arbre, 5); // 5 est le num de E

    // Niveau 3 : Sous F (fantôme à gauche, J à droite)
    insererFD(nouvNoeud('J'), arbre, 6); // 6 est le num de F

    // --- Affichages ---
    printf("Parcours Prefixe (A l'arrivee au noeud) :\n");
    parcoursPrefixe(arbre);
    printf("\n\n");

    printf("Parcours Infixe (A la moitie du noeud) :\n");
    parcoursInfixe(arbre);
    printf("\n\n");

    printf("Parcours Post-fixe (A la sortie du noeud) :\n");
    parcoursPostfixe(arbre);
    printf("\n\n");

    return 0;
}