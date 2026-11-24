/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:54 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/23 12:49:05 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	find_max_pos(t_stack *b)
{
	int		max_pos;
	int		max_rank;
	int		pos;
	t_node	*current;

	pos = 0;
	current = b->top;
	max_rank = b->top->rank;
	max_pos = 0;
	while (current)
	{
		if (current->rank > max_rank)
		{
			max_rank = current->rank;
			max_pos = pos;
		}
		pos++;
		current = current->next;
	}
	return (max_pos);
}

void	push_to_top_b(t_stack *b)
{
	int	pos;
	int	count;

	if (!b || !b->top)
		return ;
	pos = find_max_pos(b);
	if (pos < 0)
		return ;
	if (pos <= b->size / 2)
	{
		count = pos;
		while (count > 0)
		{
			rb(b);
			count--;
		}
	}
	else
	{
		count = b->size - pos;
		while (count > 0)
		{
			rrb(b);
			count--;
		}
	}
}

void	push_back_to_a(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return ;
	while (b->top)
	{
		push_to_top_b(b);
		pa(a, b);
	}
}
