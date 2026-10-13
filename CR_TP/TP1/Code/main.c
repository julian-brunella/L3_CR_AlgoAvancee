#include <stdio.h>
#include <stdlib.h>
#include "graph0corrige.c"

// Helper pour creer une arete non-orientee
void addEdge(Graph *g, int u, int v) {
    g->A[u][v] = 1;
    g->A[v][u] = 1;
}

// CAS 1: Un graphe où Welsh-Powell trouve le nombre chromatique exact
void testOptimal() {
    printf("=================================================\n");
    printf("--- CAS 1 : Graphe optimal (Le Graphe Maison) ---\n");
    printf("=================================================\n");
    
    // Un graphe à 5 sommets en forme de maison (carré + toit)
    // Nombre chromatique théorique : 3 (à cause du triangle du toit)
    Graph *g = createGraph(5);
    addEdge(g, 0, 1);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);
    addEdge(g, 3, 0); // Le carré
    addEdge(g, 0, 4);
    addEdge(g, 1, 4); // Le toit

    displayAdjacency(g);
    welshPowell(g);
    displayDegres(g);
    displayColoring(g);
    
    dotExport(g, "graphe_maison.dot");
    freeGraph(g);
}

// CAS 2: Un graphe où Welsh-Powell échoue à trouver l'optimum
void testSuboptimal() {
    printf("===================================================\n");
    printf("--- CAS 2 : Graphe sous-optimal (Biparti Piege) ---\n");
    printf("===================================================\n");
    
    // Graphe biparti à 8 sommets.
    // Etant biparti, son nombre chromatique théorique est de 2 !
    // Mais l'ordre des degrés va forcer Welsh-Powell à utiliser 3 couleurs.
    Graph *g = createGraph(8);
    addEdge(g, 0, 3);
    addEdge(g, 0, 5);
    addEdge(g, 0, 7); // Sommet 0 a un degré de 3
    addEdge(g, 1, 2);
    addEdge(g, 1, 4);
    addEdge(g, 1, 6); // Sommet 1 a un degré de 3
    
    addEdge(g, 2, 3);
    addEdge(g, 4, 5);
    addEdge(g, 6, 7); // Tous les autres ont un degré de 2

    displayAdjacency(g);
    welshPowell(g);
    displayDegres(g);
    displayColoring(g);
    
    dotExport(g, "graphe_piege.dot");
    freeGraph(g);
}

int main() {
    testOptimal();
    testSuboptimal();
    return 0;
}