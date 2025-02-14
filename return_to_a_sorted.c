#include "push_swap.h"

void	return_to_a_sorted(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_b->last_idx >= 1)
	{
		find_the_target_number(stack_b);
		if (stack_b->target_pos >= (stack_b->last_idx + 1) / 2)
		{
			while (stack_b->target_pos < stack_b->last_idx)
			{
				ft_rotate_up_b(stack_b);
				stack_b->target_pos++;
			}
			ft_place_in_a(stack_a, stack_b);
		}
		if (stack_b->target_pos < (stack_b->last_idx + 1) / 2)
		{
			while (stack_b->target_pos >= 1)
			{
				ft_rotate_down_b(stack_b);
				stack_b->target_pos--;
			}
			ft_place_in_a(stack_a, stack_b);
		}
	}
}

void	find_the_target_number(t_stack *stack_b)
{
	int		i;
	long	temp;

	i = 1;
	temp = stack_b->array[1];
	while (i <= stack_b->last_idx)
	{
		if (stack_b->array[i] >= temp)
		{
			stack_b->target_pos = i;
			temp = stack_b->array[i];
		}
		i++;
	}
}
