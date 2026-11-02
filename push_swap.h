/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 08:56:08 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/31 12:12:32 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>

typedef struct s_node
{
	int				value;
	int				rank;
	struct s_node	*next;
}					t_node;
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

// I add a struct to check weather there is a flag stands for chosen strategy 
// or to use the default one <ADAPTIVE>

typedef  enum s_strategy 
{
	SIMPLE,
	MEDIUM,
	COMPLEX,
	ADAPTIVE
}	t_strategy;

typedef struct  s_bench
{

    double  disorder;
    int     total_ops;
    int     sa;
    int     sb;
    int     ss;
    int     pa;
    int     pb;
    int     ra;
    int     rb;
    int     rr;
    int     rra;
    int     rrb;
    int     rrr;
} t_bench ;




void	swap(t_stack *test);
int	sa(t_stack *stack_a);
int	sb(t_stack *stack_b);
int	ss(t_stack *stack_a, t_stack *stack_b);
void	push(t_stack *dest, t_stack *src);
int	pa(t_stack *b, t_stack *a);
int	pb(t_stack *b, t_stack *a);
int	ra(t_stack *a);
int	rb(t_stack *b);
int	rr(t_stack *a, t_stack *b);
void	rotate(t_stack *test);
int	reverse_rotate(t_stack *test);
int	rra(t_stack *a);
int	rrb(t_stack *b);
int	rrr(t_stack *a, t_stack *b);
void	free_tokens(char **token);
int	count_tokens(char **tokens);
int	count_elements_updated(char **argv);
int	set_numbers(char **arr, char **temp_res, int k);
char	**set_arr(char **argv);
t_node	*new_node(int value);
void 	add_node_back(t_stack *stack, t_node *node);
void 	init_stack(t_stack *s);
int    build_stack(t_stack *stack, char **arr);
void    assign_ranks(t_stack *a);
bool	validate_sign(char *arr);
bool	validate_digits(char *arr);
bool	validate_overflow(char *arr);
int	validation(char **arr);
bool	validate_duplicate(char **arr);
void free_stack(t_stack *s);
void	free_arr(char **arr);
int     ft_atoi(const char *nptr);
double compute_disorder(t_stack *a);

#endif

