/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 15:03:19 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/21 19:37:48 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_isalpha(int c)
{
	if ('A' <= c && c <= 'Z')
		return (1);
	if ('a' <= c && c <= 'z')
		return (1);
	return (0);
}