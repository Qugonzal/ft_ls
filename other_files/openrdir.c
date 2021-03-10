/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   openrdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:55:25 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/11 20:35:53 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <errno.h>
#include "libft/libft.h"

int		main(int argc, char **argv)
{
	DIR	*dirstream;
	struct dirent	*elem;
	if (argc > 0)
	{
		if (argc == 1)
		{
			dirstream = opendir(".");
			while ((elem = readdir(dirstream)))
			{
				ft_putstr(elem->d_name);
				ft_putstr("\n");
			}
			ft_putnbr(errno);
		}
	}
	return (0);
}
