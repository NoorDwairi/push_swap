/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   meduim.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/16 13:12:58 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/16 13:13:00 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

//i will use a chunk based sorting

int chunk_size_calculator(int size )
{
    int chunk_size;
    if (size <= 100)
    chunk_size = size / 5;
    else 
    chunk_size = size / 11;

    if (chunk_size < 1)
    chunk_size = 1;
    return (chunk_size);
    
}

bool push_or_rotate(t_stack *a, t_stack *b,int limit)
{
    
}
void push_chunks_to_b(t_stack *a, t_stack *b , int chunck_size)
{
    int min_chunk;
    int max_chunck;
    int pushed_count;
    
    if(!a || !b)
    return;
    pushed_count=0;
    min_chunk =0;
    max_chunck = chunck_size;
    while (a->top)
    {
        if( a->top->rank > min_chunk && a->top -> rank <= max_chunck)
        {
            pb(a);
            pushed_count++;
        }
            else if(current->rank < min_chunk)
        {
            pb(b);
            rb(b);
            pushed_count++;
        }
        else
        ra(a);
        current = current ->next;
        if(pushed_count > chunck_size)
        {
            min_chunk = max_chunck;
            max_chunck +=chunck_size; 
        }
    }
}


