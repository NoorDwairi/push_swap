/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/15 11:55:12 by dlababne          #+#    #+#             */
/*   Updated: 2026/09/24 11:41:59 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	nbr_len(long int n)
{
	size_t	len;

	len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n > 9)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		i;
	long int	temp;
	char		*res;

	i = nbr_len(n);
	res = malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	temp = n;
	if (temp < 0)
		temp = -temp;
	while (temp > 9)
	{
		res[i] = (temp % 10) + '0';
		temp = temp / 10;
		i--;
	}
	res[i] = (temp % 10) + '0';
	if (n < 0)
		res[0] = '-';
	return (res);
}
