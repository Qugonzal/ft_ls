/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:36 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 20:07:18 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		wordcount(char const *s, char c)
{
	unsigned int wc;
	unsigned int i;

	wc = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			while (s[i] && s[i] != c)
				i++;
			wc++;
		}
	}
	return (wc);
}

static char		*writeword(char const *s, char c)
{
	unsigned int	i;
	char			*new;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!(new = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

static void		ft_free(char **tab, int i)
{
	while (--i > -1)
		free(tab[i]);
	free(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	wc;
	char			**tab;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	wc = wordcount(s, c);
	if (!(tab = (char **)malloc(sizeof(char *) * wc + 1)))
		return (NULL);
	while (j < wc)
	{
		while (s[i] == c)
			i++;
		if (!(tab[j] = writeword(&s[i], c)))
			ft_free(tab, j);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
