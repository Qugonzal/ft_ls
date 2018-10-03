/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:36:41 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 18:44:46 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_cut_time(char *str, time_t mtime)
{
	int	i;
	int	age;

	i = 3;
	age = (time(NULL) - mtime) / 60 / 60 / 24;
	if (-183 > age || age > 183)
	{
		while (++i < 11)
			write(1, &str[i], 1);
		i = i + 8;
		ft_putchar(' ');
		if (str[22] == ' ')
		{
			i = i + 4;
			while (++i < 29)
				write(1, &str[i], 1);
		}
		else
			while (++i < 24)
				write(1, &str[i], 1);
	}
	else
		while (++i < 16)
			write(1, &str[i], 1);
}

void		ft_put_size_n_time(t_file *file, t_stat *max, int mode, int check)
{
	char *str;

	if (mode == S_IFCHR || mode == S_IFBLK)
	{
		ft_printspace(major(check), max->mode);
		ft_putnbr(major(check));
		ft_putchar(',');
		ft_printspace(minor(check), max->size);
		ft_putnbr(minor(check));
	}
	else
	{
		if (max->mode)
		{
			ft_putstr("  ");
			ft_printspace((file->attr)->size, max->mode * max->size);
		}
		else
			ft_printspace((file->attr)->size, max->size);
		ft_putnbr_ll((file->attr)->size);
	}
	ft_putchar(' ');
	str = ctime(&((file->attr)->mtime));
	ft_cut_time(str, (file->attr)->mtime);
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
	t_file		*file;
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
