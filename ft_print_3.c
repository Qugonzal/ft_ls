/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:11 by quegonza          #+#    #+#             */
/*   Updated: 2019/11/29 19:11:11 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_owners(t_file *file, t_max *max)
{
	ft_putstr(" ");
	if ((file->attr)->user)
	{
		ft_putstr((file->attr)->user);
		ft_printspace_str((file->attr)->user, max->user);
	}
	else
	{
		ft_putstr("none");
		ft_printspace_str("none", max->user);
	}
	ft_putstr("  ");
	if ((file->attr)->group)
	{
		ft_putstr((file->attr)->group);
		ft_printspace_str((file->attr)->group, max->group);
	}
	else
	{
		ft_putstr("none");
		ft_printspace_str("none", max->user);
	}
	ft_putstr("  ");
}

void	ft_put_name(t_file *file, int mode, char *path)
{
	char	*link;
	char	*file_name;

	link = ft_memalloc(256);
	ft_putchar(' ');
	ft_putstr(file->name);
	if (mode == S_IFLNK)
	{
		file_name = ft_path(path, file->name);
		ft_putstr(" -> ");
		if (readlink(file_name, link, 256) == -1)
		{
			ft_putstr("?\n");
			ft_putstr("readlink: ");
			perror(file_name);
		}
		else
			ft_putstr(link);
		free(file_name);
	}
	free(link);
}

void	ft_strfcat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	str[260];

	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	i = 0;
	while (str[i])
	{
		s2[i] = str[i];
		i++;
	}
	s2[i] = '\0';
}
