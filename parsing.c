/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/22 10:41:53 by dlababne          #+#    #+#             */
/*   Updated: 2026/10/22 12:00:39 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"
void edge_cases(char *str){


//	is_duplicat(str);
	is_empty(str);
	check_sign(str);
}
void	check( int argc ,char **argv)
{
	int i;
	int j;
	j =1;
	i = 0;
		while(argv[j])
		{
			edge_cases(argv[j]);
			j++;
		}
}
