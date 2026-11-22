/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <deema.lababneh@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:54:54 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 13:25:52 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_three(t_stack *a)
{
	t_node	*max_node;

	if (!a || a->size != 3)
		return ;
	max_node = a->top;
	if (max_node->rank < a->top->next->rank)
		max_node = a->top->next;
	if (max_node->rank < a->top->next->next->rank)
		max_node = a->top->next->next;
	if (max_node == a->top)
		ra(a);
	else if (max_node == a->top->next)
		rra(a);
	if (a->top->rank > a->top->next->rank)
		sa(a);
}

bool	is_sorted(t_stack *a)
{
	t_node	*current;

	if (!a || !a->top)
		return (true);
	current = a->top;
	while (current->next)
	{
		if (current->rank > current->next->rank)
			return (false);
		current = current->next;
	}
	return (true);
}

t_node	*find_target_position(t_stack *b, int rank)
{
	t_node	*current;
	t_node	*target;
	t_node	*max_node;

	if (!b || !b->top)
		return (NULL);
	current = b->top;
	target = NULL;
	max_node = current;
	while (current)
	{
		if (current->rank > max_node->rank)
			max_node = current;
		if (current->rank < rank)
			if (!target || current->rank > target->rank)
				target = current;
		current = current->next;
	}
	if (target)
		return (target);
	return (max_node);
}

int	get_position(t_stack *b, t_node *target)
{
	t_node	*current;
	int		pos;

	pos = 0;
	if (!b || !target || !b->top)
		return (-1);
	current = b->top;
	while (current)
	{
		if (target->value == current->value && target->rank == current->rank)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

void	simple_sort(t_stack *a, t_stack *b)
{
	t_node	*target;

	if (!a || !b || !a->top)
		return ;
	if (is_sorted(a))
		return ;
	if (a->size == 2)
	{
		if (a->top->rank > a->top->next->rank)
			sa(a);
		return ;
	}
	if (a->size == 3)
	{
		sort_three(a);
		return ;
	}
	pb(a, b);
	pb(a, b);
	if (b->size >= 2 && b->top->rank < b->top->next->rank)
		rb(b);
	while (a->size > 3)
	{
		target = find_cheapest_move(a, b);
		if (!target)
			return ;
		execute_move(a, b, target);
	}
	sort_three(a);
	move_back_to_a(a, b);
	rotate_min_to_top(a);
}
