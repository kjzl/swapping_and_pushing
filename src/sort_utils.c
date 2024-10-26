#include "push_swap.h"

t_bool	is_sorted(t_stack *stack)
{
	t_node	*cur;

	if (!stack->head || stack->head->next == stack->head)
		return (TRUE);
	cur = stack->head;
	while (cur->next != stack->head)
	{
		if (cur->nbr > cur->next->nbr)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

void	sort_top_three_a(t_ps *ps)
{
	t_stack	*stack;

	stack = ps->a;
	if (stack->len < 3)
		return ;
	if (!is_sorted(stack))
	{
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
