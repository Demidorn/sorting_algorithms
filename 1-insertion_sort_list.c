#include "sort.h"

/**
 * insertion_sort_list - sorts a doubly linked list
 * of integers in ascending order
 * @list: pointer to list nodes
 *
 * Return: sorted linked list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *rev;
	int i, j;

	i = j = 0;
	if (!list)
		return;
	temp = *list;

	while (temp->next)
	{
		if (temp->n > temp->next->n)
		{
			swap_nodes(temp, list);
			print_list(*list);
			i = 1;
			rev = temp->prev;

			while (rev->prev)
			{
				if (rev->prev->n > rev->n)
				{
					swap_nodes(rev->prev, list);
					print_list(*list);
					j = 1;
				}
				else
					break;
				if (!j)
					rev = rev->prev;
				j = 0;
			}
		}
		if (!i)
			temp = temp->next;
		i = 0;
	}
}

/**
 * swap_nodes - orders linked list with insertion
 * @list: pointer to head
 * @temp: current node list
 * Return: swap of two nodes
 */

void swap_nodes(listint_t **list, listint_t *temp)
{
	listint_t *node1, *node1_next, *node1_prev = NULL;
	listint_t *node2, *node2_next, *node2_prev;

	node1 = temp;
	node2 = temp->next;
	if (node1->prev)
		node1_prev = node1->prev;
	else
		node1_prev = NULL;

	if (node2->next)
		node2_next = node2->next;
	else
		node2_next = NULL;
	node2_prev = node2->prev;
	if (node1_prev)
		node1_prev->next = node1_next;
	else
		*list = node2;
	if (node2_next)
		node2_next->prev = node2_prev;
	node1->next = node2_next;
	node1->prev = node2;
	node2->next = node1;
	node2->prev = node1_prev;
}
