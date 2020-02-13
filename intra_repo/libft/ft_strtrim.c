/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qugonzal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 15:01:53 by qugonzal          #+#    #+#             */
/*   Updated: 2017/04/25 15:34:05 by qugonzal         ###   ########.fr       */
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
