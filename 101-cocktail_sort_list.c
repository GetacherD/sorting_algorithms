#include "sort.h"
/**
 * Move_fwd - traverse list fwd sorting fwd
 * @list: list to be sorted
 * @ever_swap: status of swap
 * Return: last Node
 */
listint_t *Move_fwd(listint_t **list, int *ever_swap)
{
	listint_t *cur, *next, *prev;

	cur = *list;
	while (cur)
	{
		next = cur->next;
		if (next && next->n < cur->n)
		{
			cur->next = next->next;
			next->prev = cur->prev;
			cur->prev = next;
			next->next = cur;
			if (cur->next)
				cur->next->prev = cur;
			if (next->prev)
				next->prev->next = next;
			if (next->prev == NULL)
				*list = next;
			prev = next;
			*ever_swap = 0;
			print_list(*list);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	return (prev);
}

/**
 * cocktail_sort_list - list sorting with cocktail sort
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *next, *prev = NULL;
	int ever_swap = 1;

	while (ever_swap)
	{
		cur = Move_fwd(list, &ever_swap);
		if (ever_swap == 1)
			break;
		while (cur)
		{
			next = cur->prev;
			if (next && (cur->n < next->n))
			{
				cur->prev = next->prev;
				next->next = cur->next;
				cur->next = next;
				next->prev = cur;
				if (cur->prev)
					cur->prev->next = cur;
				if (next->next)
					next->next->prev = next;
				if (cur->prev == NULL)
					*list = cur;
				prev = cur;
				ever_swap = 0;
				print_list(*list);
			}
			else
			{
				prev = cur;
				cur = cur->prev;
			}
		}
		if (cur == NULL)
			cur = prev;
		if (ever_swap == 1)
			break;
		ever_swap = 1;
	}
}
