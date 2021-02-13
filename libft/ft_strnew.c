/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 15:54:04 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 15:54:04 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnew(size_t size)
{
	char	*p;
	size_t	i;

	i = 0;
	p = (char *)malloc(sizeof(char) * (size + 1));
	if (p != NULL)
	{
		while (i != (size))
		{
			p[i] = 0;
			i++;
		}
		p[i] = '\0';
		return (p);
	}
	else
		return (NULL);
}
