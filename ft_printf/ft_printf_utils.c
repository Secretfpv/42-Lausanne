/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:05:26 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/21 17:05:47 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ivalue(int i)
{
	int	n;

	n = 1;
	while (i >= 1)
	{
		n = n * 16;
		i--;
	}
	return (n);
}

int	i_power(int num)
{
	int	i;
	int	num_copy;

	i = 0;
	num_copy = num;
	while (num_copy >= 16)
	{
		num_copy = num_copy / 16;
		i++;
	}
	return (i);
}

int	buffer_move(char *buffer, int len)
{
	int	i;
	int	j;

	j = 0;
	i = 2;
	while (buffer[j] == '0')
	{
		j++;
	}
	while (buffer[j] != '\0')
	{
		buffer[i] = buffer[j];
		buffer[j] = '\0';
		i++;
		j++;
	}
	if (buffer[j] == '\0')
	{
		while (buffer[i] != '\0')
		{
			buffer[i] = '\0';
			i++;
		}
	}
	i = ft_strlen(buffer);
	buffer[0] = '0';
	buffer[1] = 'x';
	write(1, buffer, i);
	len = len + i;
	return (len);
}

int	string_write(va_list args, int len)
{
	char	*string;

	string = va_arg(args, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len = len + 6;
	}
	else if (ft_strncmp(string, "", 1) == 0)
		ft_putstr_fd("", 1);
	else if (ft_strncmp(string, "", 1) != 0)
	{
		ft_putstr_fd(string, 1);
		len = len + ft_strlen(string);
	}
	return (len);
}

int	unsint(unsigned int number, int len)
{
	char	*num2;

	if (number > INT_MAX)
	{
		num2 = ft_utoa(number);
		len += ft_strlen(num2);
		ft_putstr_fd(num2, 1);
		free(num2);
	}
	else
	{
		num2 = ft_itoa((int)number);
		len += ft_strlen(num2);
		ft_putstr_fd(num2, 1);
		free(num2);
	}
	return (len);
}
