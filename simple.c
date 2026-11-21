/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <deema.lababneh@learner.42.tech>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:54:54 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/19 21:22:15 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
//simple_sort()
//find_target_position()
//find_cheapest_move()
//calculate_rotation_cost()
//execute_move()
//sort_three()
//move_back_to_a()
//rotate_min_to_top()


void sort_three( t_stack * a)
{
    t_node *max_node;
    if(!a || a-> size != 3)
    return;
    max_node = a-> top;
    if(max_node ->rank < a->top ->next->rank)
        max_node = a->top ->next;

    if(max_node ->rank < a->top ->next->next->rank)
       max_node = a->top ->next->next;
    if (max_node == a->top)
       ra(a);
    else if (max_node ==a->top->next)
       rra(a);
    if (a->top->rank > a->top->next->rank)
		sa(a);
}

t_node  *find_target_position(t_stack *b, int rank)
{
    t_node *current;
    t_node *target;
    t_node *max_node;
    
    if (!b || !b->top)
        return (NULL);
    current = b->top;
    target = NULL;
    max_node = current;
    while(current)
    {
        if(current->rank > max_node->rank)
            max_node= current;
        if(current->rank < rank)
            if(!target || current->rank > target->rank)
                target = current;
        current = current->next;
    }
    if (target)
        return (target);
    return (max_node);
}

int     get_position(t_stack *b, t_node *target)
{
    t_node *current;
    int pos;

    pos = 0;
    if(!b || !target || !b->top)
        return(-1);
    current = b->top ;
    while(current)
    {
        if (target->value == current->value && target->rank == current->rank)
            return(pos);
        current = current->next;
        pos++;
    }
    return(-1);
}

bool    is_sorted(t_stack *a)
{
    if (!a || !a->top)
        return (true);
    t_node *current;
    current = a->top;
    while(current->next)
    {
        if (current->rank > current->next->rank)
            return(false);
        current = current->next;
    }
    return(true);
}
 
int     calculate_rotation_cost(t_stack *a, t_stack *b)
{
    t_node *current;
    t_node *target;
    int pos;

    if (!a || !b || !a->top || !b->top)
        return(-1);
    current = a->top;
    while(current)
    {
        target = find_target_position(b, current->rank);
        pos_a = get_position(a, current);
        pos_b = get_position(b, target);
        current = current->next;
    }
    return(0);
}

void    simple_sort(t_stack *a, t_stack *b)
{
    t_node *target;
    int pos;
    
    if (is_sorted(a))
        return;
    if (a->size <= 3)
    {
        sort_three(a);
        return ;
    }
    pb(a, b);
    pb(a, b);
    //b->size >= 2 && in the condition below is for checking weather I am trying to access a valid nodes 
    if (b->size >= 2 && b->top->rank < b->top->next->rank)
        rb(b);
    while(a->size > 3)  
    {
        //|-- Find target position
        //|-- Calculate rotation costs
        calculate_rotation_cost(a, b);
        //|-- Find cheapest move
        find_cheapest_move(a, b, chosen);
        //|-- Execute cheapest move
        execute_move(a, b);
    }
    sort_three(a);
    move_back_to_a(b, a);
    //rotate a until the smallest element is at the top
    rotate_min_to_top(a);
}
if(a->size <= 3)
    sort_three(a);

