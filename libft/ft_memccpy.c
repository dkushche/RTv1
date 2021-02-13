/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:21:12 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 18:21:12 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char		*p;
	const char	*z;
	char		x;
	size_t		l;

	l = n;
	x = c;
	z = src;
	p = dest;
	while (l-- > 0)
	{
		if ((*p++ = *z++) == x)
			return (p);
	}
	return (NULL);
}
