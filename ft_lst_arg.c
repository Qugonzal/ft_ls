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

t_arg		*new_arg(char *name, t_arg **nxt_elem)
{
	t_arg	*new;

	if (!(new = malloc(sizeof(t_arg))))
		exit(-1);
	ft_memcpy(new->name, name, ft_strlen(name) + 1);
	new->next = *nxt_elem;
	return (new);
}

t_arg		*ft_link(t_arg *arg_lst)
{
	t_arg	*tmp;

	arg_lst->prev = NULL;
	while (arg_lst->next)
	{
		tmp = arg_lst;
		arg_lst = arg_lst->next;
		arg_lst->prev = tmp;
	}
	while (arg_lst->prev)
		arg_lst = arg_lst->prev;
	return (arg_lst);
}
/*
t_arg		*ft_unlink_arg(t_arg *arg_lst)
{
	t_arg	*tmp;

	tmp = arg_lst;

}*/
