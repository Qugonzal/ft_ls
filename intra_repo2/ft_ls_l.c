/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:06 by quegonza          #+#    #+#             */
/*   Updated: 2020/02/25 19:02:26 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

void		ft_put_total(t_max max)
{
	ft_putstr("total ");
	ft_putnbr_ll(max.blocks);
	ft_putchar('\n');
}

t_file		*ft_ls_l(t_file *file, char *path, t_opt opt)
{
	t_file		*dir;
	t_max		max;
	mode_t		check;

	dir = NULL;
	ft_init_max(&max);
	ft_fillcheck_stat(file, &max, path, opt);
	ft_put_total(max);
	while (file->next)
	{
		ft_print_l(file, &max, path, opt);
		if (opt.option.rec)
			if ((check = file->attr->mode & S_IFMT) == S_IFDIR)
				dir = new_file(dir, file->name);
		file = file->next;
		ft_free(file->prev);
		ft_putchar('\n');
	}
	ft_print_l(file, &max, path, opt);
	if (opt.option.rec)
		if ((check = file->attr->mode & S_IFMT) == S_IFDIR)
			dir = new_file(dir, file->name);
	ft_free(file);
	ft_putchar('\n');
	return (dir);
}
