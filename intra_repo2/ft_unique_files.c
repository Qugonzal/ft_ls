/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unique_files.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:15 by quegonza          #+#    #+#             */
/*   Updated: 2020/02/26 19:12:07 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_put_ls1(t_file *file, t_opt opt)
{
	t_file *tmp;

	tmp = file;
	while (file)
	{
		ft_putstr(file->name);
		file = file->next;
	}
	ft_putstr("\n");
	file = tmp;
	if (opt.option.A)
		file = ft_skip_current_t(file);
	tmp = file;
	while (file)
	{
		ft_putstr(file->name);
		file = file->next;
	}
	file = tmp;
	if (file)
	{
		if ((opt.option.one) && file->prev)
			ft_putstr("\n");
		else if (file->prev)
			ft_putstr("  ");
		ft_putstr(file->name);
	}
	return (file);
}

void	ft_nodir(t_opt opt, char *path)
{
	struct stat sb;
	t_file		*file;
	t_max		max;

	if (opt.option.l)
	{
		file = new_file(NULL, path);
		ft_init_max(&max);
		if (lstat(file->name, &sb) == -1)
		{
			free(file->attr);
			file->attr = NULL;
		}
		else
			ft_fillstat(file->attr, &sb, opt);
		if (file->attr)
			ft_checkmax(file->attr, &max);
		ft_print_l(file, &max, "./", opt);
		ft_free(file);
		ft_putchar('\n');
	}
	else
		ft_putstr(path);
}

void	ft_rewind_lst(t_file **list)
{
	if (*list)
		while ((*list)->prev)
			*list = (*list)->prev;
}

int		ft_lst_nodir(t_file **arg_lst, t_opt opt)
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
			ft_put_ufile(&file, &list, opt);
			f = 1;
		}
		else
		{
			list = file;
			file = file->next;
		}
	}
	ft_rewind_lst(&list);
	*arg_lst = list;
	if (f & !(opt.option.l))
		ft_putchar('\n');
	return (f);
}

void	ft_put_ufile(t_file **lst, t_file **list, t_opt opt)
{
	t_file	*tmp;
	t_file	*file;

	file = *lst;
	*list = file->prev;
	ft_ls(NULL, opt, file->name);
	tmp = file;
	if ((file = file->next))
	{
		if (opt.option.one)
			ft_putchar('\n');
		else if (!(opt.option.l))
			ft_putstr("  ");
	}
	ft_unlink(tmp);
	ft_free(tmp);
	*lst = file;
}
