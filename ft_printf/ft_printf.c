/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 16:11:41 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/18 16:13:29 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int decimal(int number, int len)
{
	char	*num;

	num = ft_itoa(number);
	len = len + ft_strlen(num);
	ft_putnbr_fd(number, 1);
	free(num);
	return(len);
}

int Address(void *ptr, int len)
{
    const char	hexChars[] = "0123456789abcdef";
    char		buffer[25];
	int	i;

	buffer[24] = '\0';
	i = 23;
	while(i >= 0)
	{
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
	return(len);
	}
}

int	base(int num, char *base, int len)
{
	unsigned int	x;

	if(num >= 0)
		len = base_sixteen(num, base, len);
	
	if(num < 0)
	{
		x = (unsigned int)num;
		len = base_sixteenlong(x, base, len);
	}
	return(len);
}

int	replace(char c, va_list args, int len)
{
	if(c == 'd' || c == 'i')
		len = decimal(va_arg(args, int), len);
	else if (c == 's')
		len = string_write(args, len);
	else if (c == 'c')
	{
		ft_putchar_fd(va_arg(args, int), 1);
		len++;
	}
	else if (c == 'p')
		len = Address(va_arg(args, void *), len);
	else if (c == 'u')
		len = unsint(va_arg(args, int), len);
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
	va_end(args);
	return(len);
}

/*int main()
{
	printf("My Tests:\n");
	//printf("\nNumber of chars: %d\n", ft_printf("%s%s%s", "And ", "some", "joined"));
	printf("\nNumber of chars: %d\n", ft_printf("8$rv%icfi%ulT\n+K)M%u/ws%pVr:@g%i\n\vI%i#pB.v\Jg<`%x`~m3#s%sb1r&l'*yg%pqlj[jv ",
884440607, -1200258109, 1999641884, (void *)6335553429087845953, 495387416, -1591732976,
-1593496168,
"Y6%9AfQuc}1kx;9n(t4[&U>.TR\fk{Hw{x/\f\"R\tGak%1!0b-{0E-_y]mzzgj9WfuoUCKz?`;=2|KESz`+vh\\",
(void *)-8512464386657100969));
	printf("\n-------------\n\nShould get:\n");
	//printf("\nNumber of chars: %d\n", printf("%s%s%s", "And ", "some", "joined"));
	printf("\nNumber of chars: %d\n", printf("8$rv%icfi%ulT\n+K)M%u/ws%pVr:@g%i\n\vI%i#pB.v\Jg<`%x`~m3#s%sb1r&l'*yg%pqlj[jv ",
884440607, -1200258109, 1999641884, (void *)6335553429087845953, 495387416, -1591732976,
-1593496168,
"Y6%9AfQuc}1kx;9n(t4[&U>.TR\fk{Hw{x/\f\"R\tGak%1!0b-{0E-_y]mzzgj9WfuoUCKz?`;=2|KESz`+vh\\",
(void *)-8512464386657100969));
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
