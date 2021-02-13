/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_constr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 22:28:47 by dkushche          #+#    #+#             */
/*   Updated: 2018/03/31 22:28:47 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					create_plane(int fd, t_obj **first)
{
	char			*line;
	int				i;

	create_obj(first);
	(*first)->colision = &(check_col_plane);
	i = -1;
	while (++i < 3)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &((*first)->data[0]), NULL, line);
		if (i == 1)
		{
			check("\tnorm", &((*first)->data[2]), NULL, line);
			(*first)->data[2] = norm((*first)->data[2]);
		}
		if (i == 2)
			check("\tcol", &((*first)->data[3]), NULL, line);
		free(line);
	}
	scale_color(&((*first)->data[3]));
	return (1);
}

int					create_sphere(int fd, t_obj **first)
{
	char			*line;
	int				i;

	create_obj(first);
	(*first)->colision = &(check_col_sphere);
	i = -1;
	while (++i < 3)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &((*first)->data[0]), NULL, line);
		if (i == 1)
		{
			check("\trad", NULL, &((*first)->data[1].x), line);
			(*first)->data[1].x *= ((*first)->data[1].x < 0) ? -1.0 : 1.0;
		}
		if (i == 2)
			check("\tcol", &((*first)->data[3]), NULL, line);
		free(line);
	}
	scale_color(&((*first)->data[3]));
	return (1);
}

int					create_cylinder(int fd, t_obj **first)
{
	char			*line;
	int				i;

	create_obj(first);
	(*first)->colision = &(check_col_cylinder);
	i = -1;
	while (++i < 4)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &((*first)->data[0]), NULL, line);
		if (i == 1)
			check("\trad", NULL, &((*first)->data[1].x), line);
		if (i == 2)
			check("\tcol", &((*first)->data[3]), NULL, line);
		if (i == 3)
			check("\tvec", &((*first)->data[2]), NULL, line);
		free(line);
	}
	scale_color(&((*first)->data[3]));
	(*first)->data[2] = norm((*first)->data[2]);
	(*first)->data[1].x *= ((*first)->data[1].x < 0) ? -1.0 : 1.0;
	return (1);
}

int					create_cone(int fd, t_obj **first)
{
	char			*line;
	int				i;

	create_obj(first);
	(*first)->colision = &(check_col_cone);
	i = -1;
	while (++i < 4)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &((*first)->data[0]), NULL, line);
		if (i == 1)
			check("\ttg", NULL, &((*first)->data[1].x), line);
		if (i == 2)
			check("\tcol", &((*first)->data[3]), NULL, line);
		if (i == 3)
		{
			check("\tvec", &((*first)->data[2]), NULL, line);
			(*first)->data[2] = norm((*first)->data[2]);
		}
		free(line);
	}
	scale_color(&((*first)->data[3]));
	return (1);
}

int					create_camera(int fd, t_camera *cam)
{
	char			*line;
	int				i;

	i = -1;
	while (++i < 2)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &(cam->data[0]), NULL, line);
		if (i == 1)
		{
			check("\trot", &(cam->data[1]), NULL, line);
			cam->data[1].x = gtor(cam->data[1].x);
			cam->data[1].y = gtor(cam->data[1].y);
			cam->data[1].z = gtor(cam->data[1].z);
		}
		free(line);
	}
	return (1);
}
