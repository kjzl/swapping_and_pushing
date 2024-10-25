#include "../push_swap.h"

t_bool reverse_rotate(t_stack *stack)
{
	if (stack->head == NULL || stack->head->prev == stack->head)
			return (FALSE);
	stack->head = stack->head->prev;
	return (TRUE);
}

void rra(t_ps *ps)
{
	if(reverse_rotate(ps->a))
		write(1, "rra\n", 4);
}

void rrb(t_ps *ps)
{
	if(reverse_rotate(ps->b))
		write(1, "rrb\n", 4);
}

void rrr(t_ps *ps)
{
	t_bool checker;

	checker = reverse_rotate(ps->a);
	checker = reverse_rotate(ps->b) || checker;
	if(checker)
		write(1, "rrr\n", 4);
}
