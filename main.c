#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	stack_a;
	t_stack	stack_b;

	if (argc == 1 || argv == NULL)
		return (0);
	if (verification(argc, argv) == -1)
	{
		perror("Error: Invalid input");
		exit(EXIT_FAILURE);
	}
	inicialize_stack_a(&stack_a, argc, argv);
	inicialize_stack_b(&stack_b, argc, argv);
	if (!stack_b.array)
	{
		free_stacks(&stack_a);
		exit(EXIT_FAILURE);
	}
	sort_stacks(&stack_a, &stack_b);
	free_stacks(&stack_a);
	free_stacks(&stack_b);
	return (0);
}

long	*convert_to_long(int argc, char **argv)
{
	long	*array;
	int		i;

	if (argc < 2)
		return (NULL);
	array = (long *) malloc((argc - 1) * sizeof(long));
	if (!(array))
		return (NULL);
	i = 0;
	while (i < (argc - 1))
	{
		array[i] = ft_atoi_modified(argv[argc - 1 - i]);
		if (array[i] == 42000000000)
		{
			free(array);
			return (NULL);
		}
	}
	return (array);
}

void	inicialize_stack_a(t_stack *stack_a, int argc, char **argv)
{
	long	*temp;

	temp = convert_to_long(argc, argv);
	stack_a->array = temp;
	if (stack_a->array == NULL)
	{
		perror("Error: Memory allocation failed in convert_to_long");
		exit(EXIT_FAILURE);
	}
	stack_a->last_idx = argc - 2;
	stack_a->array = normalize_array(stack_a);
	free(temp);
}

void	inicialize_stack_b(t_stack *stack_b, int argc, char **argv)
{
	int	i;

	i = -1;
	stack_b->array = (long *) malloc((argc - 1) * sizeof(long));
	if (!stack_b->array)
		return ;
	while (++i < (argc - 1))
		stack_b->array[i] = 42000000000;
	stack_b->last_idx = 0;
}

void	free_stacks(t_stack *stack)
{
	if (stack->array)
		free(stack->array);
}
