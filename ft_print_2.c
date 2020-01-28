/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:10 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/28 17:23:01 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_xattr(t_file *file, char *path)
{
	int		size;
	char	*str;
	mode_t	check;

	check = (file->attr)->mode & ~S_IFMT;
	size = 0;
	if (check & S_IROTH)
	{
		str = ft_path(path, file->name);
		ft_clean_slash(str);
		size = listxattr(str, NULL, 0, 0);
		free(str);
	}
	if (size > 0)
		ft_putstr("@ ");
	else
		ft_putstr("  ");
}

int		ft_print_l(t_file *file, t_max *max, char *path)
{
	int		check;
	int		mode;

	if (file->attr)
	{
		check = (file->attr)->size;
		mode = (file->attr)->mode & S_IFMT;
		if (!ft_put_right((file->attr)->mode))
			return (ft_nostat(max, file->name));
		ft_xattr(file, path);
		ft_printspace((file->attr)->nlink, max->nlink);
		ft_putnbr_ll((file->attr)->nlink);
		ft_put_owners(file, max);
		ft_put_size_n_time(file, max, mode, check);
	}
	else
		return (ft_nostat(max, file->name));
	ft_put_name(file, mode, path);
	return (1);
}

void	ft_putnbr_ll(long long n)
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
	(check & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(check & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISUID)
		(check & S_IXUSR) ? ft_putchar('s') : ft_putchar('S');
	else
		(check & S_IXUSR) ? ft_putchar('x') : ft_putchar('-');
	(check & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(check & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISGID)
		(check & S_IXGRP) ? ft_putchar('s') : ft_putchar('S');
	else
		(check & S_IXGRP) ? ft_putchar('x') : ft_putchar('-');
	(check & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(check & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if (mode & S_ISVTX)
		(check & S_IXOTH) ? ft_putchar('t') : ft_putchar('T');
	else
		(check & S_IXOTH) ? ft_putchar('x') : ft_putchar('-');
	return (1);
}
