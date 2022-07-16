#include "sort.h"
/**
 * low_insert - sort for 2 elements only
 * @list: list with 2 elements
 */
void low_insert(listint_t **list)
{

	listint_t *cur, *M;

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
}
/**
 * exec_insert - sort and insert
 * @list: list head
 * @cur: cur pointer
 * @M: elemnt under compare
 * @pivot: next element poniter
 */
void exec_insert(listint_t **list,
		listint_t *cur, listint_t *M, listint_t *pivot)
{
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

/**
 * insertion_sort_list - sort using insertion algorithm
 * @list: head pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *M, *pivot;

	low_insert(list);
	M = (*list)->next;
	cur = *list;
	if (cur->n > M->n)
	{
		cur->next = M->next;
		M->next = cur;
		cur->prev = M;
		M->prev = NULL;
		*list = M;
		print_list(*list);
		M = (*list)->next;
		cur = *list;
		pivot = M->next;
	}
	else
	{
		print_list(*list);
		pivot = M->next;
		if (cur)
			cur->next = pivot;
		if (pivot)
			pivot->prev = cur;
	}
	exec_insert(list, cur, M, pivot);
}

