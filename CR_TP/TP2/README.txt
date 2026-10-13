========================================================================
ALGORITHMIQUE AVANCÉE - TP2
Suite de Welsh-Powell & Parcours d'Arbres Binaires
BRUNELLA Julian - N°22403298 - L3 Informatique
========================================================================


ARCHITECTURE DU DOSSIER
------------------------------------------------------------------------
/Code
   /Arbres       : Implémentation des parcours d'arbres binaires
                   (arbre.h, arbre.c) et construction de l'arbre 
                   étudiant (monArbre.c).
   /WelshPowell  : Implémentation améliorée de Welsh-Powell avec lecture
                   depuis un fichier (graph0.h, graph0complete.c) et 
                   programme de test sur l'Europe (main_welsh.c).
/Matrice
   pays_europe.txt : Matrice d'adjacence des 11 pays européens étudiés.
/Resultats
   22403298.png      : Représentation visuelle de mon arbre étudiant.
   graphe_europe.png : Résultat de la coloration généré par Graphviz.


COMPILATION ET EXÉCUTION - WELSH-POWELL (EUROPE)
------------------------------------------------------------------------
Placez-vous dans le sous-dossier "Code/WelshPowell" et compilez :

    gcc main_welsh.c graph0complete.c -o test_europe
    ./test_europe

Le programme lit automatiquement le fichier texte situé dans le dossier 
"Matrice" et génère un fichier DOT dans le dossier "Resultats".

Pour obtenir l'image PNG (Graphviz requis), tapez depuis ce même dossier :
    dot -Tpng ../../Resultats/graphe_europe.dot -o ../../Resultats/graphe_europe.png


COMPILATION ET EXÉCUTION - PARCOURS D'ARBRES
------------------------------------------------------------------------
Placez-vous dans le sous-dossier "Code/Arbres" et compilez :

    gcc monArbre.c arbre.c -o test_arbres
    ./test_arbres

Le programme construira l'arbre correspondant au numéro étudiant 22403298
et affichera dans la console les résultats des parcours préfixe, infixe 
et post-fixe.

========================================================================