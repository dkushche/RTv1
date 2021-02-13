/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:03:53 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 11:03:54 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*pointer;
	unsigned char	c2;
	int				i;

	i = 0;
	c2 = (unsigned char)c;
	pointer = (unsigned char *)s;
	while (n--)
	{
		if (pointer[i] == c2)
			return (pointer + i);
		i++;
	}
	return (NULL);
}
