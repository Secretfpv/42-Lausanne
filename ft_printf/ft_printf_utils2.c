/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:08:05 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/16 17:14:48 by mwikiera         ###   ########.ch       */
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
	
	i_pow = i_power(num);
	//printf("\nThis is i_pow: %d", i_pow);
	n = ivalue(i_pow);
	while(i_pow > 0)
	{
		x = 0;
//		printf("\nThis is n: %d", n);
//		printf("\nThis is my num: %d", num);
//		printf("\nThis is i_pow: %d", i_pow);
		if(num >= n)
		{
			while(num >= n)
			{
				num = num - n;
				x++;
			}
			i_pow--;
//			printf("\nThis is i_pow: %d", i_pow);
			n = ivalue(i_pow);
//			printf("\nThis is i: %d", n);

			ft_putchar_fd(base[x], 1);
			len++;
//			printf("\nI can put %d times %d.", x, n);
//			printf("\nI have stil %d left.", num);
		}
		if(num < n && i_pow > 0)
		{
			ft_putchar_fd(base[0], 1);
			len++;
			i_pow--;
		}

	}
	ft_putchar_fd(base[num], 1);
	len++;
	return(len);
}

int base_sixteenlong(unsigned long int num, char *base, int len)
{
	{
	unsigned long int x;
	unsigned long int f;
	unsigned int i_pow;
	unsigned long int n;

	f = UINT_MAX + num + 1;
	//num = num * -1;
	num = num + 268435455 + 1;
	ft_putstr_fd("f", 1);
	len++;


//	printf("i am here: %ld", num);
	i_pow = i_power(num);
	//printf("\nThis is i_pow: %d", i_pow);
	n = ivalue(i_pow);
	while(i_pow > 0)
	{
		x = 0;
//		printf("\nThis is n: %d", n);
//		printf("\nThis is my num: %d", num);
//		printf("\nThis is i_pow: %d", i_pow);
		if(num >= n)
		{
			while(num >= n)
			{
				num = num - n;
				x++;
			}
			i_pow--;
//			printf("\nThis is i_pow: %d", i_pow);
			n = ivalue(i_pow);
//			printf("\nThis is i: %d", n);

			ft_putchar_fd(base[x], 1);
			len++;
//			printf("\nI can put %d times %d.", x, n);
//			printf("\nI have stil %d left.", num);
		}
		if(num < n && i_pow > 0)
		{
			ft_putchar_fd(base[0], 1);
			len++;
			i_pow--;
		}

	}
	ft_putchar_fd(base[num], 1);
	len++;
	return(len);
}
}