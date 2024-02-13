/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 14:41:27 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/13 14:46:30 by mwikiera         ###   ########.ch       */
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

int buffer_move(char* buffer, int len)
{
	int i;
	int j;
	int copy;

	j = 0;
	//i = ft_strlen(buffer);
	i = 0;
	//printf("\nold buffer: %s\n", buffer);

	while(buffer[j] == '0')
	{
		j++;
	}
	copy = j;
	while(buffer[j] != '\0')
	{
		buffer[i] = buffer[j];
		buffer[j] = '\0';
		i++;
		j++;
	}
	i = ft_strlen(buffer);
	//printf("\nThis is my i: %d\n", i);
	//printf("\nThis is my copy: %d\n", copy);
	//printf("\nThis is my len: %d\n", len + i - copy + 2);
	write(1, "0x", 2);
	write(1, buffer, i);
	//printf("This is my new buffer: %s\n", buffer);
	len = len + i + 2;
	//printf("\n This is len: %d\n", len);
	return(len);
}

int string_write(va_list args, int len)
{
	//char *currentArg;
	char *string = va_arg(args, char *);

	//printf("%s", string);
	
	if(string == NULL) {
		ft_putstr_fd("(null)", 1);
		//printf("(null)");
		len = len + 6;
	}

	else if(ft_strncmp(string, "", 1) == 0)
		ft_putstr_fd("", 1);
		//printf("");
	else if(ft_strncmp(string, "", 1) != 0) {
		ft_putstr_fd(string, 1);
		//printf("%s", string);
		len = len + ft_strlen(string);
	}

	/*if (*string == '\0') {
		ft_putchar_fd('\0', 1);
		return (len);
	}*/
	/*if ((currentArg = va_arg(args, char *)) == NULL)
	{
		ft_putstr_fd("(null)", 1);
		len = len + 6;
	}*/

	/*printf("%s", string);

	if (string == NULL)
		printf("hello");*/
	/*if (string != "")
	{
		printf("hello");
		while (string != '\0')
		{
			ft_putchar_fd(*string, 1);
			len++;
			string++;
		}
	}*/
	return (len);
}
//(currentArg = va_arg(args, char *)) == NULL