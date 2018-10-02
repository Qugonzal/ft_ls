/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:04:07 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/02 16:12:41 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_put_ls1(unsigned char options, char *path)
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
		ft_free(file);
		ft_putchar('\n');
	}
	else
		ft_put_ls1(options, path);
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
			ft_put_ufile(&file, &list, options);
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

void	ft_put_ufile(t_file **lst, t_file **list, unsigned char options)
{
	t_file	*tmp;
	t_file	*file;

	file = *lst;
	*list = file->prev;
	ft_ls(NULL, options, file->name);
	tmp = file;
	file = file->next;
	ft_unlink(tmp);
	ft_free(tmp);
	*lst = file;
}
