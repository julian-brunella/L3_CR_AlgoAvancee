#include <stdio.h>
#include <stdlib.h>
#include "graph0complete.c" 

int main() {
    printf("===================================================\n");
    printf("--- CAS : L'Europe (TD0) ---\n");
    printf("===================================================\n");

    // Chargement depuis le fichier dans Matrice/
    Graph *g = loadGraphFromFile("../../Matrice/pays_europe.txt");
    
    if (g != NULL) {
        displayAdjacency(g);
        welshPowell(g);
        displayColoring(g);
        
        // Export vers le dossier Resultats
        dotExport(g, "../../Resultats/graphe_europe.dot");
        
        // Affichage de la commande parfaite à copier-coller dans le terminal
        printf(">>> POUR CREER LE PNG DIRECTEMENT DANS LE DOSSIER 'Resultats', TAPEZ :\n");
        printf("dot -Tpng ../../Resultats/graphe_europe.dot -o ../../Resultats/graphe_europe.png\n\n");
        
        freeGraph(g);
    }

    return 0;
}