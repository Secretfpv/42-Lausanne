/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 14:53:01 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/17 16:07:31 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


void Address(void *ptr)
{
    const char hexChars[] = "0123456789abcdef";
    char buffer[18];
    buffer[17] = '\0';

    unsigned long long address = (unsigned long long)ptr;

	buffer[0] = '0';
	buffer[1] = 'x';
	for (int i = 13; i >= 2; i--)
	{
        buffer[i] = hexChars[address % 16];
        address /= 16;
    }

    write(1, buffer, 16);
}

void	base(unsigned int num, char *base)
{
	int x;
	int i_pow;
	unsigned int n;

	//ft_putstr_fd("Hello", 1);

	while (num > 15)
	{
		x = 0;
		i_pow = i_power(num);
		//printf("\n\n I_Pow: %d", i_pow);
		//printf("\n I_Value (i_pow): %d", ivalue(i_pow));
		//printf("\n Num Before print: %d", num);
		n = ivalue(i_pow);
		while (num > n)
		{
			num = num - ivalue(i_pow);
			x++;
		}
		Hexa_print(x, base);
		
		//ft_putchar_fd(Hexa_print(x, base), 1);
	}
	if (num <= 15)
	{
		Hexa_print(num, base);

	//	ft_putchar_fd(Hexa_print(num, base), 1);
	}
}

void	replace(char c, va_list args)
{
	if(c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
		ft_putstr_fd(va_arg(args, char *), 1);
	else if (c == 'c')
		ft_putchar_fd(va_arg(args, int), 1);
	else if (c == 'p')
		Address(va_arg(args, void *));
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
		ft_putchar_fd('%', 1);
	else if (c == 'x')
	{
		base(va_arg(args, unsigned int), "0123456789abcdef");
	}
	else if (c == 'X')
		base(va_arg(args, unsigned int), "0123456789ABCDEF");
}

int	ft_printf(const char *sign, ...)
{
//	printf("\033[0m");


	va_list args;
	int i;
	int len;

	va_start(args, sign);
	i = 0;
	len = 0;

	while (sign[i])
	{
		if(sign[i] == '%')
		{
			replace(sign[i+1], args);
			i = i + 2;
		}
		else
		{
			ft_putchar_fd(sign[i], 1);
			i++;
		}
	}
	len = ft_strlen(sign);

	ft_putnbr_fd(len, 1);
//	printf("\n\nLen of string: %d", len);

	va_end(args);

	return(0);
}

/*int main(void)
{
	int 			number;
	char 			*string;
	char 			chara;
	unsigned int	unnsigned;
	char			spechar;
	int				hexamini;
	int				hexamax;

	number = 5;
	string = "Hello";
	chara = 'm';
	unnsigned = 7;
	spechar = '%';
	hexamini = 346;
	hexamax = 346;

//	printf("----------------------------\n\033[1;33mVariables\033[0m:\n");

//	printf("Number:       %d\n", number);
//	printf("String:       %s\n", string);
//	printf("Char:         %c\n", chara);
//	printf("Adress:       %p\n", (void *)string);
//	printf("Unsigned int: %u\n", unnsigned);
//	printf("Special char: %%\n");
//	printf("Dec number:   %d\n", hexamini);
//	printf("Hexamini:     %x\n", hexamini);
//	printf("Hexamax:      %X\n", hexamax);

//	printf("\n----------------------------\n\033[1;34mDisplays\033[0m:\n\n\033[1;35m");

	ft_printf("Lets try to copy %d words %s that contains %c char and adress %p and unsigned number %u and spechar %%, Hexamini %x, Hexamax %X", number, string, chara, &string, unnsigned, hexamini, hexamax);
	
//	printf("\033[0m\n\n----------------------------\n");

//	printf("\033[1;31mShould Display\033[0m:\n\n\033[1;35mLets try to copy %d words %s that contains %c char and adress %p and unsigned number %u and spechar %%, Hexamini %x, Hexamax %X\033[0m\n\n----------------------------\n\n", number, string, chara, &string, unnsigned, hexamini, hexamax);


}*/
