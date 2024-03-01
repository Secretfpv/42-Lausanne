/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:46:39 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/23 15:42:31 by mwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
//# include <stdio.h> // dont forget to remove
# include "libft/libft.h"
# include <limits.h>

int		ft_printf(const char *sign, ...);
int		ft_strlen(const char *str);
int		ivalue(int i);
int		i_power(int num);
int		buffer_move(char *buffer, int len);
int		string_write(va_list args, int len);
int		unsint(unsigned int number, int len);
char	*ft_utoa(unsigned int num);
int		base_sixteen(int num, char *base, int len);
int		base_sixteenlong(unsigned int num, char *base, int len);
int		i_power2(unsigned int num);
int		ivalue2(int i);
int		need_lines(char *buffer, int len);
int		f_hello_u(unsigned int num, char *base, int *len, int i_pow);
int		f_hello(int num, char *base, int *len, int i_pow);
int		adress_more(void *ptr, char *buffer, int len);

#endif