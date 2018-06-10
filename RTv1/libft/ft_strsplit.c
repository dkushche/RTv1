/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkushche <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 13:39:58 by dkushche          #+#    #+#             */
/*   Updated: 2017/11/03 13:40:08 by dkushche         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		get_nb_words(char const *s, char c)
{
	int			i;
	int			nb_words;
	int			new_word;

	i = 0;
	nb_words = 0;
	new_word = 1;
	while (s[i])
	{
		if (new_word && s[i] != c)
		{
			nb_words++;
			new_word = 0;
		}
		if (s[i] == c)
			new_word = 1;
		i++;
	}
	return (nb_words);
}

static char		*get_next_word(char const *s, char c, int *start)
{
	int			l;

	l = 0;
	while (s[*start] == c)
		*start += 1;
	l = *start;
	while (s[*start])
	{
		if (s[*start] == c)
			break ;
		*start += 1;
	}
	return (ft_strsub(s, l, *start - l));
}

char			**ft_strsplit(char const *s, char c)
{
	int			nb_words;
	char		**split;
	int			i;
	int			start;

	if (!s)
		return (NULL);
	nb_words = get_nb_words(s, c);
	split = (char**)malloc(sizeof(char*) * (nb_words + 1));
	if (split == NULL)
		return (NULL);
	i = 0;
	start = 0;
	while (nb_words--)
	{
		split[i] = get_next_word(s, c, &start);
		i++;
	}
	split[i] = NULL;
	return (split);
}
