========================================================================
ALGORITHMIQUE AVANCÉE - TP1 : Représentation par matrice d'adjacences
BRUNELLA Julian - N°22403298 - L3 Informatique
========================================================================



ARCHITECTURE DU DOSSIER
------------------------------------------------------------------------
/Code      : Contient les sources C (graph0 original, version corrigée, 
             et programme de test main.c).
/Resultats : Contient les exports générés par le programme (fichiers .dot 
             et images .png).



COMPILATION ET EXÉCUTION
------------------------------------------------------------------------
Placez-vous dans le sous-dossier "Code" et compilez avec GCC :

    cd Code
    gcc main.c graph0corrige.c -o test_welsh_powell
    ./test_welsh_powell

Le programme générera automatiquement les fichiers au format DOT dans 
le dossier "Resultats".



GÉNÉRATION DES IMAGES (GRAPHVIZ)
------------------------------------------------------------------------
Pour générer les images PNG depuis les fichiers DOT, placez-vous dans 
le dossier "Resultats" et utilisez Graphviz :

    cd ../Resultats
    dot -Tpng graphe_maison.dot -o graphe_maison.png
    dot -Tpng graphe_piege.dot -o graphe_piege.png

========================================================================