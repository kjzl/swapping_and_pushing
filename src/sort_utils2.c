#include "push_swap.h"

void sort_top_three_a(t_ps *ps)
{
	t_stack	*stack;

	stack = ps->a;
	if (stack->len != 3)
		return ;
	if (!is_sorted(stack))
	{
		if (node_is_max(stack, stack->head))
			sa(ps);
		if (node_is_max(stack, stack->head->next))
		{
			pb(ps);
			sa(ps);
			pa(ps);
		}
		if (node_is_min(stack, stack->head->next))
			sa(ps);
	}
}
