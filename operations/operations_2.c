/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:27:27 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/21 09:36:18 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

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

int	pa(t_stack *b, t_stack *a)
{
	if (b->size == 0)
		return (-1);
	push(a, b);
	write(1, "pa\n", 3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}

int	pb(t_stack *b, t_stack *a)
{
	if (a->size == 0)
		return (-1);
	push(b, a);
	write(1, "pb\n", 3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}
