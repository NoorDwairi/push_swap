/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/20 10:54:55 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/20 16:58:22 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void swap(t_stack *stack)
{
	t_node *temp;
	if(stack->size < 2)
		return ;
	temp =stack-> top->next;
	stack->top->next =  temp ->next;
	temp->next = stack->top;
	stack ->top =temp;
}
int sa(t_stack *stack_a)
{
	if (stack_a -> size < 2)
		return (-1);
	swap(stack_a);
	write(1,"sa\n",3);
	return (0); // at the beginning cuz we will declare a counter maybe ;)
}
int sb(t_stack *stack_b)
{
        if (stack_b -> size < 2)
                return (-1);
        swap(stack_b);
        write(1,"sb\n",3);
        return (0); // at the beginning cuz we will declare a counter maybe ;)
}
int ss(t_stack *stack_a,t_stack *stack_b)
{
        if (stack_a-> size <2 ||stack_b -> size < 2)
                return (-1);
        swap(stack_a);
	swap(stack_b);

        write(1,"ss\n",3);
        return (0); // at the beginning cuz we will declare a counter maybe ;)
}

void push(t_stack *dest ,t_stack *src)
{
	t_node temp;
	if(src->size == 0)
		return ;
	temp = src-> top;
	src->top = src->top->next;
	dest -> top = temp;




~
