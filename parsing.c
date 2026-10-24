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

void	edge_cases(char *str)
{
	is_duplicat(str);
	is_empty(str);
	check_sign(str);
}

int	count_element(char **argv)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] && (j == 0 || argv[i][j - 1] == ' '))
				// in this function we do not want to check 
				// the validation we just make a  counter to use it 
				// in a malloc which mean if it was like this 
				// "1a2 656" the counter will retrun 2 cuz we just want 
				// a size of a arr later we will check the numbers
				//  if they are valid or not
				counter++;
			j++;
		}
		i++;
	}
	return (counter);
}


char	**check(char **argv)
{
	char	**arr;
	char	**temp_res;
	int		count_elements;
	int		i;
	int		k;

	count_elements = count_elements_updated(argv);
	if (count_elements <= 0)
		return (NULL);
	arr = malloc(sizeof(char *) * (count_elements + 1));
	i = 1;
	k = 0;
	if (!arr)
		return (NULL);
	while (argv[i])
	{
		temp_res = ft_split(argv[i], ' ');
		if (!temp_res)
			return (free_tokens(arr, k), NULL);
		k = set_numbers(arr, temp_res, k);
		free(temp_res);
		i++;
	}
	arr[k] = NULL;
	return (arr);
}
