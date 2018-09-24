/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/15 19:22:12 by qugonzal          #+#    #+#             */
/*   Updated: 2018/06/15 18:27:18 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <time.h>


static void		ft_putnbr_ll(long long n)
{
	if (n >= 10)
	{
		ft_putnbr_ll(n / 10);
		ft_putnbr_ll(n % 10);
	}
	else
		ft_putchar(n + '0');
}

void		ft_fillstat(t_stat *file, struct stat *sb)
{
	struct passwd	*usr;
	struct group	*grp;
	int		mode;

	file->mode = sb->st_mode;
	mode = file->mode & S_IFMT;
	file->nlink = sb->st_nlink;
	if (mode == S_IFCHR || mode == S_IFBLK)
		file->size = sb->st_rdev;
	else
		file->size = sb->st_size;
	file->mtime = sb->st_mtime;
	file->blocks = sb->st_blocks;
	if ((usr = getpwuid(sb->st_uid)) && usr->pw_name)
		file->user = usr->pw_name;
	else
		file->user = "error";
	if ((grp = getgrgid(sb->st_gid)) && grp->gr_name)
		file->group = grp->gr_name;
	else
		file->group = "error";
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

void		ft_max_mode(t_stat *file, t_stat *max)
{
	int		check;
	int		mode;

	check = file->size;
	mode = file->mode & S_IFMT;
	if ((mode == S_IFCHR) || (mode == S_IFBLK))
	{
		if (major(check) > max->mode)
			max->mode = major(check);
		if (minor(check) > max->size)
			max->size = minor(check);
	}
	else
	{
		if (!(max->mode))
			if (check > (int)(max->size))
				max->size = check;
	}
}

void		ft_checkmax(t_stat *file, t_stat *max)
{
	if ((file->nlink) > max->nlink)
		max->nlink = file->nlink;
	if (ft_strlen(file->user) > ft_strlen(max->user))
		max->user = file->user;
	if (ft_strlen(file->group) > ft_strlen(max->group))
		max->group = file->group;
	ft_max_mode(file, max);
	max->blocks = max->blocks + file->blocks;
}

void		ft_cut_time(char *str, time_t mtime)
{
	int	i;
	int	age;

	i = 3;
	age = (time(NULL) - mtime) / 60 / 60 / 24;
	if (-183 > age || age > 183)
	{
		while (++i < 11)
			write(1, &str[i], 1);
		i = i + 8;
		ft_putchar(' ');
		while (++i < 24)
			write(1, &str[i], 1);
	}
	else
		while (++i < 16)
			write(1, &str[i], 1);
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

int		ft_nostat(t_stat *max, char *name)
{
	ft_putchar('-');
	ft_putstr("????????? ");
	ft_printspace(0, max->nlink);
	ft_putstr("? ?");
	ft_printspace_str("?", max->user);
	ft_putstr(" ?");
	ft_printspace_str("?", max->group);
	ft_putstr(" ");
	ft_printspace(0, max->size);
	ft_putstr("?            ? ");
	ft_putstr(name);
	ft_putchar('\n');
	return (0);
}

void	ft_put_owners(t_file *file, t_stat *max)
{
	ft_putchar(' ');
	if ((file->attr)->user)
	{
		ft_putstr((file->attr)->user);
		ft_printspace_str((file->attr)->user, max->user);
	}
	else
	{
		ft_putstr("none");
		ft_printspace_str("none", max->user);
	}
	ft_putstr(" ");
	if ((file->attr)->group)
	{
		ft_putstr((file->attr)->group);
		ft_printspace_str((file->attr)->group, max->group);
	}
	else
	{
		ft_putstr("none");
		ft_printspace_str("none", max->user);
	}
	ft_putstr(" ");
}

void	ft_put_size_and_time(t_file *file, t_stat *max, int mode, int check)
{
	if (mode == S_IFCHR || mode == S_IFBLK)
	{
		ft_printspace(major(check), max->mode);
		ft_putnbr(major(check));
		ft_putchar(',');
		ft_printspace(minor(check), max->size);
		ft_putnbr(minor(check));
	}
	else
	{
		if (max->mode)
		{
			ft_putstr("  ");
			ft_printspace((file->attr)->size, max->mode * max->size);
		}
		else
			ft_printspace((file->attr)->size, max->size);
		ft_putnbr_ll((file->attr)->size);
	}
	ft_putchar(' ');
	ft_cut_time(ctime(&((file->attr)->mtime)), (file->attr)->mtime);
}

void	ft_put_name(t_file *file, int mode, char *path)
{
	char	*link;

	link = ft_memalloc(256);
	ft_putchar(' ');
	ft_putstr(file->name);
	if (mode == S_IFLNK)
	{
		ft_putstr(" -> ");
		if (!readlink(ft_path(path, file->name), link, 256))
			perror("readlink");
		else
		{
			ft_putstr(link);
			free(link);
		}
	}
	ft_putchar('\n');
}

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
		ft_putchar(' ');
		ft_printspace((file->attr)->nlink, max->nlink);
		ft_putnbr_ll((file->attr)->nlink);
		ft_put_owners(file, max);
		ft_put_size_and_time(file, max, mode, check);
	}
	else
		return (ft_nostat(max, file->name));
	ft_put_name(file, mode, path);
	if (file->attr)
		free(file->attr);
	return (1);
}


void		ft_fillcheck_stat(t_file *file, t_stat *max, char *path)
{
	struct stat	sb;
	t_file		*check;
	char		*tmp_path;

	check = file;
	while (check)
	{
		tmp_path = ft_path(path, check->name);
		if (lstat(tmp_path, &sb) == -1)
		{
			perror("lstat");
			free(check->attr);
			check->attr = NULL;
		}
		else
			ft_fillstat(check->attr, &sb);
		free(tmp_path);
		if (file->attr)
			ft_checkmax(check->attr, max);
		check = check->next;
	}
}

void		ft_init_max(t_stat *max)
{
	max->mode = 0;
	max->blocks = 0;
	max->nlink = 0;
	max->size = 0;
	max->user = "";
	max->group = "";
}

t_file		*ft_ls_l(t_file *file, char *path, unsigned char options)
{
	t_file		*dir;
	t_stat		max;

	dir = NULL;
	ft_init_max(&max);
	ft_fillcheck_stat(file, &max, path);
	ft_putstr("total ");
	ft_putnbr_ll(max.blocks);
	ft_putchar('\n');
	while (file->next)
	{
		ft_print_l(file, &max, path);
		if (options & LS_REC)
			if (file->mode == 4)
				dir = new_file(dir, file->name);
		file = file->next;
		free(file->prev);
	}
	ft_print_l(file, &max, path);
	if (options & LS_REC)
		if (file->mode == 4)
			dir = new_file(dir, file->name);
	free(file);
	return (dir);
}
