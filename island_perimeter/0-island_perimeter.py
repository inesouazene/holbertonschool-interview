#!/usr/bin/python3
"""
Module for calculating the perimeter of an island in a grid.
"""


def island_perimeter(grid):
    """
    Calculate the perimeter of the island described in the grid.

    Args:
        grid (list of lists): A list of lists of integers where:
            0 represents water
            1 represents land

    Returns:
        int: The perimeter of the island.
    """
    perimeter = 0
    rows = len(grid)
    cols = len(grid[0]) if rows > 0 else 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                # Check each cell with value 1 (land)
                # Add 4 to the perimeter for each land cell
                perimeter += 4

                # Check adjacent cells and subtract 1 for each adjacent land
                # Check cell above if it exists
                if i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 1
                # Check cell below if it exists
                if i < rows - 1 and grid[i + 1][j] == 1:
                    perimeter -= 1
                # Check cell to the left if it exists
                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 1
                # Check cell to the right if it exists
                if j < cols - 1 and grid[i][j + 1] == 1:
                    perimeter -= 1

    return perimeter
