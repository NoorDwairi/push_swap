/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dlababne <dlababne@learner.42.tech>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/12 13:44:38 by dlababne          #+#    #+#             */
/*   Updated: 2026/09/24 11:45:24 by dlababne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t size)
{
	char	*a;

	if (n && size > SIZE_MAX / n)
		return (NULL);
	a = malloc(n * size);
	if (!a)
		return (NULL);
	ft_memset(a, 0, n * size);
	return (a);
}
