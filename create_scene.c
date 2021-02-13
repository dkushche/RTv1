/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 17:21:22 by dkushche          #+#    #+#             */
/*   Updated: 2018/01/31 17:21:22 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_scene			create_scene(t_camera cam, t_obj *obj, int j, t_inf inf)
{
	t_scene		res;
	int			bpp;
	int			sl;
	int			endian;

	res.cam = cam;
	res.obj = obj;
	res.n = j;
	res.wid = S_WIDTH / 2;
	res.hei = S_HEIGHT / 2;
	res.im = mlx_new_image(inf.mlx, S_WIDTH / 2, S_HEIGHT / 2);
	res.im_d = mlx_get_data_addr(res.im, &bpp, &sl, &endian);
	return (res);
}
