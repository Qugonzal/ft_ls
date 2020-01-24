/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:08 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/24 16:13:58 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*ft_path(char *path, char *name)
{
	char	*new_path;
	int		s1;
	int		s2;

	s1 = ft_strlen(path);
	s2 = ft_strlen(name);
	if (path[s1 - 1] != '/')
	{
		if (!(new_path = (char *)ft_memalloc(s1 + s2 + 2)))
			return (NULL);
		ft_strncpy(new_path, path, s1);
		new_path[s1] = '/';
		ft_strncpy(&new_path[s1 + 1], name, s2);
	}
	else
	{
		if (!(new_path = (char *)ft_memalloc(s1 + s2 + 1)))
			return (NULL);
		ft_strncpy(new_path, path, s1);
		ft_strncpy(&new_path[s1], name, s2);
	}
	return (new_path);
}

void	ft_putpath(char *path)
{
	ft_putstr(path);
	ft_putstr(":\n");
}
