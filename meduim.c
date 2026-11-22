/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meduim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:12:58 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/22 16:21:45 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	isqrt(int size)
{
	int	i;
	i = 0;
	while ((i + 1) * (i + 1) <= size)
		i++;
	return (i);
}

int	chunk_size_calculator(int size)
{
	int	chunk;

	chunk = isqrt(size);
	if (chunk < 1)
		chunk = 1;
	return (chunk);
}

bool	push_or_rotate(t_stack *a, t_stack *b, int limit)
{
	if (a->top->rank < limit)
	{
		pb(a, b);
		return (1);
	}
	ra(a);
	return (0);
}

void	push_chunks_to_b(t_stack *a, t_stack *b, int chunk_size)
{
	int	pushed;
	int	limit;

	if (!a || !b || chunk_size <= 0)
		return ;
	limit = chunk_size;
	pushed = 0;
	while (a->top)
	{
		if (push_or_rotate(a, b, limit) == 1)
			pushed++;
		if (pushed == chunk_size)
		{
			limit += chunk_size;
			pushed = 0;
		}
	}
}

void	medium_sort(t_stack *a, t_stack *b)
{
	int	chunk_size;
	if (!a || !b || a->size < 2)
		return ;
	chunk_size = chunk_size_calculator(a->size);
	push_chunks_to_b(a, b, chunk_size);
	push_back_to_a(a, b);
}
