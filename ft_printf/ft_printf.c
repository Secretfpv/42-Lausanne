/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/16 17:18:48 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/16 17:18:48 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int decimal(int number, int len)
{
	char *num;

	num = ft_itoa(number);
	len = len + ft_strlen(num);
	ft_putnbr_fd(number, 1);
	free(num);
	//printf("This is my number: %d\nAnd this is my len: %d", number, len);
	return(len);
}


int Address(void *ptr, int len)
{
    const char hexChars[] = "0123456789abcdef";
    char buffer[25];
    buffer[24] = '\0';
	int i;

	i = 23;
	while(i >= 0) {
		buffer[i] = '0';
		i--;
	}
	if(ptr == NULL) {
		ft_putstr_fd("0x0", 1);
		return (len + 3);
	}
	else {
    unsigned long long address = (unsigned long long)ptr;

	for (i = 23; i >= 0; i--)
	{
        buffer[i] = hexChars[address % 16];
        address /= 16;
    }
	
	len = buffer_move(buffer, len);
	//printf("\n This is len: %d\n", len);
	//printf("%s\n", buffer);

	//buffer[0] = '0';
	//buffer[1] = 'x';

    //write(1, buffer, 16);
	return (len);
	}
}

int	base(int num, char *base, int len)
{
	//unsigned long int x;

	if(num >= 0)
		len = base_sixteen(num, base, len);
	
	if(num < 0)
	{
		//printf("hellooooo");
//		printf("\nInt max: %d", INT_MAX);
//		printf("\nU max:   %u", INT_MAX);
//		printf("\nMy num:  %u", num);
//		printf("\nL Max:   %ld", LONG_MAX);


//		x = UINT_MAX + num + 1;

		//printf("\nThis is my new num: %d", num);	
		len = base_sixteenlong(num, base, len);
	}
	return (len);
}

int	replace(char c, va_list args, int len)
{
	if(c == 'd' || c == 'i')
		len = decimal(va_arg(args, int), len);
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
		len = Address(va_arg(args, void *), len);
	else if (c == 'u')
		len = unsint(va_arg(args, /*unsigned*/ int), len);// ft_putnbr_fd(va_arg(args, unsigned int), 1);
	else if (c == '%')
	{
		ft_putchar_fd('%', 1);
		len++;
	}
	else if (c == 'x')
	{
		len = base(va_arg(args, int), "0123456789abcdef", len);
	}
	else if (c == 'X')
		len = base(va_arg(args, int), "0123456789ABCDEF", len);

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
	printf("\nNumber of chars: %d\n", ft_printf("%x", -10));
	printf("\n-------------\n\nShould get:\n");
	//printf("\nNumber of chars: %d\n", printf("%s%s%s", "And ", "some", "joined"));
	printf("\nNumber of chars: %d\n", printf("%x", -10));
}*/

// gcc -g ft_printf.c ft_printf_utils.c ft_printf_utils2.c -Ilibft -Llibft -lft
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
