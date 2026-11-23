/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/10 10:49:40 by dlababne          #+#    #+#             */
/*   Updated: 2026/09/24 11:34:02 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	match(const char *big, const char *little, size_t i, size_t llen)
{
	size_t	j;

	j = 0;
	while (j < llen)
	{
		if (big[i + j] != little[j])
			return (0);
		j++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	blen;
	size_t	llen;

	i = 0;
	blen = ft_strlen(big);
	llen = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && i < blen)
	{
		if (big[i] == little[0] && llen <= len - i)
		{
			if (match(big, little, i, llen))
				return ((char *)&big[i]);
		}
		i++;
	}
	return (NULL);
}
