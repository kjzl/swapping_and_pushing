#include "push_swap.h"

void sort_top_three_a(t_ps *ps)
{
	t_stack	*stack;

	stack = ps->a;
	if (stack->len < 3)
		return ;
	if (!is_sorted(stack))
	{
		//printf("top3 max nbr: %d\n", range_stack_max(stack, 3)->nbr);
		if (range_node_is_max(stack, stack->head, 3))
			sa(ps);
		if (range_node_is_max(stack, stack->head->next, 3))
		{
			pb(ps);
			sa(ps);
			pa(ps);
		}
		if (range_node_is_min(stack, stack->head->next, 3))
			sa(ps);
	}
}
