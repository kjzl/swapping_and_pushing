#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "../libft/libft.h"

typedef struct s_node
{
	int				nbr;
	int				target_index;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef enum e_location
{
	TOP_A,
	TOP_B,
	BOTTOM_A,
	BOTTOM_B
}	t_location;

typedef struct s_chunk
{
	int			len;
	t_node		*head;
	t_location	location;
}	t_chunk;

typedef struct s_stack
{
	t_node		*head;
	int			len;
}	t_stack;

typedef struct s_ps
{
	t_stack		*a;
	t_stack		*b;
}	t_ps;

typedef int t_bool;

#define TRUE 1
#define FALSE 0

void	print_stack(t_stack *stack);

void sa(t_ps *ps);
void sb(t_ps *ps);
void ss(t_ps *ps);
void pa(t_ps *ps);
void pb(t_ps *ps);
void ra(t_ps *ps);
void rb(t_ps *ps);
void rr(t_ps *ps);
void rra(t_ps *ps);
void rrb(t_ps *ps);
void rrr(t_ps *ps);

t_bool	stack_pushv(t_stack *stack, int val, unsigned int target_pos);

t_bool init_targets(t_stack *stack);
t_bool is_sorted(t_stack *stack);
t_bool node_is_min(t_stack *stack, t_node *node);
t_bool node_is_max(t_stack *stack, t_node *node);
t_node *stack_max(t_stack *stack);
t_node *stack_min(t_stack *stack);
void	sort_top_three_a(t_ps *ps);
void sort_five_or_less_a(t_ps *ps);
void sort_everything(t_ps *ps);
