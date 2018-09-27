/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:04:07 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:32:32 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_nodir(unsigned char options, char *path)
{
	struct stat sb;
	t_file		*file;
	t_stat		max;

	if (options & LS_L)
	{
		file = new_file(NULL, path);
		ft_init_max(&max);
		if (lstat(file->name, &sb) == -1)
		{
			perror("lstat");
			free(file->attr);
			file->attr = NULL;
		}
		else
			ft_fillstat(file->attr, &sb);
		if (file->attr)
			ft_checkmax(file->attr, &max);
		ft_print_l(file, &max, path);
		free(file);
	}
	else
	{
		if (options & LS_1)
		{
			ft_putstr(path);
			ft_putstr("\n");
		}
		else
		{
			ft_putstr(path);
			ft_putstr("  ");
		}
	}
}

int		ft_lst_nodir(t_file **arg_lst, unsigned char options)
{
	t_file	*list;
	t_file	*file;
	int		f;

	file = *arg_lst;
	list = file;
	f = 0;
	while (file)
	{
		if (!(file->dirstream))
		{
			ft_print_ufiles(&file, &list, options);
			f = 1;
		}
		else
		{
			list = file;
			file = file->next;
		}
	}
	if (list)
		while (list->prev)
			list = list->prev;
	*arg_lst = list;
	return (f);
}

void	ft_print_ufiles(t_file **file_lst, t_file **list, unsigned char options)
{
	t_file	*tmp;
	t_file	*file;

	file = *file_lst;
	*list = file->prev;
	ft_ls(NULL, options, file->name);
	tmp = file;
	file = file->next;
	ft_unlink(tmp);
	free(tmp->attr);
	free(tmp);
	*file_lst = file;
}

int		ft_nostat(t_stat *max, char *name)
{
	ft_putchar('-');
	ft_putstr("?????????  ");
	ft_printspace(0, max->nlink);
	ft_putstr("? ?");
	ft_printspace_str("?", max->user);
	ft_putstr("  ?");
	ft_printspace_str("?", max->group);
	ft_putstr("  ");
	ft_printspace(0, max->size);
	ft_putstr("?            ? ");
	ft_putstr(name);
	ft_putchar('\n');
	return (0);
}
