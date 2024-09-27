/*
 sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.
sb (swap b): Swap the first 2 elements at the top of stack b.
Do nothing if there is only one or no elements.
ss : sa and sb at the same time.
pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.
pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.
ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.
rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.
rr : ra and rb at the same time.
rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.
rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.
rrr : rra and rrb at the same time
 *
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_stack
{
	int				nbr;
	int				index;
	int				push_cost;
	bool			above_median;
	bool			cheapest;
	struct s_stack	*target_node;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

int	ft_isspace(int c)
{
	return (c == 32 || (c > 8 && c < 14));
}

long	ft_atol(const char *nptr)
{
	long	res;
	int		neg;

	neg = 1;
	res = 0;
	while (*nptr && ft_isspace((int) *nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + *nptr - '0';
		nptr++;
	}
	return (res * neg);
}

void stack_init(t_stack **a, char **argv, bool flag_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while(argv[i])
	{
		if (error_syntax([i]))
			error_free(a, argv, flag_argc_2);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repitition(*a, (int)nbr))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)nbr);
		i++;
	}
	if (flag_argc_2)
		free_matrix(argv);
}

void	swap_first_two(t_stack **head)
{
	if (*head == NULL || head == NULL)
		return;
	t_stack *first = head;
	t_stack *second = (*head)->next;

	first->next = second->next;
	if(second->next)
		second->next->prev = first;

	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*head = second;
}

void sa(t_stack **a, bool checker)
{
	swap_first_two(a);
	if(!checker)
		write(1, "sa\n", 3);
}

void sb(t_stack **b, bool checker)
{
	swap_first_two(b);
	if(!checker)
		write(1, "sb\n", 3);
}


void ss(t_stack **a, t_stack **b, bool checker)
{
	swap_first_two(a);
	swap_first_two(b);
	if(!checker)
		write(1, "ss\n", 3);
}

int main(int argc, char **argv)
{
	t_stack *a;
	t_stack *b;

	a = NULL;
	b = NULL;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv + 1, argc == 2);
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
