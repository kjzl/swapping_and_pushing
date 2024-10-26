#include "push_swap.h"

static t_bool	has_dups(t_stack *stack)
{
	t_node	*node;
	t_node	*node2;

	if (stack->len == 0)
		return (FALSE);
	node = stack->head;
	while (node != stack->head->prev)
	{
		node2 = node->next;
		while (node2 != stack->head)
		{
			if (node->nbr == node2->nbr)
				return (TRUE);
			node2 = node2->next;
		}
		node = node->next;
	}
	return (FALSE);
}

t_bool	stack_init(t_stack *a, char **arg_nums)
{
	int i;
	int	max_len;
	int nbr;

	i = 0;
	max_len = 0;
	while (arg_nums[max_len] != NULL)
		max_len++;
	i = max_len - 1;
	while(i >= 0)
	{
		if (!ft_atoi_checked(arg_nums[i], &nbr))
			break;
		if(!stack_pushv(a, nbr, 0))
			break;
		i--;
	}
	if (i >= 0 || has_dups(a) || !init_targets(a))
	{
		ft_printf("Error\n");
		stack_free(a);
		return (FALSE);
	}
	return (TRUE);
}
