/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 12:21:34 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 19:11:16 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	int		*tmp;

	i = 0;
	tmp = (int *)s;
	while (i < n)
	{
		if (tmp[i] == (int)c)
			return (&((int *)s)[i]);
		i++;
	}
	return (0);
}
