/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 14:33:52 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/01 17:48:36 by mwikiera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

//int	push_swap()
//{
	
//}

int main(int argc, char *argv[])
{
	int	i;

	printf("%d\n", argc);
	for (i = 0; i < argc; i++)
	{
		ft_printf("%c", *argv[i]);
		ft_printf("HELLo");
	}
	return (0);
}

// gcc -g ft_push_swap.c ft_push_swap.h -Ilibft -Llibft -lft

// make clean

// make or make all


// https://github.com/mohsink20/42cursus/blob/main/push_swap/mylib/Makefile      makefile to check