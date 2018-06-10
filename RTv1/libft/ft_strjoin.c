/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:36:13 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 18:36:14 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		length;
	char	*res;

	if ((s1 == NULL) || (s2 == NULL))
		return (NULL);
	length = (int)ft_strlen(s1) + (int)ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (length + 1));
	if (res == NULL)
		return (NULL);
	res[length] = '\0';
	i = 0;
	while (s1[length = i] != '\0')
	{
		res[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		res[length] = s2[i];
		i++;
		length++;
	}
	return (res);
}
