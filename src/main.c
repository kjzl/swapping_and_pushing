#include "push_swap.h"

static void	sort_everything(t_ps *ps)
{
	if (!is_sorted(ps->a))
	{
		if (ps->a->len <= 5)
			sort_five_or_less_a(ps);
		else
			recursive_chunk_sort(ps, (t_chunk){.head = ps->a->head, .len = ps->a->len, .location = TOP_A});
	}
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
