# Minimum Operations

Ce projet implémente une solution pour calculer le nombre minimum d'opérations nécessaires pour obtenir exactement n caractères 'H' dans un fichier texte, en utilisant seulement les opérations "Copy All" et "Paste".

## Description du problème

Étant donné un fichier texte contenant un seul caractère 'H', et un éditeur de texte qui ne peut effectuer que deux opérations :
- **Copy All** : copie tous les caractères H actuels
- **Paste** : colle le contenu du presse-papier

L'objectif est de trouver le nombre minimum d'opérations pour atteindre exactement n caractères 'H'.

## Approche algorithmique

La solution utilise la factorisation en nombres premiers :
- Pour chaque facteur premier p de n, nous avons besoin de p opérations
- La somme de tous les facteurs premiers donne le nombre minimum d'opérations

## Utilisation

```python
from minoperations import minOperations

# Exemple d'utilisation
result = minOperations(9)
print(result)  # Output: 6
```

## Fichiers

- `0-minoperations.py` : Implémentation de la fonction minOperations
- `0-main.py` : Fichier de test principal