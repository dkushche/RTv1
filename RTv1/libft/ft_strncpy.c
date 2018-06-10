/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:34:35 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 12:34:35 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t maxlen)
{
	size_t	srclen;

	srclen = ft_strlen(src);
	if (srclen < maxlen)
	{
		ft_memcpy(dst, src, srclen);
		ft_memset(dst + srclen, 0, maxlen - srclen);
	}
	else
	{
		ft_memcpy(dst, src, maxlen);
	}
	return (dst);
}
