/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 16:51:03 by dkushche          #+#    #+#             */
/*   Updated: 2018/03/31 16:51:03 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

void		error(const char *er_msg)
{
	ft_putendl(er_msg);
	exit(1);
}

int			check_obj(char *name, int fd, t_obj **first, t_obj **light)
{
	if (!ft_strcmp(name, "Sphere"))
		return (create_sphere(fd, first));
	if (!ft_strcmp(name, "Plane"))
		return (create_plane(fd, first));
	if (!ft_strcmp(name, "Cone"))
		return (create_cone(fd, first));
	if (!ft_strcmp(name, "Cylinder"))
		return (create_cylinder(fd, first));
	if (!ft_strcmp(name, "Light"))
		return (create_light(fd, light));
	error("Wrong syntax");
	return (0);
}

void		parse(t_camera *cam, t_obj **first, t_obj **light, int fd)
{
	char	*line;
	char	**find_obj;
	int		i;
	int		n_cam;

	if (fd < 0 || (n_cam = 0))
		error("Reading err");
	while ((i = get_next_line(fd, &line)))
	{
		(i < 0) ? error("Reading err") : (i = -1);
		find_obj = ft_strsplit(line, ':');
		(find_obj[1]) ? error("Syntax error") : 0;
		if (!ft_strcmp(find_obj[0], "Camera"))
		{
			(n_cam == 0) ? n_cam++ : error("You have more then 1 camera");
			create_camera(fd, cam);
		}
		else
			check_obj(find_obj[0], fd, first, light);
		free(line);
		while (find_obj[++i])
			free(find_obj[i]);
		free(find_obj);
	}
	(n_cam) ? 0 : error("You don't have cam");
}

void		check(char *key, t_vec *par, double *s_par, char *line)
{
	char	**dem;
	char	**kek;
	int		i;

	i = -1;
	(line) ? 0 : error("Something goes wrong");
	dem = ft_strsplit(line, '=');
	(dem[1]) ? 0 : error("Syntax error");
	(dem[2]) ? error("Syntax error") : 0;
	if (ft_strcmp(dem[0], key))
		error("Syntax error\n");
	if (par)
	{
		kek = ft_strsplit(dem[1], ';');
		par->x = atod(kek[0]);
		par->y = atod(kek[1]);
		par->z = atod(kek[2]);
		while (kek[++i])
			free(kek[i]);
		free(kek);
		destr_cratch(0, dem);
	}
	else
		*s_par = destr_cratch(atod(dem[1]), dem);
}
