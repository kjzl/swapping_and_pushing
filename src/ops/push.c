#include "../push_swap.h"

void	stack_push(t_stack *stack, t_node *node)
{
	t_node	*old_head;

	old_head = stack->head;
	stack->head = node;
	stack->len++;
	if (old_head == 0)
	{
		stack->head->next = stack->head;
		stack->head->prev = stack->head;
		return ;
	}
	stack->head->next = old_head;
	stack->head->prev = old_head->prev;
	old_head->prev->next = stack->head;
	old_head->prev = stack->head;
	if (old_head->next == old_head)
		old_head->next = stack->head;
}

t_bool	stack_pushv(t_stack *stack, int val, unsigned int target_pos)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (node == 0)
		return (FALSE);
	node->nbr = val;
	node->target_index = target_pos;
	stack_push(stack, node);
	return (TRUE);
}

t_node	*stack_pop(t_stack *stack)
{
	t_node	*old_head;

	if (stack->head == 0)
		return (0);
	old_head = stack->head;
	if (old_head->next == old_head)
		stack->head = 0;
	else
	{
		stack->head = stack->head->next;
		stack->head->prev = old_head->prev;
		old_head->prev->next = stack->head;
	}
	stack->len--;
	old_head->next = 0;
	old_head->prev = 0;
	return (old_head);
}
void pa(t_ps *ps)
{
	t_node	*node;

	node = stack_pop(ps->b);
	if (node == 0)
		return ;
	stack_push(ps->a, node);
	write(1, "pa\n", 3);
}

void pb(t_ps *ps)
{
	t_node	*node;

	node = stack_pop(ps->a);
	if (node == 0)
		return ;
	stack_push(ps->b, node);
	write(1, "pb\n", 3);
}
