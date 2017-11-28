/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/28 06:16:25 by qugonzal         ###   ########.fr       */
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
	j = 0;
	options = 0;
	while (av[++i] && av[i][0] == '-')
	{
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

	i = 1;
	options = set_options(av, options);
	while (av[i] && av[i][0] == '-')
		i++;
	if (i < ac)
	{
		ft_putstr("arg\n");
	}
	else
//		ft_ls(".", options);
		ft_putstr("no arg\n");
	return (0);
}
