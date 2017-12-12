/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/11 16:38:06 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print(t_arg *arg_tmp)
{
	t_arg *tmp;

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

void		ft_print_n_free(t_arg *arg_tmp)
{
	t_arg *tmp;

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

int		main(int ac, char **av)
{
	unsigned char	options;
	int				i;
	int				identifier;
	t_arg			*arg_lst;

	i = 1;
	arg_lst = NULL;
	options = set_options(av);
	identifier = 0;
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (av[i])
		{
			arg_lst = new_arg(av[i], arg_lst);
			identifier = identifier + 1;
			arg_lst->ID = identifier;
			i++;
		}
		ft_link_arg_lst(arg_lst);
		arg_lst = ft_ascii_a(arg_lst);
		ft_print_n_free(arg_lst);
//		ft_ls(&(*arg_lst_lst), options);
	}
	else
//		ft_ls(".", options);
		ft_putstr("no arg_lst\n");
	ft_error();
	return (0);
}
