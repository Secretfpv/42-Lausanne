/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/22 16:42:13 by mwikiera          #+#    #+#             */
/*   Updated: 2023/10/22 16:42:13 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*d;
	char	*s;

	i = 0;
	d = (char *)dest;
	s = (char *)src;
	if (dest == 0 && src == 0)
		return (dest);
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
