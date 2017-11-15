/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/28 15:13:02 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/28 16:23:15 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_power(long nb, int power)
{
	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (power == 1)
		return (nb);
	else
		return (nb * ft_power(nb, (power - 1)));
}
