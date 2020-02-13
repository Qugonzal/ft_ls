/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:16 by quegonza          #+#    #+#             */
/*   Updated: 2020/02/13 17:10:58 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
				ft_free((*arg_lst));
				(*arg_lst) = tmp_start;
			}
			(*identifier)++;
			(*i)++;
		}
	}
}

int		ft_fts_open(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_putstr("ls: ");
			errno = 2;
			perror(" ");
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_arg_lst(t_file *arg_lst, t_opt opt, int identifier)
{
	t_file	*tmp_start;

	if (opt.option.t)
		arg_lst = ft_mtime(arg_lst, "./");
	if (opt.option.r)
		arg_lst = ft_inverse_list(arg_lst);
	if (ft_lst_nodir(&arg_lst, opt) && arg_lst)
		ft_putstr("\n");
	while (arg_lst)
	{
		tmp_start = arg_lst;
		if (identifier > 1)
		{
			ft_putstr(arg_lst->name);
			ft_putstr(":\n");
		}
		ft_ls(arg_lst->dirstream, opt, arg_lst->name);
		if (arg_lst->dirstream)
			closedir(arg_lst->dirstream);
		if ((arg_lst = arg_lst->next))
			ft_putstr("\n");
		ft_free(tmp_start);
	}
}

void	ft_no_arg(t_file *arg_lst, t_opt opt)
{
	arg_lst = new_file(arg_lst, ".");
	if (!(ft_check_open(arg_lst, NULL)))
	{
		ft_free(arg_lst);
		perror("opendir");
	}
	ft_ls(arg_lst->dirstream, opt, ".");
	closedir(arg_lst->dirstream);
	ft_free(arg_lst);
}

int		main(int ac, char **av)
{
	int				i;
	int				identifier;
	t_file			*arg_lst;
	t_opt			opt;

	i = 1;
	arg_lst = NULL;
	opt = ft_set_options(av, &i);
	identifier = 0;
	if (!ft_fts_open(av))
		return (0);
	if (i < ac)
	{
		ft_lister(&i, &identifier, av, &arg_lst);
		if (arg_lst)
		{
			ft_link_list(arg_lst);
			arg_lst = ft_ascii(arg_lst);
			ft_arg_lst(arg_lst, opt, identifier);
		}
	}
	else
		ft_no_arg(arg_lst, opt);
	system("leaks ft_ls");
	return (0);
}
