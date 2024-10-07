#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _is_palindrome - Using a pointer to a double-pointer
 * to the head node of a linked list,
 * this function calls itself with the same 'head'
 * and a pointer to '*tail''s next pointer,
 * so that the recursive calls find the end of the linked list.
 * (not finding '*tail' means we can return 1, since an empty
 * linked list is a palindrome, and if it weren't empty,
 * the parent call would handle that).
 * Once the inner-most calls get started,
 * the head and tail nodes of the linked list are checked
 * to be equal, and the inner-most call is over.
 * Then the 2nd most inward nodes from both ends are checked,
 * and so on and so forth.
 * Since the tail argument is stored locally in each function call,
 * it acts like a stack of pointers in the linked list,
 * and '*head' ACTS LIKE A GLOBAL POINTER TO THE CURRENT
 * HEAD NODE TO CHECK, WHICH SHOULD ALWAYS MOVE FOWARD.
 * THIS MEANS THAT THE VARIABLE CONTAINING YOUR '*head'
 * SHOULD NOW BE THE END OF THE LINKED LIST.
 *
 * @head: pointer to a double pointer to the head node
 * of a linked list of ints. IT SHOULD ACT LIKE A GLOBAL COUNTER
 * OUTSIDE OF THE SCOPES OF THIS FUNCTION TO KEEP TRACK OF
 * THE SEQUENCE OF INTS FROM THE HEAD, WHILE...
 *
 * @tail: ...WILL KEEP TRACK OF THE REVERSE SEQUENCE OF INTS
 * FROM THE TAIL, USING THE FUNCTION CALL STACK. THIS MEANS
 * THAT IN THE BEGGINING, 'tail' MUST BE == '*head', and
 * will progress with each call, until it can no longer move
 * foward.
 *
 * Return: Weather or not the sequence of ints in '***head'
 * is a palindrome, using recursion
 */
int _is_palindrome(listint_t ***head, listint_t **tail)
{
	if (*tail)
	{
		int inner_result = _is_palindrome(head, &((*tail)->next));

		int result = inner_result && (**head)->n == (*tail)->n;

		*head = &((**head)->next);

		return (result);
	}
	return (1);
}

/**
 * is_palindrome - Calculates
 * weather or not '*head' is a palindrome.
 *
 * @head: pointer to pointer to head node of linked list
 *
 * Return: 1 if the linked list in '*head'
 * is the same when reversed,
 * 0 otherwise.
 */
int is_palindrome(listint_t **head)
{
	return (_is_palindrome(&head, head));
}