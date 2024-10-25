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

t_bool is_sorted(t_ps *stack)
{
	t_node *cur;

	if (!stack->head || !stack->next->head)
		return (TRUE);
	cur = stack->head;
	while (cur->head != stack->head)
	{
		if (cur->nbr > cur->next->nbr)
			return (FALSE);
		cur = cur->next;
	}
	return (TRUE);
}

void sort_three(t_ps a)
{
	if (!is_sorted(a))
	{
		if ()
			sa(a);
		else if ()
		{
			sa(a);
			rra(a);
		}
		else ()
			ra(a);
	}
}

void sort_less_than_five(t_ps a)
{

}