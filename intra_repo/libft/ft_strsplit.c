/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:50:05 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/25 14:21:53 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
		tab[j] = writeword(&s[i], c);
		while (s[i] && s[i] != c)
			i++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
