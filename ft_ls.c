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
	while (file->next)
	{
		ft_putstr(file->name);
		ft_putstr("\n");
		if (file->mode == 4)
		{
			dir = new_file(dir, file->name);
		}
		file = file->next;
		free(file->prev);
	}
	ft_putstr(file->name);
	if (file->mode == 4)
	{
		dir = new_file(dir, file->name);
	}
	free(file);
	if (dir)
	{
		ft_link_list(dir);
		dir = ft_inverse_list(dir);
	}
	return (dir);
}

char	*ft_path(char **path, char *name)
{
	char *new_path;

	tmp = path;
	new_path = ft_strjoin(*path, name);
	free(*path);
	return (new_path);
}

void	ft_ls(DIR *dir, unsigned char options, char *path)
{
	struct dirent		*dirstream;
	t_file				*file;
	int					id;

	file = NULL;
	id = 0;
	while ((dirstream = readdir(dir)))
	{
		if (dirstream->d_name[0] != '.')
		{
			file = new_file(file, dirstream->d_name);
			file->mode = dirstream->d_type;
			file->id = id;
			id++;
		}
	}
	if (file)
	{
		ft_link_list(file);
		file = ft_ascii(file);
		file = ft_print_chk_dir(file);
		if ((options & LS_REC) && file)
		{
			while (file)
			{
				path = ft_path(&path, file->name);
				ft_putstr(path);
				ft_putstr(":\n");
				if (ft_check_open(file, path))
					ft_ls(file->dirstream, options, path);
				closedir(file->dirstream);
				if (file->next)
				{
					file = file->next;
					free(file->prev);
				}
				else
					free(file);
			}
		}
	}
}
