/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:47:27 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/22 16:48:03 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	decimal(int number, int len)
{
	char	*num;

	num = ft_itoa(number);
	len = len + ft_strlen(num);
	ft_putnbr_fd(number, 1);
	free(num);
	return (len);
}

int	address(void *ptr, int len)
{
	const char			hexchars[] = "0123456789abcdef";
	char				buffer[25];
	int					i;
	unsigned long long	address;

	buffer[24] = '\0';
	i = 23;
	while (i >= 0)
	{
		buffer[i] = '0';
		i--;
	}
	if (ptr == NULL)
	{
		ft_putstr_fd("0x0", 1);
		return (len + 3);
	}
	else
	{
		address = (unsigned long long)ptr;
		for (i = 23; i >= 0; i--)
		{
			buffer[i] = hexchars[address % 16];
			address /= 16;
		}
		len = buffer_move(buffer, len);
		return (len);
	}
}

int	base(int num, char *base, int len)
{
	unsigned int	x;

	if (num >= 0)
		len = base_sixteen(num, base, len);
	if (num < 0)
	{
		x = (unsigned int)num;
		len = base_sixteenlong(x, base, len);
	}
	return (len);
}

int	replace(char c, va_list args, int len)
{
	if (c == 'd' || c == 'i')
		len = decimal(va_arg(args, int), len);
	else if (c == 's')
		len = string_write(args, len);
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len++;
	}
	else if (c == 'p')
		len = address(va_arg(args, void *), len);
	else if (c == 'u')
		len = unsint(va_arg(args, int), len);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	else if (c == 'x')
		len = base(va_arg(args, int), "0123456789abcdef", len);
	else if (c == 'X')
		len = base(va_arg(args, int), "0123456789ABCDEF", len);
	return (len);
}

int	ft_printf(const char *sign, ...)
{
	va_list	args;
	int		i;
	int		len;

	va_start(args, sign);
	i = 0;
	len = 0;
	while (sign[i])
	{
		if (sign[i] == '%')
		{
			len = replace(sign[i + 1], args, len);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(sign[i], 1);
			i++;
			len++;
		}
	}
	va_end(args);
	return (len);
}
