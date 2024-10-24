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
