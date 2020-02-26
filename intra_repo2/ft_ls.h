/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:17 by quegonza          #+#    #+#             */
/*   Updated: 2020/02/26 16:20:03 by quegonza         ###   ########.fr       */
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
# include <sys/ioctl.h>
# include <sys/xattr.h>
# include <time.h>
# include <grp.h>
# include <pwd.h>

typedef	struct		s_op
{
	int	l:1;
	int	rec:1;
	int	a:1;
	int	r:1;
	int	t:1;
	int	one:1;
	int	u:1;
	int	g:1;
	int A:1;
	int other:23;
}					t_op;

typedef	union		u_opt
{
	int		value;
	t_op	option;
}					t_opt;

typedef struct		s_max
{
	mode_t			mode;
	nlink_t			nlink;
	int				user;
	int				group;
	off_t			size;
	time_t			mtime;
	blkcnt_t		blocks;
}					t_max;

typedef struct		s_stat
{
	mode_t			mode;
	nlink_t			nlink;
	char			*user;
	char			*group;
	off_t			size;
	time_t			mtime;
	blkcnt_t		blocks;
}					t_stat;

typedef struct		s_file
{
	int				id;
	char			name[260];
	DIR				*dirstream;
	unsigned char	mode;
	struct s_stat	*attr;
	struct s_file	*prev;
	struct s_file	*next;
}					t_file;

t_file				*new_file(t_file *nxt, char *name);
t_file				*ft_place_first(t_file *elem);
t_file				*ft_place_last(t_file *elem);
t_file				*ft_place_young(t_file *list);
t_file				*ft_inverse_list(t_file *file);
t_file				*ft_ascii(t_file *first);
t_file				*ft_parse(t_file *small, t_file *big);
t_file				*ft_mtime(t_file *list, char *path, t_opt opt);
t_file				*ft_mtimecopy(t_file *list, char *path, t_opt opt);
t_file				*ft_ls_all(DIR *dir, t_opt opt);
t_file				*ft_ls_l(t_file *file, char *path, t_opt opt);
t_file				*ft_skip_current_t(t_file *list);
t_file				*ft_print_chk_dir(t_file *file, char *path, t_opt opt);
t_file				*ft_put_ls1(t_file *file, t_opt opt);

void				ft_checkmax(t_stat *file, t_max *max);
void				ft_cut_time(char *str, time_t mtime);
void				ft_error(void);
void				ft_free(t_file *file);
void				ft_fillstat(t_stat *file, struct stat *sb, t_opt opt);
void				ft_fillcheck_stat(t_file *file, t_max *max, char *path, t_opt opt);
void				ft_insert(t_file *elem, t_file *dest, char option);
void				ft_init_max(t_max *max);
void				ft_link_list(t_file *file);
void				ft_ls(DIR *dir, t_opt opt, char *path);
void				ft_max_mode(t_stat *file, t_max *max);
void				ft_nodir(t_opt opt, char *path);
void				ft_print_n_free(t_file *arg_tmp);
void				ft_put_ufile(t_file **lst, t_file **list, t_opt opt);
void				ft_printspace_str(char *file_name, int max_len);
void				ft_printspace(long long nb, long long max);
void				ft_putpath(char *path);
void				ft_put_name(t_file *file, int mode, char *path);
void				ft_putnbr_ll(long long n);
void				ft_put_owners(t_file *file, t_max *max, t_opt opt);
void				ft_strfcat(char *s1, char *s2);
void				ft_unlink(t_file *elem);
void				ft_no_option(char chr);
void				ft_put_size_n_time(t_file *file, t_max *max,
		int mode, int check);
void				ft_lister(int *i, int *identifier, char **av,
		t_file **arg_lst);

char				*ft_path(char *path, char *name);
void				ft_clean_slash(char *path);

int					ft_check_open(t_file *dir, char *path);
t_opt				ft_set_options(char **av, int *i);
void				ft_normal_option(char *av, t_opt *opt);
int					ft_print_l(t_file *file, t_max *max, char *path, t_opt opt);
int					ft_lst_nodir(t_file **arg_lst, t_opt opt);
int					ft_put_mode(mode_t mode);
int					ft_put_right(mode_t mode);
int					ft_nostat(t_max *max, char *name);

#endif
