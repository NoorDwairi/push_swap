/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:54:55 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/22 15:41:46 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	swap(t_stack *test)
{
	t_node	*temp;

	if (!test || test->size < 2 || !test->top)
		return ;
	temp = test->top->next;
	test->top->next = temp->next;
	temp->next = test->top;
	test->top = temp;
}

int	sa(t_stack *stack_a)
{
	if (!stack_a || stack_a->size < 2)
		return (-1);
	swap(stack_a);
	stack_a->config->sa++;
	stack_a->config->total_ops++;
	write(1, "sa\n", 3);
	return (0);
}

int	sb(t_stack *stack_b)
{
	if (!stack_b || stack_b->size < 2)
		return (-1);
	swap(stack_b);
	stack_b->config->sb++;
	stack_b->config->total_ops++;
	write(1, "sb\n", 3);
	return (0);
}

int	ss(t_stack *stack_a, t_stack *stack_b)
{
	if (!stack_a || !stack_b)
		return (-1);
	if (stack_a->size < 2 && stack_b->size < 2)
		return (-1);
	if (stack_a->size >= 2)
		swap(stack_a);
	if (stack_b->size >= 2)
		swap(stack_b);
	stack_a->config->ss++;
	stack_a->config->total_ops++;
	write(1, "ss\n", 3);
	return (0);
}

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
