/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/06 05:58:15 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_n_free(t_arg **arg_tmp)
{
	t_arg *tmp;

	tmp = *arg_tmp;
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
	t_arg			**arg_lst;
	t_arg			*tmp_arg;

	i = 1;
	tmp_arg = NULL;
	options = 0;
	options = set_options(av, options);
	identifier = 0;
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (av[i])
		{
			tmp_arg = new_arg(av[i], tmp_arg);
			identifier = identifier + 1;
			tmp_arg->ID = identifier;
			i++;
		}
		arg_lst = ft_link_arg_lst(&tmp_arg);
		arg_lst = ft_ascii_a(arg_lst);
		ft_print_n_free(arg_lst);
//		ft_ls(&(*arg_lst), options);
	}
	else
//		ft_ls(".", options);
		ft_putstr("no arg\n");
	ft_error();
	return (0);
}
