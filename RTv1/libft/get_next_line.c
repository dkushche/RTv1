/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:29:57 by dkushche          #+#    #+#             */
/*   Updated: 2017/12/12 19:29:57 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

t_node				*cr_node(t_node **nodec, int fd)
{
	t_node			*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (NULL);
	new_node->fd = fd;
	new_node->content = NULL;
	new_node->next = *nodec;
	return (new_node);
}

int					find_end_give(char **s, t_node **n, int fd, int *ret)
{
	t_node			*tmp;
	char			*last;

	tmp = *n;
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	if (!tmp)
	{
		if (!(*n = cr_node(n, fd)))
		{
			free(*s);
			return (0);
		}
		else
			return (1);
	}
	if (tmp->content && ft_strlen(tmp->content))
	{
		*ret = 1;
		last = *s;
		*s = ft_strjoin(*s, tmp->content);
		free(last);
	}
	return (1);
}

int					restruct_end_it(t_node **n, char **s, int fd, char **l)
{
	char			*some_shit;
	t_node			*tmp;
	char			*myline;
	int				i;

	i = 0;
	tmp = *n;
	some_shit = *s;
	while (tmp != NULL && tmp->fd != fd)
		tmp = tmp->next;
	while (some_shit[i] != '\n' && some_shit[i] != '\0')
		i++;
	myline = ft_strnew(i);
	*l = ft_memcpy(myline, some_shit, i);
	ft_strdel(&(tmp->content));
	if (some_shit[i] != '\0')
	{
		tmp->content = ft_strnew(1);
		myline = tmp->content;
		tmp->content = ft_strjoin(tmp->content, some_shit + i + 1);
		free(myline);
	}
	ft_strdel(s);
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	char			*buffers[2];
	int				ret[2];
	static t_node	*nodec = NULL;

	CHECKER((buffers[0] = ft_strnew(BUFF_SIZE)));
	if ((fd < 0 || line == NULL || read(fd, buffers[0], 0) < 0 || (ret[1] = 0)))
		return (-1);
	CHECKER((buffers[1] = ft_strnew(0)));
	CHECKER((find_end_give(&(buffers[1]), &nodec, fd, &ret[1])));
	while ((ret[0] = read(fd, buffers[0], BUFF_SIZE)))
	{
		ret[1] = 1;
		*line = buffers[1];
		CHECKER((buffers[1] = ft_strjoin(buffers[1], buffers[0])));
		free(*line);
		ft_strclr(buffers[0]);
		if (ft_strchr(buffers[1], '\n'))
			break ;
	}
	free(buffers[0]);
	if (ret[1])
		return ((restruct_end_it(&nodec, &(buffers[1]), fd, line)));
	free(buffers[1]);
	return (0);
}
