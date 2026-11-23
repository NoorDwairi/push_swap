/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   adaptive.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 12:45:39 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/23 12:45:41 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_strategy choose_strategy(double disorder)
{
    if(disorder <.2)
    return(SIMPLE);
    else if(disorder >= .2 && disorder <.5)
    return(MEDIUM);
    else if(disorder >=.5 && disorder <= 1)
    return(COMPLEX);
    else
    return(INVALID);

}


void run_adaptive(t_stack *a, t_stack *b ,t_config *cfg)
{
    if(!a || !b || !cfg ||a->size < 2 || is_sorted(a))
    return;
    if(cfg->selected == ADAPTIVE)
    cfg -> used =choose_strategy(cfg->disorder);
    else 
    cfg->used =cfg ->selected;
    if(cfg ->used == SIMPLE)
    simple_sort(a,b);
    else if (cfg -> used == MEDIUM)
    medium_sort(a,b);
    else (cfg -> used == COMPLEX)
    complex_sort(a,b);
}