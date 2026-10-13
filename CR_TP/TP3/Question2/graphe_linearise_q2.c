#include "graphe_linearise_q2.h"

// Optimisation de l'allocaztion
Graph *createGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;

    // Allocation d'un seul bloc contigu de taille n*n
    g->A = (int *)calloc(n * n, sizeof(int));
    
    g->colors = (int *)malloc(n * sizeof(int));
    g->degrees = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        g->colors[i] = -1;
        g->degrees[i] = 0;
    }
    
    return g;
}

// Utilisation de la formule (i * V) + j pour accéder à l'élément (i, j) dans la matrice d'adjacence linéarisée.
Graph *loadGraphFromFile(const char *filename) {
    FILE *f = fopen(filename, "r");
    if (!f) return NULL;

    int n;
    if (fscanf(f, "%d", &n) != 1) {
        fclose(f);
        return NULL;
    }

    Graph *g = createGraph(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            // Remplacement de g->A[i][j] par la formule linéarisée
            fscanf(f, "%d", &g->A[i * n + j]);
        }
    }

    fclose(f);
    return g;
}

int neighborUsingColor(Graph *g, int vertex, int color) {
    for (int i = 0; i < g->n; i++) {
        // Remplacement de g->A[vertex][i]
        if (g->A[vertex * g->n + i] == 1 && g->colors[i] == color) {
            return 1;
        }
    }
    return 0;
}

void computeDegrees(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        g->degrees[i] = 0;
        for (int j = 0; j < g->n; j++) {
            if (g->A[i * g->n + j] == 1) {
                g->degrees[i]++;
            }
        }
    }
}

// L'algorithme de Welsh-Powell en lui-même ne change pas, car il s'appuie sur computeDegrees() et neighborUsingColor().
void welshPowell(Graph *g) {
    computeDegrees(g); 
    
    int *verticesOrder = (int *)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) verticesOrder[i] = i;
    
    // Tri par degré décroissant
    for (int i = 0; i < g->n - 1; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->degrees[verticesOrder[i]] < g->degrees[verticesOrder[j]]) {
                int temp = verticesOrder[i];
                verticesOrder[i] = verticesOrder[j];
                verticesOrder[j] = temp;
            }
        }
    }
    
    int c = 0; 
    for (int i = 0; i < g->n; i++) {
        int u = verticesOrder[i]; 
        
        if (g->colors[u] == -1) {
            g->colors[u] = c;
            for (int j = i + 1; j < g->n; j++) {
                int v = verticesOrder[j];
                if (!neighborUsingColor(g, v, c) && g->colors[v] == -1) {
                    g->colors[v] = c;
                }
            }
            c++;
        }
    }
    free(verticesOrder);
}

void displayAdjacency(Graph *g) {
    printf("Matrice d'adjacence linearisee :\n   ");
    for (int i = 0; i < g->n; i++) printf("%d ", i);
    printf("\n");
    
    for (int i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->A[i * g->n + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayDegres(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        printf("Sommet %d: degre=%d\n", i, g->degrees[i]);
    }
    printf("\n");
}

void displayColoring(Graph *g) {
    int nbColors = 0;
    for (int i = 0; i < g->n; i++) {
        if (g->colors[i] >= nbColors) nbColors = g->colors[i] + 1;
    }
    printf("Coloration realisee avec %d couleurs.\n", nbColors);
}

void dotExport(Graph *g, const char *fileName) {
    FILE *f = fopen(fileName, "w");
    if (!f) return;
    
    fprintf(f, "graph G {\n    node [style=filled];\n");
    const char *colorsPalette[] = {"red", "blue", "green", "yellow", "pink", "cyan", "violet"};
    
    for (int i = 0; i < g->n; i++) {
        fprintf(f, "    %d [fillcolor=%s, label=\"%d\\n(c%d)\"];\n", 
                i, colorsPalette[g->colors[i] % 7], i, g->colors[i]);
    }
    
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            // Lecture linéarisée pour exporter les arêtes
            if (g->A[i * g->n + j] == 1) {
                fprintf(f, "    %d -- %d;\n", i, j);
            }
        }
    }
    fprintf(f, "}\n");
    fclose(f);
}

// Optimisation de la libération de mémoire : on libère les blocs contigus d'un seul coup.
void freeGraph(Graph *g) {
    // Fini la boucle, on libère le bloc d'un seul coup !
    free(g->A);
    free(g->colors);
    free(g->degrees);
    free(g);
}