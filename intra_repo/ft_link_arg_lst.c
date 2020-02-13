/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_arg_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:02:04 by quegonza          #+#    #+#             */
/*   Updated: 2020/01/28 16:16:17 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*new_file(t_file *nxt, char *name)
{
	t_file	*file;
	int		s;

	s = ft_strlen(name);
	if (s > 256)
	{
		ft_putstr("ls: ");
		ft_putstr(name);
		ft_putstr(": filename is too long\n");
		return (NULL);
	}
	if (!(file = (t_file *)ft_memalloc(sizeof(t_file))))
	{
		perror("malloc:");
		exit(-1);
	}
	if (!(file->attr = (t_stat *)ft_memalloc(sizeof(t_stat))))
	{
		perror("malloc :");
		exit(-1);
	}
	file->next = nxt;
	ft_strcpy(file->name, name);
	return (file);
}

void		ft_link_list(t_file *file)
{
	t_file	*previous;
	t_file	*tmp;

	file->prev = NULL;
	tmp = file;
	while (tmp->next)
	{
		previous = tmp;
		tmp = tmp->next;
		tmp->prev = previous;
	}
}

void		ft_free(t_file *file)
{
	if (file)
	{
		if (file->attr)
		{
			if ((file->attr)->user)
				free((file->attr)->user);
			if ((file->attr)->group)
				free((file->attr)->group);
			free(file->attr);
		}
		free(file);
	}
	file = NULL;
}

void		ft_unlink(t_file *elem)
{
	if (elem->prev)
		(elem->prev)->next = elem->next;
	if (elem->next)
		(elem->next)->prev = elem->prev;
}

void		ft_insert(t_file *elem, t_file *dest, char option)
{
	if (option == 'G')
	{
		elem->next = dest;
		elem->prev = dest->prev;
		if (dest->prev)
			(dest->prev)->next = elem;
		dest->prev = elem;
	}
	else
	{
		elem->next = dest->next;
		elem->prev = dest;
		if (dest->next)
			(dest->next)->prev = elem;
		dest->next = elem;
	}
}
