/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/20 16:33:36 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

# define	LS_L	(1 << 1)
# define	LS_REC	(1 << 2)
# define	LS_A	(1 << 3)
# define	LS_R	(1 << 4)
# define	LS_T	(1 << 5)

typedef struct		s_stat
{
	mode_t		mode;
	nlink_t		nlink;
	char		*user;
	char		*group;
	off_t		size;
	time_t		mtime;
	blkcnt_t	blocks;
}			t_stat;

typedef struct		s_file
{
	int		id;
	char		name[256];
	DIR		*dirstream;
	unsigned char	mode;
	struct s_stat	*attr;
	struct s_file	*prev;
	struct s_file	*next;
}			t_file;

t_file		*new_file(t_file *nxt, char *name);
t_file		*ft_place_first(t_file *elem);
t_file		*ft_place_last(t_file *elem);
t_file		*ft_inverse_list(t_file *file);
t_file		*ft_ascii(t_file *first);
t_file		*ft_parse(t_file *small, t_file *big);
t_file		*ft_mtime(t_file *list, char *path);  

void		ft_unlink(t_file *elem);
void		ft_link_list(t_file *file);
void		ft_insert(t_file *elem, t_file *dest, char option);

void		ft_ls(DIR *dir, unsigned char options, char *path);
t_file		*ft_ls_l(t_file *file, char *path, unsigned char options);

char		ft_check_open(t_file *dir, char *path);
char		*ft_path(char *path, char *name);

void		ft_error(void);
void		ft_print_n_free(t_file *arg_tmp);
void		ft_print(t_file *arg_tmp);

void		ft_print_options(unsigned char options);
void		no_option(char chr);
unsigned char	set_options(char **av);

#endif
