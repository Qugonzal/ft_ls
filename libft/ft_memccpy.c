/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 16:40:09 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 19:13:57 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	int		*tmp1;
	int		*tmp2;

	i = 0;
	tmp1 = (int *)dst;
	tmp2 = (int *)src;
	while (i < n)
	{
		tmp1[i] = tmp2[i];
		if (tmp2[i] == (int)c)
			return ((int *)dst + (i + 1));
		i++;
	}
	return (0);
}
