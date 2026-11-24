/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:27:29 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/23 13:27:32 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static char	**prepare_input(char **args)
{
	char	**arr;

	arr = set_arr(args);
	if (!arr)
		return (print_error(), NULL);
	if (!validation(arr))
	{
		free_tokens(arr);
		return (NULL);
	}
	return (arr);
}

static int	init_stacks(t_stack *a, t_stack *b, t_config *cfg, char **arr)
{
	int	ok;

	init_stack(a);
	init_stack(b);
	a->config = cfg;
	b->config = cfg;
	ok = build_stack(a, arr);
	free_tokens(arr);
	return (ok);
}

static t_strategy	pick_strategy(t_config *cfg)
{
	if (cfg->selected != ADAPTIVE)
		return (cfg->selected);
	if (cfg->disorder < 0.2)
		return (SIMPLE);
	if (cfg->disorder < 0.5)
		return (MEDIUM);
	return (COMPLEX);
}

static void	run_sort(t_stack *a, t_stack *b)
{
	t_config	*cfg;

	cfg = a->config;
	assign_ranks(a);
	cfg->disorder = compute_disorder(a);
	cfg->used = pick_strategy(cfg);
	if (is_sorted(a))
		return ;
	if (cfg->used == SIMPLE)
		simple_sort(a, b);
	else if (cfg->used == MEDIUM)
		medium_sort(a, b);
	else
		complex_sort(a, b);
}

int	main(int argc, char **argv)
{
	t_stack		a;
	t_stack		b;
	t_config	cfg;
	char		**arr;
	int			n;

	if (argc < 2)
		return (0);
	init_config(&cfg);
	n = parse_flags(argv, &cfg);
	if (n < 0)
		return (print_error(), 1);
	if (!argv[n + 1])
		return (0);
	arr = prepare_input(argv + n);
	if (!arr)
		return (1);
	if (!init_stacks(&a, &b, &cfg, arr))
		return (print_error(), 1);
	run_sort(&a, &b);
	if (cfg.bench)
		print_bench(&a);
	free_stack(&a);
	free_stack(&b);
	return (0);
}