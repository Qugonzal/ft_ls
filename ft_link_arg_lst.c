/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_arg_lst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 04:24:43 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 05:29:12 by qugonzal         ###   ########.fr       */
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
