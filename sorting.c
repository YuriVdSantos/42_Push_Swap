#include "push_swap.h"

void	sort_all(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->last_idx <= 25)
	{
		push_the_small_5(stack_a, stack_b);
		if (!is_sorted(stack_a))
			sort_three(stack_a);
		return_to_a_sorted(stack_a, stack_b);
	}
	if (stack_a->last_idx > 25 && stack_a->last_idx <= 75)
	{
		push_the_small_23(stack_a, stack_b);
		if (!is_sorted(stack_a))
			sort_three(stack_a);
		return_to_a_sorted(stack_a, stack_b);
	}
	if (stack_a->last_idx > 75)
		radix_sort(stack_a, stack_b);
}

int	is_sorted(t_stack *stack)
{
	int	i;

	i = stack->last_idx;
	if (stack->last_idx == 0)
		return (1);
	while (i > 0)
	{
		if (stack->array[i] > stack->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}

void	sort_stacks(t_stack *stack_a, t_stack *stack_b)
{
	if (is_sorted(stack_a))
		return ;
	else if (stack_a->last_idx + 1 <= 3)
		sort_three(stack_a);
	sort_all(stack_a, stack_b);
}

void	sort_three(t_stack *stack_a)
{
	int	bot;
	int	mid;
	int	top;

	bot = stack_a->array[0];
	mid = stack_a->array[1];
	top = stack_a->array[2];
	if (stack_a->last_idx + 1 == 2 && !is_sorted(stack_a))
		ft_swap_a(stack_a);
	else if (stack_a->last_idx + 1 == 3)
		sort_three_utils(top, mid, bot, stack_a);
}

void	sort_three_utils(int top, int mid, int bot, t_stack *stack_a)
{
	if (top < mid && mid > bot && top < bot)
	{
		ft_rotate_down_a(stack_a);
		ft_swap_a(stack_a);
	}
	else if (top > mid && mid < bot && top < bot)
		ft_swap_a(stack_a);
	else if (top < mid && mid > bot && top > bot)
		ft_rotate_down_a(stack_a);
	else if (top > mid && mid < bot && top > bot)
		ft_rotate_up_a(stack_a);
	else if (top > mid && mid > bot)
	{
		ft_rotate_up_a(stack_a);
		ft_swap_a(stack_a);
	}
}
