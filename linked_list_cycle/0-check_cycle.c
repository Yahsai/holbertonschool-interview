#include "lists.h"

/**
 * check_cycle - Checks and returns
 * weather or not 'list' has a cycle.
 *
 * A linked list has a cycle if there's no end
 * to "end" of the list (there's no node
 * who's 'next' value is NULL),
 * and if the last node points back to another
 * node already visited.
 *
 * Since we're probably not allowed to allocate our own memory,
 * I'll instead use two pointers.
 * One travels every node (named 'tortoise')
 * The other travels 2 nodes at a time (named 'hare').
 *
 * If the list has no loop, the 'hare' should get to the end
 * before the 'tortoise', and the function returns 0 (false).
 *
 * If the list has a loop, the hare should keep looping every 2 nodes,
 * and the tortoise every 1 node, until they meet again.
 *
 * When we run the tortoise and hare simulation,
 * if the tortoise and hare meet, there's a cycle.
 *
 * But if either the tortoise or hare encounter a NULL
 * node, there's no cycle, since the list has an end.
 *
 * @list: Pointer to the HEAD NODE of a linked list.
 * (I can't prove it, but I believe that any node in the
 * list should work fine, too)
 *
 * Return: 1 if there's a cycle in 'list',
 * 0 if there isn't.
 */
int check_cycle(listint_t *list)
{
	listint_t *tortoise = list;
	listint_t *hare = list;

	while (tortoise && hare)
	{
		/* Check if one of the 2 nodes is at the end */
		if (tortoise == NULL)
			return (0);
		if (hare == NULL)
			return (0);

		/* march once */
		tortoise = tortoise->next;

		/*
		 * march twice, but stop if the first step
		 * already finds an end
		 */
		hare = hare->next;
		if (hare == NULL)
			return (0);
		hare = hare->next;

		/* The 2 pointers met, so it's a cycle! */
		if (tortoise == hare)
			return (1);
	}

	/* list was empty. */
	return (0);
}