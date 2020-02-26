/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:36 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 14:57:24 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t i;
	size_t littlesize;

	i = 0;
	littlesize = ft_strlen(little);
	if (!little[i])
		return ((char *)big);
	while (big[i] && (i < len))
	{
		if (len - i < littlesize)
			return (0);
		if (ft_strncmp(&big[i], little, littlesize) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
