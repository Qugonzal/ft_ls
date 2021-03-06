/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:13 by quegonza          #+#    #+#             */
/*   Updated: 2019/11/29 19:02:13 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_fillstat_ug(t_stat *file, struct stat *sb)
{
	struct passwd	*usr;
	struct group	*grp;

	if ((usr = getpwuid(sb->st_uid)) && usr->pw_name)
		file->user = ft_strdup(usr->pw_name);
	else
	{
		if (sb->st_uid)
			file->user = ft_strdup(ft_itoa(sb->st_uid));
		else
			file->user = ft_strdup("error");
	}
	if ((grp = getgrgid(sb->st_gid)) && grp->gr_name)
		file->group = ft_strdup(grp->gr_name);
	else
	{
		if (sb->st_gid)
			file->user = ft_strdup(ft_itoa(sb->st_gid));
		else
			file->group = ft_strdup("error");
	}
}

void		ft_fillstat(t_stat *file, struct stat *sb)
{
	int				mode;

	file->mode = sb->st_mode;
	mode = file->mode & S_IFMT;
	file->nlink = sb->st_nlink;
	if (mode == S_IFCHR || mode == S_IFBLK)
		file->size = sb->st_rdev;
	else
		file->size = sb->st_size;
	file->mtime = sb->st_mtime;
	file->blocks = sb->st_blocks;
	ft_fillstat_ug(file, sb);
}

void		ft_fillcheck_stat(t_file *file, t_max *max, char *path)
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
			ft_putstr("lstat: ");
			ft_putstr(path);
			perror(check->name);
			free(check->attr);
			check->attr = NULL;
		}
		else
			ft_fillstat(check->attr, &sb);
		free(tmp_path);
		if (check->attr)
			ft_checkmax(check->attr, max);
		check = check->next;
	}
}
