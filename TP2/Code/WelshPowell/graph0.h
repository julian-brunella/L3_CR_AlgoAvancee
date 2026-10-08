#ifndef GRAPH_H
#define GRAPH_H

#include <stdio.h>
#include <stdlib.h>

// Graph structure 
struct Graph {
    int n;          // number of vertices
    int **A;        // adjacency matrix
    int *colors;    // vertices colors      
    int *degrees;   // vertices degrees         
};

typedef struct Graph Graph;

Graph *createGraph(int n) ;
// Check whether a neighbor is using a color  
int neighborUsingColor(Graph *g, int vertex, int color) ;
// Welsh-Powell Algorithm
void welshPowell(Graph *g) ;
// Display adjacency matrix
void displayAdjacency(Graph *g) ;
// display degrees
void displayDegres(Graph *g) ;
void displayColoring(Graph *g) ;
// Export the graph with DOT format with colors
void dotExport(Graph *g, const char *fileName) ;
// Free graph memory
void freeGraph(Graph *g) ;
#endif