/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/15 00:06:00 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 05:28:37 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_files_list(char *name)
{
	struct dirent	*dirstream;
	t_file			*file

	file = NULL;
	while (dirstream = readdir(name))
	{
		
	}
}

void	ft_ls(char *name unsigned char options)
{
}
