/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quegonza <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/10 14:52:36 by quegonza          #+#    #+#             */
/*   Updated: 2019/04/10 14:57:24 by quegonza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int				i;
	unsigned int	j;

	if (!s)
		return (NULL);
	i = ft_strlen(s) - 1;
	j = 0;
	while (i >= 0 && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
		i--;
	while (s[j] && (s[j] == ' ' || s[j] == '\t' || s[j] == '\n'))
		j++;
	if (i < 0)
		return (ft_strdup(""));
	return (ft_strsub(s, j, i - j + 1));
}
