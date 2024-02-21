/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:17:05 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/21 17:17:05 by mwikiera         ###   ########.ch       */
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
}
