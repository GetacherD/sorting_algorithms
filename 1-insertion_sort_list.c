#include "sort.h"
/**
 * insertion_sort_list - sort using insertion algorithm
 * @list: head pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{

	listint_t *M, *cur, *pivot;

	M = (*list);
	while (M)
	{
		pivot = M->next;
		cur = M->prev;
		while (cur && cur->n > M->n)
		{
			cur->next = M->next;
			if (M->next)
				M->next->prev = cur;
			if (cur->prev)
				cur->prev->next = M;
			else
				*list = M;
			M->prev = cur->prev;
			cur->prev = M;
			M->next = cur;
			cur = M->prev;
			print_list(*list);
		}
		M = pivot;
	}
}
