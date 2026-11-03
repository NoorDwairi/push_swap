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

bool is_flag(char *s)
{
    if(!s)
    return (0);
        if(s[0] == '-' && s[1] =='-')
        return (true);
        return (false);
}

int	apply_strategy(char *ch, t_config *cfg)
{
	if (ft_strncmp(ch, "--simple", 9) == 0)
		cfg->selected = SIMPLE;
	else if (ft_strncmp(ch, "--medium", 9) == 0)
		cfg->selected = MEDIUM;
	else if (ft_strncmp(ch, "--complex", 10) == 0)
		cfg->selected = COMPLEX;
	else if (ft_strncmp(ch, "--adaptive", 11) == 0)
		cfg->selected = ADAPTIVE;
	else
		return (0);
	return (1);
}

int	apply_flag(char *ch, t_config *cfg)
{
	if (ft_strncmp(ch, "--bench", 8) == 0)
	{
		cfg->bench = true;
		return (1);
	}
	return (apply_strategy(ch, cfg));
}

int	parse_flags(char **argv, t_config *cfg)
{
    int i;
    
    i= 1;

    
        while(argv[i] && is_flag(argv[i]))
        {
           if(!apply_strategy(argv[i],cfg))
           return (-1);
           i++;
    }
    return(i-1);
}