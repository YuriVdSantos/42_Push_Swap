#include "push_swap.h"

long	*normalize_array(t_stack *stack_a, int size)
{
	int		i;
	int		j;
	int		k;
	long	*array_nor;

	array_nor = (long *) malloc((stack_a->last_idx + 1) * sizeof(long));
	if (!(array_nor))
		return (NULL);
	j = 0;
	k = 0;
	while (j <= stack_a->last_idx)
	{
		i = 0;
		while (i <= stack_a->last_idx)
		{
			if (stack_a->array[j] > stack_a->array[i])
				k++;
			i++;
		}
		array_nor[j] = k;
		k = 0;
		j++;
	}
	return (array_nor);
}

void	radix_sort(t_stack *stack_a, t_stack *stack_b)
{
	int		i;
	int		j;
	int		size;
	int		max_bits;

	size = stack_a->last_idx + 1;
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = -1;
	while (++i < max_bits)
	{
		j = -1;
		while (++j < size)
		{
			if (((stack_a->array[stack_a->last_idx] >> i) & 1) == 0)
				ft_place_in_b(stack_a, stack_b);
			else
				ft_rotate_up_a(stack_a);
		}
		while (stack_b->last_idx >= 1)
			ft_place_in_a(stack_a, stack_b);
	}
}
