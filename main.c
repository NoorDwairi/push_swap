/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:35:45 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 12:41:43 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	**arr;

	arr = set_arr(argv);
	if (!arr)
		return (0);
	init_stack(&a);
	init_stack(&b);
	if (!validation(arr, count_tokens(arr)))
		return (free_tokens(arr), 0);
	if (!build_stack(&a, arr))
		return (free_tokens(arr), 0);
}
