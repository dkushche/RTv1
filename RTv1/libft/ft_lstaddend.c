/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddend.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 22:14:59 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/08 22:15:00 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstaddend(t_list **alst, t_list *new)
{
	t_list		*node;

	if (alst != NULL && *alst != NULL && new != NULL)
	{
		node = *alst;
		while (node->next)
		{
			node = node->next;
		}
		node->next = new;
		new->next = NULL;
	}
}
