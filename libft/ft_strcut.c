/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcut.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 16:37:53 by qugonzal          #+#    #+#             */
/*   Updated: 2017/06/06 17:34:44 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

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
