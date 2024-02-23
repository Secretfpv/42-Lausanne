/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:39:38 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/23 15:42:41 by mwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	need_lines(char *buffer, int len)
{
	int	i;

	i = ft_strlen(buffer);
	buffer[0] = '0';
	buffer[1] = 'x';
	write(1, buffer, i);
	len = len + i;
	return (len);
}

int	f_hello_u(unsigned int num, char *base, int *len, int i_pow)
{
	unsigned int	n;
	unsigned int	modulo;

	n = ivalue(i_pow);
	modulo = num / n;
	ft_putchar_fd(base[modulo], 1);
	num = num - (modulo * n);
	(*len)++;
	return (num);
}

int	f_hello(int num, char *base, int *len, int i_pow)
{
	int	n;
	int	modulo;

	n = ivalue(i_pow);
	modulo = num / n;
	ft_putchar_fd(base[modulo], 1);
	num = num - (modulo * n);
	(*len)++;
	return (num);
}

int	adress_more(void *ptr, char *buffer, int len)
{
	const char			hexchars[] = "0123456789abcdef";
	unsigned long long	address;
	int					i;

	i = 23;
	address = (unsigned long long)ptr;
	while (i >= 0)
	{
		buffer[i] = hexchars[address % 16];
		address /= 16;
		i--;
	}
	len = buffer_move(buffer, len);
	return (len);
}
