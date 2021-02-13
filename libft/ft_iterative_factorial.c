/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:14:46 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 16:14:48 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_iterative_factorial(int nb)
{
	int f;
	int i;

	if (nb < 0 || nb > 13)
	{
		return (0);
	}
	else
	{
		i = 1;
		f = 1;
		while (i <= nb)
		{
			f *= i;
			i++;
		}
		return (f);
	}
}
