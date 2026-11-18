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
    while ((i + 1) * (i +1) <= size)
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

void medium_sort(t_stack *a , t_stack *b)
{
    int chunck_size;
    if (!a || !b || a->size < 2)
    return ;

    chunk_size =chunk_size_calculator(a->size);
    push_chunks_to_b(a,b,chunck_size);
    push_back_to_a(a,b);
}