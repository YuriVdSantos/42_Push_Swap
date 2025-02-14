#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stacks
{
	long	*array;
	int		last_idx;
	int		position_top;
	int		position_bottom;
	int		target_pos;
}	t_stack;

int		verification(int argc, char *argv[]);
int		main(int argc, char **argv);
long	ft_atoi_modified(const char *nptr);
int		*convert_to_int(int argc, char **argv);
void	inicialize_stack_a(t_stack *stack_a, int argc, char **argv);
int		ft_strcmp(const char *s1, const char *s2);
char	**fill_array(char **argv, int argc);
int		duplication_ver(int argc, char **array);
void	free_array(char **array);
void	inicialize_stack_b(t_stack *stack_b, int argc, char **argv);
long	*normalize_array(t_stack *stack_a);
void	free_stacks(t_stack *stack);

/*moves*/

void	ft_swap_a(t_stack *stack_a);
void	ft_swap_b(t_stack *stack_b);
void	ft_swap_ss(t_stack *stack_a, t_stack *stack_b);
void	ft_place_in_a(t_stack *stack_a, t_stack *stack_b);
void	ft_place_in_b(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_up_a(t_stack *stack_a);
void	ft_rotate_up_b(t_stack *stack_b);
void	ft_rotate_up_ab(t_stack *stack_a, t_stack *stack_b);
void	ft_rotate_down_a(t_stack *stack_a);
void	ft_rotate_down_b(t_stack *stack_b);
void	ft_rotate_down_ab(t_stack *stack_a, t_stack *stack_b);

/*sorting*/
int		is_sorted(t_stack *stack);
void	sort_stacks(t_stack *stack_a, t_stack *stack_b);
void	sort_all(t_stack *stack_a, t_stack *stack_b);
void	sort_three(t_stack *stack_a);
void	sort_three_utils(int top, int mid, int bot, t_stack *stack_a);
void	find_the_smallest_5(t_stack *stack_a);
void	push_the_small_5(t_stack *stack_a, t_stack *stack_b);
void	push_the_small_23(t_stack *stack_a, t_stack *stack_b);
long	temp_bottom_function_5(t_stack *stack_a);
void	find_the_smallest_22(t_stack *stack_a);
long	temp_bottom_function(t_stack *stack_a);
void	check_position_place_in_b(t_stack *stack_a, long temp_top, \
		long temp_bottown);
void	return_to_a_sorted(t_stack *stack_a, t_stack *stack_b);
void	find_the_target_number(t_stack *stack_b);
void	radix_sort(t_stack *stack_a, t_stack *stack_b);

#endif