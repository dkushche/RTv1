/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:34:40 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 18:34:40 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*source;
	char	*dest;
	size_t	i;

	i = -1;
	source = (char *)src;
	dest = (char *)dst;
	if (source < dest)
		while ((int)(--len) >= 0)
			*(dest + len) = *(source + len);
	else
		while (++i < len)
			*(dest + i) = *(source + i);
	return (dst);
}
