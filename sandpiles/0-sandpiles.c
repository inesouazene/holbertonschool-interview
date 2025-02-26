#include <stdio.h>
#include "sandpiles.h"

/**
 * print_grid - Prints a 3x3 grid
 * @grid: 3x3 grid to be printed
 */
void print_grid(int grid[3][3])
{
    int i, j;

    printf("=\n");
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (j)
                printf(" ");
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
int is_stable(int grid[3][3])
{
    int i, j;
    
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            if (grid[i][j] > 3)
                return (0);
        }
    }
    return (1);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles
 * @grid1: First 3x3 grid (result stored here)
 * @grid2: Second 3x3 grid
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
    int i, j;
    int temp[3][3];

    /* Step 1: Add grid2 to grid1 */
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            grid1[i][j] += grid2[i][j];
        }
    }

    /* Step 2: Toppling until stable */
    while (!is_stable(grid1))
    {
        /* Print grid before toppling */
        print_grid(grid1);
        
        /* Copy current grid1 to temp */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                temp[i][j] = grid1[i][j];
            }
        }

        /* Perform toppling */
        for (i = 0; i < 3; i++)
        {
            for (j = 0; j < 3; j++)
            {
                if (temp[i][j] > 3)
                {
                    grid1[i][j] -= 4;
                    if (i > 0)
                        grid1[i - 1][j] += 1;
                    if (i < 2)
                        grid1[i + 1][j] += 1;
                    if (j > 0)
                        grid1[i][j - 1] += 1;
                    if (j < 2)
                        grid1[i][j + 1] += 1;
                }
            }
        }
    }
}
