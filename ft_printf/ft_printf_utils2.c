/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 14:14:55 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/16 14:14:55 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char* ft_utoa(unsigned int num) {
    // Determine the length of the number
    unsigned int temp = num;
    int length = 1;
    while (temp /= 10) {
        length++;
    }

    // Allocate memory for the string (including null terminator)
    char* str = (char*)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        return NULL; // Memory allocation failed
    }

    // Convert the number to string from right to left
    str[length] = '\0'; // Null-terminate the string
    while (length--) {
        str[length] = '0' + (num % 10); // Convert digit to character
        num /= 10;
    }

    return str;
}

int base_sixteen(int num, char *base, int len)
{
	int x;
	int i_pow;
	int n;
	
	//printf("\nI am here and this is my value: %d", num);
	while (num > 15)
	{
		x = 0;
		i_pow = i_power(num);
		printf("\nThis is i_pow: %d", i_pow);
		n = ivalue(i_pow);
		printf("\nThis is i: %d", n);
		while (num > n)
		{
			num = num - ivalue(i_pow);
			x++;
		}
		//printf("This is x: %d", x);
		ft_putchar_fd(base[x], 1);
		len++;
	}
	if (num <= 15)
	{
		ft_putchar_fd(base[num], 1);
		len++;
	}
	return(len);
}

int base_sixteenlong(long int num, char *base, int len)
{
	int x;
	int i_pow;
	int n;
	
	//printf("\nI am here1 and this is my value: %ld", num);
	while (num > 15)
	{
		x = 0;
		i_pow = i_power(num);
		n = ivalue(i_pow);
		while (num > n)	
		{
			num = num - ivalue(i_pow);
			x++;
		}
		//printf("This is x: %d", x);
		ft_putchar_fd(base[x], 1);
		len++;
	}
	if (num <= 15)
	{
		ft_putchar_fd(base[num], 1);
		len++;
	}
	return(len);
}