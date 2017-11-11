/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:51:34 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/11 18:32:13 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	void *s;

	if (!(s = (void *)malloc(sizeof(void) * size)))
		exit(-1);/*return (NULL);*/
	ft_bzero(s, size);
	return (s);
}
