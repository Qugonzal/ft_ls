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

t_file		*new_file(t_file *nxt, char *name)
{
	t_file		*file;

	if (!(file = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
	file->next = nxt;
	ft_strcpy(file->name, name);
	return (file);
}

void		ft_link_list(t_file *file)
{
	t_file	*previous;

	file->prev = NULL;
	while (file->next)
	{
		previous = file;
		file = file->next;
		file->prev = previous;
	}
}

void	ft_ls(DIR *dir, unsigned char options)
{
	struct dirent	*dirstream;
	t_file		file;
	int		id;

	file = NULL;
	id = 0;
	while (dirstream = readdir(dir))
	{
		file = new_file(file, dirstream->d_name);
		ft_memcpy(file->mode, &(dirstream->d_type), sizeof(unsigned char));
		file->id = id;
		id++;
	}
	ft_link_list(file);
	ft_print_and_free(file);
}
