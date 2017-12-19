/** ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/19 05:03:59 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
# include <stdio.h>
# include <sys/stat.h>
# include <sys/types.h>

# define	LS_L	(1 << 1)
# define	LS_REC	(1 << 2)
# define	LS_A	(1 << 3)
# define	LS_R	(1 << 4)
# define	LS_T	(1 << 5)

typedef struct		s_file
{
	struct s_file	*prev;
	struct s_file	*next;
	int				ID;
	char			name[256];
	DIR				*dirstream;
	mode_t			mode;
	nlink_t			nlink;
	uid_t			uid;
	gid_t			gid;
	off_t			size;
	time_t			mtime;
}					file;

void				ft_error(void);
void				ft_check_open(t_file *file_lst);
void				ft_print_n_free(t_file *file_tmp);
void				ft_print(t_file *file_tmp);
void				ft_unlink_file(t_file *file);
void				no_option(char chr);
unsigned char		set_options(char **av);
void				ft_insert_file(t_file *file, t_file *file_place, char option);
t_file				*new_file(char *name, t_file *nxt_elem);
void				ft_link_list(t_file *file_lst);
t_file				*ft_ascii(t_file *file_lst);
t_file				*ft_parse(t_file *small, t_file *big);
t_file				*ft_place_last(t_file *file);
t_file				*ft_place_first(t_file *file);

#endif
