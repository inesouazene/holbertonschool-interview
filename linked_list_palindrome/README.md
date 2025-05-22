# Linked List Palindrome

Ce projet implémente une fonction en C qui vérifie si une liste chaînée simple est un palindrome.

## Description du problème

Un palindrome est une séquence qui se lit identiquement dans les deux sens. Pour une liste chaînée, cela signifie que les valeurs doivent être symétriques par rapport au centre de la liste.

**Exemple de palindrome :**
```
1 -> 17 -> 972 -> 50 -> 98 -> 98 -> 50 -> 972 -> 17 -> 1
```

**Exemple non palindrome :**
```
1 -> 2 -> 3 -> 4 -> 5
```

## Spécifications techniques

### Prototype de la fonction
```c
int is_palindrome(listint_t **head);
```

### Valeurs de retour
- `1` : si la liste est un palindrome
- `0` : si la liste n'est pas un palindrome
- Une liste vide est considérée comme un palindrome

### Structure de données
```c
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;
```

## Approche algorithmique

L'algorithme utilisé suit ces étapes :

1. **Cas particulier** : Une liste vide ou NULL est considérée comme un palindrome
2. **Première passe** : Parcourir la liste pour compter le nombre de nœuds
3. **Allocation mémoire** : Créer un tableau pour stocker les valeurs
4. **Deuxième passe** : Remplir le tableau avec les valeurs de la liste
5. **Vérification** : Comparer les valeurs du début et de la fin du tableau
6. **Nettoyage** : Libérer la mémoire allouée

### Complexité
- **Temps** : O(n) où n est le nombre de nœuds
- **Espace** : O(n) pour stocker les valeurs dans un tableau

## Compilation et exécution

### Compilation
```bash
gcc -Wall -Werror -Wextra -pedantic 0-main.c linked_lists.c 0-is_palindrome.c -o palindrome
```

### Exécution
```bash
./palindrome
```

### Résultat attendu
```
1
17
972
50
98
98
50
972
17
1
Linked list is a palindrome
```

## Structure du projet

```
linked_list_palindrome/
├── README.md              # Ce fichier
├── lists.h                # Fichier d'en-tête avec les prototypes
├── 0-is_palindrome.c      # Implémentation de la fonction principale
├── linked_lists.c         # Fonctions utilitaires pour les listes
└── 0-main.c              # Fichier de test
```

## Fonctions utilitaires incluses

- `print_listint()` : Affiche tous les éléments d'une liste
- `add_nodeint_end()` : Ajoute un nœud à la fin de la liste
- `free_listint()` : Libère toute la mémoire d'une liste

## Standards de codage

Le code respecte les standards suivants :
- **Style Betty** : Convention de codage C
- **Compilation** : Compatible avec gcc 4.8.4 sur Ubuntu 14.04 LTS
- **Flags de compilation** : `-Wall -Werror -Wextra -pedantic`
- **Header guards** : Protection contre les inclusions multiples
- **Gestion mémoire** : Pas de fuites mémoire, libération appropriée

## Cas de test

La fonction gère correctement :
- ✅ Listes vides
- ✅ Listes à un seul élément
- ✅ Listes palindromes de longueur paire
- ✅ Listes palindromes de longueur impaire
- ✅ Listes non palindromes
- ✅ Échec d'allocation mémoire

## Auteur

Projet développé dans le cadre de la préparation aux entretiens techniques chez Holberton School.