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

void	ft_inverse_list(t_file *file)
{
		t_file *tmp;

		tmp = file;
		while (file)
		{
			file->prev = file->next;
			file = file->next;
		}
		file->next = NULL;
		while (file->prev)
		{
			tmp = file;
			file = file->prev;
			file->next = tmp;
		}
}
