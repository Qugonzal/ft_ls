/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 00:00:33 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/18 06:31:52 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include "libft/libft.h"
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>

typedef struct		dir_list
{
	char			name[256];
	struct dir_list	*next;
	struct dir_list	*prev;
}					d_list;

void	ft_ls(char *name);
d_list	*lister(struct dirent *file, d_list **list);

#endif
