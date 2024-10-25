
#include "../push_swap.h"

static t_bool	swap_first_two(t_stack *stack)
{
	if (stack->len < 2)
		return (FALSE);
	t_node *old_head = stack->head;
	stack->head = stack->head->next;
	if (stack->len == 2)
	{
		stack->head->prev = old_head;
		stack->head->next = old_head;
		old_head->next = stack->head;
		old_head->prev = stack->head;
	}
	else
	{
		old_head->next = stack->head->next;
		stack->head->next = old_head;
		stack->head->prev = old_head->prev;
		old_head->prev = stack->head;
	}
	return (TRUE);
}

void sa(t_ps *ps)
{

	if(swap_first_two(ps->a))
		write(1, "sa\n", 3);
}

void sb(t_ps *ps)
{
	if(swap_first_two(ps->b))
		write(1, "sb\n", 3);
}


void ss(t_ps *ps)
{
	t_bool checker;

	checker = swap_first_two(ps->a);
	checker = swap_first_two(ps->b) || checker;
	if(checker)
		write(1, "ss\n", 3);
}
