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
		t_file	*start;
		t_file	*tmp;

		start = file;
		file = file->prev;
		(file->next)->next = (file->next)->prev;
		(file->next)->prev = 0;
		tmp = file->prev;
		while (tmp)
		{
			file->prev = file->next;
			file->next = tmp;
			file = tmp;
			tmp = tmp->prev;
		}
		file->prev = file->next;
		file->next = 0;
		return (start);
}
