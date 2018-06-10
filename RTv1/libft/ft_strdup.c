/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:20:22 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 16:20:27 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	char	*p;
	int		i;

	i = 0;
	while (src[i] != '\0')
		i++;
	p = (char *)malloc(sizeof(char) * (i + 1));
	i = 0;
	if (p != NULL)
	{
		while (src[i] != '\0')
		{
			p[i] = src[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}
