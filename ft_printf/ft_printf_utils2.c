/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 16:39:14 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/01 16:59:53 by mwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	unsigned int	temp;
	int				length;
	char			*str;

	temp = num;
	length = 0;
	while (temp > 0)
	{
		temp /= 10;
		length++;
	}
	str = (char *) malloc ((length + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[length] = '\0';
	while (length--)
	{
		str[length] = '0' + (num % 10);
		num /= 10;
	}
	return (str);
}

int	base_sixteen(int num, char *base, int len)
{
	int	i_pow;

	i_pow = i_power(num);
	while (i_pow > 0)
	{
		num = f_hello(num, base, &len, i_pow);
		i_pow--;
	}
	if (num < ft_strlen(base))
		ft_putchar_fd(base[num], 1);
	len++;
	return (len);
}

int	base_sixteenlong(unsigned int num, char *base, int len)
{
	unsigned int	i_pow;

	i_pow = i_power2((unsigned int)num);
	while (i_pow > 0)
	{
		num = f_hello_u(num, base, &len, i_pow);
		i_pow--;
	}
	if (num < (unsigned int)ft_strlen(base))
		ft_putchar_fd(base[num], 1);
	len++;
	return (len);
}

int	i_power2(unsigned int num)
{
	int				i;
	unsigned int	num_copy;

	i = 0;
	num_copy = num;
	while (num_copy >= 16)
	{
		num_copy = num_copy / 16;
		i++;
	}
	return (i);
}

int	ivalue2(int i)
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
