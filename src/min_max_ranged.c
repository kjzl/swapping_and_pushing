#include "push_swap.h"

t_node	*range_stack_max(t_stack *stack, int range)
{
	t_node	*cur;
	t_node	*max;

	if (stack->len == 0)
		return (FALSE);
	cur = stack->head->next;
	max = stack->head;
	while (cur != stack->head && --range > 0)
	{
		if (cur->nbr > max->nbr)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

t_node	*range_stack_min(t_stack *stack, int range)
{
	t_node	*cur;
	t_node	*min;

	if (stack->len == 0)
		return (FALSE);
	cur = stack->head->next;
	min = stack->head;
	while (cur != stack->head && --range > 0)
	{
		if (cur->nbr < min->nbr)
			min = cur;
		cur = cur->next;
	}
	return (min);
}

t_bool	range_node_is_min(t_stack *stack, t_node *node, int range)
{
	t_node	*min;

	min = range_stack_min(stack, range);
	return (node == min);
}

t_bool	range_node_is_max(t_stack *stack, t_node *node, int range)
{
	t_node	*max;

	max = range_stack_max(stack, range);
	return (node == max);
}
