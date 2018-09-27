/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:22:12 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:42:40 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>

t_file		*ft_ls_l(t_file *file, char *path, unsigned char options)
{
	t_file		*dir;
	t_stat		max;

	dir = NULL;
	ft_init_max(&max);
	ft_fillcheck_stat(file, &max, path);
	ft_putstr("total ");
	ft_putnbr_ll(max.blocks);
	ft_putchar('\n');
	while (file->next)
	{
		ft_print_l(file, &max, path);
		if (options & LS_REC)
			if (file->mode == 4)
				dir = new_file(dir, file->name);
		file = file->next;
		free(file->prev);
	}
	ft_print_l(file, &max, path);
	if (options & LS_REC)
		if (file->mode == 4)
			dir = new_file(dir, file->name);
	free(file);
	return (dir);
}