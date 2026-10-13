=============================================================================
                      TP3 - ALGORITHMIQUE AVANCEE
=============================================================================

Ce repertoire contient les codes sources du TP3, séparé en deux dossiers 
correspondant aux deux questions abordées.


-----------------------------------------------------------------------------
ARCHITECTURE DU PROJET
-----------------------------------------------------------------------------
TP3/
 |-- Question1/       # Arbres N-aires et Graphes par listes d'adjacence
 |-- Question2/       # Algo de Welsh-Powell avec matrice linearisee
 |-- consignes.pdf/   # Le sujet du TP3
 |-- README.txt       # Ce fichier


-----------------------------------------------------------------------------
QUESTION 1 : Optimisation des structures de données
-----------------------------------------------------------------------------
Objectif : 
Faire evoluer les structures du TP0 pour optimiser la complexite spatiale.
- Arbre N-aire : Implemenation du modele "Premier-Fils / Frere-Droit" pour 
  garantir une empreinte mémoire fixe par noeud (2 pointeurs).
- Graphe : Remplacement de la matrice par un tableau de listes d'adjacence 
  pour resoudre le probleme des matrices creuses (complexite O(V + E)).

Compilation :
Se placer dans le dossier Question1/ :
> cd Question1
> gcc main_q1.c -o main_q1

Execution :
> ./main_q1      (sous Linux/Mac)
> .\main_q1.exe  (sous Windows)


-----------------------------------------------------------------------------
QUESTION 2 : Linearisation de la matrice (Welsh-Powell)
-----------------------------------------------------------------------------
Objectif :
Adapter l'algorithme de coloration Welsh-Powell (TP2) pour qu'il fonctionne 
avec une matrice d'adjacence linearisée (tableau 1D int *A au lieu de int **A).
L'acces aux données se fait par une formule mathématique (i * V + j) afin de 
maximiser la localité spatiale et de limiter les défauts de cache processeur.

Le programme charge le graphe depuis le fichier texte, exécute la coloration, 
et exporte le résultat au format DOT.

Compilation :
Se placer dans le dossier Question2/ :
> cd ../Question2
> gcc main_welsh_linearise.c -o main_welsh_linearise

Execution :
> ./main_welsh_linearise      (sous Linux/Mac)
> .\main_welsh_linearise.exe  (sous Windows)

Génération du rendu visuel (Graphviz requis) :
Une fois le programme execute, un fichier .dot est généré. 
Pour créer l'image PNG correspondante, utiliser la commande :
> dot -Tpng graphe_europe_linearise.dot -o graphe_europe.png

=============================================================================
