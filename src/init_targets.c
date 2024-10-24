#include "push_swap.h"

void quickly_sort_array(int *array, int size)
{
	int	index;
	int	tmp;

	index = 1;
	if (size != 0)
	{
		while (index < size)
		{
			if (array[index] < array[index - 1])
			{
				tmp = array[index];
				array[index] = array[index - 1];
				array[index - 1] = tmp;
				index = 0;
			}
			++index;
		}
	}
}

int *stack_to_array(t_stack *stack)
{
	int		*array;
	t_node	*node;
	int		index;

	array = malloc(sizeof(int) * stack->len);
	if (array == NULL)
		return (NULL);
	node = stack->head;
	index = 0;
	while (index < stack->len)
	{
		array[index] = node->nbr;
		node = node->next;
		++index;
	}
	return (array);
}

t_node *node_by_nbr(t_stack *stack, int nbr)
{
	t_node *node;

	node = stack->head;
	while (node != NULL)
	{
		if (node->nbr == nbr)
			return (node);
		node = node->next;
	}
	return (NULL);
}

void set_targets(t_stack *stack, int *sorted_arr)
{
	t_node	*node;
	int		index;

	node = stack->head;
	index = 0;
	while (index < stack->len)
	{
		node_by_nbr(stack, sorted_arr[index])->target_index = index;
		node = node->next;
		++index;
	}
}

t_bool init_targets(t_stack *stack)
{
	int *array;

	array = stack_to_array(stack);
	if (array == NULL)
		return (FALSE);
	quickly_sort_array(array, stack->len);
	set_targets(stack, array);
	free(array);
	return (TRUE);
}
