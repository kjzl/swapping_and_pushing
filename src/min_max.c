#include "push_swap.h"

t_bool node_is_min(t_stack *stack, t_node *node)
{
	t_node *min;

	min = stack_min(stack);
	return (node == min);
}

t_bool node_is_max(t_stack *stack, t_node *node)
{
	t_node *max;

	max = stack_max(stack);
	return (node == max);
}

t_node *stack_max(t_stack *stack)
{
	t_node *cur;
	t_node *max;

	if (stack->len == 0)
		return (NULL);
	cur = stack->head->next;
	max = stack->head;
	while (cur != stack->head)
	{
		if (cur->nbr > max->nbr)
			max = cur;
		cur = cur->next;
	}
	return (max);
}

t_node *stack_min(t_stack *stack)
{
	t_node *cur;
	t_node *min;

	if (stack->len == 0)
		return (NULL);
	cur = stack->head->next;
	min = stack->head;
	while (cur != stack->head)
	{
		if (cur->nbr < min->nbr)
			min = cur;
		cur = cur->next;
	}
	return (min);
}
