/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 12:22:43 by dlababne          #+#    #+#             */
/*   Updated: 2026/09/24 11:35:42 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	copy_substr(char *s1, char const *s, size_t start, size_t sublen)
{
	size_t	i;

	i = 0;
	while (i < sublen)
	{
		s1[i] = s[start + i];
		i++;
	}
	s1[i] = '\0';
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	sl;
	size_t	sublen;

	sl = ft_strlen(s);
	if (sl <= start)
	{
		s1 = malloc(1);
		if (!s1)
			return (NULL);
		s1[0] = '\0';
		return (s1);
	}
	sublen = sl - start;
	if (len < sublen)
		sublen = len;
	s1 = malloc(sublen + 1);
	if (!s1)
		return (NULL);
	copy_substr(s1, s, start, sublen);
	return (s1);
}
