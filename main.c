/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:35:29 by yvieira-          #+#    #+#             */
/*   Updated: 2025/02/22 15:44:56 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
<<<<<<< HEAD
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	init_stack_a(&a, argv +1);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a, false);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			sort_stacks(&a, &b);
=======
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
>>>>>>> e613da43a923c694a66fc8f59d58d6fdeacc795a
	}
	sort_stacks(&stack_a, &stack_b);
	free_stacks(&stack_a);
	free_stacks(&stack_b);
	return (0);
}
<<<<<<< HEAD
=======

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
>>>>>>> e613da43a923c694a66fc8f59d58d6fdeacc795a
