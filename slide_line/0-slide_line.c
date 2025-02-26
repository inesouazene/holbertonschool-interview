#include "slide_line.h"

/**
 * slide_line - Slides and merges an array of integers
 * @line: Points to an array of integers
 * @size: Number of elements in the array
 * @direction: Direction to slide (SLIDE_LEFT or SLIDE_RIGHT)
 * Return: 1 upon success, 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t i, pos;
	int merged = 0;

	/* Check for invalid parameters */
	if (line == NULL || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
		return (0);

	if (size <= 1)
		return (1);

	if (direction == SLIDE_LEFT)
	{
		/* Slide to the left */
		pos = 0;
		for (i = 0; i < size; i++)
		{
			if (line[i] == 0)
				continue;

			if (pos > 0 && line[pos - 1] == line[i] && !merged)
			{
				line[pos - 1] *= 2;
				line[i] = 0;
				merged = 1;
			}
			else
			{
				if (i != pos)
				{
					line[pos] = line[i];
					line[i] = 0;
				}
				pos++;
				merged = 0;
			}
		}
	}
	else /* SLIDE_RIGHT */
	{
		/* Slide to the right */
		pos = size - 1;
		for (i = size; i > 0; i--)
		{
			if (line[i - 1] == 0)
				continue;

			if (pos < size - 1 && line[pos + 1] == line[i - 1] && !merged)
			{
				line[pos + 1] *= 2;
				line[i - 1] = 0;
				merged = 1;
			}
			else
			{
				if (i - 1 != pos)
				{
					line[pos] = line[i - 1];
					line[i - 1] = 0;
				}
				pos--;
				merged = 0;
			}
		}
	}

	return (1);
}