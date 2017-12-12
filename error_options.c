/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_options.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:08:10 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/12 21:01:58 by qugonzal         ###   ########.fr       */
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
	ft_putstr("./ft_ls: illegal option -- '");
	ft_putchar(chr);
	ft_putstr("'\nusage: ./ft_ls [-lRart] [file ...]\n");
	exit(-1);
}

int		*ft_hard_option(char *av, int *options)
{
	int j;

	j = 1;
	while (av[++j])
	{
		if ()
		else
			no_option(av[j]);
	}
	return (options);
}

int		*ft_normal_option(char *av, int *options)
{
	int j;

	j = 0;
	while (av[++j])
	{	
		if (av[j] == 'l')
			*options = *options | LS_L;
		else if (av[j] == 'R')
			*options = *options | LS_REC;
		else if (av[j] == 'a')
			*options = *options | LS_A;
		else if (av[j] == 'r')
			*options = *options | LS_R;
		else if (av[j] == 't')
			*options = *options | LS_T;
		else
			no_option(av[j]);
	}
	return (options);
}

unsigned char	set_options(char **av)
{
	int		i;
	int		j;
	unsigned char	options;

	i = 0;
	options = 0;
	while (av[++i] && av[i][0] == '-')
	{
		j = 0;
		while (av[i][++j])
		{	
			if (av[i][j] == '-')
				ft_hard_option(av[i], options);
			else
				ft_normal_option(av[i], options);
		}
	}
	return (options);
}
