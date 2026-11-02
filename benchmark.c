/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   benchmark.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:15:58 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/02 12:16:00 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void init_bench(t_bench *b)
{
    b ->     disorder=0.0;
    b ->     total_ops=0;
    b ->     sa=0;
    b ->     sb=0;
    b ->     ss=0;
    b ->     pa=0;
    b ->     pb=0;
    b ->     ra=0;
    b ->     rb=0;
    b ->     rr=0;
    b ->     rra=0;
    b ->     rrb=0;
    b ->     rrr=0;
}

void count_operation (t_bench *b ,char *operation )
{
    if(!b || !operation)
    return;
       if (!b || !operation)
        return ;
    if (ft_strncmp(operation, "sa", 3) == 0)
        b->sa++;
    else if (ft_strncmp(operation, "sb", 3) == 0)
        b->sb++;
    else if (ft_strncmp(operation, "ss", 3) == 0)
        b->ss++;
    else if (ft_strncmp(operation, "pa", 3) == 0)
        b->pa++;
    else if (ft_strncmp(operation, "pb", 3) == 0)
        b->pb++;
    else if (ft_strncmp(operation, "ra", 3) == 0)
        b->ra++;
    else if (ft_strncmp(operation, "rb", 3) == 0)
        b->rb++;
    else if (ft_strncmp(operation, "rr", 3) == 0)
        b->rr++;
    else if (ft_strncmp(operation, "rra", 4) == 0)
        b->rra++;
    else if (ft_strncmp(operation, "rrb", 4) == 0)
        b->rrb++;
    else if (ft_strncmp(operation, "rrr", 4) == 0)
        b->rrr++;
    else
        return ;
    b->total_ops++;
    
}
