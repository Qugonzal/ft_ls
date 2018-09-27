/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:50:44 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_skip_current_t(t_file *list)
{
	t_file *tmp;
	t_file *file;

	file = list;
	while (file)
	{
		tmp = file;
		if (!ft_strcmp(".", file->name))
		{
			if (file == list)
				list = file->next;
			file = file->next;
			ft_unlink(tmp);
			free(tmp);
		}
		else if (!ft_strcmp("..", file->name))
		{
			if (file == list)
				list = file->next;
			file = file->next;
			ft_unlink(tmp);
			free(tmp);
		}
		else
			file = file->next;
	}
	return (list);
}

t_file	*ft_ls_all(DIR *dir, char options, t_file *file)
{
	struct dirent	*dirstream;
	int		id;

	id = 0;
	if (options & LS_A)
		while ((dirstream = readdir(dir)))
		{
			file = new_file(file, dirstream->d_name);
			file->mode = dirstream->d_type;
			file->id = id;
			id++;
		}
	else
		while ((dirstream = readdir(dir)))
			if (dirstream->d_name[0] != '.')
			{
				file = new_file(file, dirstream->d_name);
				file->mode = dirstream->d_type;
				file->id = id;
				id++;
			}
	return (file);
}

void	ft_ls(DIR *dir, unsigned char options, char *path)
{
	t_file		*file;
	t_file		*temp;
	char		*npath;

	file = NULL;
	temp = NULL;
	if (!dir)
	{
		ft_nodir(options, path);
		return ;
	}
	file = ft_ls_all(dir, options, file);
	if (file)
	{
		ft_link_list(file);
		file = ft_ascii(file);
		if (options & LS_T)
			file = ft_mtime(file, path);
		if (options & LS_R)
			file = ft_inverse_list(file);
		file = ft_print_chk_dir(file, path, options);
		if ((options & LS_REC) && file)
		{
			file = ft_skip_current_t(file);
			while (file)
			{
				npath = ft_path(path, file->name);
				if (options & LS_REC)
					ft_putpath(npath);
				if (ft_check_open(file, npath))
				{
					ft_ls(file->dirstream, options, npath);
					closedir(file->dirstream);
				}
				free(npath);
				temp = file;
				file = file->next;
				if (temp->attr)
					free(temp->attr);
				free(temp);
			}
		}
	}
}
