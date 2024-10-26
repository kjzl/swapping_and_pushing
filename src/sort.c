#include "push_swap.h"

static void find_pivots(t_chunk chunk, int pq[2])
{
	int one_third;

	one_third = chunk.len / 3;
	pq[0] = find_chunk_min_target(chunk) + one_third - 1;
	pq[1] = find_chunk_min_target(chunk) + one_third * 2 - 1;
}

static void	init_splitted_chunks(t_chunk chunk, t_chunk splitted[3])
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

static void split_chunk(t_ps *ps, t_chunk chunk, t_chunk splitted[3])
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

static void	push_chunk_top_a(t_ps *ps, t_chunk chunk)
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
	int		chunk_len;

	if (chunk.len > 3)
	{
		split_chunk(ps, chunk, splitted);
		recursive_chunk_sort(ps, splitted[0]); //MAX
		recursive_chunk_sort(ps, splitted[1]); //MID
		recursive_chunk_sort(ps, splitted[2]); //MIN
		return;
	}
	chunk_len = chunk.len;
	push_chunk_top_a(ps, chunk);
	if (chunk_len == 2 && range_node_is_max(ps->a, ps->a->head, 2))
		sa(ps);
	else if (chunk_len == 3)
		sort_top_three_a(ps);
}
