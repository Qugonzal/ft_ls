/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:48:58 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/18 18:55:33 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_error(void)
{
	if (errno)
	{
		ft_putstr("Erreur, errno == ");
		ft_putnbr(errno);
		ft_putstr(":\n");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
}

int			ft_check_open(t_file *dir)
{
	if (!(dir->dirstream = opendir(dir->name)))
	{
		ft_putstr("errno == ");
		ft_putnbr(errno);
		ft_putstr("\n");
		perror(dir->name);
		ft_unlink_dir(dir);
		free(&dir);
		return (1);
	}
	return (0);
}
