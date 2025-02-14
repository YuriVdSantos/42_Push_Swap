#include "push_swap.h"

static int	is_digit_modified(const char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] != '\0')
	{
		if (nptr[i] >= '0' && nptr[i] <= '9')
		i++;
		else if (nptr[i] == '-' || nptr[i] == '+')
		{
			if (nptr[i + 1] == '-' || nptr[i + 1] == '+' || \
			!ft_isdigit(nptr[i + 1]))
				return (0);
			if (nptr[i + 1] >= '0' && nptr[i + 1] <= '9')
				i++;
		}
		else if (!ft_isdigit(nptr[i]))
			return (0);
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

long	ft_atoi_modified(const char *nptr)
{
	int		i;
	long	num;
	long	sign;

	i = 0;
	sign = 1;
	num = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
		num = num * 10 + (nptr[i++] - '0');
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		return (42000000000);
	if (!is_digit_modified(nptr))
		return (42000000000);
	return (sign * num);
}

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}
