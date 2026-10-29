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

void    assign_ranks(t_stack *a)
{
	t_node		*current;
	t_node		*compare;
	int		rank;

	current = a->top;
	while(current)
	{
		rank = 0;
		compare = a -> top;
		while(compare)
		{
			if(current-> value > compare-> value)
			rank++;
		compare = compare -> next;
		}
		current -> rank = rank;
		current = current -> next;
	}

}