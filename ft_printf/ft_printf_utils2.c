/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:19:57 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/18 17:11:33 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_utoa(unsigned int num)
{
	unsigned	int	temp;
    int				length;
	char			*str;

	temp = num;
	length = 1;
    while(temp /= 10)
	{
        length++;
    }
    str = (char*)malloc((length + 1) * sizeof(char));
    if(str == NULL)
    	return(NULL);
    str[length] = '\0';
    while(length--)
	{
        str[length] = '0' + (num % 10);
        num /= 10;
    }
    return(str);
}

int base_sixteen(int num, char *base, int len)
{
	int	x;
	int	i_pow;
	int	n;
	
	i_pow = i_power(num);
	n = ivalue(i_pow);
	while(i_pow > 0)
	{
		x = 0;
		if(num >= n)
		{
			while(num >= n)
			{
				num = num - n;
				x++;
			}
			i_pow--;
			n = ivalue(i_pow);
			ft_putchar_fd(base[x], 1);
			len++;
		}
		if(num < n && i_pow > 0)
		{
			ft_putchar_fd(base[0], 1);
			len++;
			i_pow--;
		}

	}
	if(num < ft_strlen(base))
		ft_putchar_fd(base[num], 1);
	len++;
	return(len);
}

int base_sixteenlong(unsigned int num, char *base, int len)
{
	int				x;
	unsigned int	i_pow;
	unsigned int	n;

	i_pow = i_power2((unsigned int)num);
	n = ivalue2(i_pow);
	while(i_pow > 0)
	{
		x = 0;
		if(num >= n)
		{
			while(num >= n)
			{
				num = num - n;
				x++;
			}
			i_pow--;
			n = ivalue(i_pow);
			ft_putchar_fd(base[x], 1);
			len++;
		}
		if(num < n && i_pow > 0)
		{
			ft_putchar_fd(base[0], 1);
			len++;
			i_pow--;
		}

	}
	if(num < (unsigned int)ft_strlen(base))
		ft_putchar_fd(base[num], 1);
	len++;
	return(len);
}

int	i_power2(unsigned int num)
{
	int				i;
	unsigned int	num_copy;

	i = 0;
	num_copy = num;
	while(num_copy >= 16)
	{
		num_copy = num_copy / 16;
		i++;
	}
	return(i);
}

int	ivalue2(int i)
{
	int	n;

	n = 1;
	while(i >= 1)
	{
		n = n * 16;
		i--;
	}
	return(n);
}