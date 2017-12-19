/**************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/19 05:08:49 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print(t_file *file_tmp)

	tmp = file_tmp;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
}

void		ft_print_n_free(t_file *file_tmp)
{
	t_file *tmp;

	tmp = file_tmp;
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
	t_file			*file_lst;

	i = 1;
	file_lst = NULL;
	options = set_options(av);
	identifier = 0;
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		while (av[i])
		{
			file_lst = new_file(av[i], file_lst);
			if (ft_check_open(file_lst))
			{
				identifier = identifier + 1;
				file_lst->id = identifier;
			}
			i++;
		}
		ft_link_file_lst(file_lst);
		ft_print_n_free(ft_ascii(file_lst));
	}
	else
		ft_putstr("no arg\n");
	ft_error();
	return (0);
}
