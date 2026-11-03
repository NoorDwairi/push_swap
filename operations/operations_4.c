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

int	rra(t_stack *a, t_bench *bench)
{
	if (!a || a->size < 2)
		return (-1);
	reverse_rotate(a);
	bench->rra++;
	bench->total_ops++;
	write(1, "rra\n", 4);
	return (0);
}

int	rrb(t_stack *b, t_bench *bench)
{
	if (!b || b->size < 2)
		return (-1);
	reverse_rotate(b);
	bench->rrb++;
	bench->total_ops++;
	write(1, "rrb\n", 4);
	return (0);
}

int	rrr(t_stack *a, t_stack *b, t_bench *bench)
{
	if (!a || !b)
		return (-1);
	if (a->size < 2 && b->size < 2)
		return (-1);
	reverse_rotate(a);
	reverse_rotate(b);
	bench->rrr++;
	bench->total_ops++;
	write(1, "rrr\n", 4);
	return (0);
}

void init_operations(t_bench *bench)
{
	bench->sa = 0;
	bench->sb = 0;
	bench->ss = 0;
	bench->pa = 0;
	bench->pb = 0;
	bench->ra = 0;
	bench->rb = 0;
	bench->rr = 0;
	bench->rra = 0;
	bench->rrb = 0;
	bench->rrr = 0;
	bench->total_ops = 0;
	bench->bench = 0;
	bench->strategy = "ADAPTIVE";
	disorder = 0;
}