/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 17:02:35 by mwikiera          #+#    #+#             */
/*   Updated: 2024/02/15 17:02:35 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char* ft_utoa(unsigned int num) {
    // Determine the length of the number
    unsigned int temp = num;
    int length = 1;
    while (temp /= 10) {
        length++;
    }

    // Allocate memory for the string (including null terminator)
    char* str = (char*)malloc((length + 1) * sizeof(char));
    if (str == NULL) {
        return NULL; // Memory allocation failed
    }

    // Convert the number to string from right to left
    str[length] = '\0'; // Null-terminate the string
    while (length--) {
        str[length] = '0' + (num % 10); // Convert digit to character
        num /= 10;
    }

    return str;
}