/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:47:43 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/15 16:47:43 by mwikiera         ###   ########.ch       */
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
	i = 2;
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
	if(buffer[j] == '\0')
    {
      while(buffer[i] != '\0')
      {
        buffer[i] = '\0';
        i++;
      }
    }
	i = ft_strlen(buffer);
	//printf("\nThis is my i: %d\n", i);
	//printf("\nThis is my copy: %d\n", copy);
	//printf("\nThis is my len: %d\n", len + i - copy + 2);
	//write(1, "0x", 2);
	buffer[0] = '0';
	buffer[1] = 'x';
	write(1, buffer, i);
	//printf("This is my new buffer: %s\n", buffer);
	len = len + i;
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
	return (len);
}

int unsint2(/*unsigned*/ int number, int len)
{
	char *num2;
	unsigned int num;
	long int x;

	//new = number
//	printf("This is my number: %ld\n", LONG_MAX);
//	printf("This is my num:    %u\n", new);

	if ((int)number < 0)
	{
		num = (unsigned int)(UINT_MAX + 1 + number);
		//num = 4294967296;
		//x = num + 2147483647 + 1;
		num2 = ft_itoa((unsigned int)num);
		printf("num2: %s\n", num2);
		printf("number: %d\n", number);
		len = len + ft_strlen(num2);
		ft_putstr_fd(num2, 1);
		free(num2);
	}


	/*else if ((int)number >= 0) {
	num2 = ft_itoa(number);
	len = len + ft_strlen(num2);
	ft_putnbr_fd(number, 1);
	free(num2);
	}*/
	//printf("This is my number: %d\nAnd this is my len: %d", number, len);
	return(len);
}


int unsint(unsigned int number, int len)
{
    char *num2;

    if (number > INT_MAX) {
        num2 = ft_utoa(number); // Assuming ft_utoa() converts unsigned int to string
        len += ft_strlen(num2);
        ft_putstr_fd(num2, 1); // Assuming ft_putstr_fd() writes a string to file descriptor 1 (stdout)
        free(num2);
    } else {
        num2 = ft_itoa((int)number); // Assuming ft_itoa() converts int to string
        len += ft_strlen(num2);
        ft_putstr_fd(num2, 1);
        free(num2);
    }

    return len;
}
