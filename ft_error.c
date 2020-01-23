/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:01:22 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/15 17:47:48 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_error(void)
{
	if (errno)
	{
		ft_putstr("errno == ");
		ft_putnbr(errno);
		ft_putstr(":\n");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
}

int		ft_nostat(t_max *max, char *name)
{
	ft_putchar('-');
	ft_putstr("?????????  ");
	ft_printspace(0, max->nlink);
	ft_putstr("? ?");
	ft_printspace_str("?", max->user);
	ft_putstr("  ?");
	ft_printspace_str("?", max->group);
	ft_putstr("  ");
	ft_printspace(0, max->size);
	ft_putstr("?            ? ");
	ft_putstr(name);
	ft_putchar('\n');
	return (0);
}

int		ft_chknopath(t_file *dir)
{
	struct stat sb;

	if (!(dir->dirstream = opendir(dir->name)))
	{
		dir->dirstream = NULL;
		if (errno == 20)
			return (1);
		else if (lstat(dir->name, &sb))
		{
			ft_putstr("ft-ls: ");
			perror(dir->name);
			return (0);
		}
	}
	return (1);
}

int		ft_check_open(t_file *dir, char *path)
{
	if (path)
	{
		if (!(dir->dirstream = opendir(path)))
		{
			ft_putstr("ls: ");
			perror(dir->name);
			return (0);
		}
	}
	else
	{
		if (!(ft_chknopath(dir)))
			return (0);
	}
	return (1);
}
