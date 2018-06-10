/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:06:54 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 14:06:55 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_strlcat(char *dst, const char *src, size_t maxlen)
{
	size_t			size_of_src;
	size_t			size_of_dst;

	size_of_src = ft_strlen(src);
	size_of_dst = ft_strlen(dst);
	if (size_of_dst >= maxlen)
		return (maxlen + size_of_src);
	if (size_of_src < maxlen - size_of_dst)
	{
		ft_memcpy(dst + size_of_dst, src, size_of_src + 1);
	}
	else
	{
		ft_memcpy(dst + size_of_dst, src, maxlen - size_of_dst - 1);
		dst[maxlen - 1] = '\0';
	}
	return (size_of_dst + size_of_src);
}
