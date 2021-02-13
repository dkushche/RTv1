/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:16:18 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 16:16:25 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int x)
{
	int i;
	int result;

	i = 1;
	result = 1;
	while (result < x)
	{
		if (result == x)
		{
			return (result);
		}
		i++;
		result = i * i;
	}
	if (i * i > x)
	{
		return (0);
	}
	else
	{
		return (i);
	}
}
