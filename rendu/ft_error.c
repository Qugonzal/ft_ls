/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:48:58 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/25 17:45:07 by qugonzal         ###   ########.fr       */
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
