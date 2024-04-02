/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 20:03:47 by mwikiera          #+#    #+#             */
/*   Updated: 2024/03/20 20:22:48 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	find_biggest_num_a(int argc, char *argv[], int stack_a)
{
	int		last_a;
	int 	first_a;

	argc++;// usless
	first_a = 1;// first element
	last_a = 2;// takes the second argument of the list to make comparation
	while (last_a <= stack_a)
	{
		if (ft_atoi(argv[first_a]) < ft_atoi(argv[last_a]))
		{
			first_a = last_a;
		}
		last_a++;
	}
	ft_printf("biggest args found _ a: %s\n", argv[first_a]);
}

void	find_biggest_num_b(int argc, char *argv[], int stack_a)
{
	int		last_b;
	int 	first_b;

	first_b = stack_a + 1;// first element
	last_b = argc - 1;// takes the second argument of the list to make comparation
	while (last_b < argc)
	{
		if (ft_atoi(argv[first_b]) < ft_atoi(argv[last_b]))
		{
			first_b = last_b;
		}
		last_b++;
	}
	ft_printf("biggest args found _ b: %s\n", argv[first_b]);
}

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
		return (0);
	}
	
	if (atoi(argv[1]) == 0)//    bullshit
		return (7);
	
	return (1);
}

int	push_swap(int argc, char *argv[])
{
	int	stack_a;
	//int	middle_num;

	stack_a = argc - 1;
	if (check_number_args(argc, argv) == 0)
		return (0);
	
	checker(argc, argv);
	//if (checker(argc, argv) == 0)
	//	return (0);

	func_display(argc, argv, stack_a);


	//while (checker(argc, argv) == 0)
	//{
		//midvalue(argv, argc);
	//}






	//2nd algoritme not working
	/*middle_num = middle_number_a(argv, stack_a);
	
	ft_printf("midnunum: %d\n", middle_num);
	ft_printf("argc/2-1: %d\n", argc / 2 - 1);

	//while (checker(argc, argv) == 0)
	for (int f = 0; f < 9; f++)
	//while (stack_a > argc / 2 - 1)
	{
		if (ft_atoi(argv[1]) <= middle_num)
		{
			if (ft_atoi(argv[1]) < ft_atoi(argv[2]))
			{
				swap_a(&argv, stack_a);
			}
			stack_a = push_b(&argv, stack_a);
			if ((argc - 1) - stack_a > 1)// condition to be sure the opp. stack > 1 
			{	
				if (ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))	
				{
					rotate_b(argc, &argv, stack_a);
				}
			}
		}
		else if (ft_atoi(argv[1]) > middle_num)
		{
			rotate_a(&argv, stack_a);
		}
	}

	func_display(argc, argv, stack_a);

	if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
	{
		swap_a(&argv, stack_a);
	}

	while (stack_a < (argc - 1))
	{
		stack_a = push_a(&argv, stack_a);
	}*/

	//rotate_a(&argv, stack_a);
	
	
	// 1st algoritm to sort numbers 
	/*while (checker(argc, argv) == 0)
	{
		while (stack_a > 1)
		{
			if ((argc - 1) - stack_a > 1)
			{
				if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
				{
					ss(&argv, stack_a, argc);
					stack_a = push_b(&argv, stack_a);
				}
			}
			else if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
				swap_a(&argv, stack_a);
			else if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
				swap_a(&argv, stack_a);
			else if (ft_atoi(argv[1]) < ft_atoi(argv[2]))// fix this issue
				stack_a = push_b(&argv, stack_a);
			if ((argc - 1) - stack_a > 1)// condition to be sure the opp. stack > 1 
				if (ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
					swap_b(&argv, stack_a, argc);
			//func_display(argc, argv, stack_a);
		}

		//func_display(argc, argv, stack_a);

		while ((argc - 1) - stack_a > 1)
		{
			if (stack_a > 1)
			{
				if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
				{
					ss(&argv, stack_a, argc);
					stack_a = push_b(&argv, stack_a);
				}
			}
			if(ft_atoi(argv[stack_a + 1]) < ft_atoi(argv[stack_a + 2]))
				swap_b(&argv, stack_a, argc);
			else if (ft_atoi(argv[stack_a + 1]) > ft_atoi(argv[stack_a + 2]))
				stack_a = push_a(&argv, stack_a);
			else if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
				swap_a(&argv, stack_a);
			if (stack_a > 1)// condition to be sure the opp. stack > 1 
				if (ft_atoi(argv[1]) > ft_atoi(argv[2]))
					swap_a(&argv, stack_a);
			//func_display(argc, argv, stack_a);
		}
		if ((argc - 1) - stack_a == 1)
			stack_a = push_a(&argv, stack_a);
	}*/

	checker(argc, argv);
	ft_printf("\n========\nSorted!  :)\n");
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