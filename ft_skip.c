/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/03 17:49:38 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/03 17:57:45 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_file		*ft_skip(t_file *file)
{
	if ((file->name[1] == '\0') || (file->name[1] == '.'))
	{
		if (!ft_strcmp(".", file->name))
		{
			ft_unlink(file);
			ft_free(file);
			return (NULL);
		}
		else if (!ft_strcmp("..", file->name))
		{
			ft_unlink(file);
			ft_free(file);
			return (NULL);
		}
	}
	return (file);
}

t_file		*ft_skipper(t_file *file)
{
	t_file	*tmp;

	tmp = file->next;
	if (file->name[0] == '.')
	{
		if (!(file = ft_skip(file)))
			file = tmp;
		else
			file = file->next;
	}
	else
		file = file->next;
	return (file);
}

t_file		*ft_skip_current_t(t_file *file)
{
	t_file	*tmp;

	while (file->next)
		file = ft_skipper(file);
	tmp = file->prev;
	if (file->name[0] == '.')
		file = ft_skip(file);
	if (!file && !tmp)
		return (NULL);
	else if (tmp)
	{
		while (tmp->prev)
			tmp = tmp->prev;
		return (tmp);
	}
	else
		return (file);
}
