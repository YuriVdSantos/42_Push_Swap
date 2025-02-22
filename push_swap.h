/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yvieira- <yvieira-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 21:31:26 by yvieira-          #+#    #+#             */
/*   Updated: 2025/02/22 15:15:17 by yvieira-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
<<<<<<< HEAD
# include "./libft/libft.h"
=======
# include "libft/libft.h"
>>>>>>> e613da43a923c694a66fc8f59d58d6fdeacc795a

typedef struct s_stacks
{
<<<<<<< HEAD
	int					nbr;
	int					index;
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}	t_stack_node;

int				error_syntax(char *str_n);
int				error_duplicate(t_stack_node *a, int n);
void			free_stack(t_stack_node **stack);
void			free_errors(t_stack_node **a);
void			init_stack_a(t_stack_node **a, char **argv);
void			init_nodes_a(t_stack_node *a, t_stack_node *b);
void			init_nodes_b(t_stack_node *a, t_stack_node *b);
void			current_index(t_stack_node *stack);
void			set_cheapest(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			prep_for_push(t_stack_node **s, t_stack_node *n, char c);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
bool			stack_sorted(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
void			sa(t_stack_node **a, bool print);
void			sb(t_stack_node **b, bool print);
void			ss(t_stack_node **a, t_stack_node **b, bool print);
void			ra(t_stack_node **a, bool print);
void			rb(t_stack_node **b, bool print);
void			rr(t_stack_node **a, t_stack_node **b, bool print);
void			rra(t_stack_node **a, bool print);
void			rrb(t_stack_node **b, bool print);
void			rrr(t_stack_node **a, t_stack_node **b, bool print);
void			pa(t_stack_node **a, t_stack_node **b, bool print);
void			pb(t_stack_node **b, t_stack_node **a, bool print);
void			sort_three(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);
void			rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a,
					t_stack_node **b,
					t_stack_node *cheapest_node);
void			move_a_to_b(t_stack_node **a, t_stack_node **b);
void			move_b_to_a(t_stack_node **a, t_stack_node **b);
void			min_on_top(t_stack_node **a);
=======
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
>>>>>>> e613da43a923c694a66fc8f59d58d6fdeacc795a

#endif