/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_arg_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 04:24:43 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/01 19:19:09 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
t_file		*new_arg(char *name, t_file *nxt_elem)
{
	t_file		*new;

	if (!(new = (t_file *)malloc(sizeof(t_arg))))
		exit(-1);
	ft_memcpy(new->name, name, ft_strlen(name) + 1);
	new->next = nxt_elem;
	return (new);
}*/

t_file		*new_file(t_file *nxt, char *name)
{
	t_file		*file;
	int		s;

	s = ft_strlen(name);
	if (s > 256)
	{
		ft_putstr("ls: ");
		ft_putstr(name);
		ft_putstr(": filename is too long\n");
		return (NULL);
	}
	if (!(file = (t_file *)malloc(sizeof(t_file))))
	{
		perror("malloc:");
		exit(-1);
	}
	if (!(file->attr = (t_stat *)malloc(sizeof(t_stat))))
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
			free(file->attr);
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
