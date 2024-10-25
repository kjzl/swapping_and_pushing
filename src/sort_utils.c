#include "push_swap.h"

t_bool is_sorted(t_stack *stack)
{
	t_node *cur;

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

	if (!stack->head)
		return (NULL);
	cur = stack->head;
	max = cur;
	while (cur->next != stack->head)
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

	if (!stack->head)
		return (NULL);
	cur = stack->head;
	min = cur;
	while (cur->next != stack->head)
	{
		if (cur->nbr < min->nbr)
			min = cur;
		cur = cur->next;
	}
	return (min);
}