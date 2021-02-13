/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:43:49 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 17:43:50 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int			length;
	char const	*bes;
	char		*res;
	int			maxlength;

	if (s == NULL)
		return (NULL);
	length = 0;
	bes = s;
	length = ft_strlen(bes);
	length++;
	res = (char *)malloc(sizeof(char) * length);
	if (res == NULL)
		return (NULL);
	length--;
	maxlength = length;
	while (length >= 0)
	{
		if (length != maxlength)
			res[length] = (f)(length, s[length]);
		else
			res[length] = s[length];
		length--;
	}
	return (res);
}
