#include "push_swap.h"

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

t_bool stack_init(t_stack *a, char **arg_nums)
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

void	ft_free_split(char **strs)
{
	int i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
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
	stack_init(&a, arg_nums);
	if (argc == 2)
		ft_free_split(arg_nums);
	sort_everything(&ps);
	stack_free(&a);
	return (0);
}
