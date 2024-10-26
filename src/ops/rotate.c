#include "../push_swap.h"

static t_bool	rotate(t_stack *stack)
{
	if (stack->head == NULL || stack->head->next == stack->head)
		return (FALSE);
	stack->head = stack->head->next;
	return (TRUE);
}

void	ra(t_ps *ps)
{
	if (rotate(ps->a))
		write(1, "ra\n", 3);
}

void	rb(t_ps *ps)
{
	if (rotate(ps->b))
		write(1, "rb\n", 3);
}

void	rr(t_ps *ps)
{
	t_bool	checker;

	checker = rotate(ps->a);
	checker = rotate(ps->b) || checker;
	if (checker)
		write(1, "rr\n", 3);
}
