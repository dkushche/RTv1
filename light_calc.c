/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_calc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/22 15:28:18 by dkushche          #+#    #+#             */
/*   Updated: 2018/04/22 15:28:18 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					in_shadow(t_obj *temp, double l_dist, t_vec l, t_vec point)
{
	double			obj_dist;
	t_vec			vec;

	while (temp)
	{
		obj_dist = temp->colision(point, l, temp, &vec);
		if (obj_dist < l_dist && obj_dist > 0.00001)
			return (1);
		temp = temp->next;
	}
	return (0);
}

double				give_refl(t_vec normal, t_vec l, t_obj *tmp_l, t_vec vec)
{
	t_vec			refl;

	refl = norm(minus(vxs(vxs(normal, 2), dot(normal, l)), l));
	if (dot(refl, vxs(vec, -1)) > 0)
		return (pow((dot(refl, vxs(vec, -1))), 40) * tmp_l->data[1].x);
	else
		return (0);
}

double				checkl(t_scene *scn, t_vec normal, t_vec vec, double dist)
{
	double			l_intens;
	t_vec			point;
	t_obj			*tmp_l;
	t_vec			l;
	double			l_dist;

	l_intens = 0;
	if (dot(vec, normal) > 0)
		normal = vxs(normal, -1);
	point = plus(scn->cam.data[0], vxs(vec, dist));
	tmp_l = scn->light;
	while (tmp_l)
	{
		l = minus(tmp_l->data[0], point);
		l_dist = sqrt(dot(l, l));
		l = norm(l);
		if (!in_shadow(scn->obj, l_dist, l, point))
		{
			if (dot(l, normal) > 0)
				l_intens += dot(l, normal) * tmp_l->data[1].x\
				+ give_refl(normal, l, tmp_l, vec);
		}
		tmp_l = tmp_l->next;
	}
	return (l_intens);
}

int					create_light(int fd, t_obj **light)
{
	char			*line;
	int				i;

	create_obj(light);
	i = -1;
	while (++i < 2)
	{
		if (!get_next_line(fd, &line))
			error("Wrong syntax");
		if (i == 0)
			check("\tpos", &((*light)->data[0]), NULL, line);
		if (i == 1)
			check("\tpow", NULL, &((*light)->data[1].x), line);
		if ((*light)->data[1].x < 0)
			(*light)->data[1].x = 0;
		free(line);
	}
	return (1);
}
