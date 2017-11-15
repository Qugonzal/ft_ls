/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:30:29 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/15 05:50:55 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

d_list	*lister(struct dirent *file, d_list **list)
{
	d_list	*new;

	if (!(new = malloc(sizeof(d_list))))
		exit(-1);
	new->name = (char[256])ft_strcpy(new->name, file->d_name);
	new->next = *list;
	return (new);
}

void	ft_ls(char *name)
{
	DIR				*dirstream;
	struct dirent	*elem;
	d_list			*list;
	d_list			*firstelem;

	dirstream = opendir(name);
	if (!(list = malloc(sizeof(d_list))))
		exit(-1);
//	list->name = "ho";
//	ft_putstr(list->name);
//	ft_putstr("\n");
	elem = readdir(dirstream);
//	ft_putstr(elem->d_name);
//	ft_putstr("\nWWWWW");
	(char *)list->name = ft_strcpy((char *)list->name, elem->d_name);
	list->next = NULL;
	while ((elem = readdir(dirstream)))
	{
		list = lister(elem, &list);
	}
	firstelem = list;
	while (list->next)
	{
		ft_putstr(list->name);
		list = list->next;
	}
	while (firstelem->next)
	{
		list = firstelem->next;
		free(firstelem);
		firstelem = list;
	}
	free(firstelem);
	closedir(dirstream);
	ft_putnbr(errno);
}
