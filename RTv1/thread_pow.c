/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pow.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:41:38 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/31 16:41:39 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int					thread_pow(t_camera cam, t_obj **objs, t_obj **light,\
	t_inf inf)
{
	pthread_t		pid[4];
	int				j;
	int				checker;
	t_scene			*p_scene;

	p_scene = (t_scene *)malloc(sizeof(t_scene) * 4);
	j = -1;
	while (++j < 4)
	{
		p_scene[j] = create_scene(cam, *objs, j, inf);
		p_scene[j].light = *light;
		checker = pthread_create(&pid[j], NULL, cam_trace, &(p_scene[j]));
		if (checker)
			return (0);
	}
	while (--j > -1)
	{
		if ((checker = pthread_join(pid[j], NULL)))
			return (0);
	}
	draw_that(p_scene, inf);
	return (1);
}

void				scale_color(t_vec *col)
{
	col->x = (col->x < 0) ? 0 : col->x;
	col->x = (col->x > 255) ? 255 : col->x;
	col->y = (col->y < 0) ? 0 : col->y;
	col->y = (col->y > 255) ? 255 : col->y;
	col->z = (col->z < 0) ? 0 : col->z;
	col->z = (col->z > 255) ? 255 : col->z;
}
