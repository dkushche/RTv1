/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/12 19:34:11 by dkushche          #+#    #+#             */
/*   Updated: 2017/12/12 19:34:11 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct		s_node
{
	char			*content;
	int				fd;
	struct s_node	*next;
}					t_node;

# define BUFF_SIZE 42

# define CHECKER(elem) if (!elem) return (-1);

int					get_next_line(const int fd, char **line);

#endif
