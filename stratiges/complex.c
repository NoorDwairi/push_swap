/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <deema.lababneh@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 01:34:14 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/23 12:48:27 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_pass(t_stack *a, t_stack *b, int bit)
{
	int	size;

	if (!a || !b || a->size <= 0)
		return ;
	size = a->size;
	while (size > 0)
	{
		if (is_bit_zero(a->top->rank, bit))
			pb(a,b);
		else
			ra(a);
		size--;
	}
	if (!b)
		return ;
	while (b->size > 0)
	{
		pa(a,b);
	}
}

int	get_max_bits(t_stack *a)
{
	int	max_bits;
	int	max_rank;

	if (!a || a->size <= 0)
		return (0);
	max_rank = a->size - 1;
	max_bits = 0;
	while (max_rank > 0)
	{
		max_rank = max_rank >> 1;
		max_bits++;
	}
	return (max_bits);
}

bool	is_bit_zero(int rank, int bit)
{
	if (((rank >> bit) & 1) == 0)
		return (true);
	return (false);
}

void	complex_sort(t_stack *a, t_stack *b)
{
	int	max_bits;
	int	bit;

	if (!a || !b || a->size <= 0)
		return ;
	if (is_sorted(a))
		return ;
	max_bits = get_max_bits(a);
	bit = 0;
	while (bit < max_bits)
	{
		radix_pass(a, b, bit);
		bit++;
	}
}
