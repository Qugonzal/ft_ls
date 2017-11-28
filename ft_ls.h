/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/28 04:04:34 by qugonzal         ###   ########.fr       */
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

/*typedef struct			s_list
{
	char				name[256];
	struct s_list		*next;
	struct s_list		*prev;
}						t_list;

void					ft_ls(char *name);
d_list					*lister(struct dirent *file, d_list **list);
*/
#endif
