/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:09 by quegonza          #+#    #+#             */
/*   Updated: 2020/02/14 18:12:37 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
**
**readlink + readdir/stat & chk if dir (then fil 'dir')
***
**padding (see testmain in 'test_line') 
**
*/
void		ft_chk_linkdir(t_file *dir, char *name)
{
	size_t	bufsize;

	
}

t_file		*ft_chk_dir(t_file *file, t_file **dire, t_opt opt)
{
	t_file			*tmp;
	t_file			*dir;
	unsigned char	check;

	check = file->mode;
	dir = *dire;
	if ((opt.option.one) && file->prev)
		ft_putstr("\n");
	else if (file->prev)
		ft_putstr("  ");
	tmp = file;
	ft_putstr(file->name);
	ft_putnbr(check);
	if (opt.option.rec)
	{
		if (check & DT_DIR)
			dir = new_file(dir, file->name);
		else if (check & DT_LNK)
//			ft_chk_linkdir(dir, file->name);
	}
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
