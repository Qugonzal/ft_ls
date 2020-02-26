/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:26 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 15:37:43 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	char *new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)ft_memalloc(ft_strlen(s1) + len + 1)))
		return (NULL);
	ft_strncpy(new, s1, ft_strlen(s1));
	ft_strncpy(&new[ft_strlen(s1)], s2, len);
	return (new);
}
