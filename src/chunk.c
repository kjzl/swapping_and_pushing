#include "push_swap.h"

t_node	*top_chunk_node(t_ps *ps, t_chunk chunk)
{
	if (chunk.location == TOP_A)
		return (ps->a->head);
	if (chunk.location == TOP_B)
		return (ps->b->head);
	if (chunk.location == BOTTOM_A)
		return (ps->a->head->prev);
	return (ps->b->head->prev);
}

t_stack	*stack_of_chunk(t_ps *ps, t_chunk chunk)
{
	if (chunk.location == TOP_A || chunk.location == BOTTOM_A)
		return (ps->a);
	return (ps->b);
}

void	chunk_push(t_ps *ps, t_chunk *from, t_chunk *to)
{
	t_node	*node;

	if (from->len == 0 || from->location == to->location)
		return ;
	from->len--;
	node = top_chunk_node(ps, *from);
	if (to->len == 0 || !loc_bottom(to->location))
		to->head = node;
	if (!loc_bottom(from->location))
		from->head = stack_of_chunk(ps, *from)->head;
	if (from->location == BOTTOM_A)
		rra(ps);
	else if (from->location == BOTTOM_B)
		rrb(ps);
	if (loc_on_a(from->location) && !loc_on_a(to->location))
		pb(ps);
	else if (!loc_on_a(from->location) && loc_on_a(to->location))
		pa(ps);
	if (to->location == BOTTOM_A)
		ra(ps);
	else if (to->location == BOTTOM_B)
		rb(ps);
	to->len++;
}

int	find_chunk_min_target(t_chunk chunk)
{
	int		min;
	t_node	*node;
	int		i;

	i = 0;
	min = INT_MAX;
	node = chunk.head;
	while (i < chunk.len)
	{
		if (node->target_index < min)
			min = node->target_index;
		node = node->next;
		i++;
	}
	return (min);
}

void	chunk_optimize(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_B && to_sort->len == data->b->len)
		to_sort->location = TOP_B;
	if (to_sort->location == BOTTOM_A && to_sort->len == data->a->len)
		to_sort->location = TOP_A;
}
