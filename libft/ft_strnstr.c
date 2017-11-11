/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:51:45 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/28 16:19:42 by qugonzal         ###   ########.fr       */
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
