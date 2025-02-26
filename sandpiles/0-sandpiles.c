#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
 */
static void print_grid(int grid[3][3])
{
	int i, j;

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
 * topple - Topple an unstable sandpile
 * @grid: 3x3 grid
 *
 */
static void topple(int grid[3][3])
{
	int i, j;
	int tmp_grid[3][3];

	/* Create a copy of the grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			tmp_grid[i][j] = grid[i][j];
	}

	/* Topple the sandpile */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (tmp_grid[i][j] > 3)
			{
				grid[i][j] -= 4;
				/* Add to neighbors if they exist */
				if (i + 1 < 3)
					grid[i + 1][j] += 1;
				if (i - 1 >= 0)
					grid[i - 1][j] += 1;
				if (j + 1 < 3)
					grid[i][j + 1] += 1;
				if (j - 1 >= 0)
					grid[i][j - 1] += 1;
			}
		}
	}
}

/**
 * is_stable - Checks if a sandpile is stable
 * @grid: 3x3 grid to check
 *
 * Return: 1 if stable, 0 otherwise
 */
static int is_stable(int grid[3][3])
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

	/* Add grid2 to grid1 */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
			grid1[i][j] += grid2[i][j];
	}

	/* Topple until stable */
	while (!is_stable(grid1))
	{
		printf("=\n");
		print_grid(grid1);
		topple(grid1);
	}
}