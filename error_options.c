/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:08:10 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/06 05:51:29 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_error(void)
{
	if (errno)
	{
		ft_putstr("Erreur, errno == ");
		ft_putnbr(errno);
		ft_putstr(":\n");
		ft_putstr(strerror(errno));
		ft_putstr("\n");
	}
}

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

