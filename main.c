/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 03:01:56 by qugonzal          #+#    #+#             */
/*   Updated: 2018/10/02 20:21:33 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
/*
   void		ft_print_options(unsigned char options)
   {
   if (options) 
   {
   ft_putstr("-- OPTIONS --> ");
   if (options & LS_L)
   ft_putstr("-l\n");
   if (options & LS_REC)
   ft_putstr("-R\n");
   if (options & LS_A)
   ft_putstr("-a\n");
   if (options & LS_R)
   ft_putstr("-r\n");
   if (options & LS_T)
   ft_putstr("-t\n");
   }
   else
   ft_putstr("-- NO OPTIONS --\n");
   }*/
/*
void		ft_print(t_file *arg_tmp)
{
	t_file *tmp;

	tmp = arg_tmp;
	while (tmp->next)
	{
		ft_putstr(tmp->name);
		ft_putstr("\n");
		tmp = tmp->next;
	}
	ft_putstr(tmp->name);
	ft_putstr("\n");
}
*/
void	ft_lister(int *i, int *identifier, char **av, t_file **arg_lst)
{
	t_file		*tmp_start;

	while (av[*i])
	{
		(*arg_lst) = new_file((*arg_lst), av[*i]);
		if (!(*arg_lst))
			(*i)++;
		else
		{
			(*arg_lst)->id = *identifier;
			if (!(ft_check_open((*arg_lst), NULL)))
			{
				tmp_start = (*arg_lst)->next;
				ft_free((*arg_lst));
				(*arg_lst) = tmp_start;
			}
			(*identifier)++;
			(*i)++;
		}
	}
}

int		ft_fts_open(char **av)
{
	int i;

	i = 1;
	while (av[i])
	{
		if (!av[i][0])
		{
			ft_putstr("ft_ls: ");
			errno = 2;	
			perror("fts_open");
			return (0);
		}
		i++;
	}
	return (1);
}
/*
int		ft_av(char **av)
{
		int i;

		i = 1;
		while (av[i])
		{
			
		}
}*/

int		main(int ac, char **av)
{
	unsigned char	options;
	t_file			*tmp_start;
	int				i;
	int				identifier;
	t_file			*arg_lst;

	i = 1;
	arg_lst = NULL;
	options = ft_set_options(av);
	identifier = 0;
	if (!ft_fts_open(av))
		return (0);
	while (av[i] && av[i][0] == '-' && av[i][1])
		i++;
//	i = ft_av(av);
	if (i < ac)
	{
		ft_lister(&i, &identifier, av, &arg_lst);
		if (arg_lst)
		{
			ft_link_list(arg_lst);
			arg_lst = ft_ascii(arg_lst);
			if (options & LS_T)
				arg_lst = ft_mtime(arg_lst, "./");
			if (options & LS_R)
				arg_lst = ft_inverse_list(arg_lst);
			if (ft_lst_nodir(&arg_lst, options) && arg_lst)
				ft_putstr("\n");
			while (arg_lst)
			{
				tmp_start = arg_lst;
				if (identifier > 1)
				{
					ft_putstr(arg_lst->name);
					ft_putstr(":\n");
				}
				ft_ls(arg_lst->dirstream, options, arg_lst->name);
				if (arg_lst->dirstream)
					closedir(arg_lst->dirstream);
				if ((arg_lst = arg_lst->next))
					ft_putstr("\n");
				ft_free(tmp_start);
			}
		}
	}
	else
	{
		arg_lst = new_file(arg_lst, ".");
		if (!(ft_check_open(arg_lst, NULL)))
		{
			ft_free(arg_lst);
			perror("opendir");
		}
		ft_ls(arg_lst->dirstream, options, ".");
		closedir(arg_lst->dirstream);
	  	ft_free(arg_lst);
	}
	if (!(options & LS_L) && !(options & LS_REC) && !(options & LS_1))
		ft_putchar('\n');
	return (0);
}
