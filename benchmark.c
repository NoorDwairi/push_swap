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
void init_config(t_config *b)
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
    b ->    used= ADAPTIVE;
    b ->    selected = ADAPTIVE;
    b ->    bench = 0;
}


