/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_link_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 04:24:43 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/01 16:54:33 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

void		ft_link_list(t_file *file_lst)
{
	t_file	*tmp;
	t_file	*start;

	start = file_lst;
	file_lst->prev = NULL;
	while (file_lst->next)
	{
		tmp = file_lst;
		file_lst = file_lst->next;
		file_lst->prev = tmp;
	}
	file_lst = start;
}

t_file		*new_file(char *name, t_file *nxt_elem)
{
	t_file		*new;

	if (!(new = (t_file *)malloc(sizeof(t_file))))
		exit(-1);
	ft_memcpy(new->name, name, ft_strlen(name) + 1);
	new->next = nxt_elem;
	return (new);
}

void		ft_unlink_file(t_file *file)
{
	if (file->prev)
		(file->prev)->next = file->next;
	if (file->next)
		(file->next)->prev = file->prev;
}

void		ft_insert_file(t_file *file, t_file *file_place, char option)
{
	if (option == 'G')
	{
		file->next = file_place;
		file->prev = file_place->prev;
		if (file_place->prev)
			(file_place->prev)->next = file;
		file_place->prev = file;
	}
	else
	{
		file->next = file_place->next;
		file->prev = file_place;
		if (file_place->next)
			(file_place->next)->prev = file;
		file_place->next = file;
	}
}
