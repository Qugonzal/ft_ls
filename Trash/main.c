/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/13 13:37:27 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_options(unsigned char options)
{
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
		ft_putnbr(tmp->mode);
		ft_putstr(" :mode\n");
		tmp = tmp->next;
		free(tmp->prev);
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
	free(tmp);
}

int		main(int ac, char **av)
{
	unsigned char	options;
	int				i;
	int				identifier;
	t_file			*arg_lst;
	t_file			*tmp_start;

	i = 1;
	arg_lst = NULL;
	options = set_options(av);
	ft_print_options(options);
	identifier = 0;
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (av[i])
		{
			arg_lst = new_file(arg_lst, av[i]);
			arg_lst->id = identifier;
			if (ft_check_open(arg_lst))
				identifier++;
			i++;
		}
		ft_link_list(arg_lst);
		arg_lst = ft_ascii(arg_lst);
		tmp_start = arg_lst;
		while (arg_lst)
		{
			ft_putstr(" ---- ");
			ft_putstr(arg_lst->name);
			ft_putstr(" ---- :\n");
			ft_ls(arg_lst->dirstream, options);
			closedir(arg_lst->dirstream);
			arg_lst = arg_lst->next;
		}
		ft_print_n_free(tmp_start);
//		ft_ls(&(*arg_lst_lst), options);
	}
	else
	{
		ft_ls(opendir("."), options);
	}
	ft_error();
	return (0);
}