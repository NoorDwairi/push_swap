/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <deema.lababneh@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:56:08 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/23 12:43:08 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;

typedef enum s_strategy
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE,
	INVALID
}					t_strategy;

typedef struct s_config
{
	double			disorder;
	t_strategy		selected;
	t_strategy		used;
	bool			bench;
	int				total_ops;
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_config;

typedef struct s_stack
{
	t_node			*top;
	int				size;
	t_config		*config;

}					t_stack;

void				swap(t_stack *test);
int					sa(t_stack *stack_a);
int					sb(t_stack *stack_b);
int					ss(t_stack *stack_a, t_stack *stack_b);
void				push(t_stack *dest, t_stack *src);
int					pa(t_stack *a, t_stack *b);
int					pb(t_stack *a, t_stack *b);
void				rotate(t_stack *test);
int					ra(t_stack *a);
int					rb(t_stack *b);
int					rr(t_stack *a, t_stack *b);
int					reverse_rotate(t_stack *test);
int					rra(t_stack *a);
int					rrb(t_stack *b);
int					rrr(t_stack *a, t_stack *b);

void				free_tokens(char **token);
int					count_tokens(char **tokens);
int					count_elements_updated(char **argv);
int					set_numbers(char **arr, char **temp_res, int k);
char				**set_arr(char **argv);
bool				validate_sign(char *arr);
bool				validate_digits(char *arr);
bool				validate_overflow(char *arr);
bool				validate_duplicate(char **arr);
int					validation(char **arr);
void				print_error(void);

t_node				*new_node(int value);
void				add_node_back(t_stack *stack, t_node *node);
void				init_stack(t_stack *s);
int					build_stack(t_stack *stack, char **arr);
void				free_stack(t_stack *s);
void				assign_ranks(t_stack *a);

void				init_config(t_config *cfg);
bool				is_flag(char *s);
int					apply_flag(char *ch, t_config *cfg);
int					parse_flags(char **argv, t_config *cfg);
char				*strategy_name(t_strategy strategy);
int					apply_strategy(char *ch, t_config *cfg);
double				compute_disorder(t_stack *a);
char				*measure_complexity(t_strategy used);
void				print_bench(t_stack *a);

void				sort_three(t_stack *a);
bool				is_sorted(t_stack *a);
t_node				*find_target_position(t_stack *b, int rank);
int					get_position(t_stack *b, t_node *target);
void				simple_sort(t_stack *a, t_stack *b);
int					max(int a, int b);
int					update_min_cost(int cost, int min_cost);
int					calculate_rotation_cases(t_stack *a, t_stack *b, int pos_a,
						int pos_b);
int					calculate_rotation_cost(t_stack *a, t_stack *b,
						t_node *candidate);
t_node				*find_cheapest_move(t_stack *a, t_stack *b);
void				rotate_forward(t_stack *a, t_stack *b, int pos_a,
						int pos_b);
void				rotate_backward(t_stack *a, t_stack *b, int back_a,
						int back_b);
void				rotate_mixed(t_stack *a, t_stack *b, int pos_a, int pos_b);
void				execute_move(t_stack *a, t_stack *b, t_node *candidate);
t_node				*find_target_in_a(t_stack *a, int rank);
void				move_back_to_a(t_stack *a, t_stack *b);
void				rotate_min_to_top(t_stack *a);

int					find_max_pos(t_stack *b);
void				push_to_top_b(t_stack *b);
void				push_back_to_a(t_stack *a, t_stack *b);
int					isqrt(int size);
int					chunk_size_calculator(int size);
bool				push_or_rotate(t_stack *a, t_stack *b, int limit);
void				push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size);
void				medium_sort(t_stack *a, t_stack *b);

void				radix_pass(t_stack *a, t_stack *b, int bit);
int					get_max_bits(t_stack *a);
int					fill_stack_b(t_stack *a, t_stack *b);
bool				is_bit_zero(int rank, int bit);
void				complex_sort(t_stack *a, t_stack *b);

#endif
