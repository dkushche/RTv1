/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:13:03 by dkushche          #+#    #+#             */
/*   Updated: 2018/02/06 17:13:03 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				rot_vec(t_vec rot, t_vec *vec)
{
	double			par;

	par = vec->y;
	vec->y = cos(rot.x) * vec->y - sin(rot.x) * vec->z;
	vec->z = sin(rot.x) * par + cos(rot.x) * vec->z;
	par = vec->x;
	vec->x = vec->x * cos(rot.y) + sin(rot.y) * vec->z;
	vec->z = cos(rot.y) * vec->z - sin(rot.y) * par;
	par = vec->x;
	vec->x = vec->x * cos(rot.z) - vec->y * sin(rot.z);
	vec->y = par * sin(rot.z) + vec->y * cos(rot.z);
}

int					vec_rgb(t_vec rgb)
{
	int				r;
	int				g;
	int				b;

	r = (rgb.x > 255) ? 255 : rgb.x;
	g = (rgb.y > 255) ? 255 : rgb.y;
	b = (rgb.z > 255) ? 255 : rgb.z;
	return (r * 256 * 256 + g * 256 + b);
}

t_vec				second_part(t_scene *scn, t_vec vec)
{
	t_obj			*now;
	double			dist[2];
	t_vec			normal[3];
	t_obj			*win;
	double			bom;

	win = NULL;
	rot_vec(scn->cam.data[1], &vec);
	vec = norm(vec);
	now = scn->obj;
	dist[0] = 99999999;
	while (now)
	{
		dist[1] = now->colision(scn->cam.data[0], vec, now, &normal[0]);
		if (dist[1] < dist[0] && dist[1] > 1)
		{
			normal[1] = normal[0];
			win = now;
			dist[0] = dist[1];
		}
		now = now->next;
	}
	bom = checkl(scn, normal[1], vec, dist[0]);
	normal[2] = ((win) ? (vxs(win->data[3], bom)) : (gener(0, 0, 0)));
	return (normal[2]);
}

void				*cam_trace(void *param)
{
	t_scene			*scn;
	t_vec			vec;
	int				wid_im_pos[2];
	t_vec			col;
	int				hei;

	scn = param;
	hei = scn->hei;
	while (--hei >= 0)
	{
		vec.y = (hei - (scn->hei * (scn->n / 2))) * STEP_Y;
		wid_im_pos[0] = -1;
		while (++wid_im_pos[0] < scn->wid)
		{
			vec.x = (scn->n % 2 ? (wid_im_pos[0]) : (wid_im_pos[0] - scn->wid));
			vec.x *= STEP_X;
			vec.z = 1;
			norm(vec);
			col = second_part(scn, vec);
			wid_im_pos[1] = ((abs(hei + 1 - scn->hei) * scn->wid)\
								+ wid_im_pos[0]) * 4;
			*(int *)(scn->im_d + wid_im_pos[1]) = vec_rgb(col);
		}
	}
	pthread_exit(NULL);
}
