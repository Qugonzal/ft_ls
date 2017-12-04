/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/30 18:25:49 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			no_option(char chr)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(chr);
	ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
	exit(-1);
}

unsigned char	set_options(char **av, unsigned char options)
{
	int		i;
	int		j;

	i = 0;
	options = 0;
	while (av[++i] && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j])
		{	
			if (av[i][j] == 'l')
				options = options | LS_L;
			else if (av[i][j] == 'R')
				options = options | LS_REC;
			else if (av[i][j] == 'a')
				options = options | LS_A;
			else if (av[i][j] == 'r')
				options = options | LS_R;
			else if (av[i][j] == 't')
				options = options | LS_T;
			else
				no_option(av[i][j]);
		}
	}
	return (options);
}

void		ft_print_n_free(t_arg **arg_tmp)
{
	while ((*arg_tmp)->next)
	{
		ft_putstr((*arg_tmp)->name);
		ft_putstr("\n");
		(*arg_tmp) = (*arg_tmp)->next;
		free((*arg_tmp)->prev);
	}
	ft_putstr((*arg_tmp)->name);
	ft_putstr("\n");
	free((*arg_tmp));
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
	return (0);
}
