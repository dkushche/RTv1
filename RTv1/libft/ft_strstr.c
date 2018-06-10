/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 14:55:41 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 14:55:42 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *strb, const char *stra)
{
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	size = ft_strlen(stra);
	if (!size)
		return ((char *)strb);
	while (strb[i] != '\0')
	{
		while (stra[j] == strb[i + j])
		{
			if (j == size - 1)
				return ((char *)strb + i);
			j++;
		}
		j = 0;
		i++;
	}
	return (NULL);
}
