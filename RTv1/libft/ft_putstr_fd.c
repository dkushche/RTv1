/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 14:08:52 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/03 14:08:53 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	put_fd(char s, int fd)
{
	write(fd, &s, 1);
}

void			ft_putstr_fd(char const *str, int fd)
{
	if (str != NULL)
	{
		while (*str != '\0')
			put_fd(*str++, fd);
	}
}
