/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 17:16:49 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/21 17:16:54 by mwikiera         ###   ########.ch       */
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
int		f_too_long(int num, char *base, int len, int i_pow);
int		f_too_long_u(unsigned int num, char *base, int len, unsigned int i_pow);

#endif