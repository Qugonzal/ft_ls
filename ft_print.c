/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:09 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/28 17:11:55 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_chk_dir(t_file *file, t_file **dire, t_opt opt)
{
	t_file *tmp;
	t_file *dir;
	mode_t check;

	check = ((file->attr)->mode & S_IFMT);
	dir = *dire;
	if ((opt.option.one) && file->prev)
		ft_putstr("\n");
	else if (file->prev)
		ft_putstr("  ");
	tmp = file;
	ft_putstr(file->name);
	if (opt.option.rec)
		if (check == S_IFDIR)
			dir = new_file(dir, file->name);
	*dire = dir;
	file = file->next;
	ft_free(tmp);
	return (file);
}

t_file		*ft_print_chk_dir(t_file *file, char *path, t_opt opt)
{
	t_file *dir;

	dir = NULL;
	if (opt.option.l)
		dir = ft_ls_l(file, path, opt);
	else
		while (file)
			file = ft_chk_dir(file, &dir, opt);
	if (dir)
	{
		ft_link_list(dir);
		dir = ft_inverse_list(dir);
	}
	if (!(opt.option.l))
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
