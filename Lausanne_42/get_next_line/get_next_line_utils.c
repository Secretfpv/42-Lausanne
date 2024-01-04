/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 20:21:39 by mwikiera          #+#    #+#             */
/*   Updated: 2023/12/29 20:21:39 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (str == NULL || str[i] == '\0')
	{
		return (i);
	}
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *returnbuffer, char *buffer, char *next_chars)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (buffer[i] != '\0')
	{
		returnbuffer[i] = buffer[i];
		i++;
	}
	while (next_chars[j] != '\0')
	{
		returnbuffer[i] = next_chars[j];
		i++;
		j++;
	}
	returnbuffer[i] = '\0';
	return (returnbuffer);
}

int		ft_strlenline(char *buffer)
{
	int	i;

	i = 0;
	while (buffer[i] != '\n' && buffer[i] != '\0')
	{
		i++;
	}
	if(buffer[i] == '\n')
		return(i + 1);
	return (i);	
}

void	*ft_memset(void *b, int c, size_t len)
{
	char	*p;

	p = (char *)b;
	while (len > 0)
	{
		p[len - 1] = c;
		len--;
	}
	return (b);
}
