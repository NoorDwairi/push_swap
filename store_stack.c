/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 14:03:42 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/31 12:11:26 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
#include <stdlib.h>

// we do not use the rank until we do the startigies 

t_node	*new_node(int value)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->next = NULL;
	node -> rank = 0;
	return (node);
}
//🇯🇴
void 	add_node_back(t_stack *stack, t_node *node)
{
	t_node	*last;
	if(!stack || !node)
		return;
	if (!stack->top)
	{
		stack->top = node;
	}
	else
	{
		last = stack->top;
		while (last->next != NULL)
		{
			last = last->next;
		}
		last->next = node;
	}
	stack->size++;
}

void 	init_stack(t_stack *s)
{
	s->top = NULL;
	s->size =0;
	s->config = NULL;
}

int    build_stack(t_stack *stack, char **arr)
{
	int i;
	t_node *n;

	i = 0;
	while(arr[i])
	{
		n = new_node(ft_atoi(arr[i]));
		if(!n)
		{
			free_stack(stack);
			return(0);
		}
		add_node_back(stack, n);
		i++;
	}
	return (1);
}

