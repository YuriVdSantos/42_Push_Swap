#include "push_swap.h"

void	ft_swap_a(t_stack *stack_a)
{
	long	temp;

	if (stack_a->last_idx < 1)
		return ;
	temp = stack_a->array[stack_a->last_idx];
	stack_a->array[stack_a->last_idx] = stack_a->array[stack_a->last_idx - 1];
	stack_a->array[stack_a->last_idx - 1] = temp;
	ft_printf("sa\n");
}

void	ft_swap_b(t_stack *stack_b)
{
	long	temp;

	if (stack_b->last_idx < 1)
		return ;
	temp = stack_b->array[stack_b->last_idx];
	stack_b->array[stack_b->last_idx] = stack_b->array[stack_b->last_idx - 1];
	stack_b->array[stack_b->last_idx - 1] = temp;
	ft_printf("sb\n");
}

void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	ft_printf("ss\n");
}

void	ft_place_in_a(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_b->last_idx < 1)
		return ;
	stack_a->last_idx++;
	stack_a->array[stack_a->last_idx] = stack_b->array[stack_b->last_idx];
	stack_b->array[stack_b->last_idx] = 42000000000;
	stack_b->last_idx--;
	ft_printf("pa\n");
}

void	ft_place_in_b(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->last_idx < 0)
		return ;
	stack_b->last_idx++;
	stack_b->array[stack_b->last_idx] = stack_a->array[stack_a->last_idx];
	stack_a->array[stack_a->last_idx] = 42000000000;
	stack_a->last_idx--;
	ft_printf("pb\n");
}
