// TODO: Insert 42 header here

#include "ymath.h"
#include "ytypes.h"

static t_bool	is_prime(t_uint num)
{
	t_uint	i;

	if (num <= 1)
		return (FALSE);
	if (num <= 3)
		return (TRUE);
	if (num % 2 == 0 || num % 3 == 0)
		return (FALSE);
	i = 5;
	while (i * i <= num)
	{
		if (num % i == 0 || num % (i + 2) == 0)
			return (FALSE);
		i += 6;
	}
	return (TRUE);
}

t_uint	get_next_prime(t_uint num)
{
	t_uint	i;

	if (num <= 1)
		return (2);
	i = 0;
	while (i < PRIME_SEARCH_THRESHOLD)
	{
		num++;
		if (is_prime(num))
			return (num);
		i++;
	}
	return (0);
}
