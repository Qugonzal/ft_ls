/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:26 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 15:36:51 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcut(int x, int flag, char *s)
{
	char	*tmp;
	int		i;

	if (x < 1 || flag < 0 || flag > 1)
		return (NULL);
	i = ft_strlen(s) - x;
	if (!(tmp = malloc(sizeof(char) * i + 1)))
		return (NULL);
	tmp[i] = '\0';
	i = -1;
	if (flag == 0)
		while (s[x])
			tmp[++i] = s[x++];
	else
		while (tmp[++i] != '\0')
			tmp[i] = s[i];
	free(s);
	return (tmp);
}
