#ifndef GRAPH_LINEARISE_H
#define GRAPH_LINEARISE_H

#include <stdio.h>
#include <stdlib.h>

// Structure modifiée : on passe de int **A à int *A
typedef struct Graph {
    int n;          // Nombre de sommets (V)
    int *A;         // Matrice d'adjacence LINEARISEE (taille V*V)
    int *colors;    // Couleurs attribuées      
    int *degrees;   // Degré de chaque sommet         
} Graph;

Graph *createGraph(int n);
Graph *loadGraphFromFile(const char *filename);
int neighborUsingColor(Graph *g, int vertex, int color);
void computeDegrees(Graph *g);
void welshPowell(Graph *g);
void displayAdjacency(Graph *g);
void displayDegres(Graph *g);
void displayColoring(Graph *g);
void dotExport(Graph *g, const char *fileName);
void freeGraph(Graph *g);

#endif