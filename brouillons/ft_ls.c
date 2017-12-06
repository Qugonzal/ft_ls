/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:30:29 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/30 18:25:42 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

d_list	*lister(struct dirent *file, d_list **list)
{
	d_list	*new;

	if (!(new = malloc(sizeof(d_list))))
		exit(-1);
	ft_strcpy((char *)new->name, file->d_name);
	new->next = *list;
	return (new);
}

void	ft_ls(char *name, unsigned char options)
{
	DIR				*dirstream;
	struct dirent	*elem;
	d_list			*list;
	d_list			*firstelem;

	dirstream = opendir(name);
	list = NULL;
	while ((elem = readdir(dirstream)))
		list = lister(elem, &list);
	firstelem = list;
	while (firstelem->next)
	{
		list = firstelem->next;
		free(firstelem);
		firstelem = list;
	}
	free(firstelem);
	closedir(dirstream);
}
