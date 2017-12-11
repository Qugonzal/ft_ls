/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:15:24 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/11 17:55:30 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		ft_place_first(t_arg *arg)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = arg;
	index = arg;
	while (index->prev)
	{
		index = index->prev;
		if ((ft_strcmp(index->name, tmp->name)) < 0)
			tmp = index;
	}
	if (tmp->prev)
	{
		ft_unlink_arg(tmp);
		ft_insert_arg(tmp, index, 'G');
	}
}

void		ft_place_last(t_arg *arg)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = arg;
	index = arg;
	while (index->next)
	{
		index = index->next;
		if ((ft_strcmp(index->name, tmp->name)) > 0)
			tmp = index;
	}
	if (tmp->next)
	{
		ft_unlink_arg(tmp);
		ft_insert_arg(tmp, index, 'D');
	}
}

t_arg		*ft_parse(t_arg *small, t_arg *big)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = small;
/*	if (tmp->next)
		index = tmp->next;*/
	index = small;
/*	else
		return (small);*/
	if ((index->ID) == (big->ID))
		return (small);
	ft_putstr("yoyo\n");
	while (index->ID != big->ID)
	{
		ft_putstr("yoyo\n");
		if ((ft_strcmp(index->name, tmp->name)) > 0)
			tmp = index;
		index = index->next;
	}
	ft_unlink_arg(tmp);
	ft_insert_arg(tmp, big, 'G');
	return (ft_parse(small, tmp));
}

void		ft_ascii_a(t_arg *arg_lst)
{
	t_arg	*big;

	ft_place_last(arg_lst);
	big = arg_lst;
	ft_place_first(arg_lst);
	ft_parse(arg_lst, big);
}
