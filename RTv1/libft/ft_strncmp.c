/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 15:56:16 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 15:56:17 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	if (!str1 && !str2)
		return (0);
	while (n != 0)
	{
		if (*str1 != *str2++)
			return (*(unsigned char *)str1 - *(unsigned char *)--str2);
		if (*str1 == '\0')
			break ;
		str1++;
		n--;
	}
	return (0);
}
