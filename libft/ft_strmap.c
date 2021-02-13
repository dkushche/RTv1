/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 17:29:33 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 17:29:33 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strmap(char const *s, char (*f)(char))
{
	int			length;
	int			maxlength;
	char		*res;

	if (s != NULL)
	{
		length = ft_strlen(s);
		length += 1;
		res = (char *)malloc(sizeof(char) * length);
		if (res == NULL)
			return (NULL);
		length--;
		maxlength = length;
		while (length >= 0)
		{
			if (length != maxlength)
				res[length] = (f)(s[length]);
			else
				res[length] = s[length];
			length--;
		}
		return (res);
	}
	return (NULL);
}
