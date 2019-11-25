/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:17:43 by qugonzal          #+#    #+#             */
/*   Updated: 2019/11/21 17:42:08 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_chk_dir(t_file *file, t_file **dire, int options)
{
	t_file *tmp;
	t_file *dir;

	dir = *dire;
	if ((options & LS_1) && file->prev)
		ft_putstr("\n");
	else if (file->prev)
		ft_putstr("  ");
	tmp = file;
	ft_putstr(file->name);
	if (options & LS_REC)
		if ((file->mode & DT_DIR))
			dir = new_file(dir, file->name);
	*dire = dir;
	file = file->next;
	ft_free(tmp);
	return (file);
}

t_file		*ft_print_chk_dir(t_file *file, char *path, int options)
{
	t_file *dir;

	dir = NULL;
	if (options & LS_L)
		dir = ft_ls_l(file, path, options);
	else
		while (file)
			file = ft_chk_dir(file, &dir, options);
	if (dir)
	{
		ft_link_list(dir);
		dir = ft_inverse_list(dir);
	}
	if (!(options & LS_L))
		ft_putstr("\n");
	return (dir);
}

void		ft_printspace_str(char *file_name, int max_len)
{
	int nb;

	nb = max_len - ft_strlen(file_name);
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
