/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bench.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/25 11:05:19 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/25 11:05:29 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	print_two_digits(int n)
{
	if (n < 10)
		ft_putchar_fd('0', 2);
	ft_putnbr_fd(n, 2);
}

static void	print_disorder(t_stack *a)
{
	int	disorder;

	disorder = (int)(a->config->disorder * 10000 + 0.5);
	ft_putstr_fd("[bench] disorder: ", 2);
	ft_putnbr_fd(disorder / 100, 2);
	ft_putchar_fd('.', 2);
	print_two_digits(disorder % 100);
	ft_putstr_fd("%\n", 2);
}

static void	print_basic_counts(t_config *config)
{
	ft_putstr_fd("[bench] total_ops: ", 2);
	ft_putnbr_fd(config->total_ops, 2);
	ft_putchar_fd('\n', 2);
	ft_putstr_fd("[bench] sa: ", 2);
	ft_putnbr_fd(config->sa, 2);
	ft_putstr_fd(" sb: ", 2);
	ft_putnbr_fd(config->sb, 2);
	ft_putstr_fd(" ss: ", 2);
	ft_putnbr_fd(config->ss, 2);
	ft_putstr_fd(" pa: ", 2);
	ft_putnbr_fd(config->pa, 2);
	ft_putstr_fd(" pb: ", 2);
	ft_putnbr_fd(config->pb, 2);
	ft_putchar_fd('\n', 2);
}

static void	print_rotation_counts(t_config *config)
{
	ft_putstr_fd("[bench] ra: ", 2);
	ft_putnbr_fd(config->ra, 2);
	ft_putstr_fd(" rb: ", 2);
	ft_putnbr_fd(config->rb, 2);
	ft_putstr_fd(" rr: ", 2);
	ft_putnbr_fd(config->rr, 2);
	ft_putstr_fd(" rra: ", 2);
	ft_putnbr_fd(config->rra, 2);
	ft_putstr_fd(" rrb: ", 2);
	ft_putnbr_fd(config->rrb, 2);
	ft_putstr_fd(" rrr: ", 2);
	ft_putnbr_fd(config->rrr, 2);
	ft_putchar_fd('\n', 2);
}

void	print_bench(t_stack *a)
{
	if (!a || !a->config)
		return ;
	print_disorder(a);
	ft_putstr_fd("[bench] strategy: ", 2);
	ft_putstr_fd(strategy_name(a->config->selected), 2);
	ft_putstr_fd(" / ", 2);
	ft_putstr_fd(measure_complexity(a->config->used), 2);
	ft_putchar_fd('\n', 2);
	print_basic_counts(a->config);
	print_rotation_counts(a->config);
}
