# TP1 SDD - Cottais Adrian - G22

## Objet du TP:

Le but de ce TP est dans un premier temps de créer **une matrice avec des coûts de productions** stockés dans un fichier.
Deuxièment, il faut stocker dans une liste chainée les **K coûts les plus faibles** avec K passé en paramètre du programme.
Enfin, il faut **supprimer tous les blocs d'une usine u** et exporter le **résultat dans un fichier**.


## Schéma et description des structures de données utilisées

### Structure n°1:

Utilisation d'un tableau dynamique de m lignes et n colonnes.
Les valeurs m et n sont lues dans le fichier donc la tableau d'adapte en fonction de leurs tailles. La structure de données associée est donc une **liste contigue de taille m x n**.

Mettre une photo

### Structure n°2:

Utilisation d'une liste chainée avec K cellules de 4 blocs chacuns.
Une cellule est composée d'une zone mémoire pour le coût de fabrication, une pour l'usine, une pour la semaine de production etfin la dernière est un pointeur vers la prochaine cellule.

Mettre une photo

## Nature des entrées du Programme:


### Fichiers:

Tous les fichiers ont la même syntaxe.
Sur la première ligne on retrouve la valeur m puis n séparé par un espace.
Ensuite, sur chacune des lignes suivantes on trouve un coût de production.
**Attention**: On doit disposer de n x m valeurs sinon il y aura une erreur lors de l'insertion dans la matrice.

**Exemple de fichier**:
````
    2 2
    112
    113
    167
    145
````

**Choix du fichier**: il faut passer le nom en paramètre lors de l'appel du programme.

### K valeurs:
Le nombres de K plus petits coûts à insérer dans la liste chainée est un entier inférieur ou égale au nombre de valeurs totales (n x m) sinon le programme retourne une erreur. Il est aussi à préciser en paramètre du programme.

**Appel du programme**:
````
    make
    ./tp1 filename.txt K
````

### Choix de l'usine à supprimer:
Le choix est à faire quand le programme s'execute. Une boite de dialogue permettra de renseigner cette valeur.

Mettre photo

## Détail des fichiers du programme:

### Organisation du code source:

**matrix.h**: Fichier entêtes gestion de la matrice.
**matrix.c**: Fichier contenant les fonctions pour la gestion de la matrice. 
**linked_list.h**: Fichier entêtes gestion de la liste chainée.
**linked_list.c**: Fichier contenant les fonctions pour la gestion la liste chainée.
**basics.h**: Fichier entêtes avec les fonctions de base 
**basics.c**: Fichier contenant les fonctions de base
**Tp1.c**: Programme principal

### Détail du Makefile:
```
    CC=gcc
    OPT= -c -ansi -pedantic -Wall
    tp1 : tp1.o basics.o matrix.o linked_list.o
	    $(CC) -o tp1 Tp1.o basics.o matrix.o linked_list.o
    tp1.o : Tp1.c
	    $(CC) $(OPT) Tp1.c 
    basics.o : basics.c basics.h
	    $(CC) $(OPT) basics.c 
    matrix.o : matrix.c matrix.h
	    $(CC) $(OPT) matrix.c
    linked_list.o : linked_list.c linked_list.h
	    $(CC) $(OPT) linked_list.c
    clair :
	    rm tp1.o basics.o matrix.o linked_list.o
    propre : clair
	    rm tp1

```
### Fichier de données:

Dans le code fourni, il y a 5 jeux de données disponibles qui permettent de tester le bon fonctionnement du programme.
Ces fichiers ont la syntaxe suivante: data**num**.txt.

Enfin le fichier **output.txt** est utilisé pour stocker la liste chainée.


## Détail des fonctions

### Fonction matrix:

**Fonction createMatrix(lines, columns)**:
Principe:
```
Allocation du nombre de lignes de la matrice

Si allocation réussie alors:
    Pour i de 0 à n-1:
     allocation des colonnes;
     verification allocation;
    Fin pour
    Si allocations non réussies:
        libérer matrix;
    Fsi
Fsi

Retour matrice;
```

**Procédure insertVal(es:matrice e:file, lines, columns)**
```
Pour i de 0 à m-1:
    Pour j de 0 à n-1:
        Lire et stocker valeur du fichier dans la case i,j de la matrice
    Fin Pour
Fin Pour
```

**Procédure displayMatrix(e: matrice, lines, columns)**
```
Pour i de 0 à m-1:
    Pour j de 0 à n-1:
        Afficher la case i,j de la matrice;
    Fin Pour
    Saut de ligne;
Fin Pour
```

**Procédure freeMatrix(es:matrice e:file, lines, columns)**
```
Pour i de 0 à m-1:
    Libérer matrice i;
Fin pour
Libérer matrice;

```