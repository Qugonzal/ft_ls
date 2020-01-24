/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:06 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/24 19:38:17 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_ls_all(DIR *dir, char options)
{
	struct dirent	*dirstream;
	int				id;
	t_file			*file;

	id = 0;
	file = NULL;
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

t_file		*ft_recurse(t_file *file, char *path, int options)
{
	t_file	*temp;
	char	*npath;

	temp = NULL;
	ft_putchar('\n');
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
	return (file);
}

int			ft_iflink(char *path)
{
	struct stat sb;

	if (lstat(path, &sb) == -1)
	{
		ft_putstr("lstat: ");
		ft_putstr(path);
	}
	sb.st_mode = sb.st_mode & S_IFMT;
	if (sb.st_mode == S_IFLNK)
		return (1);
	else
		return (0);
}

void		ft_ls(DIR *dir, int options, char *path)
{
	t_file		*file;

	if (!dir || ft_iflink(path))
	{
		ft_nodir(options, path);
		return ;
	}
	file = ft_ls_all(dir, options);
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
				file = ft_recurse(file, path, options);
		}
	}
}
