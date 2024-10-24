#include "push_swap.h"

int	ft_isspace(int c)
{
	return (c == 32 || (c > 8 && c < 14));
}

t_bool	has_overflow(int *output, int neg, const char *nptr)
{
	if (*output > INT_MAX / 10)
		return (TRUE);
	if (*output == INT_MAX / 10)
	{
		if (neg == -1 && *nptr > '8')
			return (TRUE);
		if (neg == 1 && *nptr > '7')
			return (TRUE);
	}
	return (FALSE);
}

t_bool	ft_atoi_checked(const char *nptr, int *output)
{
	int		neg;
	t_bool	contains_digit;

	neg = 1;
	*output = 0;
	while (*nptr && ft_isspace((int) *nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	contains_digit = FALSE;
	while (*nptr >= '0' && *nptr <= '9')
	{
		if (has_overflow(output, neg, nptr))
			return (FALSE);
		*output = (*output) * 10 + *nptr - '0';
		nptr++;
		contains_digit = TRUE;
	}
	*output *= neg;
	return (*nptr == 0 && contains_digit);
}

void stack_free(t_stack *stack)
{
	t_node	*node;
	t_node	*next;

	if (stack->head == 0)
		return ;
	node = stack->head;
	next = node->next;
	while (next != stack->head)
	{
		free(node);
		node = next;
		next = node->next;
	}
	free(node);
	stack->head = 0;
	stack->len = 0;
}

t_bool has_dups(t_stack *stack)
{
	t_node	*node;
	t_node	*node2;

	node = stack->head;
	while (node != NULL)
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

t_bool stack_init(t_stack *a, char **arg_nums)
{
	int i;
	int nbr;

	i = 0;
	while(arg_nums[i] != NULL)
	{
		if (!ft_atoi_checked(arg_nums[i], &nbr))
			break;
		if(!stack_pushv(a, nbr, 0))
			break;
		i++;
	}
	if (arg_nums[i] != NULL || has_dups(a) || !init_targets(a))
	{
		stack_free(a);
		return (FALSE);
	}
	return (TRUE);
}


int main(int argc, char **argv)
{
	t_ps	ps;
	t_stack a;
	t_stack b;
	char	**arg_nums;

	a = (t_stack){0};
	b = (t_stack){0};
	ps = (t_ps){&a, &b};
	if (argc == 1)
		return (1);
	else if (argc == 2)
		arg_nums = ft_split(argv[1], ' ');
	else
		arg_nums = argv + 1;
	// TODO: if stack_init ...
	// free arg_nums if from ft_split
	stack_init(&a, arg_nums);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
	}
	free_stack(&a);

	return (0);
}
