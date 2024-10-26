#include "push_swap.h"

t_bool	loc_on_a(t_location loc)
{
	return (loc == TOP_A || loc == BOTTOM_A);
}

t_bool	loc_bottom(t_location loc)
{
	return (loc == BOTTOM_A || loc == BOTTOM_B);
}
