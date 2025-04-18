#!/usr/bin/python3
"""
Module for the canUnlockAll method.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.

    Args:
        boxes (list of lists): A list containing lists representing locked boxes.
                              Each box may contain keys to other boxes.

    Returns:
        bool: True if all boxes can be opened, else False.
    """
    if not boxes or type(boxes) is not list:
        return False

    n = len(boxes)
    if n == 0:
        return True

    # Keep track of unlocked boxes
    unlocked = [False] * n
    unlocked[0] = True  # First box is already unlocked

    # Initialize queue with keys from the first box
    keys_to_check = boxes[0].copy()

    # Process keys until we can't unlock any more boxes
    while keys_to_check:
        current_key = keys_to_check.pop()
        
        # Check if the key is valid and opens a new box
        if 0 <= current_key < n and not unlocked[current_key]:
            unlocked[current_key] = True
            # Add new keys from the recently unlocked box
            keys_to_check.extend(boxes[current_key])

    # Check if all boxes are unlocked
    return all(unlocked)
    