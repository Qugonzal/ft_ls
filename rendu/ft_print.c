/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:17:43 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:26:50 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_print_n_free(t_file *arg_tmp)
{
	t_file *tmp;

	tmp = arg_tmp;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
		ft_free(tmp->prev);
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
	ft_free(tmp);
}

t_file		*ft_print_chk_dir(t_file *file, char *path, char options)
{
	t_file *dir;
	t_file *tmp;

	dir = NULL;
	if (options & LS_L)
		dir = ft_ls_l(file, path, options);
	else
	{
		while (file)
		{
			tmp = file;
			ft_putstr(file->name);
			if (options & LS_1)
				ft_putstr("\n");
			else
				ft_putstr("  ");
			if (options & LS_REC)
				if (file->mode == 4)
					dir = new_file(dir, file->name);
			file = file->next;
			ft_free(tmp);
		}
		if (!(options & LS_1))
			ft_putstr("\n");
	}
	if (dir)
	{
		ft_link_list(dir);
		dir = ft_inverse_list(dir);
	}
	return (dir);
}

void		ft_printspace_str(char *file_name, char *max_name)
{
	int nb;

	nb = ft_strlen(max_name) - ft_strlen(file_name);
	while (nb > 0)
	{
		ft_putchar(' ');
		nb--;
	}
}

void		ft_printspace(long long nb, long long max)
{
	long long n;
	long long ord;

	n = max;
	ord = 0;
	while (n)
	{
		n = n / 10;
		ord++;
	}
	if (nb)
		n = nb;
	else
		n = 1;
	while (ord)
	{
		if (n)
			n = n / 10;
		else
			ft_putchar(' ');
		ord--;
	}
}
