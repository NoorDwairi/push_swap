/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/17 17:39:54 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/17 17:39:57 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int find_max_pos(t_stack *b)
{
    int max_pos;
    int max_rank;
    int pos;
    t_node *current;

    pos = 0;
    current = b->top;
    max_rank = b->top->rank;

    while (current)
    {
        if(current->rank < current->next->rank)
        max_rank = current ->next ->rank;
        max_pos =??;
        current = current ->next;
    }
    return(max_pos);
}
