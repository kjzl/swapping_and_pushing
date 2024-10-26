#include "push_swap.h"

int find_chunk_min(t_chunk chunk)
{
	int min;
	t_node *node;
	int	i;

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

void find_pivots(t_chunk chunk, int pq[2])
{
	int one_third;

	one_third = chunk.len / 3;
	pq[0] = find_chunk_min(chunk) + one_third - 1;
	pq[1] = find_chunk_min(chunk) + one_third * 2 - 1;
}

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

t_bool	loc_on_a(t_location loc)
{
	return (loc == TOP_A || loc == BOTTOM_A);
}

t_bool	loc_bottom(t_location loc)
{
	return (loc == BOTTOM_A || loc == BOTTOM_B);
}

t_stack	*stack_of_chunk(t_ps *ps, t_chunk chunk)
{
	if (chunk.location == TOP_A || chunk.location == BOTTOM_A)
		return (ps->a);
	return (ps->b);
}

void chunk_push(t_ps *ps, t_chunk *from, t_chunk *to)
{
	t_node	*node;

	if (from->len == 0)
		return ;
	if (from->location != to->location)
	{
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
	else
	{
		// print from where to which location to which location we try to push
		//printf("from %d to %d\n", from->location, to->location);
	}
	// if (to->head == NULL)
	// 	printf("to->head is NULL\n");
}

void	chunk_optimize(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->location == BOTTOM_B && to_sort->len == data->b->len)
		to_sort->location = TOP_B;
	if (to_sort->location == BOTTOM_A && to_sort->len == data->a->len)
		to_sort->location = TOP_A;
}

void	init_splitted_chunks(t_chunk chunk, t_chunk splitted[3])
{
	splitted[0] = (t_chunk){.head = 0, .len = 0, .location = BOTTOM_A};
	splitted[1] = (t_chunk){.head = 0, .len = 0, .location = TOP_B};
	splitted[2] = (t_chunk){.head = 0, .len = 0, .location = BOTTOM_B};
	if (chunk.location == BOTTOM_A)
		splitted[0].location = TOP_A;
	else if (chunk.location == TOP_A)
		splitted[0].location = BOTTOM_A;
	else if (chunk.location == BOTTOM_B)
	{
		splitted[0].location = TOP_A;
		splitted[2].location = BOTTOM_A;
	}
	else if (chunk.location == TOP_B)
	{
		splitted[0].location = TOP_A;
		splitted[1].location = BOTTOM_A;
	}
}

void split_chunk(t_ps *ps, t_chunk chunk, t_chunk splitted[3])
{
	int pivots[2];
	t_node *node;

	chunk_optimize(ps, &chunk);
	init_splitted_chunks(chunk, splitted);
	find_pivots(chunk, pivots);
	node = top_chunk_node(ps, chunk);
	while (chunk.len)
	{
		if (node->target_index <= pivots[0])
			chunk_push(ps, &chunk, &splitted[2]);
		else if (node->target_index <= pivots[1])
			chunk_push(ps, &chunk, &splitted[1]);
		else
			chunk_push(ps, &chunk, &splitted[0]);
		node = top_chunk_node(ps, chunk);
	}
}

void	push_chunk_top_a(t_ps *ps, t_chunk chunk)
{
	t_chunk	top_a;

	top_a = (t_chunk){.head = 0, .len = 0, .location = TOP_A};
	if (chunk.location == TOP_A)
		return;
	while (chunk.len)
		chunk_push(ps, &chunk, &top_a);
}

void	recursive_chunk_sort(t_ps *ps, t_chunk chunk)
{
	t_chunk splitted[3];

	//printf("rec chunk_sort\n");
	print_stack(ps->a);
	print_stack(ps->b);
	if (chunk.len == 1)
	{
		push_chunk_top_a(ps, chunk);
		//printf("sorted top 1\n");
		print_stack(ps->a);
	}
	else if (chunk.len == 2)
	{
		push_chunk_top_a(ps, chunk);
		if (ps->a->head->target_index > ps->a->head->next->target_index)
			sa(ps);
		//printf("sorted top 2\n");
		print_stack(ps->a);
	}
	else if (chunk.len == 3)
	{
		push_chunk_top_a(ps, chunk);
		sort_top_three_a(ps);
	}
	else
	{
		//printf("A: ");
		//print_stack(ps->a);
		//printf("B: ");
		//print_stack(ps->b);
		split_chunk(ps, chunk, splitted);
		recursive_chunk_sort(ps, splitted[0]); //MAX
		recursive_chunk_sort(ps, splitted[1]); //MID
		recursive_chunk_sort(ps, splitted[2]); //MIN
	}
}

void sort_everything(t_ps *ps)
{

	if (!is_sorted(ps->a))
	{
		if (ps->a->len <= 5)
			sort_five_or_less_a(ps);
		else
			recursive_chunk_sort(ps, (t_chunk){.head = ps->a->head, .len = ps->a->len, .location = TOP_A});
	}
}
