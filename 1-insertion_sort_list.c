#include "sort.h"
/**
 * add_to_start - helper function add element to start
 * @list: head of list
 * @cur: cur node
 * @pivot: pivot node
 */
void add_to_start(listint_t **list, listint_t *cur, listint_t *pivot)
{

			cur->prev->next = pivot;
			if (pivot)
				pivot->prev = cur->prev;
			cur->next = *list;
			(*list)->prev = cur;
			cur->prev = NULL;
			*list = cur;
			print_list(*list);
}
/**
 * _exec_sort - execute sort on filtered list
 * @list: head pointer
 */
void _exec_sort(listint_t **list)
{
	listint_t *cur, *pivot, *mover, *head;
	int add_start = 1;

	cur = (*list)->next;
	pivot = cur->next;
	mover = cur->prev;
	while (cur)
	{
		while (mover)
		{
			if (mover->n <= cur->n)
			{
				cur->prev->next = pivot;
				if (pivot)
					pivot->prev = cur->prev;
				mover->next->prev = cur;
				cur->next = mover->next;
				mover->next = cur;
				cur->prev = mover;
				add_start = 0;
				print_list(*list);
				break;
			}
			mover = mover->prev;
		}
		if (add_start == 1)
		{
			add_to_start(list, cur, pivot);
			add_start = 1;
		}
		cur = pivot;
		add_start = 1;
		if (cur)
			mover = cur->prev;
		if (pivot)
			pivot = pivot->next;
	}
}
/**
 * insertion_sort_list - sort using insertion algorithm
 * @list: head pointer to doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *cur, *pivot, *mover, *head;
	int add_start = 1;

	if (!list || !(*list) || !((*list)->next))
		return;
	if (!(((*list)->next)->next))
	{
		if ((*list)->n > ((*list)->next)->n)
		{
			cur = (*list)->next;
			(*list)->prev = cur;
			cur->prev = NULL;
			cur->next = *list;
			(*list)->next = NULL;
			(*list) = cur;
		}
		return;
	}
	_exec_sort(list);
}

