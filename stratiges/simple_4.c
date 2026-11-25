/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:03:02 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 13:26:05 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	move_back_to_a(t_stack *a, t_stack *b)
{
	t_node	*target;
	int		pos;

	while (b->size > 0)
	{
		target = find_target_in_a(a, b->top->rank);
		pos = get_position(a, target);
		if (pos < 0)
			return ;
		if (pos <= a->size / 2)
		{
			while (pos-- > 0)
				ra(a);
		}
		else
		{
			while (pos++ < a->size)
				rra(a);
		}
		pa(a, b);
	}
}

void	rotate_min_to_top(t_stack *a)
{
	t_node	*current;
	t_node	*min_node;
	int		pos;

	if (!a || !a->top)
		return ;
	current = a->top;
	min_node = current;
	while (current)
	{
		if (current->rank < min_node->rank)
			min_node = current;
		current = current->next;
	}
	pos = get_position(a, min_node);
	if (pos <= a->size / 2)
	{
		while (pos-- > 0)
			ra(a);
	}
	else
	{
		while (pos++ < a->size)
			rra(a);
	}
}

int	fill_stack_b(t_stack *a, t_stack *b)
{
	t_node	*target;

	pb(a, b);
	if (a->size > 3)
		pb(a, b);
	if (b->size >= 2 && b->top->rank < b->top->next->rank)
		rb(b);
	while (a->size > 3)
	{
		target = find_cheapest_move(a, b);
		if (!target)
			return (0);
		execute_move(a, b, target);
	}
	return (1);
}
