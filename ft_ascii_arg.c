/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:15:24 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 16:27:46 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_place_first(t_file *elem)
{
	t_file	*index;

	index = elem;
	while (index->prev)
	{
		index = index->prev;
		if ((ft_strcmp(index->name, elem->name)) < 0)
			elem = index;
	}
	if (elem->prev)
	{
		ft_unlink(elem);
		ft_insert(elem, index, 'G');
	}
	return (elem);
}

t_file		*ft_place_last(t_file *elem)
{
	t_file	*index;

	index = elem;
	while (index->next)
	{
		index = index->next;
		if ((ft_strcmp(index->name, elem->name)) > 0)
			elem = index;
	}
	if (elem->next)
	{
		ft_unlink(elem);
		ft_insert(elem, index, 'D');
	}
	return (elem);
}

t_file		*ft_parse(t_file *small, t_file *big)
{
	t_file	*tmp;
	t_file	*index;

	tmp = small;
	index = small;
	while (index->id != big->id)
	{
		if ((ft_strcmp(index->name, tmp->name)) > 0)
			tmp = index;
		index = index->next;
	}
	if (ft_strcmp(tmp->name, small->name) == 0)
		return (small);
	ft_unlink(tmp);
	ft_insert(tmp, big, 'G');
	return (ft_parse(small, tmp));
}

t_file		*ft_ascii(t_file *first)
{
	t_file	*last;

	last = ft_place_last(first);
	first = ft_place_first(last);
	return (ft_parse(first, last));
}
