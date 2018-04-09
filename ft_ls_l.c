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

	file->mode = sb->st_mode;
	file->nlink = sb->st_nlink;
	file->size = sb->st_size;
	file->mtime = sb->st_mtime;
	file->blocks = sb->st_blocks;
	if ((usr = getpwuid(sb->st_uid)))
		file->user = usr->pw_name;
	else
		file->user = "error";
	if ((grp = getgrgid(sb->st_gid)))
		file->group = grp->gr_name;
	else
		file->group = "error";
}

void		ft_printspace_str(char *file_name, char *max_name)
{
	int nb;

	nb = ft_strlen(max_name) - ft_strlen(file_name);
	while (nb)
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

void		ft_checkmax(t_stat *file, t_stat *max)
{
	if ((file->nlink) > max->nlink)
		max->nlink = file->nlink;
	if (ft_strlen(file->user) > ft_strlen(max->user))
		max->user = file->user;
	if (ft_strlen(file->group) > ft_strlen(max->group))
		max->group = file->group;
	if ((file->size) > max->size)
			max->size = file->size;
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

void		ft_put_right(mode_t mode)
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
		ft_putchar('?');
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
}

void		ft_nostat(t_stat *max)
{
	ft_putchar('-');
	ft_putstr("????????? ");
	ft_printspace(0, max->nlink);
	ft_putstr("? ?");
	ft_printspace_str("?", max->user);
	ft_putstr(" ?");
	ft_printspace_str("?", max->group);
	ft_putchar(' ');
	ft_printspace(0, max->size);
	ft_putstr("            ? ");
}

void		ft_print_l(t_file *file, t_stat *max)
{
	if (file->attr)
	{
		ft_put_right((file->attr)->mode);
		ft_putchar(' ');
		ft_printspace((file->attr)->nlink, max->nlink);
		ft_putnbr_ll((file->attr)->nlink);
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
		ft_putchar(' ');
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
		ft_putchar(' ');
		ft_printspace((file->attr)->size, max->size);
		ft_putnbr_ll((file->attr)->size);
		ft_putchar(' ');
		ft_cut_time(ctime(&((file->attr)->mtime)), (file->attr)->mtime);
	}
	else
		ft_nostat(max);
	ft_putchar(' ');
	ft_putstr(file->name);
	ft_putchar('\n');
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
			perror("stat");
			free(file->attr);
			file->attr = NULL;
//			ft_nostat(check->attr);
		}
		else
			ft_fillstat(check->attr, &sb);
		free(tmp_path);
		if (file->attr)
			ft_checkmax(check->attr, max);
		check = check->next;
	}
}

t_file		*ft_ls_l(t_file *file, char *path, unsigned char options)
{
	t_file		*dir;
	t_stat		max;

	dir = NULL;
	max.blocks = 0;
	max.nlink = 0;
	max.size = 0;
	max.user = "";
	max.group = "";
	ft_fillcheck_stat(file, &max, path);
	ft_putstr("total ");
	ft_putnbr_ll(max.blocks);
	ft_putchar('\n');
	while (file->next)
	{
		ft_print_l(file, &max);
		if (options & LS_REC)
			if (file->mode == 4)
				dir = new_file(dir, file->name);
		file = file->next;
		free(file->prev);
	}
	ft_print_l(file, &max);
	if (options & LS_REC)
		if (file->mode == 4)
			dir = new_file(dir, file->name);
	free(file);
	return (dir);
}
