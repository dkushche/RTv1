/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 17:38:12 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/25 17:38:14 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memset(void *memptr, int val, size_t num)
{
	char	*p;

	p = memptr;
	while (num)
	{
		*p = val;
		p = p + 1;
		num--;
	}
	return (memptr);
}
