#include "push_swap.h"

static t_bool	has_overflow(int *output, int neg, const char *nptr)
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
