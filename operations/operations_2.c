/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:32:38 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/22 12:47:57 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

int	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return (-1);
	rotate(a);
	a->config->ra++;
	a->config->total_ops++;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return (-1);
	rotate(b);
	b->config->rb++;
	b->config->total_ops++;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (-1);
	if (a->size < 2 && b->size < 2)
		return (-1);
	if (a->size >= 2)
		rotate(a);
	if (b->size >= 2)
		rotate(b);
	a->config->rr++;
	a->config->total_ops++;
	write(1, "rr\n", 3);
	return (0);
}

void	rotate(t_stack *test)
{
	t_node	*temp;
	t_node	*current;

	if (!test || test->size < 2 || !test->top || !test->top->next)
		return ;
	temp = test->top->next;
	current = test->top;
	while (current->next)
		current = current->next;
	current->next = test->top;
	test->top->next = NULL;
	test->top = temp;
}
