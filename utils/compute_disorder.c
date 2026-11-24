/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_disorder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/22 13:07:14 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/23 13:18:17 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	assign_ranks(t_stack *a)
{
	t_node	*current;
	t_node	*compare;
	int		rank;

	if (!a)
		return ;
	current = a->top;
	while (current)
	{
		rank = 0;
		compare = a->top;
		while (compare)
		{
			if (current->value > compare->value)
				rank++;
			compare = compare->next;
		}
		current->rank = rank;
		current = current->next;
	}
}

double	compute_disorder(t_stack *a)
{
	int		mistake;
	int		total_pairs;
	t_node	*current;
	t_node	*compare;

	if (!a || a->size < 2)
		return (0.0);
	current = a->top;
	mistake = 0;
	total_pairs = 0;
	while (current)
	{
		compare = current->next;
		while (compare)
		{
			total_pairs += 1;
			if (current->rank > compare->rank)
				mistake += 1;
			compare = compare->next;
		}
		current = current->next;
	}
	return ((double)mistake / total_pairs);
}

char	*measure_complexity(t_strategy used)
{
	if (used == SIMPLE)
		return ("O(n²)");
	if (used == MEDIUM)
		return ("O(n√n)");
	if (used == COMPLEX)
		return ("O(n log n)");
	return ("Unknown");
}

