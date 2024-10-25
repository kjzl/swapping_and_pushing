/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_less_than_five.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ommehdiz <ommehdiz@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 09:22:12 by ommehdiz          #+#    #+#             */
/*   Updated: 2024/10/25 11:21:14 by ommehdiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_three_a(t_ps *ps)
{
	t_stack	*stack;

	stack = ps->a;
	if (stack->len != 3)
		return ;
	sort_top_three_a(ps);
	// if (!is_sorted(stack))
	// {
	// 	if (node_is_max(stack, stack->head))
	// 		sa(ps);
	// 	if (node_is_max(stack, stack->head->next))
	// 	{
	// 		rra(ps);
	// 	}
	// 	if (node_is_min(stack, stack->head->next))
	// 		sa(ps);
	// }
}

int find_position(t_stack *stack, int target_index)
{
	t_node	*node;
	int		index;

	node = stack->head;
	index = 0;
	while (node != NULL)
	{
		if (node->target_index == target_index)
			return (index);
		node = node->next;
		++index;
	}
	return (-1);
}

void sort_four_a(t_ps *ps)
{
	t_stack	*stack;
	int		target_index;

	stack = ps->a;
	if (stack->len != 4 || is_sorted(stack))
		return ;
	target_index = find_position(stack, stack_min(stack)->target_index);
	if (target_index <= 1)
	{
		while (stack->head->target_index != stack_min(stack)->target_index)
			ra(ps);
	}
	else
	{
		while (stack->head->target_index != stack_min(stack)->target_index)
			rra(ps);
	}
	pb(ps);
	sort_three_a(ps);
	pa(ps);
}

void sort_five_a(t_ps *ps)
{
	t_stack	*stack;
	int		target_index;

	stack = ps->a;
	if (stack->len != 5 || is_sorted(stack))
		return ;
	target_index = find_position(stack, 0);
	if (target_index <= 2)
	{
		while (stack->head->target_index != 0)
			ra(ps);
	}
	else
	{
		while (stack->head->target_index != 0)
			rra(ps);
	}
	pb(ps);
	sort_four_a(ps);
	pa(ps);
}

void sort_five_or_less_a(t_ps *ps)
{
	t_stack	*stack;

	stack = ps->a;
	if (stack->len > 5)
		return ;
	if (!is_sorted(stack))
	{
		if (stack->len == 2)
			sa(ps);
		else if (stack->len == 3)
			sort_three_a(ps);
		else if (stack->len == 4)
			sort_four_a(ps);
		else if (stack->len == 5)
			sort_five_a(ps);
	}
}
