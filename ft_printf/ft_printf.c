/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 14:46:21 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/13 11:00:18 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int Address(void *ptr, int len)
{
    const char hexChars[] = "0123456789abcdef";
    char buffer[18];
    buffer[17] = '\0';

	if(ptr == NULL) {
		ft_putstr_fd("(nil)", 1);
		return (len + 5);
	}
	else {
    unsigned long long address = (unsigned long long)ptr;

	for (int i = 13; i >= 0; i--)
	{
        buffer[i] = hexChars[address % 16];
        address /= 16;
    }
	buffer[0] = '0';
	buffer[1] = 'x';

    write(1, buffer, 16);
	return (len + 14);
	}
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
		//Hexa_print(x, base);
		ft_putchar_fd(base[x], 1);
		
		//ft_putchar_fd(Hexa_print(x, base), 1);
	}
	if (num <= 15)
	{
		//Hexa_print(num, base);
		ft_putchar_fd(base[num], 1);

	//	ft_putchar_fd(Hexa_print(num, base), 1);
	}
}

int	replace(char c, va_list args, int len)
{
	if(c == 'd')
		ft_putnbr_fd(va_arg(args, int), 1);
	else if (c == 's')
	{
		len = string_write(args, len);
		//ft_putstr_fd(va_arg(args, char *), 1);
	}
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len++;
	}
	else if (c == 'p')
		len = len + Address(va_arg(args, void *), len);
	else if (c == 'u')
		ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	else if (c == 'x')
	{
		base(va_arg(args, unsigned int), "0123456789abcdef");
	}
	else if (c == 'X')
		base(va_arg(args, unsigned int), "0123456789ABCDEF");

	return (len);
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
			len = replace(sign[i+1], args, len);
				i = i + 2;
		}
		else
		{
			ft_putchar_fd(sign[i], 1);
			i++;
			len++;
		}
	}
	//len = ft_strlen(sign);

//	ft_putnbr_fd(len, 1);
//	printf("\n\nLen of string: %d", len);

	va_end(args);

	return(len);
}



/*int main()
{
	printf("My Tests:\n");
	//printf("\nNumber of chars: %d\n", ft_printf("%s%s%s", "And ", "some", "joined"));
	printf("\nNumber of chars: %d\n", ft_printf("%p", ""));
	printf("\n-------------\n\nShould get:\n");
	//printf("\nNumber of chars: %d\n", printf("%s%s%s", "And ", "some", "joined"));
	printf("\nNumber of chars: %d\n", printf("%p", ""));
}*/

// gcc -g ft_printf.c ft_printf_utils.c -Ilibft -Llibft -lft
// !!!! Make clean and Make every time

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
