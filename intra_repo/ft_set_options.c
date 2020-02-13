/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_options.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:12 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/28 17:23:36 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_no_option(char chr)
{
	ft_putstr("ls: illegal option -- ");
	ft_putchar(chr);
	ft_putstr("\nusage: ./ft_ls [-lRart] [file ...]\n");
	exit(-1);
}

t_opt	ft_hard_option(char *av, t_opt opt)
{
	int j;

	j = 1;
	while (av[++j])
	{
		if (!(ft_strncmp("recursive", &av[j], ft_strlen(&av[j]))))
			opt.option.rec = 1;
		else if (!(ft_strncmp("all", &av[j], ft_strlen(&av[j]))))
			opt.option.a = 1;
		else if (!(ft_strncmp("reverse", &av[j], ft_strlen(&av[j]))))
			opt.option.r = 1;
		else
			ft_no_option(av[j]);
	}
	return (opt);
}

void	ft_normal_option(char *av, t_opt *opt)
{
	int j;

	j = 0;
	while (av[++j])
	{
		if (av[j] == 'l')
			opt->option.l = 1;
		else if (av[j] == 'R')
			opt->option.rec = 1;
		else if (av[j] == 'a')
			opt->option.a = 1;
		else if (av[j] == 'r')
			opt->option.r = 1;
		else if (av[j] == 't')
			opt->option.t = 1;
		else if (av[j] == '1')
		{
			if ((opt->option.l))
				opt->option.l = 0;
			opt->option.one = 1;
		}
		else
			ft_no_option(av[j]);
	}
}

t_opt	ft_set_options(char **av, int *nb)
{
	t_opt	opt;
	int		i;

	i = 0;
	opt.value = 0;
	while (av[++i] && av[i][0] == '-')
	{
		if (av[i][1] == '-' && !av[i][2])
		{
			*nb = i + 1;
			return (opt);
		}
		if (!av[i][1])
		{
			*nb = i;
			return (opt);
		}
		else
			ft_normal_option(av[i], &opt);
	}
	*nb = i;
	return (opt);
}
