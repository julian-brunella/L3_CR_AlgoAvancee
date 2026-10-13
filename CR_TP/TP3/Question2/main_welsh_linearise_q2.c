#include <stdio.h>
#include <stdlib.h>
#include "graphe_linearise_q2.c" 

int main() {
    // Remonte les dossiers selon l'architecture de ton projet
    Graph *g = loadGraphFromFile("../../TP2/Matrice/pays_europe.txt");
    
    if (g != NULL) {
        displayAdjacency(g);
        
        printf("--- Lancement de Welsh-Powell ---\n");
        welshPowell(g);
        
        displayDegres(g);
        displayColoring(g);
        
        dotExport(g, "graphe_europe_linearise.dot");
        printf("Export DOT reussi.\n");
        
        freeGraph(g);
    } else {
        printf("Erreur : Fichier introuvable.\n");
    }

    return 0;
}