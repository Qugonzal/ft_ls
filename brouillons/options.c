/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:08:10 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 04:59:04 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			no_option(char chr)
{
	ft_putstr("./ft_ls: illegal option -- '");
	ft_putchar(chr);
	ft_putstr("'\nusage: ./ft_ls [-lRart] [file ...]\n");
	exit(-1);
}

unsigned char		ft_hard_option(char *av, unsigned char *options)
{
	int j;

	j = 1;
	while (av[++j])
	{
		if (!(ft_strncmp("recursive", &av[j], ft_strlen(&av[j]))))
			*options = *options | LS_REC;
		else if (!(ft_strncmp("all", &av[j], ft_strlen(&av[j]))))
			*options = *options | LS_A;
		else if (!(ft_strncmp("reverse", &av[j], ft_strlen(&av[j]))))
			*options = *options | LS_R;
		else
			no_option(av[j]);
	}
	return (*options);
}

unsigned char		ft_normal_option(char *av, unsigned char *options)
{
	int j;

	j = 0;
	ft_putstr("normal option\n");
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
	return (*options);
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
			if ((av[i][j] == '-') && (av[i][j + 1] == '-'))
				options = ft_hard_option(&av[i][j], &options);
			else
				options = ft_normal_option(&av[i][j], &options);
	}
	return (options);
}
