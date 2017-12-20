/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/20 17:22:50 by qugonzal         ###   ########.fr       */
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
	start_tmp = file;
	while (file->next)
	{
		previous = file;
		file = file->next;
		file->prev = previous;
	}
	file = start_tmp;
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
	ft_print_n_free(start_tmp);
	if (options & LS_REC)
	{
		while (dir)
		{
				if (ft_check_open(file))
					ft_ls(file->dirstream, options);
			}
			file = file->next;
		}
	}
}
