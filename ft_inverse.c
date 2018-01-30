/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 19:26:32 by qugonzal          #+#    #+#             */
/*   Updated: 2017/12/27 20:02:37 by qugonzal         ###   ########.fr       */
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
