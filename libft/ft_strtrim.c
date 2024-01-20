/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 18:10:07 by mwikiera          #+#    #+#             */
/*   Updated: 2023/10/25 12:26:39 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		x;
	size_t	i;
	size_t	j;
	char	*str;

	x = 1;
	str = 0;
	if (s1 != 0 && set != 0)
	{
		i = 0;
		j = ft_strlen(s1);
		if (j == 0)
		{
			j = 1;
			x = 0;
		}
		while (s1[i] && ft_strchr(set, s1[i]))
			i++;
		while (s1[j - 1] && ft_strchr(set, s1[j - 1]) && j > i)
			j--;
		str = (char *)malloc(sizeof(char) * (j - i + x));
		if (str)
			ft_strlcpy(str, &s1[i], j - i + x);
	}
	return (str);
}
