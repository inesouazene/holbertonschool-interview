#include "lists.h"
#include <stdlib.h>

/**
 * is_palindrome - checks if a singly linked list is a palindrome
 * @head: double pointer to the head of the list
 *
 * Return: 0 if it is not a palindrome, 1 if it is a palindrome
 */
int is_palindrome(listint_t **head)
{
	listint_t *current;
	int *values;
	int len = 0, i;

	/* Handle empty list - considered palindrome */
	if (!head || !*head)
		return (1);

	current = *head;

	/* First pass: count the number of nodes */
	while (current)
	{
		len++;
		current = current->next;
	}

	/* Allocate memory for values array */
	values = malloc(sizeof(int) * len);
	if (!values)
		return (0);

	current = *head;

	/* Second pass: store values in array */
	for (i = 0; i < len; i++)
	{
		values[i] = current->n;
		current = current->next;
	}

	/* Check if array is palindrome */
	for (i = 0; i < len / 2; i++)
	{
		if (values[i] != values[len - 1 - i])
		{
			free(values);
			return (0);
		}
	}

	free(values);
	return (1);
}
