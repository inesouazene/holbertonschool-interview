#include "slide_line.h"

/**
 * slide_left - Slides and merges an array of integers to the left
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
static int slide_left(int *line, size_t size)
{
	size_t i, pos = 0;
	int merged = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0)
			continue;

		/* If we have a number at pos and it's the same as current number */
		if (pos > 0 && line[pos - 1] == line[i] && !merged)
		{
			line[pos - 1] *= 2; /* Double the value */
			line[i] = 0;        /* Set current position to 0 */
			merged = 1;         /* Mark as merged */
		}
		else
		{
			/* If current position isn't the same as the position to place */
			if (i != pos)
			{
				line[pos] = line[i]; /* Move number to new position */
				line[i] = 0;         /* Set current position to 0 */
			}
			pos++;       /* Increment position */
			merged = 0;  /* Reset merged flag */
		}
	}

	return (1);
}

/**
 * slide_right - Slides and merges an array of integers to the right
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * Return: 1 upon success, 0 upon failure
 */
static int slide_right(int *line, size_t size)
{
	int i, pos = size - 1;
	int merged = 0;

	for (i = size - 1; i >= 0; i--)
	{
		if (line[i] == 0)
			continue;

		/* If we have a number at pos and it's the same as current number */
		if (pos < size - 1 && line[pos + 1] == line[i] && !merged)
		{
			line[pos + 1] *= 2; /* Double the value */
			line[i] = 0;        /* Set current position to 0 */
			merged = 1;         /* Mark as merged */
		}
		else
		{
			/* If current position isn't the same as the position to place */
			if (i != pos)
			{
				line[pos] = line[i]; /* Move number to new position */
				line[i] = 0;         /* Set current position to 0 */
			}
			pos--;       /* Decrement position */
			merged = 0;  /* Reset merged flag */
		}
	}

	return (1);
}

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (size <= 1)
		return (1);

	if (direction == SLIDE_LEFT)
		return (slide_left(line, size));
	else
		return (slide_right(line, size));
}
