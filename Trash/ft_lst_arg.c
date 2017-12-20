/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_arg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 15:15:24 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/30 18:25:38 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_arg		**ft_insert_arg(t_arg **arg, t_arg **arg_place, char option)
{
	if (option == 'G')
	{
		(*arg)->next = *arg_place;
		(*arg)->prev = (*arg_place)->prev;
		if ((*arg_place)->prev)
			((*arg_place)->prev)->next = *arg;
		(*arg_place)->prev = *arg;
	}
	else
	{
		(*arg)->next = (*arg_place)->next;
		(*arg)->prev = *arg_place;
		if ((*arg_place)->next)
			((*arg_place)->next)->prev = *arg;
		(*arg_place)->next = *arg;
	}
	return (arg);
}

t_arg		*new_arg(char *name, t_arg *nxt_elem)
{
	t_arg		*new;

	if (!(new = (t_arg *)malloc(sizeof(t_arg))))
		exit(-1);
	ft_memcpy(new->name, name, ft_strlen(name) + 1);
	new->next = nxt_elem;
	return (new);
}

t_arg		**ft_link_arg_lst(t_arg **arg_lst)
{
	t_arg	*tmp;
	t_arg	*start;

	start = *arg_lst;
	(*arg_lst)->prev = NULL;
	while ((*arg_lst)->next)
	{
		tmp = (*arg_lst);
		(*arg_lst) = (*arg_lst)->next;
		(*arg_lst)->prev = tmp;
	}
	arg_lst = &start;
	return (arg_lst);
}

void		ft_unlink_arg(t_arg **arg)
{
	t_arg *tmp;

	tmp = *arg;
	if (tmp->prev)
		(tmp->prev)->next = tmp->next;
	if (tmp->next)
		(tmp->next)->prev = tmp->prev;
}

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
			*arg = tmp;
	}
	if ((*arg)->next)
	{
		ft_unlink_arg(arg);
		ft_insert_arg(arg, &tmp, 'D');
	}
	return (arg);
}

t_arg		**ft_parse(t_arg **small, t_arg **big)
{
	t_arg	*tmp;
	t_arg	*index;

	tmp = (*small)->next;
	index = tmp;
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
	ft_parse(arg_lst, &big);
	return (arg_lst);
}
