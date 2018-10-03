/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 05:08:10 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 15:13:00 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_no_option(char chr)
{
	ft_putstr("./ft_ls: illegal option -- ");
	ft_putchar(chr);
	ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
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
			ft_no_option(av[j]);
	}
	return (*options);
}

unsigned char		ft_normal_option(char *av, unsigned char *options)
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
		else if (av[j] == '1')
			*options = *options | LS_1;
		else
			ft_no_option(av[j]);
	}
	return (*options);
}

unsigned char	ft_set_options(char **av, int *nb)
{
	unsigned char	options;
	int				i;

	i = 0;
	options = 0;
	while (av[++i] && av[i][0] == '-')
	{
		if (av[i][1] == '-' && !av[i][2])
		{
			*nb = i + 1;
			return (options);
		}
		if (!av[i][1])
		{
			*nb = i;
			return (options);
		}
		else
			options = ft_normal_option(av[i], &options);
	}
	*nb = i;
	return (options);
}
