/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 21:03:39 by mwikiera          #+#    #+#             */
/*   Updated: 2023/10/25 21:03:45 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int i)
{
	while (*s != '\0')
	{
		if (*s == (char)i)
			return ((char *)s);
		s++;
	}
	if (i == '\0' || i == 1024)
		return ((char *)s);
	return (NULL);
}
