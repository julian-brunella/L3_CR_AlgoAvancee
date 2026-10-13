#include <stdio.h>
#include <stdlib.h>
#include "fonctions_q1.c" 

int main() {
    // --- TEST DE L'ARBRE N-AIRE ---
    printf("--- ARBRE N-AIRE ---\n");
    NoeudArbre *racine = creerNoeudArbre("Dossier_Racine");
    NoeudArbre *f1 = creerNoeudArbre("Dossier_Images");
    NoeudArbre *f2 = creerNoeudArbre("Dossier_Documents");
    NoeudArbre *f3 = creerNoeudArbre("Dossier_Telechargements");
    
    ajouterFils(racine, f1);
    ajouterFils(racine, f2);
    ajouterFils(racine, f3);
    
    NoeudArbre *sous_f1 = creerNoeudArbre("Vacances.png");
    ajouterFils(f1, sous_f1);
    
    afficherArbre(racine, 0);
    libererArbre(racine);


    // --- TEST DU GRAPHE PAR LISTES D'ADJACENCE ---
    printf("\n--- GRAPHE (CARTE DE L'EUROPE) ---\n");
    GrapheListes *europe = creerGraphe(11);
    
    definirNomSommet(europe, 0, "France");
    definirNomSommet(europe, 1, "Espagne");
    definirNomSommet(europe, 2, "Portugal");
    definirNomSommet(europe, 3, "Andorre");
    definirNomSommet(europe, 4, "Italie");
    definirNomSommet(europe, 5, "Autriche");
    definirNomSommet(europe, 6, "Suisse");
    definirNomSommet(europe, 7, "Allemagne");
    definirNomSommet(europe, 8, "Luxembourg");
    definirNomSommet(europe, 9, "Belgique");
    definirNomSommet(europe, 10, "Pays-Bas");
    
    ajouterArete(europe, 0, 1); // France - Espagne
    ajouterArete(europe, 0, 4); // France - Italie
    ajouterArete(europe, 0, 6); // France - Suisse
    ajouterArete(europe, 0, 7); // France - Allemagne
    ajouterArete(europe, 1, 2); // Espagne - Portugal
    ajouterArete(europe, 4, 6); // Italie - Suisse
    ajouterArete(europe, 7, 9); // Allemagne - Belgique
    
    afficherGraphe(europe);
    libererGraphe(europe);
    
    return 0;
}