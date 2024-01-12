/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 13:02:45 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/08 13:05:07 by mwikiera         ###   ########.ch       */
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
void	Hexa_print(int number, char *base);

#endif