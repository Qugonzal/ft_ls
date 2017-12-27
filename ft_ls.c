/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/27 20:44:20 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(t_file *nxt, char *name)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
	file->next = nxt;
	ft_strcpy(file->name, name);
	return (file);
}

void		ft_link_list(t_file *file)
{
	t_file	*previous;
	t_file	*start_tmp;

	file->prev = NULL;
	if (file)
	{
		start_tmp = file;
		while (file->next)
		{
			previous = file;
			file = file->next;
			file->prev = previous;
		}
		file = start_tmp;
	}
	else
	{
		ft_putstr("FAIL");
		exit(-1);
	}
}

t_file		*ft_print_chk_dir(t_file *file)
{
	t_file *dir;

	dir = NULL;
	while (file)
	{
		ft_putstr(file->name);
		if (dir->mode == 4)
		{
			dir = new_file(file, file->name);
			ft_check_open(dir);
		}
	}
	ft_link_list(dir);
	ft_inverse_list(dir);
	return (dir);
}

void	ft_ls(DIR *dir, unsigned char options)
{
	struct dirent		*dirstream;
	t_file				*file;
	t_file				*start_tmp;
// t_file.   *dir
	int					id;

	file = NULL;
// dir = NULL;
	id = 0;
	ft_print_options(options);
	while ((dirstream = readdir(dir)))
	{
		file = new_file(file, dirstream->d_name);
		file->mode = dirstream->d_type;
//   if (file->mode = 4)
//      dir = new_file(dir, dirstream->name);

		file->id = id;
		id++;
	}
	ft_link_list(file);
	file = ft_ascii(file);
	start_tmp = file;
	ft_print_chk_dir(file);
/*	if ((options & LS_REC))
	{
		while ()
	}*/
	ft_print_n_free(start_tmp);
}
