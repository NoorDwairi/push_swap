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

int isqrt(int size)// the chunk size 
{
    int i;
    i =0;
    while ((i + 1) * (i +1)<=n)
    i++;
    return(i);
}

int chunk_size_calculator(int size )
{
    int chunk;
    chunk = isqrt(size);

    if (chunk < 1)
    chunk = 1;
    
    return (chunk);
    
}

bool push_or_rotate(t_stack *a, t_stack *b,int limit)
{
    if(a->top->rank < limit)
    {
        pb(a,b);
        return(1);
    }
    ra(a);
    return(0); 

}
void push_chunks_to_b(t_stack *a, t_stack *b , int chunck_size)
{
    int pushed;
    int limit ;
   
    
    if(!a || !b || chunck_size <= 0)
    return;

    limit=chunck_size;
    pushed =0;
    while (a->top)
    {
        if(push_or_rotate(a,b,limit) == 1)
        pushed++;
        if(pushed == chunck_size)
        {
            limit +=chunck_size;
            pushed=0;
        }
        
        

    }
    
    
}
/*
void push_chunks_to_b(t_stack *a, t_stack *b , int chunck_size)
{
    int min_chunk;
    int max_chunck;
    
    
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
*/

