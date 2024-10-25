
#include "push_swap.h"

t_bool	swap_first_two(t_node **head)
{
	if (*head == NULL || (*head)->next == *head )
	{
		return (FALSE);
	}
	t_node *first = *head;
	t_node *second = (*head)->next;

	first->next = second->next;
	if(second->next != first)
	{
		second->next->prev = first;
		second->next->next = second;
	}

	second->prev = first->prev;
	second->next = first;
	first->prev = second;
	*head = second;
	return (TRUE);
}

void sa(t_ps *ps)
{

	if(swap_first_two(&ps->a->head))
		write(1, "sa\n", 3);
}

void sb(t_ps *ps)
{
	if(swap_first_two(&ps->b->head))
		write(1, "sb\n", 3);
}


void ss(t_ps *ps)
{
	t_bool checker;

	checker = swap_first_two(&ps->a->head);
	checker = swap_first_two(&ps->b->head) || checker;
	if(checker)
		write(1, "ss\n", 3);
}
