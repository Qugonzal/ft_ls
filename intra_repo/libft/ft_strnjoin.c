/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 14:33:25 by qugonzal          #+#    #+#             */
/*   Updated: 2017/10/03 17:46:09 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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
