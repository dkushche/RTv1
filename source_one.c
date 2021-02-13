/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   source_one.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:05:01 by dkushche          #+#    #+#             */
/*   Updated: 2018/02/02 18:05:01 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			optimaze_light(t_obj **light)
{
	t_obj		*tmp;
	double		count;

	count = 0;
	tmp = *light;
	while (tmp)
	{
		count += tmp->data[1].x;
		tmp = tmp->next;
	}
	if (count <= 1.0)
		return ;
	tmp = *light;
	while (tmp)
	{
		tmp->data[1].x /= count;
		tmp = tmp->next;
	}
}

int				my_key_funct(int k, void *param)
{
	(void)param;

	param = NULL;
	if (k == 53)
		exit(0);
	return (0);
}

int				just_exit(void *param)
{
	(void)param;
	exit(0);
	return (1);
}

int				main(int argc, char **argv)
{
	t_inf		inf;
	t_camera	cam;
	t_obj		*first;
	t_obj		*light;

	first = NULL;
	light = NULL;
	(argc == 2) ? 0 : error("I need 1 argument");
	inf.mlx = mlx_init();
	inf.win = mlx_new_window(inf.mlx, S_WIDTH, S_HEIGHT, "RTv1");
	parse(&cam, &first, &light, open(argv[1], O_RDONLY));
	optimaze_light(&light);
	if (!thread_pow(cam, &first, &light, inf))
		return (1);
	mlx_hook(inf.win, 2, 0, &(my_key_funct), NULL);
	mlx_hook(inf.win, 17, 0, &just_exit, (void *)0);
	mlx_loop(inf.mlx);
	return (0);
}
