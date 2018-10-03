/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:48:58 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 16:20:37 by qugonzal         ###   ########.fr       */
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

int		ft_nostat(t_stat *max, char *name)
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

char	ft_check_open(t_file *dir, char *path)
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
		if (!(dir->dirstream = opendir(dir->name)))
		{
			if (errno == 20)
				return (1);
			else
			{
				ft_putstr("ls: ");
				perror(dir->name);
			}
			return (0);
		}
	}
	return (1);
}
