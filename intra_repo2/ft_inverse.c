/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 19:01:54 by quegonza          #+#    #+#             */
/*   Updated: 2019/11/29 19:01:54 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file	*ft_inverse_list(t_file *file)
{
	if (file->next)
		file = file->next;
	while (file->next)
	{
		(file->prev)->next = (file->prev)->prev;
		(file->prev)->prev = file;
		file = file->next;
	}
	if (file->prev)
	{
		(file->prev)->next = (file->prev)->prev;
		(file->prev)->prev = file;
		file->next = file->prev;
		file->prev = NULL;
	}
	return (file);
}
