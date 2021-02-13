/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:02:38 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/31 18:02:38 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int		i;

	if (s1 == NULL && s2 == NULL)
		return (1);
	if ((s1 != NULL && s2 == NULL) || (s1 == NULL && s2 != NULL))
		return (0);
	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && n)
	{
		if (s1[i] == s2[i])
		{
			i++;
			n--;
			continue;
		}
		return (0);
	}
	return (1);
}
