#include "push_swap.h"

void	ft_rotate_up_a(t_stack *stack_a)
{
	long	temp;

	if (stack_a->last_idx <= 0)
		return ;
	temp = stack_a->array[stack_a->last_idx];
	ft_memmove
	(
		&stack_a->array[1], \
		&stack_a->array[0], \
		sizeof(long) * stack_a->last_idx
	);
	stack_a->array[0] = temp;
	ft_printf("ra\n");
}

void	ft_rotate_up_b(t_stack *stack_b)
{
	long	temp;

	if (stack_b->last_idx <= 1)
		return ;
	temp = stack_b->array[stack_b->last_idx];
	ft_memmove
	(
		&stack_b->array[2], \
		&stack_b->array[1], \
		sizeof(long) * stack_b->last_idx - 2
	);
	stack_b->array[1] = temp;
	stack_b->array[stack_b->last_idx + 1] = 42000000000;
	ft_printf("rb\n");
}

void	ft_rotate_up_ab(t_stack *stack_a, t_stack *stack_b)
{
	ft_rotate_up_a(stack_a);
	ft_rotate_up_b(stack_b);
	ft_printf("rr");
}

void	ft_rotate_down_a(t_stack *stack_a)
{
	long	temp;
	int		last_idx;

	if (stack_a->last_idx <= 0)
		return ;
	last_idx = stack_a->last_idx;
	temp = stack_a->array[0];
	ft_memmove
	(
		&stack_a->array[0], \
		&stack_a->array[1], \
		sizeof(long) * last_idx
	);
	stack_a->array[last_idx] = temp;
	ft_printf("rra\n");
}

void	ft_rotate_down_b(t_stack *stack_b)
{
	long	temp;
	int		last_idx;

	if (stack_b->last_idx <= 0)
		return ;
	last_idx = stack_b->last_idx;
	temp = stack_b->array[1];
	ft_memmove
	(
		&stack_b->array[1], \
		&stack_b->array[2], \
		sizeof(long) * last_idx - 2
	);
	stack_b->array[last_idx] = temp;
	ft_printf("rrb\n");
}
