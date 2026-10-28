/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/27 11:41:14 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/28 10:50:26 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

bool	validate_duplicate(char **arr)
{
	int	i;
	int	j;
	int	element_1;
	int	element_2;

	i = 0;
	while (arr[i])
	{
		j = i + 1;
		while (arr[j])
		{
			element_1 = ft_atoi(arr[i]);
			element_2 = ft_atoi(arr[j]);
			if (element_1 == element_2)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
