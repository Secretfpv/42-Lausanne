/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 16:51:57 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/04 13:28:36 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	base(unsigned int num, char *base)
{
	printf("Number: %d    ", num);
	printf("Base: %s    ", base);
	printf("BASE: %d", ft_strlen(base) + 1);








}

void	replace(char c, va_list args)
{
	if(c == 'd')
		printf("%d", va_arg(args, int));
	else if (c == 's')
		printf("%s", va_arg(args, char *));
	else if (c == 'c')
		printf("%c", va_arg(args, int));
	else if (c == 'p')
		printf("%p", va_arg(args, void *));
	else if (c == 'u')
		printf("%u", va_arg(args, unsigned int));
	else if (c == '%')
		printf("%%");
	else if (c == 'x')
		base(va_arg(args, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		base(va_arg(args, unsigned int), "123456789ABCDEF");
}

int	ft_printf(const char *sign, ...)
{
	//ft_putchar_fd('A', 1);
	//ft_strlen(sign);
	printf("%s\n", sign);

	printf("\033[0m");


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
			//printf("777");
			i = i + 2;
		}
		else
		{
			printf("%c", sign[i]);
			i++;
		}
	}
	len = ft_strlen(sign);

	printf("\nLen of string: %d", len);

	return(0);
}

int main(void)
{
	int 			number;
	char 			*string;
	char 			chara;
	unsigned int	negative;
	//char			spechar;
	int				hexamini;
	int				hexamax;

	number = 5;
	string = "Hello";
	chara = 'o';
	negative = 7;
	//spechar = '%';
	hexamini = 346;
	hexamax = 346;

	printf("----------------------------\n\033[1;33mVariables\033[0m:\n");

	printf("Number:       %d\n", number);
	printf("String:       %s\n", string);
	printf("Char:         %c\n", chara);
	printf("Adress:       %p\n", &string);
	printf("Unsigned int: %u\n", negative);
	printf("Special char: %%\n");
	printf("Dec number:   %d\n", hexamini);
	printf("Hexamini:     %x\n", hexamini);
	printf("Hexamax:      %X\n", hexamax);

	printf("\n----------------------------\n\033[1;34mDisplays\033[0m:\n\n\033[1;35m");

	ft_printf("Lets try to copy %d words %s that contains %c char and adress %p and negative number %u and spechar %%, Hexamini %x, Hexamax %X", number, string, chara, &string, negative, hexamini, hexamax);

	printf("\033[0m\n\n----------------------------\n");

	printf("\033[1;31mShould Display\033[0m:\n\n\033[1;35mLets try to copy %d words %s that contains %c char and adress %p and negative number %u and spechar %%, Hexamini %x, Hexamax %X\033[0m\n\n----------------------------\n", number, string, chara, &string, negative, hexamini, hexamax);
}
