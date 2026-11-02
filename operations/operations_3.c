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

int	ra(t_stack *a, t_bench *bench)
{
	if (!a || a->size < 2)
		return (-1);
	rotate(a);
	bench->ra++;
	bench->total_ops++;
	write(1, "ra\n", 3);
	return (0);
}

int	rb(t_stack *b, t_bench *bench)
{
	if (!b || b->size < 2)
		return (-1);
	rotate(b);
	bench->rb++;
    bench->total_ops++;
	write(1, "rb\n", 3);
	return (0);
}

int	rr(t_stack *a, t_stack *b, t_)
{
	if (!a || !b)
		return (-1);
	if (a->size < 2  || b->size < 2)
	return(-1);
	rotate(a);
	rotate(b);
	bench->rr++;
	bench->total_ops++;
	write(1,"rr\n",3);
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