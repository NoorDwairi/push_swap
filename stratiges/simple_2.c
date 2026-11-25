/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:00:03 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 13:25:39 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	update_min_cost(int cost, int min_cost)
{
	if (cost < min_cost)
		return (cost);
	return (min_cost);
}

int	calculate_rotation_cases(t_stack *a, t_stack *b, int pos_a, int pos_b)
{
	int	back_a;
	int	back_b;
	int	min_cost;

	if (pos_a < 0 || pos_b < 0)
		return (-1);
	back_a = 0;
	back_b = 0;
	if (pos_a != 0)
		back_a = a->size - pos_a;
	if (pos_b != 0)
		back_b = b->size - pos_b;
	min_cost = max(pos_a, pos_b);
	min_cost = update_min_cost(max(back_a, back_b), min_cost);
	min_cost = update_min_cost(pos_a + back_b, min_cost);
	return (update_min_cost(back_a + pos_b, min_cost));
}

int	calculate_rotation_cost(t_stack *a, t_stack *b, t_node *candidate)
{
	t_node	*target;
	int		pos_a;
	int		pos_b;
	int		min_cost;

	if (!a || !b || !candidate || !a->top || !b->top)
		return (-1);
	target = find_target_position(b, candidate->rank);
	if (!target)
		return (-1);
	pos_a = get_position(a, candidate);
	pos_b = get_position(b, target);
	if (pos_a < 0 || pos_b < 0)
		return (-1);
	min_cost = calculate_rotation_cases(a, b, pos_a, pos_b);
	return (min_cost);
}

t_node	*find_cheapest_move(t_stack *a, t_stack *b)
{
	t_node	*current;
	t_node	*cheapest_node;
	int		cost;
	int		min_cost;

	current = a->top;
	min_cost = INT_MAX;
	cheapest_node = NULL;
	while (current)
	{
		cost = calculate_rotation_cost(a, b, current);
		if (cost >= 0 && cost < min_cost)
		{
			min_cost = cost;
			cheapest_node = current;
		}
		current = current->next;
	}
	return (cheapest_node);
}
