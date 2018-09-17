/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/17 18:43:49 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(t_file *nxt, char *name)
{
	t_file		*file;
	int		s;

	s = ft_strlen(name);
	if (s > 256)
	{
		ft_putstr("ls: ");
		ft_putstr(name);
		ft_putstr(": filename is too long\n");
		return (NULL);
	}
	if (!(file = (t_file *)malloc(sizeof(t_file))))
	{
		perror("malloc:");
		exit(-1);
	}
	if (!(file->attr = (t_stat *)malloc(sizeof(t_stat))))
	{
		perror("malloc :");
		exit(-1);
	}
	file->next = nxt;
	ft_strcpy(file->name, name);
	return (file);
}

t_file		*ft_place_young(t_file *list)
{
	t_file	*file;
	t_file	*tmp;

	tmp = list;
	file = list->next;
	while (file)
	{
		if (file->attr)
			if ((file->attr)->mtime > ((tmp->attr)->mtime))
				tmp = file;
		file = file->next;
	}
	if (tmp->prev && (tmp != list))
	{
		ft_unlink(tmp);
		ft_insert(tmp, list, 'G');
	}
	return (tmp);
}

t_file		*ft_mtimecopy(t_file *list, char *path)
{
	t_file 		*file;
	struct stat	sb;
	char		*tmp_path;

	file = list;
	while (file)
	{
		tmp_path = ft_path(path, file->name);
		if (lstat(tmp_path, &sb) == -1)
		{
			free(file->attr);
			file->attr = NULL;
			perror("stat");
		}
		else
			(file->attr)->mtime = sb.st_mtime;
		free(tmp_path);
		file = file->next;
	}
	return (ft_place_young(list));
}

t_file		*ft_mtime(t_file *list, char *path)
{
	t_file	*file;

	list = ft_mtimecopy(list, path);
	file = list->next;
	while (file)
	{
		file = ft_place_young(file);
		file = file->next;
	}
	return (list);
}

void		ft_link_list(t_file *file)
{
	t_file	*previous;
	t_file	*tmp;

	file->prev = NULL;
	tmp = file;
	while (tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
		tmp->prev = previous;
	}
}

t_file		*ft_print_chk_dir(t_file *file, char *path, char options)
{
	t_file *dir;

	dir = NULL;
	if (options & LS_L)
		dir = ft_ls_l(file, path, options);
	else
	{
		while (file)
		{
			if (file->prev)
				free(file->prev);
			ft_putstr(file->name);
			if (options & LS_1)
				ft_putstr("\n");
			else
				ft_putstr("  ");
			if (options & LS_REC)
				if (file->mode == 4)
					dir = new_file(dir, file->name);
			file = file->next;
		}
		if (!(options & LS_1))
			ft_putstr("\n");
		free(file);
	}
	if (dir)
	{
		ft_link_list(dir);
		dir = ft_inverse_list(dir);
	}
	return (dir);
}

char	*ft_path(char *path, char *name)
{
	char *new_path;
	int	s1;
	int	s2;

	s1 = ft_strlen(path);
	s2 = ft_strlen(name);
	if (!(new_path = (char *)ft_memalloc(s1 + s2 + 2)))
		return (NULL);
	ft_strncpy(new_path, path, s1);
	if (new_path[s1 - 1] != '/')
	{
		new_path[s1] = '/';
		ft_strncpy(&new_path[s1 + 1], name, s2);
	}
	else
		ft_strncpy(&new_path[s1], name, s2);
	return (new_path);
}

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

void	ft_putpath(char *path)
{
	ft_putstr("\n");
	ft_putstr(path);
	ft_putstr(":\n");
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
	file = ft_ls_all(dir, options, file);
	if (file)
	{
		ft_link_list(file);
		if (options & LS_T)
			file = ft_mtime(file, path);
		else
			file = ft_ascii(file);
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
