/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 19:55:25 by qugonzal          #+#    #+#             */
/*   Updated: 2017/11/28 02:56:29 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

d_list	*lister_a(char *name, d_list **lst)
{
	d_list	*new;

	if (!(new = malloc(sizeof(d_list))))
		exit(-1);
	ft_strcpy((char *)new->name, name);
	new->next = *lst;
	return (new);
}

int		main(int argc, char **argv)
{
	int i;
	d_list	*lsta;
	d_list	*firstelem;
//	d_list	*sw;
//	d_list	*tmp;
//	char *cmp;

	i = 1;
	if (argc == 1)
	{
		ft_ls(".");
		return (0);
	}
	if (!(lsta = malloc(sizeof(d_list))))
		return (0);
	ft_strcpy(lsta->name, argv[i]);
	lsta->next = NULL;
	if (argc > 1)
	{
		i++;
		while (i < argc)
		{
			lsta->prev = lister_a(argv[i], &lsta);
			lsta = lsta->prev;
			i++;
		}
		lsta->prev = NULL;
		firstelem = lsta;
/*		while (lsta->next)
		{
			sw = lsta;
			while (sw->prev)
			{
				if (ft_strcmp(sw->name, (sw->prev)->name) < 0)
				{
					tmp = sw->next;
					sw->next = sw->prev;
					(sw->prev)->next = tmp;
					(sw->prev)->prev = sw;
					sw->prev = (sw->prev)->prev;
				}
				sw = sw->prev;
			}
			lsta = lsta->next;
		}*/
/*		while (lsta->next)
		{
			ft_putstr(lsta->name);
			ft_putstr("\n");
			lsta = lsta->next;
		}
		ft_putstr(lsta->name);
		ft_putstr("WWW\n");
		while (lsta->prev)
		{
			ft_putstr(lsta->name);
			ft_putstr("\n");
			lsta = lsta->prev;
		}
		ft_putstr(lsta->name);*/
		while (firstelem->next)
		{
			lsta = firstelem->next;
			free(firstelem);
			firstelem = lsta;
		}
	}
	return (0);
}
