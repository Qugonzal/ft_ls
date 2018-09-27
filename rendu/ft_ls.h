/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2018/09/27 19:14:28 by qugonzal         ###   ########.fr       */
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
# include <sys/ioctl.h>

# define	LS_L	(1 << 1)
# define	LS_REC	(1 << 2)
# define	LS_A	(1 << 3)
# define	LS_R	(1 << 4)
# define	LS_T	(1 << 5)
# define	LS_1	(1 << 6)

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

t_file			*new_file(t_file *nxt, char *name);
t_file			*ft_place_first(t_file *elem);
t_file			*ft_place_last(t_file *elem);
t_file			*ft_place_young(t_file *list);
t_file			*ft_inverse_list(t_file *file);
t_file			*ft_ascii(t_file *first);
t_file			*ft_parse(t_file *small, t_file *big);
t_file			*ft_mtime(t_file *list, char *path);  
t_file			*ft_mtimecopy(t_file *list, char *path);
t_file			*ft_ls_all(DIR *dir, char options, t_file *file);
t_file			*ft_ls_l(t_file *file, char *path, unsigned char options);
t_file			*ft_skip_current_t(t_file *list);
t_file			*ft_print_chk_dir(t_file *file, char *path, char options);

void			ft_checkmax(t_stat *file, t_stat *max);
void			ft_cut_time(char *str, time_t mtime);
void			ft_error(void);
void			ft_fillstat(t_stat *file, struct stat *sb);
void			ft_fillcheck_stat(t_file *file, t_stat *max, char *path);
void			ft_insert(t_file *elem, t_file *dest, char option);
void			ft_init_max(t_stat *max);
void			ft_link_list(t_file *file);
void			ft_lister(int *i, int *identifier, char **av, t_file **arg_lst);
void			ft_ls(DIR *dir, unsigned char options, char *path);
void			ft_max_mode(t_stat *file, t_stat *max);
void			ft_nodir(unsigned char options, char *path);
void			ft_print_n_free(t_file *arg_tmp);
void			ft_print_ufiles(t_file **file_lst, t_file **list, unsigned char options);
void			ft_printspace_str(char *file_name, char *max_name);
void			ft_printspace(long long nb, long long max);
void			ft_putpath(char *path);
void			ft_put_name(t_file *file, int mode, char *path);
void			ft_putnbr_ll(long long n);
void			ft_put_owners(t_file *file, t_stat *max);
void			ft_put_size_and_time(t_file *file, t_stat *max, int mode, int check);
void			ft_strfcat(char *s1, char *s2);
void			ft_unlink(t_file *elem);
void			ft_no_option(char chr);

char			ft_check_open(t_file *dir, char *path);
char			*ft_path(char *path, char *name);

unsigned char	ft_set_options(char **av);
unsigned char	ft_normal_option(char *av, unsigned char *options);

int				ft_print_l(t_file *file, t_stat *max, char *path);
int				ft_lst_nodir(t_file **arg_lst, unsigned char options);
int				ft_put_mode(mode_t mode);
int				ft_put_right(mode_t mode);
int				ft_nostat(t_stat *max, char *name);

#endif
