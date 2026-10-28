/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndwairi <ndwairi@learner.42.tech>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/26 08:56:30 by ndwairi           #+#    #+#             */
/*   Updated: 2026/10/26 08:56:33 by ndwairi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <push_swap.h>

void	free_tokens(char **token, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		free(token[j]);
		j++;
	}
	free(token);
}
int	count_tokens(char **tokens)
{
	int	i;

	i = 0;
	while (tokens[i])
		i++;
	return (i);
}
int	count_elements_updated(char **argv)
{
	char	**temp_res;
	int		i;
	int		j;
	int		counter;

	i = 1;
	counter = 0;
	while (argv[i])
	{
		temp_res = ft_split(argv[i], ' ');
		if (!temp_res)
			return (-1);
		j = count_tokens(temp_res);
		if (j == 0)
		{
			free_tokens(temp_res, 0);
			return (-1);
		}
		counter += j;
		free_tokens(temp_res, j);
		i++;
	}
	return (counter);
}

int	set_numbers(char **arr, char **temp_res, int k)
{
	int	j;

	j = 0;
	while (temp_res[j])
	{
		arr[k] = temp_res[j];
		j++;
		k++;
	}
	return (k);
}

char	**set_arr(char **argv)
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