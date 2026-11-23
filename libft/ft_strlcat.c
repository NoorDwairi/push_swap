/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 10:39:44 by dlababne          #+#    #+#             */
/*   Updated: 2026/09/24 11:31:03 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlength;
	size_t	slength;
	size_t	ava;

	i = 0;
	slength = ft_strlen(src);
	while (i < dstsize && dst[i] != '\0')
		i++;
	dlength = i;
	if (dstsize <= dlength)
		return (dstsize + slength);
	ava = dstsize - dlength - 1;
	if (ava > slength)
		ava = slength;
	i = 0;
	while (i < ava)
	{
		dst[dlength + i] = src[i];
		i++;
	}
	dst[dlength + i] = '\0';
	return (dlength + slength);
}
