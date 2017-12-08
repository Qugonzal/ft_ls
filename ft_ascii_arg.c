/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ascii_arg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:15:24 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/08 05:33:09 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		**ft_place_first(t_arg **arg)
{
	t_arg	*tmp;

	tmp = *arg;
	while (tmp->prev)
	{
		tmp = tmp->prev;
		if ((ft_strcmp(tmp->name, (*arg)->name)) < 0)
			*arg = tmp;
	}
	if ((*arg)->prev)
	{
		ft_unlink_arg(arg);
		ft_insert_arg(arg, &tmp, 'G');
	}
	return (arg);
}

t_arg		**ft_place_last(t_arg **arg)
{
	t_arg	*tmp;

	tmp = *arg;
	while (tmp->next)
	{
		tmp = tmp->next;
		if ((ft_strcmp(tmp->name, (*arg)->name)) > 0)
			arg = &tmp;
	}
	if ((*arg)->next)
	{
		ft_unlink_arg(arg);
		arg = ft_insert_arg(arg, &tmp, 'D');
	}
	return (arg);
}

t_arg		**ft_parse(t_arg **small, t_arg **big)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = *small;
	if (tmp->next)
		index = tmp->next;
	else
		return (small);
	if ((index->ID) == ((*big)->ID))
		return (small);
	while (index->ID != (*big)->ID)
	{
		if ((ft_strcmp(index->name, tmp->name)) > 0)
			tmp = index;
		index = index->next;
	}
	ft_unlink_arg(&tmp);
	big = ft_insert_arg(&tmp, big, 'G');
	return (ft_parse(small, big));
}

t_arg		**ft_ascii_a(t_arg **arg_lst)
{
	t_arg	*big;

	ft_place_last(arg_lst);
	big = *arg_lst;
	ft_place_first(arg_lst);
	return (ft_parse(arg_lst, &big));
}
