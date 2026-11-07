/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/07 14:54:54 by dlababne          #+#    #+#             */
/*   Updated: 2026/11/07 14:54:57 by dlababne         ###   ########.fr       */
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

void    simple_sort(t_stack *a, t_stack *b)
{
    pb(a, b);
    pb(a, b);
    //b->size >= 2 && in the condition below is for checking weather I am trying to access a valid nodes 
    if (b->size >= 2 && b->top->rank < b->top->next->rank)
        rb(b);
    while(a->size > 3)
    {
        //|-- Find target position
        find_target_position(a, b);
        //|-- Calculate rotation costs
        calculate_rotation_cost(a, b);
        //|-- Find cheapest move
        find_cheapest_move(a, b);
        //|-- Execute cheapest move
        execute_move(a, b);
    }
    sort_three(a);
    move_back_to_a(b, a);
    //rotate a until the smallest element is at the top
    rotate_min_to_top(a);
}