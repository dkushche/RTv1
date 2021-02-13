/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_col.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:08:15 by dkushche          #+#    #+#             */
/*   Updated: 2018/03/31 17:08:15 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "rtv1.h"

double			descrim(double par[3], int *can)
{
	double		descr;
	double		f_root;
	double		s_root;

	descr = par[1] * par[1] - 4 * par[0] * par[2];
	if (descr >= 0)
	{
		*can = 1;
		f_root = (-1 * par[1] + sqrt(descr)) / (2 * par[0]);
		s_root = (-1 * par[1] - sqrt(descr)) / (2 * par[0]);
		if (f_root < 0 && s_root < 0)
			return (-100);
		if ((f_root > 0 && f_root < s_root) || s_root < 0)
			return (f_root);
		else
			return (s_root);
	}
	else
		return (-100);
}

double			check_col_plane(t_vec start, t_vec ray,\
								t_obj *obj, t_vec *normal)
{
	double		a;
	t_vec		x;

	x = minus(obj->data[0], start);
	if ((a = dot(ray, obj->data[2])))
	{
		*normal = (a > 0) ? vxs(obj->data[2], -1) : obj->data[2];
		return ((dot(x, obj->data[2]) / a));
	}
	return (-100);
}

double			check_col_sphere(t_vec start, t_vec ray,\
								t_obj *obj, t_vec *normal)
{
	t_vec		x;
	double		par[3];
	int			help;
	double		res;

	x = minus(start, obj->data[0]);
	par[0] = dot(ray, ray);
	par[1] = 2 * dot(ray, x);
	par[2] = dot(x, x) - (obj->data[1].x * obj->data[1].x);
	help = 0;
	res = descrim(par, &help);
	if (help)
		*normal = norm(minus(plus(start, vxs(ray, res)), obj->data[0]));
	return (res);
}

double			check_col_cylinder(t_vec start, t_vec ray,\
									t_obj *obj, t_vec *normal)
{
	t_vec		x;
	double		par[3];
	double		help;
	int			can;
	double		res;

	x = minus(start, obj->data[0]);
	par[0] = dot(ray, ray) - pow(dot(ray, obj->data[2]), 2);
	par[1] = 2 * (dot(ray, x) - dot(ray, obj->data[2]) * dot(x, obj->data[2]));
	par[2] = dot(x, x) - pow(dot(x, obj->data[2]), 2)\
					- obj->data[1].x * obj->data[1].x;
	can = 0;
	res = descrim(par, &can);
	if (!can)
		return (res);
	help = dot(ray, vxs(obj->data[2], res)) + dot(x, obj->data[2]);
	x = minus(plus(start, vxs(ray, res)), obj->data[0]);
	*normal = norm(minus(x, vxs(obj->data[2], help)));
	return (res);
}

double			check_col_cone(t_vec start, t_vec ray,\
								t_obj *obj, t_vec *normal)
{
	t_vec		x;
	double		par[3];
	double		help;
	int			can;
	double		res;

	x = minus(start, obj->data[0]);
	par[0] = dot(ray, ray) - (1 + obj->data[1].x * obj->data[1].x)\
									* pow(dot(ray, obj->data[2]), 2);
	par[1] = (dot(ray, x));
	par[1] -= (1 + obj->data[1].x * obj->data[1].x) * dot(ray, obj->data[2])\
									* dot(x, obj->data[2]);
	par[1] *= 2;
	par[2] = dot(x, x) - (1 + obj->data[1].x * obj->data[1].x)\
									* pow(dot(x, obj->data[2]), 2);
	can = 0;
	res = descrim(par, &can);
	if (!can)
		return (res);
	help = dot(ray, vxs(obj->data[2], res)) + dot(x, obj->data[2]);
	x = minus(plus(start, vxs(ray, res)), obj->data[0]);
	*normal = norm(minus(x, vxs(vxs(obj->data[2], help),\
			1 + obj->data[1].x * obj->data[1].x)));
	return (res);
}
