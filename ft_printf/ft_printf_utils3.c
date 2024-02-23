/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 11:39:38 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/23 12:00:08 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	f_too_long(int num, char *base, int len, int i_pow)
{
	int	x;
	int	n;

	n = i_pow;
	x = 0;
	if (num >= n)
	{
		while (num >= n)
		{
			num = num - n;
			x++;
		}
		i_pow--;
		n = ivalue(i_pow);
		ft_putchar_fd(base[x], 1);
		len++;
	}
	if (num < n && i_pow > 0)
	{
		ft_putchar_fd(base[0], 1);
		len++;
		i_pow--;
	}
	return (len);
}

int	f_too_long_u(unsigned int num, char *base, int len, unsigned int i_pow)
{
	int				x;
	unsigned int	n;

	n = i_pow;
	printf("Enter func: %d\n", i_pow);
	x = 0;
	if (num >= n)
	{
		printf("This is my num: %u\n", num);
		printf("This is my n: %u\n", n);
		n = ivalue2(i_pow);
		printf("This is my n power n: %u\n", n);
		while (num >= n)
		{
			num = num - n;
			x++;
		}
		printf("Can put %d times %u:\n", x, n);
		i_pow--;
		n = ivalue(i_pow);
		printf("Inside func (n): %d\n", i_pow);
		ft_putchar_fd(base[x], 1);
		len++;
	}
	if (num < n && i_pow > 0)
	{
		ft_putchar_fd(base[0], 1);
		len++;
		//i_pow--;
	}
	return (len);
}

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
