/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:18:58 by dkushche          #+#    #+#             */
/*   Updated: 2017/10/26 16:18:59 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int		ft_unprintch(char str)
{
	if (str == ' ' || str == '\t' || str == '\n')
	{
		return (1);
	}
	else if (str == '\v' || str == '\r' || str == '\f')
	{
		return (1);
	}
	else if (str == '0')
	{
		return (1);
	}
	else
		return (0);
}

static void		split(int *i, int *j, int together, const char *str)
{
	if (together)
	{
		while (ft_unprintch(str[*i]))
		{
			*i = *i + 1;
			*j = *j + 1;
		}
	}
	else
	{
		while (ft_unprintch(str[*i]))
			*i = *i + 1;
	}
}

static int		find_sign(int *porog, int *sign, int *i, const char *str)
{
	if (str[*i] == '-' || str[*i] == '+')
	{
		*porog = 11;
		if (str[*i + 1] >= '0' && str[*i + 1] <= '9')
		{
			*sign = (str[*i] == '+') ? 1 : -1;
			*i = *i + 1;
		}
		else
			return (0);
	}
	return (1);
}

int				ft_atoi(const char *str)
{
	int			i;
	int			res;
	int			sign;
	int			porog;
	int			j;

	j = 0;
	i = 0;
	res = 0;
	sign = 1;
	porog = 10;
	split(&i, &j, 0, str);
	if (!find_sign(&porog, &sign, &i, str))
		return (0);
	split(&i, &j, 1, str);
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i++] - '0';
		j++;
	}
	if (j > porog)
		return (sign == 1 ? -1 : 0);
	res *= sign;
	return (res);
}
