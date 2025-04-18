# Island Perimeter

## Description
This project contains a solution to calculate the perimeter of an island in a grid. The grid is represented as a 2D array/list of integers where 0 represents water and 1 represents land.

## Requirements
* All files will be interpreted/compiled on Ubuntu 14.04 LTS using `python3` (version 3.4.3)
* All files should end with a new line
* The first line of all files should be exactly `#!/usr/bin/python3`
* Code follows the `PEP 8` style (version 1.7)
* No module imports are allowed
* All modules and functions must be documented
* All files must be executable

## Task: Island Perimeter
* File: `0-island_perimeter.py`
* Function: `island_perimeter(grid)`
* Description: Returns the perimeter of the island described in the grid.

### Problem Statement
Create a function that returns the perimeter of the island described in a grid:
* Grid is a list of list of integers:
  * 0 represents water
  * 1 represents land
  * Each cell is square, with a side length of 1
  * Cells are connected horizontally/vertically (not diagonally)
  * Grid is rectangular, with its width and height not exceeding 100
* The grid is completely surrounded by water
* There is only one island (or nothing)
* The island doesn't have "lakes" (water inside that isn't connected to the water surrounding the island)

### Function Prototype
```python
def island_perimeter(grid):
```

### Example
```python
grid = [
    [0, 0, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 0, 0, 0, 0],
    [0, 1, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0]
]
island_perimeter(grid)  # Returns: 12
```