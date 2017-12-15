/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:15:24 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/15 05:29:21 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		*ft_place_first(t_arg *arg)
{
	t_arg	*index;

	index = arg;
	while (index->prev)
	{
		index = index->prev;
		if ((ft_strcmp(index->name, arg->name)) < 0)
			arg = index;
	}
	if (arg->prev)
	{
		ft_unlink_arg(arg);
		ft_insert_arg(arg, index, 'G');
	}
	return (arg);
}

t_arg		*ft_place_last(t_arg *arg)
{
	t_arg	*index;

	index = arg;
	while (index->next)
	{
		index = index->next;
		if ((ft_strcmp(index->name, arg->name)) > 0)
			arg = index;
	}
	if (arg->next)
	{
		ft_unlink_arg(arg);
		ft_insert_arg(arg, index, 'D');
	}
	return (arg);
}

t_arg		*ft_parse(t_arg *small, t_arg *big)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = small;
	index = small;
	while (index->ID != big->ID)
	{
		if ((ft_strcmp(index->name, tmp->name)) > 0)
			tmp = index;
		index = index->next;
	}
	if (ft_strcmp(tmp->name, small->name) == 0)
		return (small);
	ft_unlink_arg(tmp);
	ft_insert_arg(tmp, big, 'G');
	return (ft_parse(small, tmp));
}

t_arg		*ft_ascii_a(t_arg *arg_lst)
{
	t_arg	*big;

	big = ft_place_last(arg_lst);
	arg_lst = ft_place_first(big);
	return (ft_parse(arg_lst, big));
}
