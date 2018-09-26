/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/26 18:47:52 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
   void		ft_print_options(unsigned char options)
   {
   if (options) 
   {
   ft_putstr("-- OPTIONS --> ");
   if (options & LS_L)
   ft_putstr("-l\n");
   if (options & LS_REC)
   ft_putstr("-R\n");
   if (options & LS_A)
   ft_putstr("-a\n");
   if (options & LS_R)
   ft_putstr("-r\n");
   if (options & LS_T)
   ft_putstr("-t\n");
   }
   else
   ft_putstr("-- NO OPTIONS --\n");
   }*/

void		ft_print(t_file *arg_tmp)
{
	t_file *tmp;

	tmp = arg_tmp;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
}

void		ft_print_n_free(t_file *arg_tmp)
{
	t_file *tmp;

	tmp = arg_tmp;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
		free(tmp->prev);
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
	free(tmp);
}

void	ft_lister(int *i, int *identifier, char **av, t_file **arg_lst)
{
	t_file		*tmp_start;

	while (av[*i])
	{
		(*arg_lst) = new_file((*arg_lst), av[*i]);
		if (!(*arg_lst))
			(*i)++;
		else
		{
			(*arg_lst)->id = *identifier;
			if (!(ft_check_open((*arg_lst), NULL)))
			{
				tmp_start = (*arg_lst)->next;
				free((*arg_lst));
				(*arg_lst) = tmp_start;
			}
			(*identifier)++;
			(*i)++;
		}
	}
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

int		main(int ac, char **av)
{
	unsigned char	options;
	t_file			*tmp_start;
	int				i;
	int				identifier;
	t_file			*arg_lst;

	i = 1;
	arg_lst = NULL;
	options = set_options(av);
	identifier = 0;
	while (av[i] && av[i][0] == '-' && av[i][1])
		i++;
	if (i < ac)
	{
		ft_lister(&i, &identifier, av, &arg_lst);
		if (arg_lst)
		{
			ft_link_list(arg_lst);
			arg_lst = ft_ascii(arg_lst);
			if (options & LS_T)
				arg_lst = ft_mtime(arg_lst, "./");
			if (options & LS_R)
				arg_lst = ft_inverse_list(arg_lst);
			if (ft_lst_nodir(&arg_lst, options))
				ft_putstr("\n");
			while (arg_lst)
			{
				tmp_start = arg_lst;
				if (identifier > 1)
				{
					ft_putstr(arg_lst->name);
					ft_putstr(":\n");
				}
				ft_ls(arg_lst->dirstream, options, arg_lst->name);
				if (arg_lst->dirstream)
					closedir(arg_lst->dirstream);
				if ((arg_lst = arg_lst->next))
					ft_putchar('\n');
				free(tmp_start);
			}
		}
	}
	else
	{
		ft_ls(opendir("."), options, ".");
	}
	return (0);
}
