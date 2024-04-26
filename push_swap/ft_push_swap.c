/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 11:55:00 by mwikiera          #+#    #+#             */
/*   Updated: 2024/04/25 11:55:37 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	func_display(int argc, char *argv[], int stack_a)
{
	int	i;

	ft_printf("\n");
	i = 1;
	while (i <= stack_a)
	{
		ft_printf("a - %s\n", argv[i]);
		i++;
	}
	ft_printf("========\n");
	while ((i - stack_a)  <= (argc - 1) - stack_a)
	{
		ft_printf("b - %s\n", argv[i]);
		i++;
	}
	ft_printf("\n");
}

int	check_number_args(int argc, char *argv[])
{
	//int	i;

	if (argc < 3)
	{
		ft_printf("Not enough arguments\n");
		return (argc - 1);
	}
	
	if (atoi(argv[0]) == 0)//    bullshit
		return (argc - 1);
	
	return (argc - 1);
}

int	push_swap(int argc, char *argv[])
{
	int	stack_a;
	//int	middle_num;

	stack_a = argc - 1;
	if (check_number_args(argc, argv) < 2)
		return (0);

	func_display(argc, argv, stack_a);

	ft_printf("Nb of args: %d\n", check_number_args(argc, argv));

	if (stack_a > 3)
	{
//		ft_printf("ARGS+\n\n");
		ft_sort(argv, argc, stack_a);
	}

	if (stack_a == 3)
	{
		ft_printf("i am here with 3 args\n");
		ft_sort_3_a(argv, stack_a);
	}

	if (stack_a == 2)
	{
		if (ft_atoi(argv[2]) < ft_atoi(argv[1]))
			swap_a(&argv, stack_a);
	}
	

	//checker(argc, argv);
	//ft_printf("\n========\nSorted!  :)\n");
	func_display(argc, argv, stack_a);
	return (0);
}

int main(int argc, char *argv[])
{
	push_swap(argc, argv);

	return (0);
}

// gcc -g ft_push_swap.c ft_push_swap.h -Ilibft -Llibft -lft
// new: gcc -Wall -Wextra -Werror ft_push_swap.c ft_push_swap_functions.c ft_push_swap_functions2.c -o push_swap -Ilibft -Llibft -lft

// to run: ./push_swap 5 4 3 2 1
// if needed chmod +x push_swap

// make clean

// make or make all

// https://github.com/mohsink20/42cursus/blob/main/push_swap/mylib/Makefile      makefile to check