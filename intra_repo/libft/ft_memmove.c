/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/18 17:46:59 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/28 16:14:25 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*tmp1;
	unsigned char	*tmp2;

	tmp1 = (unsigned char *)dst;
	tmp2 = (unsigned char *)src;
	i = 0;
	if (dst < src)
	{
		while (i < len)
		{
			tmp1[i] = tmp2[i];
			i++;
		}
	}
	else if (dst > src)
	{
		while (len--)
			tmp1[len] = tmp2[len];
	}
	return (dst);
}
