/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:48:58 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/27 20:23:24 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_error(void)
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


char		ft_check_open(t_file *dir, char *path)
{
	if (path)
	{
		if (!(dir->dirstream = opendir(path)))
		{
			ft_putstr("errno == ");
			ft_putnbr(errno);
			ft_putstr("\n");
			perror(dir->name);
			return (0);
		}
	}
	else 
	{
		if (!(dir->dirstream = opendir(dir->name)))
		{
			ft_putstr("errno == ");
			ft_putnbr(errno);
			ft_putstr("\n");
			perror(dir->name);
			return (0);
		}
	}
	return (1);
}
/*
char		ft_check_dir(t_file *dir)
{
	if (!(dir->dirstream = opendir(dir->name)))
	{
		ft_putstr("errno == ");
		ft_putnbr(errno);
		ft_putstr("\n");
		perror(dir->name);
		ft_unlink(dir);
		free(dir);
		dir = NULL;
		return (0);
	}
	return (1);
}*/
