/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:33:29 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/28 18:33:29 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char	*z;
	size_t	j;

	if (size > 4294967295)
		return (NULL);
	j = 0;
	z = (char *)malloc(sizeof(char) * size);
	if (z == NULL)
		return (NULL);
	while (j != size)
	{
		*(z + j) = 0;
		j++;
	}
	return ((void *)z);
}
