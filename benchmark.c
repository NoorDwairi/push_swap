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


