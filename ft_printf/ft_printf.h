/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 16:42:33 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/15 16:42:33 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // dont forget to remove
//# include "/home/michal/Lausanne_42/libft/libft.h"
# include "libft/libft.h"
# include <limits.h>

int	ft_printf(const char *, ...);
int	ft_strlen(const char *str);
int	ivalue(int i);
int	i_power(int num);
int buffer_move(char* buffer, int len);
int string_write(va_list args, int len);
int unsint(unsigned int number, int len);
char* ft_utoa(unsigned int num);

#endif