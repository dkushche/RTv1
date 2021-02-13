/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 12:35:25 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 12:35:25 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strncat(char *dst, const char *src, size_t maxlen)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	cpylen;

	dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	if (srclen < maxlen)
		cpylen = srclen;
	else
		cpylen = maxlen;
	ft_memcpy(dst + dstlen, src, cpylen);
	dst[dstlen + cpylen] = '\0';
	return (dst);
}
