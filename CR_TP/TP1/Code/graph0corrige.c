#include "graph0.h"

// Create a graph with n vertices
Graph *createGraph(int n) {
    Graph *g = (Graph *)malloc(sizeof(Graph));
    g->n = n;

    g->A = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        g->A[i] = (int *)calloc(n, sizeof(int));
    }
    
    g->colors = (int *)malloc(n * sizeof(int));
    g->degrees = (int *)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        g->colors[i] = -1;
        g->degrees[i] = 0;
    }
    
    return g;
}

// Check whether a neighbor is using a color  
int neighborUsingColor(Graph *g, int vertex, int color) {
    for (int i = 0; i < g->n; i++) {
        if (g->A[vertex][i] == 1 && g->colors[i] == color) {
            return 1;
        }
    }
    return 0;
}

// Helper to compute all vertices degrees (Added to complete the algorithm)
void computeDegrees(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        g->degrees[i] = 0;
        for (int j = 0; j < g->n; j++) {
            if (g->A[i][j] == 1) {
                g->degrees[i]++;
            }
        }
    }
}

// Welsh-Powell Algorithm
void welshPowell(Graph *g) {
    computeDegrees(g); // 1. Compute degrees
    
    int *verticesOrder = (int *)malloc(g->n * sizeof(int));
    for (int i = 0; i < g->n; i++) {
        verticesOrder[i] = i;
    }
    
    // 2. Sort vertices by decreasing degree 
    for (int i = 0; i < g->n - 1; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->degrees[verticesOrder[i]] < g->degrees[verticesOrder[j]]) {
                int temp = verticesOrder[i];
                verticesOrder[i] = verticesOrder[j];
                verticesOrder[j] = temp;
            }
        }
    }
    
    int c = 0; // color ID 
    
    // 3. Coloration process
    for (int i = 0; i < g->n; i++) {
        int u = verticesOrder[i]; 
        
        if (g->colors[u] == -1) {
            g->colors[u] = c;
            printf("Vertex %d: color %d\n", u, c);
            
            for (int j = i + 1; j < g->n; j++) {
                int v = verticesOrder[j];
                
                // Fixed syntax: ensure vertex is uncolored AND neighbors don't use color c
                if  (!neighborUsingColor(g, v, c) && g->colors[v] == -1) {
                    g->colors[v] = c;
                    printf("Vertex %d: color %d\n", v, c);
                }
            }
            
            c++;
            printf("\n");
        }
    }
    
    free(verticesOrder);
}

// Display adjacency matrix
void displayAdjacency(Graph *g) {
    printf("adjacency matrix:\n");
    printf("   ");
    for (int i = 0; i < g->n; i++) {
        printf("%d ", i);
    }
    printf("\n");
    
    for (int i = 0; i < g->n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < g->n; j++) {
            printf("%d ", g->A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

// display degrees
void displayDegres(Graph *g) {
    printf("Vertices degrees:\n");
    for (int i = 0; i < g->n; i++) {
        printf("Vertex %d: degree=%d\n", i, g->degrees[i]);
    }
    printf("\n");
}

void displayColoring(Graph *g) {
    printf("Coloring:\n");
    
    int nbColors = 0;
    for (int i = 0; i < g->n; i++) {
        if (g->colors[i] >= nbColors) {
            nbColors = g->colors[i] + 1;
        }
    }
    
    printf("Number of colors: %d\n\n", nbColors);
    
    for (int c = 0; c < nbColors; c++) {
        printf("Color %d: ", c);
        for (int i = 0; i < g->n; i++) {
            if (g->colors[i] == c) {
                printf("%d ", i);
            }
        }
        printf("\n");
    }
}

// Export the graph with DOT format with colors
void dotExport(Graph *g, const char *fileName) {
    FILE *f = fopen(fileName, "w");
    if (!f) {
        perror("Error creating dot file");
        return;
    }
    
    fprintf(f, "graph G {\n");
    fprintf(f, "    node [style=filled];\n");
    
    const char *colorsPalette[] = {
        "red", "blue", "green", "yellow", 
        "pink", "cyan", "violet", "gold", "coral", "lime"
    };
    int nbColorsPalette = 10;
    
    for (int i = 0; i < g->n; i++) {
        int c = g->colors[i];
        const char *htmlColor = colorsPalette[c % nbColorsPalette];
        fprintf(f, "    %d [fillcolor=%s, label=\"%d\\n(c%d)\"];\n", 
                i, htmlColor, i, c);
    }
    
    // Define edges 
    for (int i = 0; i < g->n; i++) {
        for (int j = i + 1; j < g->n; j++) {
            if (g->A[i][j] == 1) {
                fprintf(f, "    %d -- %d;\n", i, j);
            }
        }
    }
    
    fprintf(f, "}\n");
    fclose(f);
    printf("\n==> DOT file written: %s\n", fileName);
    printf("    Visualize: dot -Tpng %s -o graph.png\n\n", fileName);
}

// Free graph memory
void freeGraph(Graph *g) {
    for (int i = 0; i < g->n; i++) {
        free(g->A[i]);
    }
    free(g->A);
    free(g->colors);
    free(g->degrees);
    free(g);
}