/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/01 21:42:24 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_skip(t_file *file)
{
	t_file	*next;

	next = file->next;
	if ((file->name[1] == '\0') || (file->name[1] == '.'))
	{
		if (!ft_strcmp(".", file->name))
		{
			ft_unlink(file);
			ft_free(file);
			return (next);
		}
		else if (!ft_strcmp("..", file->name))
		{
			ft_unlink(file);
			ft_free(file);
			return (next);
		}
	}
	return (next);
}

void		ft_skip_current_t(t_file **lst)
{
	t_file	*tmp;
	t_file	*file;

	file = *lst;
	tmp = file;
	while (file)
	{
		if (file->prev)
			tmp = file->prev;
		if (file->name[0] == '.')
			file = ft_skip(file);
		else
			file = file->next;
	}
	if (tmp)
		while (tmp->prev)
			tmp = tmp->prev;
	*lst = tmp;
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

void	ft_free_list(t_file *file)
{
	t_file	*tmp;
	while (file)
	{
		tmp = file;
		file = file->next;
		ft_free(tmp);
	}
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
			ft_skip_current_t(&file);
			while (file)
			{
				ft_putstr("\n\n");
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
				ft_free(temp);
			}
		}
	}
}
