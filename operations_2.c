/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:27:27 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/03 13:00:47 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	push(t_stack *dest, t_stack *src)
{
	t_node	*temp;

	temp = src->top;
	src->top = src->top->next;
	temp->next = dest->top;
	dest->top = temp;
	src->size--;
	dest->size++;
}

int	pa(t_stack *a, t_stack *b)
{
	if (!a || !b || !b->top)
		return (-1);
	push(a, b);
	write(1, "pa\n", 3);
	a->config->pa++;
	a->config->total_ops++;
	return (0);
}

int	pb(t_stack *a, t_stack *b)
{
	if (!a || !b || !a->top)
		return (-1);
	push(b, a);
	write(1, "pb\n", 3);
	a->config->pb++;
	a->config->total_ops++;
	return (0);
}
