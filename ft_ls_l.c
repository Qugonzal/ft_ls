#include "ft_ls.h"
#include <time.h>


char		*ft_conv_right(unsigned long n)
{
	char i;
	char *right;

	if (!(right = ft_memalloc(sizeof(char) * 4)))
	{
		perror("malloc:");
		exit(-1);
	}
	i = 3;
	while (i)
	{
		if (n >= 8)
		{
			n /= 8;
			right[i - 1] = (n % 8) + '0';
		}
		i--;
	}
	return (right);
}

static void		ft_putnbr_ul_octal(unsigned long n)
{
	if (n >= 8)
	{
		ft_putnbr_ul_octal(n / 8);
		ft_putnbr_ul_octal(n % 8);
	}
	else
		ft_putchar(n + '0');
}

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

t_stat		*ft_fillstat(struct stat *sb)
{
	struct passwd	*usr;
	struct group	*grp;
	t_stat		*file;

	if (!(file = malloc(sizeof(t_stat))))
	{
		perror("malloc :");
		exit(-1);
	}
	if (sb->st_mode)
		file->mode = sb->st_mode;
	else
		file->mode = 0;
	if (sb->st_nlink)
		file->nlink = sb->st_nlink;
	else
		file->nlink = 0;
	if ((usr = getpwuid(sb->st_uid)))
	{
		file->user = usr->pw_name;
		ft_putstr(usr->pw_dir);
		ft_putnbr_ll(usr->pw_gid);
		ft_putstr(usr->pw_gecos);
	}
	else
		file->user = "error";
	if ((grp = getgrgid(sb->st_gid)))
	{
		file->group = grp->gr_name;
	}
	else
		file->group = "error";
	if (sb->st_size)
		file->size = sb->st_size;
	else
		file->size = 0;
	if (sb->st_mtime)
		file->mtime = sb->st_mtime;
	else
		file->mtime = 0;
	if (sb->st_blocks)
		file->blocks = sb->st_blocks;
	else
		file->blocks = 0;
	return (file);
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
	if (file->nlink)
		if ((file->nlink) > max->nlink)
			max->nlink = file->nlink;
	if (file->user)
		if (ft_strlen(file->user) > ft_strlen(max->user))
			max->user = file->user;
	if (file->group)
		if (ft_strlen(file->group) > ft_strlen(max->group))
			max->group = file->group;
	if (file->size)
		if ((file->size) > max->size)
			max->size = file->size;
	max->blocks = max->blocks + file->blocks;
}

void		ft_cut_time(char *time)
{
	int	i;

	i = 4;
	while (i < 16)
	{
		write(1, &time[i], 1);
		i++;
	}
}

void		ft_print_ls(t_file *file, t_stat *max)
{
	ft_putnbr_ll((file->attr)->nlink);
	ft_printspace((file->attr)->nlink, max->nlink);
	ft_putchar(' ');
	if ((file->attr)->user)
		ft_putstr((file->attr)->user);
	else
		ft_putstr("none");
	ft_putchar(' ');
	if ((file->attr)->group)
		ft_putstr((file->attr)->group);
	else
		ft_putstr("none");
	ft_putchar(' ');
	ft_putnbr_ll((file->attr)->size);
	ft_printspace((file->attr)->size, max->size);
	ft_putchar(' ');
	ft_cut_time(ctime(&((file->attr)->mtime)));
	ft_putchar(' ');
	ft_putnbr_ul_octal((file->attr)->mode);
	ft_putchar(' ');
	ft_putstr(file->name);
	ft_putchar('\n');
	free(file->attr);
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
		if (stat(tmp_path, &sb) == -1)
			perror("stat");
		else
			check->attr = ft_fillstat(&sb);
		free(tmp_path);
		ft_checkmax(check->attr, max);
		check = check->next;
	}
}

t_file			*ft_ls_l(t_file *file, char *path, unsigned char options)
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
		ft_print_ls(file, &max);
		if (options & LS_REC)
			if (file->mode == 4)
				dir = new_file(dir, file->name);
		file = file->next;
		free(file->prev);
	}
	ft_print_ls(file, &max);
	if (options & LS_REC)
		if (file->mode == 4)
			dir = new_file(dir, file->name);
	free(file);
	if (dir)
		return (dir);
	else
		return (NULL);
}
