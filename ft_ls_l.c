/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:22:12 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/02 16:16:43 by qugonzal         ###   ########.fr       */
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
			if (file->mode & DT_DIR)
				dir = new_file(dir, file->name);
		file = file->next;
		ft_free(file->prev);
		ft_putchar('\n');
	}
	ft_print_l(file, &max, path);
	if (options & LS_REC)
		if (file->mode & DT_DIR)
			dir = new_file(dir, file->name);
	ft_free(file);
	ft_putchar('\n');
	return (dir);
}
