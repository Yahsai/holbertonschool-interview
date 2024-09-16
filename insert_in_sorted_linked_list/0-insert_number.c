#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - Inserts new node with 'number' as its
 * 'n' attribute, in its correct spot in the linked list
 * pointed to by 'head';
 * 'head' IS ASSUMED TO BE A SORTED LINKED LIST OF INTS,
 * IN ASCENDING ORDER.
 *
 * @head: pointer to head pointer of linked list of integers,
 * SORTED IN ASCENDING ORDER. Each node is assumed to be of type
 * 'listint_t'
 * @number: number to put in new node, and to insert
 * in the linked list pointed to by 'head', in its correct position
 *
 * Return: the address of the new node if the memory allocation
 * was successful, NULL otherwise.
 */
listint_t *insert_node(listint_t **head, int number)
{
	listint_t *number_node = malloc(sizeof(listint_t));
	listint_t **current = head;

	/* memory failed */
	if (number_node == NULL)
		return (NULL);

	while (*current && (**current).n < number)
		current = &(**current).next;

	number_node->n = number;
	number_node->next = *current;

	*current = number_node;

	return (number_node);
}