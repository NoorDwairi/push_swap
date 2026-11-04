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

void	init_config(t_config *cfg)
{
	cfg->disorder = 0.0;
	cfg->total_ops = 0;
	cfg->sa = 0;
	cfg->sb = 0;
	cfg->ss = 0;
	cfg->pa = 0;
	cfg->pb = 0;
	cfg->ra = 0;
	cfg->rb = 0;
	cfg->rr = 0;
	cfg->rra = 0;
	cfg->rrb = 0;
	cfg->rrr = 0;
	cfg->used = ADAPTIVE;
	cfg->selected = ADAPTIVE;
	cfg->bench = false;
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
           if(!apply_flag(argv[i],cfg))
           return (-1);
           i++;
		}
    return(i-1);
}