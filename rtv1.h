/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 18:01:18 by dkushche          #+#    #+#             */
/*   Updated: 2018/02/02 18:01:18 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <pthread.h>
# include "libft/libft.h"
# include "minilibx/mlx.h"

# define CRATCH 0.00000001
# define S_WIDTH 1000
# define S_HEIGHT 1000
# define STEP_X (1.0 / S_WIDTH)
# define STEP_Y (1.0 / S_HEIGHT)

typedef struct			s_inf
{
	void				*mlx;
	void				*win;
}						t_inf;

typedef struct			s_vec
{
	double				x;
	double				y;
	double				z;
}						t_vec;

typedef struct			s_camera
{
	t_vec				data[2];
}						t_camera;

typedef struct			s_object
{
	t_vec				data[4];
	double				(*colision)(t_vec start, t_vec ray,\
						struct s_object *obj, t_vec *normal);
	struct s_object		*next;
}						t_obj;

typedef struct			s_part_scene
{
	t_camera			cam;
	t_obj				*obj;
	t_obj				*light;
	int					wid;
	int					hei;
	int					n;
	void				*im;
	char				*im_d;
}						t_scene;

t_camera				create_cam(t_vec pos, t_vec rot);
void					create_obj(t_obj **first);
t_scene					create_scene(t_camera cam, t_obj *obj,\
										int j, t_inf inf);
int						thread_pow(t_camera cam, t_obj **objs,\
										t_obj **light, t_inf inf);
void					draw_that(t_scene *scenes, t_inf inf);
void					*cam_trace(void	*param);
double					check_col_plane(t_vec start, t_vec ray,\
									t_obj *obj, t_vec *normal);
double					check_col_sphere(t_vec start, t_vec ray,\
									t_obj *obj, t_vec *normal);
double					check_col_cylinder(t_vec start, t_vec ray,\
									t_obj *obj, t_vec *normal);
double					check_col_cone(t_vec start, t_vec ray,\
									t_obj *obj, t_vec *normal);
double					checkl(t_scene *scn, t_vec normal,\
									t_vec vec, double dist);
double					atod(char *pom);
double					destr_cratch(double res, char **dem);
int						create_plane(int fd, t_obj **first);
int						create_sphere(int fd, t_obj **first);
int						create_cylinder(int fd, t_obj **first);
int						create_cone(int fd, t_obj **first);
int						create_camera(int fd, t_camera *cam);
int						create_light(int fd, t_obj **light);
void					error(const char *er_msg);
int						check_obj(char *name, int fd,\
										t_obj **first, t_obj **light);
void					parse(t_camera *cam, t_obj **first,\
									t_obj **light, int fd);
void					check(char *key, t_vec *par, double *s_par,\
									char *line);
t_vec					minus(t_vec a, t_vec b);
t_vec					plus(t_vec a, t_vec b);
double					dot(t_vec a, t_vec b);
t_vec					norm(t_vec a);
t_vec					vxs(t_vec a, double b);
t_vec					gener(double x, double y, double z);
double					gtor(double gr);
void					scale_color(t_vec *col);

#endif
