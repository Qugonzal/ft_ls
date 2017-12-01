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

int		main(int ac, char **av)
{
	unsigned char	options;
	int				i;
	t_arg			*arg_lst;
	t_arg			*tmp;

	i = 1;
	arg_lst = NULL;
	options = 0;
	options = set_options(av, options);
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (av[i])
		{
			arg_lst = new_arg(av[i], &arg_lst);
			i++;
		}
		arg_lst = ft_link(arg_lst);
		while (arg_lst->next)
		{
			if (ft_strchr(arg_lst->name, 'Z'))
			{
				ft_unlink_arg(arg_lst);
				tmp = arg_lst->next;
				while (tmp->next)
					tmp = tmp->next;
				ft_insert_arg(arg_lst, tmp, 1);
			}
			arg_lst = arg_lst->next;
		}
		while (arg_lst->prev)
			arg_lst = arg_lst->prev;
		while (arg_lst->next)
		{
			ft_putstr(arg_lst->name);
			ft_putstr("\n");
			arg_lst = arg_lst->next;
			free(arg_lst->prev);
		}
		ft_putstr(arg_lst->name);
		ft_putstr("\n");
		free(arg_lst);
//		ft_ls(&arg_lst, options);
	}
	else
//		ft_ls(".", options);
		ft_putstr("no arg\n");
	return (0);
}
