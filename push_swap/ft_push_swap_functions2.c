/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap_functions2.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mwikiera <mwikiera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 12:02:32 by mwikiera          #+#    #+#             */
/*   Updated: 2024/04/25 12:03:42 by mwikiera         ###   ########.ch       */
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
//	ft_printf("%d\n", ft_atoi(argv[1]));
//	ft_printf("%d\n", ft_atoi(argv[2]));
//	ft_printf("%d\n", ft_atoi(argv[3]));

	if (ft_atoi(argv[1]) < ft_atoi(argv[2]) && ft_atoi(argv[3]) < ft_atoi(argv[2]))
	{
		reverse_rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
	if (ft_atoi(argv[3]) < ft_atoi(argv[2]) && ft_atoi(argv[2]) < ft_atoi(argv[1]))
	{
		rotate_a(&argv, stack_a);
		swap_a(&argv, stack_a);
	}
	if (ft_atoi(argv[2]) < ft_atoi(argv[3]) && ft_atoi(argv[2]) < ft_atoi(argv[1]) && ft_atoi(argv[3]) < ft_atoi(argv[1]))
		rotate_a(&argv, stack_a);
	if (ft_atoi(argv[2]) < ft_atoi(argv[3]) && ft_atoi(argv[2]) < ft_atoi(argv[1]))
		swap_a(&argv, stack_a);
	if (ft_atoi(argv[3]) < ft_atoi(argv[2]) && ft_atoi(argv[1]) < ft_atoi(argv[2]))
		reverse_rotate_a(&argv, stack_a);
}

void	ft_sort(char *argv[], int argc, int *stack_a)
{
	//int min_moves;
	int first;
	int second;
	int third;

	//ft_printf("\nstack_a: %d\n", *stack_a);
	push_b(&argv, stack_a);
	push_b(&argv, stack_a);
	//ft_printf("\nstack_a: %d\n", *stack_a);
	push_b(&argv, stack_a);
	//stack_a = push_b(&argv, stack_a);
	ft_printf("push 2x to b\n\n");

	//if (ft_atoi(argv[*stack_a + 1]) < ft_atoi(argv[argc - 1]))
	//	swap_b(&argv, *stack_a, argc);

	//while (*stack_a > 3)
	for (int a = 0; a < 2; a++)  // change to 1 2 3 4 ...
	{
		ft_printf("\n\n doing this again \n\n");
	first = path1(argv, argc, *stack_a);
	second = path2(argv, argc, *stack_a);
	third = path3(argv, argc, *stack_a);

	func_display(argc, argv, *stack_a);
	
	if (first <= second && first <= third)
	{
		ft_printf("\n1a is min and has: %d moves\n", first);
		sorta1(argv, argc, stack_a); // fonction OFF
	}
	if (second < first && second <= third)
	{
		ft_printf("\n2a is min and has: %d moves\n", second);
		//sorta3();
	}
	if (third < first && third < second)
	{
		ft_printf("\n3a is min and has: %d moves\n", third);
		//sorta3();
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

	ft_printf("--> %d \n\n", min_moves);
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

	ft_printf("--> %d \n\n", min_moves);
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

	ft_printf("--> %d \n\n", min_moves);
	return (min_moves);
}
