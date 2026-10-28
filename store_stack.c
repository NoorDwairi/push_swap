/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:03:42 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/27 14:03:44 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_node *new_node(int value)
{
    t_node *node;
    node = malloc(sizeof(t_node));
    if(!node)
    return(NULL);
    node -> value = value;
    node ->next = NULL;
    return (node);

}
//🇯🇴
void add_back(t_stack *stack , t_node *node)
{
    t_node *last;
    if(!stack->top)
    {
        stack-> top = node;
        stack->size ++;
    }
    last = stack->top;
    while( last->next != NULL)
    {
        last = last ->next;
    }
    last ->next = node;
    stack->size++;

}
t_stack * build_stack(char **arr ,int size)
{

}