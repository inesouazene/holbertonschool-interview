#!/usr/bin/python3
"""
Module pour calculer le nombre minimum d'opérations
nécessaires pour obtenir n caractères H dans un fichier
en utilisant seulement les opérations Copy All et Paste
"""


def minOperations(n):
    """
    Calcule le nombre minimum d'opérations nécessaires pour obtenir
    exactement n caractères H dans le fichier.

    Args:
        n (int): Le nombre de caractères H désirés

    Returns:
        int: Le nombre minimum d'opérations nécessaires.
             Retourne 0 si n est impossible à atteindre.
    """
    if n <= 1:
        return 0

    operations = 0
    divisor = 2

    # Trouve tous les facteurs premiers de n
    while divisor <= n:
        # Tant que n est divisible par divisor
        while n % divisor == 0:
            operations += divisor
            n //= divisor
        divisor += 1

    return operations
