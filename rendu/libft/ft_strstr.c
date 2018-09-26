/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 18:51:45 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/19 19:12:09 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int i;

	i = 0;
	if (!little[i])
		return ((char *)big);
	while (big[i])
	{
		if (!(ft_strncmp(&big[i], little, ft_strlen(little))))
			return ((char *)&big[i]);
		i++;
	}
	return (0);
}
