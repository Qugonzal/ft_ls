/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/01 15:53:51 by qugonzal          #+#    #+#             */
/*   Updated: 2018/06/01 18:16:52 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int		main(void)
{
		int nb = 8256;
		int nb1 = nb >> 8;
		int nb2 = nb & ~(nb1 << 8);
		ft_putstr("fort = ");
		ft_putnbr(nb >> 8);
		ft_putstr("\nfaible = ");
		ft_putnbr(nb2);
		return (0);
}
