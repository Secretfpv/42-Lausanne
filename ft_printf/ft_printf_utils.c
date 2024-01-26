/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:24:19 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/25 20:32:53 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//int	ft_strlen(const char *str)
//{
//	int	i;

//	i = 0;
//	while (str[i] != '\0')
//		i++;
//	return (i);
//}

int	ivalue(int i)
{
	int n;

	n = 1;
	//printf("\n old i %d ", i);
	while (i >= 1)
	{
		n = n * 16;
		i--;
	}
	//printf ("\n N Value: %d\n", n);
	return (n);
}

int	i_power(int num)
{
	int i;
	int num_copy;

	i = 0;
	num_copy = num;
	//printf("\n --num--> %d <--num-- ", num_copy);
	while (num_copy >= 16)
	{
		//printf("\n --num--> %d <--num-- ", num_copy);
		num_copy = num_copy / 16;
		i++;
		//printf("\n --num--> %d <--num-- ", num_copy);
	}
	//printf("\n I Value: %d", i);
	return (i);
}

int string_write(va_list args, int len, int i)
{
	char *currentArg;
	
	//ft_putnbr_fd(i, 1);

	while (i >= 0 && (!(currentArg = va_arg(args, char *))))
    {
		//currentArg = va_arg(args, char *);
    	len = len + ft_strlen(currentArg);
    	ft_putstr_fd(currentArg, 1);
		
	//	ft_putnbr_fd(i, 1);
    }
	
	//if ((currentArg = va_arg(args, char *)) == NULL)
	//{
	//	ft_putstr_fd("(null)", 1);
	//	len = len + 6;
	//}
return (len);
}


//(currentArg = va_arg(args, char *)) == NULL