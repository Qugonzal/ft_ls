/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/15 16:33:29 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/14 14:55:52 by qugonzal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dst, const char *src)
{
	int taille;
	int i;

	taille = 0;
	i = 0;
	while (src[taille] != '\0')
		taille++;
	while (taille >= 0)
	{
		dst[i] = src[i];
		i++;
		taille--;
	}
	return (dst);
}
