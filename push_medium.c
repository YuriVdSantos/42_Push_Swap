#include "push_swap.h"

void	push_the_small_23(t_stack *stack_a, t_stack *stack_b)
{
	while (stack_a->last_idx + 1 > 3)
	{
		find_the_smallest_22(stack_a);
		while (stack_a->position_top > 0)
		{
			ft_rotate_up_a(stack_a);
			stack_a->position_top--;
		}
		while (stack_a->position_bottom > 0)
		{
			ft_rotate_down_a(stack_a);
			stack_a->position_bottom--;
		}
		ft_place_in_b(stack_a, stack_b);
	}
}

void	find_the_smallest_22(t_stack *stack_a)
{
	int		i;
	int		j;
	long	temp_top;
	long	temp_bottom;

	j = 0;
	i = stack_a->last_idx;
	temp_top = stack_a->array[stack_a->last_idx];
	while (i >= (stack_a->last_idx - 23) && i >= 0)
	{
		if (stack_a->array[i] <= temp_top)
		{
			stack_a->position_top = j;
			temp_top = stack_a->array[i];
		}
		j++;
		i--;
	}
	temp_bottom = temp_bottom_function(stack_a);
	check_position_place_in_b(stack_a, temp_top, temp_bottom);
}

long	temp_bottom_function(t_stack *stack_a)
{
	int		i;
	int		j;
	long	temp_bottom;

	i = 0;
	j = 1;
	temp_bottom = stack_a->array[0];
	while (i < 22)
	{
		if (stack_a->array[i] <= temp_bottom)
		{
			stack_a->position_bottom = j;
			temp_bottom = stack_a->array[i];
		}
		j++;
		i++;
	}
	return (temp_bottom);
}

void	check_position_place_in_b(t_stack *stack_a, long temp_top, \
		long temp_bottown)
{
	if (temp_bottown < temp_top)
		stack_a->position_top = 0;
	if (temp_top < temp_bottown)
		stack_a->position_bottom = 0;
	if (temp_top == temp_bottown)
	{
		if (stack_a->position_top < stack_a->position_bottom \
			|| stack_a->position_top == stack_a->position_bottom)
		stack_a->position_bottom = 0;
		else if (stack_a->position_bottom < stack_a->position_top)
		stack_a->position_top = 0;
	}
}
