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
	is_duplicat(str);
	is_empty(str);
	check_sign(str);
}
int	count_elements(char **argv)
{
	int i;
	int j;
	int counter;
	
	counter = 0;
	i = 1;
	while(argv[i])
	{
		j = 0;
		while(argv[i][j])
		{
			if (argv[i][j] == ' ' && ft_isdigit(argv[i][j + 1]))
				counter++;
			j++;

		}
		counter++;
		i++;
	}
	return(counter);
}
void	check( int argc ,char **argv)
{
	char **temp_res;
	char **arr;
	int i;
	int j;
	int k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		temp_res =ft_split(argv[i],' ');
		while(temp_res[j])
		{	
			arr[k]= temp_res[j];
			k++;
			j++;  
		}
		i++;
	}
}
