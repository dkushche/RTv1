/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/31 17:28:47 by dkushche          #+#    #+#             */
/*   Updated: 2018/03/31 17:28:47 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vec			plus(t_vec a, t_vec b)
{
	t_vec		res;

	res.x = a.x + b.x;
	res.y = a.y + b.y;
	res.z = a.z + b.z;
	return (res);
}

double			dot(t_vec a, t_vec b)
{
	double		res;

	res = a.x * b.x + a.y * b.y + a.z * b.z;
	return (res);
}

t_vec			norm(t_vec a)
{
	t_vec		res;
	double		len;

	len = sqrt(dot(a, a));
	res.x = a.x / len;
	res.y = a.y / len;
	res.z = a.z / len;
	return (res);
}

t_vec			vxs(t_vec a, double b)
{
	t_vec		res;

	res.x = a.x * b;
	res.y = a.y * b;
	res.z = a.z * b;
	return (res);
}

t_vec			gener(double x, double y, double z)
{
	t_vec		res;

	res.x = x;
	res.y = y;
	res.z = z;
	return (res);
}
