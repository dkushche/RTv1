/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:49:10 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 18:49:11 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_unprintcher(char str)
{
	if (str == ' ' || str == '\n' || str == '\t')
		return (1);
	else
		return (0);
}

static int	extra(char **res, int start, char const *s)
{
	if (start == (int)ft_strlen(s))
	{
		*res = (char *)malloc(sizeof(char) * 1);
		**res = '\0';
		return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s)
{
	int		startendi[3];
	char	*res;

	if (s == NULL)
		return (NULL);
	startendi[2] = 0;
	while (ft_unprintcher(s[startendi[2]]))
		startendi[2]++;
	startendi[0] = startendi[2];
	if (extra(&res, startendi[0], s))
		return (res);
	startendi[2] = ft_strlen(s) - 1;
	while (ft_unprintcher(s[startendi[2]]))
		startendi[2]--;
	startendi[1] = startendi[2];
	res = (char *)malloc(sizeof(char) * (startendi[1] - startendi[0] + 2));
	if (res == NULL)
		return (NULL);
	startendi[2] = 0;
	while (startendi[0] <= startendi[1])
		res[startendi[2]++] = s[startendi[0]++];
	res[startendi[2]] = '\0';
	return (res);
}
