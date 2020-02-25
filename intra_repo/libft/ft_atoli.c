/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:49:27 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 14:57:23 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoli(const char *str)
{
	unsigned char	i;
	long			nb;
	int				sign;

	i = 0;
	sign = 1;
	nb = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -sign;
	while ('0' <= str[i] && str[i] <= '9')
		nb = nb * 10 + str[i++] - 48;
	return (nb * sign);
}
