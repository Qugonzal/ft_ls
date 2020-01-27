/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:12 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/27 16:26:41 by quegonza         ###   ########.fr       */
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

int					ft_hard_option(char *av, t_opt opt)
{
	int j;

	j = 1;
	while (av[++j])
	{
		if (!(ft_strncmp("recursive", &av[j], ft_strlen(&av[j]))))
			opt.option.rec = 1;
		else if (!(ft_strncmp("all", &av[j], ft_strlen(&av[j]))))
			*options = *options | (1 << 3);
		else if (!(ft_strncmp("reverse", &av[j], ft_strlen(&av[j]))))
			*options = *options | (1 << 4);
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
			*options = *options | (1 << 1);
		else if (av[j] == 'R')
			*options = *options | (1 << 2);
		else if (av[j] == 'a')
			*options = *options | (1 << 3);
		else if (av[j] == 'r')
			*options = *options | (1 << 4);
		else if (av[j] == 't')
			*options = *options | (1 << 5);
		else if (av[j] == '1')
		{
			if ((*options & (1 << 1)))
				*options = *options ^ (1 << 1);
			*options = *options | (1 << 6);
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
