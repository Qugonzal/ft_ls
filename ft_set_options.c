/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:12 by quegonza          #+#    #+#             */
/*   Updated: 2019/11/29 19:02:12 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void				ft_no_option(char chr)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(chr);
	ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
	exit(-1);
}

int					ft_hard_option(char *av, int *options)
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

int					ft_normal_option(char *av, int *options)
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
		{
			if ((*options & LS_L))
				*options = *options ^ LS_L;
			*options = *options | LS_1;
		}
		else
			ft_no_option(av[j]);
	}
	return (*options);
}

int					ft_set_options(char **av, int *nb)
{
	int	options;
	int	i;

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
