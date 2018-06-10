/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_that.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 17:05:14 by dkushche          #+#    #+#             */
/*   Updated: 2018/02/06 17:05:14 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void				draw_that(t_scene *scenes, t_inf inf)
{
	int				i;
	int				x;
	int				y;

	i = -1;
	while (++i < 4)
	{
		x = (i % 2) * scenes[i].wid;
		y = (i / 2) * scenes[i].hei;
		mlx_put_image_to_window(inf.mlx, inf.win, scenes[i].im, x, y);
	}
	free(scenes);
}
