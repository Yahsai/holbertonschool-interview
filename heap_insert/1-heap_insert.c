#include "binary_trees.h"

/**
 * heap_end - Returns the address of the pointer
 * to where the next unoccupied slot of the heap
 * is
 */
heap_t **heap_end(heap_t **root, int value)
{
	if (root == NULL)
		return (NULL);

	heap_t **left = heap_end((*root)->left);
	heap_t **right = heap_end((*root)->right);

	if (*left == NULL)
		return (*left);
	if (*right == NULL)
		return (*right);
}

/**
 * heap_insert_place - Returns the address of the pointer
 * to where the new node should be inserted
 */
heap_t **heap_insert_place(heap_t **root, int value) {
	if (root == NULL)
		return (NULL);

	heap_t **left = heap_end((*root));
}

/**
 * heap_insert - TRIES TO:
 * Create a new 'heap_t' type node with:
 * 'value' as its 'n', into its correct place in
 * the heap pointed to by 'root'.
 *
 * USING MAX-HEAP ORDERING.
 *
 * By 'heap' I mean all of the nodes of the heap
 * AND THE POINTER TO THE ROOT NODE, WHICH MAY EVEN BE NULL.
 *
 * THIS MEANS THAT IF '*root' is NULL, THE NEW NODE WILL
 * BECOME THE ROOT NODE OF THE HEAP!!!
 *
 * If 'root' is NULL or if the malloc FAILS,
 * This function just returns NULL.
 *
 * @root: pointer to (L-VALUE!!) pointer to root
 * @value: int to insert into heap into correct place
 *
 * Return: pointer to new heap node
 * (in its correct place in the heap)
 * if malloc was successful,
 * NULL otherwise
 */
heap_t *heap_insert(heap_t **root, int value)
{
	if (root == NULL)
		return (NULL);

	/* make node */

	heap_t *new = malloc(sizeof(heap_t));

	if (new == NULL)
		return (NULL);

	new->n = value;
	new->parent = NULL;
	new->left = NULL;
	new->right = NULL;

	/* find place to insert node */

	heap_t **insert_place = root;

	while (*insert_place != NULL
		&& insert_place->n > value)
	{

		insert_place = (*insert_place)->
	}

	heap_t *insert_place_parent = (*insert_place)->parent;
	heap_t *insert_place_left = (*insert_place)->left;
	heap_t *insert_place_right = (*insert_place)->right;

	new->parent = insert_place_parent;
	new->left = insert_place_left;
	new->right = insert_place_right;

	(*insert_place)
}