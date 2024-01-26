/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 16:27:39 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/17 16:27:39 by mwikiera         ###   ########.ch       */
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

int	ft_printf(const char *, ...);
int	ft_strlen(const char *str);
int	ivalue(int i);
int	i_power(int num);
int string_write(va_list args, int len);

#endif