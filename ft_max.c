/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:42:13 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:42:51 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_max_mode(t_stat *file, t_stat *max)
{
	int		check;
	int		mode;

	check = file->size;
	mode = file->mode & S_IFMT;
	if ((mode == S_IFCHR) || (mode == S_IFBLK))
	{
		if (major(check) > max->mode)
			max->mode = major(check);
		if (minor(check) > max->size)
			max->size = minor(check);
	}
	else
	{
		if (!(max->mode))
			if (check > (int)(max->size))
				max->size = check;
	}
}

void		ft_checkmax(t_stat *file, t_stat *max)
{
	if ((file->nlink) > max->nlink)
		max->nlink = file->nlink;
	if (ft_strlen(file->user) > ft_strlen(max->user))
		max->user = file->user;
	if (ft_strlen(file->group) > ft_strlen(max->group))
		max->group = file->group;
	ft_max_mode(file, max);
	max->blocks = max->blocks + file->blocks;
}

void		ft_init_max(t_stat *max)
{
	max->mode = 0;
	max->blocks = 0;
	max->nlink = 0;
	max->size = 0;
	max->user = "";
	max->group = "";
}
