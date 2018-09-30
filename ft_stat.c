/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/27 19:37:52 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:41:05 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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

