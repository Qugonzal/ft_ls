/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:26:18 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/29 19:37:12 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_print_l(t_file *file, t_stat *max, char *path)
{
	int		check;
	int		mode;

	if (file->attr)
	{
		check = (file->attr)->size;
		mode  = (file->attr)->mode & S_IFMT;
		if (!ft_put_right((file->attr)->mode))
			return (ft_nostat(max, file->name));
		ft_putstr("  ");
		ft_printspace((file->attr)->nlink, max->nlink);
		ft_putnbr_ll((file->attr)->nlink);
		ft_put_owners(file, max);
		ft_put_size_and_time(file, max, mode, check);
	}
	else
		return (ft_nostat(max, file->name));
	ft_put_name(file, mode, path);
	return (1);
}

void		ft_putnbr_ll(long long n)
{
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + '0');
}

int		ft_put_mode(mode_t mode)
{
	mode_t check;

	check = (mode & S_IFMT);
	if (check == S_IFREG)
		ft_putchar('-');
	else if (check == S_IFDIR)
		ft_putchar('d');
	else if (check == S_IFIFO)
		ft_putchar('p');
	else if (check == S_IFCHR)
		ft_putchar('c');
	else if (check == S_IFBLK)
		ft_putchar('b');
	else if (check == S_IFSOCK)
		ft_putchar('s');
	else if (check == S_IFLNK)
		ft_putchar('l');
	else
		return (0);
	return (1);
}

int		ft_put_right(mode_t mode)
{
	mode_t check;

	if (!ft_put_mode(mode))
		return (0);
	check = (mode & ~S_IFMT);
	(check & S_IRUSR) ? ft_putstr("r") : ft_putstr("-");
	(check & S_IWUSR) ? ft_putstr("w") : ft_putstr("-");    
	(check & S_IXUSR) ? ft_putstr("x") : ft_putstr("-");
	(check & S_IRGRP) ? ft_putstr("r") : ft_putstr("-");
	(check & S_IWGRP) ? ft_putstr("w") : ft_putstr("-");
	(check & S_IXGRP) ? ft_putstr("x") : ft_putstr("-");
	(check & S_IROTH) ? ft_putstr("r") : ft_putstr("-");
	(check & S_IWOTH) ? ft_putstr("w") : ft_putstr("-");
	(check & S_IXOTH) ? ft_putstr("x") : ft_putstr("-");
	return (1);
}
