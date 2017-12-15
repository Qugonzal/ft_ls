/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 03:48:58 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 05:54:22 by qugonzal         ###   ########.fr       */
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

void			ft_check_open(t_arg *arg_lst)
{
	t_arg	*tmp;

	tmp = arg_lst;

	while (tmp)
	{
		if (!(tmp->dirstream = opendir(tmp->name)))
		{
			ft_putstr("errno == ");
			ft_putnbr(errno);
			ft_putstr("\n");
			perror(tmp->name);
			ft_unlink_arg(tmp);
			free(&tmp);
		}
		tmp = tmp->next;
	}
}
