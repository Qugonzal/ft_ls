/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:59:37 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 15:36:51 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		conv(char *s, int c, int i)
{
	int j;

	j = i;
	while (c > 9)
	{
		s[j] = (c % 10) + 48;
		c = c / 10;
		j--;
	}
	s[j] = c + 48;
}

static int		min(char *s, int c)
{
	s[0] = '-';
	s[1] = '2';
	c = 147483648;
	return (c);
}

char			*ft_itoa(int c)
{
	int		i;
	int		nb;
	char	*s;

	nb = c;
	i = 0;
	while ((nb = nb / 10) != 0)
		i++;
	if (c < 0)
		i++;
	if (!(s = (char *)malloc(sizeof(char) * i + 2)))
		return (NULL);
	if (c == -2147483648)
		c = min(s, c);
	if (c < 0)
	{
		s[0] = '-';
		c = -c;
	}
	conv(s, c, i);
	s[i + 1] = '\0';
	return (s);
}
