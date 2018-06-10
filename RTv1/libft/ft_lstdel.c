/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:28:08 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/08 20:28:08 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list			*node;
	t_list			*nextnode;

	if (alst != NULL && del != NULL)
	{
		node = *alst;
		while (node)
		{
			del(node->content, node->content_size);
			nextnode = node->next;
			free(node);
			node = nextnode;
		}
		*alst = NULL;
	}
}
