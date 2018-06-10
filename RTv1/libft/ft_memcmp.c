/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 11:29:48 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 11:29:48 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *buf1, const void *buf2, size_t count)
{
	unsigned char	*pointer1;
	unsigned char	*pointer2;
	int				i;

	if (!buf1 && !buf2 && !count)
		return (0);
	i = 0;
	pointer1 = (unsigned char *)buf1;
	pointer2 = (unsigned char *)buf2;
	while (count--)
	{
		if (pointer1[i] != pointer2[i])
			return (int)(pointer1[i] - pointer2[i]);
		i++;
	}
	return (0);
}
