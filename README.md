# TP1 SDD - Cottais Adrian - G22

## Objectif du TP:

Le but de ce TP est dans un premier temps de créer **une matrice avec des coûts de productions** stockés dans un fichier.
Deuxièment, il faut stocker dans une liste chainée les **K coûts les plus faibles** avec K passé en paramètre du programme.
Enfin, il faut **supprimer tous les blocs d'une usine u** et exporter le **résultat dans un fichier**.


## Schéma et description des structures de données utilisées

### Structure n°1:

Utilisation d'un tableau dynamique de m lignes et n colonnes.
Les valeurs m et n sont lues dans le fichier donc la tableau d'adapte en fonction de leurs tailles. La structure de données associée est donc une **liste contigue de taille m x n**.


![](https://i.imgur.com/md4an9o.png)


### Structure n°2:

Utilisation d'une liste chainée avec K cellules de 4 blocs chacuns.
Une cellule est composée d'une zone mémoire pour le coût de fabrication, une pour l'usine, une pour la semaine de production etfin la dernière est un pointeur vers la prochaine cellule.

![](https://i.imgur.com/YKo1CMT.png)


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

### Fonctions matrix:

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

### Fonctions linked_list:
**Procédure add_cell(e:preceding, cell)**:

```
    La zone memoire suivante de la cellule prend le contenu de preceding;
    La zone memoire du preceding prend l'adresse de la cellule;
```

**Fonction search_prec(adr_tête,val_cherchee)**:
Pour les listes chainées triées.
```    
    cour= valeur de la tete;
    prec= adresse de la tete;
    
    Tant que la liste est pas finie de défiler et que val_cherchee < à val de la case:
        Avance du prec sur la zone suivante du cour;
        Avance du cour sur le prochain bloc;
    Fin Tant Que
    
    Retourner le prec
        
```

**Fonction search_prec_bis(adr_tête,val_cherchee)**
Pour les listes chainées non triées.
```    
    cour= valeur de la tete;
    prec= adresse de la tete;
    
    Tant que la liste est pas finie de défiler et que val_cherchee != à val de la case:
        Avance du prec sur la zone suivante du cour;
        Avance du cour sur le prochain bloc;
    Fin Tant Que
    
    Retourner le prec
```

**Procédure del_cel(e:precedent)**:
```
    Stockage du contenu du precedent dans un pointeur sauv;
    Contenu du précédent prend la val de la case suivante de sauv;
    Libérer sauv;
```

**Procédure free_list(es:tete)**:
```
    Double pointeur prec prend l'adresse de la tête;
    Tant que la tete est pas à NIL faire:
        Appel de la fonction del_cel(prec);
    Fin Tant que
        
```
**display_linkChain(e:tete)**:
```
    cour=tete
    Tant que la liste est pas finie de défiler:
        Afficher le coût de la case cour;
        Afficher l'usine de la case cour;
        Afficher la semaine de la case cour;
        Cour prend l'adresse dans contenu dans le suivant du cour actuel
    Fin Tant Que
```

**Fonction create_cell(coût, num_usine, sem_prod)**:
```
        cell=allocation taille d'une cellule
        Si allocation réussie:
            Ajout du coût,num_usine, sem_prod dans la cellule;
        Fsi
        Retourner cell;
```

**Procédure del_factory(adr_tete, num_usine)**:
```
    prec prend adr_tete;
    Tant que la valeur pointée de prec est différente de NIL:
        prec= appel fonction search_prec_bis(prec);
        Si valeur pointée de prec est diff de NIL:
            del_cel(prec);
        Fsi
    Fin Tant Que
```

**Procédure writefile(nomFichier, tete)**:
```
    Ouverture du fichier en ecriture;
    Si ouverture ok:
        Ecriture dans fichier entete du type: "Cost", "Factory", "Week";
        Tant que toute la liste n'est pas parcourue:
            Ecriture dans fichier du coût,usine et semaine;
            Passage sur le prochain bloc;
        Fin tant que
        
        Fermeture du fichier;
    Sinon:
        Ecriture "Fichier introuvable";
    Fsi

```    
### Fonctions TP1(main):
Algorithme de principe du main():
```
Debut:

    Si on a 2 arguments en paramètres du programme:
        Récupération du nom du fichier et de K ;
        Ouverture du fichier en mode lecture;
        Si fichier ouvert:
            Récupération de m et n;
            Création de matrice;
            Si matrice bien créee:
                Insertion des valeurs fichier dans matrice;
                Affichage matrice;
                Si K>0 && K <= n * m:
                    Creation tête liste chainée;
                    Pour 0 à m-1:
                        Pour 0 à n-1:
                            Si i*n+j<K :
                                Recherche du précédent;
                                Création cellule;
                                Ajout cellule;
                            Sinon:
                                Si val en tete liste est sup à celle de la matrice:
                                    Recherche du précédent;
                                    Création cellule;
                                    Ajout cellule;
                                    Supprimer la cellule en tête;
                                Fsi
                            Fsi
                        Fin pour 
                    Fin pour 
                    Afficher liste chainée;
                    Demander et récupérer usine à supprimer;
                    Suppression de tous les blocs de ces usines;
                    Afficher liste chainée;
                    Ecrire liste dans un fichier;
                    Libérer liste;
                Sinon
                    Ecrire K pas dans les normes;
                Fsi
                Libérer matrice;
            Fsi
            Fermer fichier;
        Sinon
            Ecrire "Fichier introuvable";
        Fsi
    Fsi
FIN
    
```



## Jeu de tests

### Avec le fichier data.txt avec le contenu suivant:
```   
    4 3
    11
    12
    167
    130
    14
    103
    112
    97
    15
    96
    117
    13
```
On cherche à afficher les 4 coûts les plus faibles.
Commande exéctution:

```
    ./tp1 data.txt 4 
```
Matrice de sortie:
```
    11 12 167 
    130 14 103 
    112 97 15 
    96 117 13
```

Liste chainée de sortie:
```
     Cost:14
     Factory :1
     Week:1
     --------- 
     Cost:13
     Factory :3
     Week:2
     --------- 
     Cost:12
     Factory :0
     Week:1
     --------- 
     Cost:11
     Factory :0
     Week:0
```
Choix de suppression de l'usine 1, avec un bloc contenant cette usine en tête. Résultats après:
```  
    Modify linked-list 
 
     Cost:13
     Factory :3
     Week:2
     --------- 
     Cost:12
     Factory :0
     Week:1
     --------- 
     Cost:11
     Factory :0
     Week:0
     --------- 
```
Choix de suppression de l'usine 3, avec un bloc contenant cette usine en milieu de liste. Résultats après:
```    
    Modify linked-list 
 
    Cost:14
    Factory :1
    Week:1
    --------- 
    Cost:12
    Factory :0
    Week:1
    --------- 
    Cost:11
    Factory :0
    Week:0
    --------- 

```
Choix de suppression de l'usine 0, avec un bloc contenant cette usine en milieu de liste et en fin. Résultats après:
```
    Modify linked-list 
 
    Cost:14
    Factory :1
    Week:1
    --------- 
    Cost:13
    Factory :3
    Week:2
    ---------
```
Avec le même fichier avec le 2 côuts les plus faibles:
```
    ./tp1 data.txt 2 
```
Résultat avant suppression:
```
    Cost:12
    Factory :0
    Week:1
    --------- 
    Cost:11
    Factory :0
    Week:0
    ---------
```
Tests avec la suppresion de l'usine 0:
```
    Modify linked-list 
```
Il reste bien aucuns blocs.

Si par exemple on supprime l'usine 1 qui n'est pas présente, on a le résulat suivant:
```
Modify linked-list 
 
    Cost:12
    Factory :0
    Week:1
    --------- 
    Cost:11
    Factory :0
    Week:0
    --------- 
```
### Avec le fichier data2.txt avec le contenu suivant:
```
    2 2
    112
    113
    167
    145
```

Ce fichier va générer une matrice 2x2 carré.
Matrice générée:
```
    112 113 
    167 145 
```
Si on souhaite obtenir les 4 coûts les plus faibles:
```
    ./tp1 data2.txt 4
```
Résultats avant le tri:
```
    Cost:167
    Factory :1
    Week:0
    --------- 
    Cost:145
    Factory :1
    Week:1
    --------- 
    Cost:113
    Factory :0
    Week:1
    --------- 
    Cost:112
    Factory :0
    Week:0
```
Suppression de l'usine 1:
```
Modify linked-list 
 
    Cost:113
    Factory :0
    Week:1
    --------- 
    Cost:112
    Factory :0
    Week:0
    --------- 
```
Suppression de l'usine 0:

```
Modify linked-list 
 
    Cost:167
    Factory :1
    Week:0
    --------- 
    Cost:145
    Factory :1
    Week:1
    --------- 
```

### Avec le fichier data6.txt avec le contenu suivant:
Ce fichier permet de tester si le programme fonctionne correctement avec 0 valeurs dans la matrice.
```
    0 0
```
```
    ./tp1 data6.txt 0
```
**Résultat**:

Ici on a donc un matrice de taille 0 avec 0 valeurs.

Si on rentre K supérieur ou égale à 0, ou inférieur à 0 on aura le message d'erreur suivant:
```    
   K est trop grand par rapport au nombre de valeurs disponibles dans la matrice, soit inférieur ou égale à 0 
```
**Remarque**: ce message sera affiché à chaque fois que K sera **supérieur à m x n**.

Tout fonctionne bien avec une matrice de taille 0 car on de toute façon on ne pourra pas choisir les K coûts les plus faibles.
Rien n'est initialisé et on obtient directement le message d'erreur.