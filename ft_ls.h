/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/30 18:25:55 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/libft.h"
# include <dirent.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>

# define	LS_L	(1 << 1)
# define	LS_REC	(1 << 2)
# define	LS_A	(1 << 3)
# define	LS_R	(1 << 4)
# define	LS_T	(1 << 5)

typedef struct		s_arg
{
	int		ID;
	struct s_arg	*prev;
	char		name[256];
	struct s_arg	*next;
}			t_arg;

t_arg			**ft_insert_arg(t_arg **arg, t_arg **arg_place, char option);
t_arg			*new_arg(char *name, t_arg *nxt_elem);
t_arg			**ft_link_arg_lst(t_arg **arg_lst);
t_arg			**ft_ascii_a(t_arg **arg_lst);
t_arg			**ft_parse(t_arg **small, t_arg **big);
t_arg			**ft_place_last(t_arg **arg);
t_arg			**ft_place_first(t_arg **arg);
void			ft_unlink_arg(t_arg **arg);

#endif
