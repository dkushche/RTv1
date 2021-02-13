/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gtor.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 17:48:59 by dkushche          #+#    #+#             */
/*   Updated: 2018/02/07 17:49:00 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double				destr_cratch(double res, char **dem)
{
	free(dem[0]);
	free(dem[1]);
	free(dem);
	return (res);
}

double				gtor(double gr)
{
	while (gr >= 360)
		gr -= 360;
	while (gr <= -360)
		gr += 360;
	return (M_PI * (gr / 180.0));
}

double				atod(char *pom)
{
	char			**dem;
	int				first;
	int				second;
	double			res;
	int				sign;

	(pom) ? 0 : error("Invalid syntax");
	if (ft_strchr(pom, '.'))
	{
		dem = ft_strsplit(pom, '.');
		dem[2] ? error("Invalid number") : 0;
		if (!ft_strlen(dem[0]) || ft_strlen(dem[0]) > 9)
			error("Invalid number");
		first = atoi(dem[0]);
		sign = (first < 0) ? -1 : 1;
		if (!ft_strlen(dem[1]) || ft_strlen(dem[1]) > 9)
			error("Invalid number");
		second = atoi(dem[1]);
		res = (double)first + (sign * ((double)second\
						/ pow(10, ft_strlen(dem[1]))));
		res = (res == 0) ? destr_cratch(CRATCH, dem) : destr_cratch(res, dem);
		return (res);
	}
	error("Value must be double");
	return (0);
}

t_vec				minus(t_vec a, t_vec b)
{
	t_vec			res;

	res.x = a.x - b.x;
	res.y = a.y - b.y;
	res.z = a.z - b.z;
	return (res);
}
