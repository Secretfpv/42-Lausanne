/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 12:53:15 by mwikiera          #+#    #+#             */
/*   Updated: 2024/01/03 12:54:38 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h> // dont forget to remove
//# include "/home/michal/Lausanne_42/libft/libft.h"
//# include "libft.h"

int	ft_printf(const char *, ...);
int	ft_strlen(const char *str);

#endif