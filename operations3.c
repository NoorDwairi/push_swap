/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 09:32:38 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/21 10:45:10 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	ra(t_stack *a)
{
	if (!a || a->size < 2)
		return (-1);
	rotate(a);
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack *b)
{
	if (!b || b->size < 2)
		return (-1);
	rotate(b);
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (0);
	if (a->size >= 2 || b->size >= 2)
	{
		rr(a, b);
		write(1, "rr\n", 3);
	}
	return (-1);
}

void	rotate(t_stack *test)
{
	t_node	*temp;
	t_node	*current;

	if (!test || test->size < 2 || !test->top || !test->top->next)
		return ;
	current = test->top;
	temp = test->top;
	while (current->next)
	{
		current = current->next;
	}
	current->next = test->top;
	test->top->next = NULL;
	test->top = temp->next;
}
