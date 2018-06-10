/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:07:15 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 18:07:16 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *destination, const void *source, size_t n)
{
	const char	*z;
	char		*p;

	z = source;
	p = destination;
	while (n)
	{
		*p = *z;
		p = p + 1;
		z = z + 1;
		n--;
	}
	return (destination);
}
