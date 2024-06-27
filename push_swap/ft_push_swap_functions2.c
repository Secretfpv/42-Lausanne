/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 01:44:56 by mwikiera          #+#    #+#             */
/*   Updated: 2024/06/27 01:49:42 by mwikiera         ###   ########.ch       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

int	checker(int argc, char *argv[])
{
	int	i;

	i = 1;
	while (i < argc - 1)
	{
		if (ft_atoi(argv[i]) > ft_atoi(argv[i + 1]))
		{
			//ft_printf("\nNot sorted  :(\n");
			return (0);// this case its not sorted
		}
		i++;
	}
	//ft_printf("\nSorted!  :)\n");
	return (1);// in this case its sorted
}

void	ft_sort_3_a(char *argv[], int stack_a)
{
	/*if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[1]) > ft_atoi(argv[3]) && ft_atoi(argv[2]) > ft_atoi(argv[3]))// > >
	{
		rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
	else if (ft_atoi(argv[3]) < ft_atoi(argv[2]) && ft_atoi(argv[2]) > ft_atoi(argv[1]) && ft_atoi(argv[3]) < ft_atoi(argv[1]))
		reverse_rotate_a(&argv, stack_a);
	else if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[3]) > ft_atoi(argv[1]) && ft_atoi(argv[2]) < ft_atoi(argv[3]))
		swap_a(&argv, stack_a);
	else if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[1]) > ft_atoi(argv[3]) && ft_atoi(argv[3]) > ft_atoi(argv[2]))
		rotate_a(&argv, stack_a);*/		//   This is from smaller to bigger and the next one is from bigger to smaller 

	// Dont touch this, its really good this time !!!!!!!

	if (ft_atoi(argv[1]) < ft_atoi(argv[2]) && ft_atoi(argv[1]) < ft_atoi(argv[3]) && ft_atoi(argv[2]) < ft_atoi(argv[3]))// > >
		reverse_rotate_a(&argv, stack_a);
	else if (ft_atoi(argv[3]) > ft_atoi(argv[2]) && ft_atoi(argv[2]) < ft_atoi(argv[1]) && ft_atoi(argv[3]) > ft_atoi(argv[1]))
	{
		swap_a(&argv, stack_a);
		reverse_rotate_a(&argv, stack_a);
	}
	else if (ft_atoi(argv[1]) < ft_atoi(argv[2]) && ft_atoi(argv[3]) < ft_atoi(argv[1]) && ft_atoi(argv[2]) > ft_atoi(argv[3]))
		rotate_a(&argv, stack_a);
	else if (ft_atoi(argv[1]) < ft_atoi(argv[2]) && ft_atoi(argv[1]) < ft_atoi(argv[3]) && ft_atoi(argv[3]) < ft_atoi(argv[2]))
		swap_a(&argv, stack_a);
	else if (ft_atoi(argv[1]) > ft_atoi(argv[2]) && ft_atoi(argv[1]) > ft_atoi(argv[3]) && ft_atoi(argv[3]) < ft_atoi(argv[2]))
	{
		reverse_rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
}

void	ft_sort(char *argv[], int argc, int *stack_a)
{
	int first;
	int second;
	int third;

	while (*stack_a > 3)
	//for (int a = 0; a < 2; a++)  // change to 1 2 3 4 ...
	{
//		ft_printf("\n\n doing this again \n\n");
		first = path1(argv, argc, *stack_a);
		second = path2(argv, argc, *stack_a);
		third = path3(argv, argc, *stack_a);

//	func_display(argc, argv, *stack_a);
	
		if (first <= second && first <= third)
		{
//			ft_printf("\n1a is min and has: %d moves\n", first);
			sorta1(argv, argc, stack_a); // fonction OFF
		}
		else if (second < first && second <= third)
		{
//			ft_printf("\n2a is min and has: %d moves\n", second);
			sorta3(argv, argc, stack_a);
		}
		else if (third < first && third < second)
		{
//			ft_printf("\n3a is min and has: %d moves\n", third);
			sorta3(argv, argc, stack_a);
		}
	}
}

int path1(char *argv[], int argc, int stack_a)
{
	int min_moves;
	int down;

	min_moves = moves_up(argv, argc, stack_a, 1);
	down = moves_down(argv, argc, stack_a, 1);

	if (down < min_moves)
		min_moves = down;

//	ft_printf("1+--> %d \n\n", min_moves);
	return (min_moves);
}

int path2(char *argv[], int argc, int stack_a)
{
	int min_moves;
	int down;

	min_moves = moves_up(argv, argc, stack_a, 2);
	down = moves_down(argv, argc, stack_a, 2);

	if (down < min_moves)
		min_moves = down;

//	ft_printf("2++--> %d \n\n", min_moves);
	return (min_moves);
}

int path3(char *argv[], int argc, int stack_a)
{
	int min_moves;
	int down;

	min_moves = moves_up(argv, argc, stack_a, 3);
	down = moves_down(argv, argc, stack_a, 3);

	if (down < min_moves)
		min_moves = down;

//	ft_printf("3+++--> %d \n\n", min_moves);
	return (min_moves);
}
