/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/14 17:20:21 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/14 17:37:01 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if ((int)s[i] == c)
			return ((char *)&s[i]);
		i++;
	}
	if ((int)s[i] == c)
		return ((char *)&s[i]);
	return (0);
}
