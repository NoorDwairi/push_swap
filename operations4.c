/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/21 17:27:26 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/21 17:27:28 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

int	reverse_rotate(t_stack *test)
{
	t_node	*temp;
	t_node	*current;

	if (!test || test->size < 2 || !test->top || !test->top->next)
		return (-1);
	current = test->top;
	while (current->next)
	{
		if (current->next->next == NULL)
		{
			temp = current->next;
			current->next = NULL;
			break ;
		}
		current = current->next;
	}
	temp->next = test->top;
	test->top = temp;
	return (0);
}

int	rra(t_stack *a)
{
	if (!a || a->size < 2)
		return (-1);
	reverse_rotate(a);
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack *b)
{
	if (!b || b->size < 2)
		return (-1);
	reverse_rotate(b);
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack *a, t_stack *b)
{
	if (!a || !b)
		return (-1);
	if (a->size < 2 && b->size < 2)
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	write(1, "rrr\n", 4);
	return (0);
}
