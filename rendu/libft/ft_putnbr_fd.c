/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 14:47:56 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/24 17:45:50 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_putnbr_rfd(long n, int fd)
{
	if (n >= 10)
	{
		ft_putnbr_rfd(n / 10, fd);
		ft_putnbr_rfd(n % 10, fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

void			ft_putnbr_fd(int n, int fd)
{
	long a;

	a = n;
	if (n < 0)
	{
		a *= -1;
		ft_putchar_fd('-', fd);
	}
	ft_putnbr_rfd(a, fd);
}
