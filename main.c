/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 13:27:29 by ndwairi           #+#    #+#             */
/*   Updated: 2026/11/23 13:27:32 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
//THIS MAIN IS NOT CORRECT BUT I AM TRYING TO MAKE TOMMOROW I WILL COMPLETE IT
int main(int argc, char **argv)
{
    t_stack **a;
    t_stack **b;
    t_config *cfg;
     if(argc < 2)
    return (-1);

    init_config(cfg);
    if(!validation(argv))
    ft_print("ON The stdrr we should print ERORR\n");
    *a = malloc(sizeof(t_stack));
    *b = malloc(sizeof(t_stack));
    *a=NULL;
    *b=NULL;
    init_stack(a);
    init_stack(b);
    if(is_sorted(a))
    {
        free_stack(a);
        free_stack(b);
        return(0);
    }
    set_arr(argv);
    free_stack(a);
    free_stack(b);

    return(0);

   
}
