#include "sort.h"
/**
 * insertion_sort_list - sort using insertion algorithm
 * @list: head pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *M, *pivot;

	if (!list || !(*list) || !((*list)->next))
		return;
	if ((*list)->next->next == NULL)
	{
		cur = *list;
		M = cur->next;
		if (cur->n > M->n)
		{
			M->next = cur;
			cur->prev = M;
			cur->next = NULL;
			M->prev = NULL;
			*list = M;
		}
		print_list(*list);
		return;
	}
	M = (*list)->next;
	cur = *list;
	if (cur->n > M->n)
	{
		M = *list;
		*list = (*list)->next;
		cur = *list;
		cur->prev = NULL;
		pivot = cur->next;
	}
	else
	{
		pivot = M->next;
		if (cur)
			cur->next = pivot;
		if (pivot)
			pivot->prev = cur;
	}
	while (M)
	{
		while (cur)
		{
			if (cur->n < M->n)
			{
				M->next = cur->next;
				M->prev = cur;
				cur->next = M;
				if (M->next)
					M->next->prev = M;
				break;
			}
			cur = cur->prev;
		}
		if (cur == NULL)
		{
			M->next = *list;
			M->prev = NULL;
			*list = M;
		}
		print_list(*list);
		M = pivot;
		if (M)
		{
			cur = M->prev;
			pivot = M->next;
			if (cur)
				cur->next = pivot;
			if (pivot)
				pivot->prev = cur;
		}
	}
}

