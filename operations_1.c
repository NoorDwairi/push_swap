/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:54:55 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/21 09:34:52 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *test)
{
	t_node	*temp;

	temp = test->top->next;
	test->top->next = temp->next;
	temp->next = test->top;
	test->top = temp;
}

int	sa(t_stack *stack_a)
{
	if (stack_a->size < 2)
		return (-1);
	swap(stack_a);
	write(1, "sa\n", 3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}

int	sb(t_stack *stack_b)
{
	if (stack_b->size < 2)
		return (-1);
	swap(stack_b);
	write(1, "sb\n", 3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->size < 2 || stack_b->size < 2)
		return (-1);
	swap(stack_a);
	swap(stack_b);
	write(1, "ss\n", 3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}
